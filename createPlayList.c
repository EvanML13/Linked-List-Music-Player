#include "../include/givenA3.h"

int createPlayList(A3Song **headLL, char fileName[MAX_LENGTH]){

    int count = 0, nameLength, randomNumber, songID;
    bool isUnique;
    char line [10000]; // Buffer To Store An Entire Row Of The CSV File

    // Opens File 
    FILE *fptr = fopen(fileName, "r");

    // Returns -1 If The File Cannot Be Opened
    if(fptr == NULL){
        return -1;
    }

    // Reads The First Line Of The File
    if(fgets(line, sizeof(line), fptr) != NULL){

        // To Prevent The First Row Of The CSV File Labled SongName,note1,note2,... From Being Added To The Linked List I Check If The First Line Contains A Subset Of The String "SongName" And Skip It
        // Learned About The strstr Function From https://www.w3schools.com/c/ref_string_strstr.php   
        if(strstr(line, "SongName") != NULL){
            // printf("Header Skipped\n")
        }
    
        // If The First Line Does Not Contain The Sub String "SongName" Then Move Back To The Begining Of The File
        else{
            fseek(fptr, 0, SEEK_SET);
        }
    }

    // Itterates Through Each Each Line Of The File
    while(fgets(line, sizeof(line), fptr)){

        // Creates A New Song Node
        A3Song *newSong = malloc(sizeof(A3Song));

        int i = 0;
        
        // Adds The Song Name To The Song Name Node Not Including The Comma And Null Terminator
        while(line[i] != ',' && line[i] != '\0'){
            newSong->songName[i] = line[i];
            i++;
        }

        // Adds The Null Terminatior To The End Of The Song Name
        newSong->songName[i] = '\0';

        // Skips The Comma At The End Of The Song Name
        i++; 

        //printf("Song Name: %s\n", newSong->songName);

        // Generate A Song ID Untill It Is Unique
        do{

            // Gets The Songs Name Length And Random Number Between 1 And 1000
            nameLength = strlen(newSong->songName);
            randomNumber = rand() % 1000 + 1;

            // Calculates Song ID
            songID = nameLength + randomNumber;

            // Assumes The Song ID Is Unique
            isUnique = true;

            // Traverses The Linked List
            A3Song *current = *headLL;
            while(current != NULL){

                // If The Song ID Already Exists Then Itterate Back Through The Loop To Make Another Unique ID
                if(current->songId == songID){
                    isUnique = false;
                    break;
                }

                // Moves To The Next Song
                current = current->nextSong;
            }

        }while(isUnique != true);

        // Assigns The Unique Song ID
        newSong->songId = songID;

        //printf("Song ID: %d\n", newSong->songId);

        // Iterates Through Each Song Note
        for(int noteIndex = 0; noteIndex < 21; noteIndex++){

            int j = 0;

            // Adds The Note To The Note Node Not Including The Comma And Null Terminator
            while (line[i] != ',' && line[i] != '\0' && j < NOTE_LENGTH - 1){
                newSong->songNotes[noteIndex][j] = line[i];
                i++;
                j++;
            }

            // Adds The Null Terminator To The End Of The Note
            newSong->songNotes[noteIndex][j] = '\0';

            i++; // Skips The Tab And Moves To The Next Note

            //printf("Note %d: %s\n", noteIndex + 1, newSong->songNotes[noteIndex]);
        }

        // Adds New Song To The End Of The Linked List
        newSong->nextSong = NULL;

        // If The Linked List Is Empty The Head Is The Only Node
        if(*headLL == NULL){
            *headLL = newSong;
        }

        else{
            
            // Traverses The Linked List
            A3Song *current = *headLL;
            while(current->nextSong != NULL){
                
                // Moves To The Next Song
                current = current->nextSong;
            }

            // Adds The New Song To The End Of The Linked List
            current->nextSong = newSong;
        }

        // Increases The Count For The Amount Of Songs In The Playlist
        count ++;
    }

    fclose(fptr);
    
    // Returns The Number Of Songs Added To The Playlist
    return count;
}