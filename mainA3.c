#include "../include/givenA3.h"

int main(int argc, char * argv[]){

    int choice;

    // 1. Create a new playlist Variables
    char fileName[MAX_LENGTH] = "musicalNotes.csv";
    int numPlaylistSongs;
    A3Song *playlist = NULL;

    // 2. Add a new song to an existing playlist Variables
    int beginOrEnd;
    bool songAdded;

    // 4. Play a song from the playlist, given its id Variables
    int givenSongId;
    int songIdFound;
    
    // 5. Play a song from the playlist, given its name Variables
    char givenSongName[MAX_LENGTH];
    int songNameFound;
    int c;
            
    // 6. Count the number of occurrences of a note in a given song Variables
    char noteToCount[NOTE_LENGTH];
    int noteCount; 

    do{
        do{
            // Prints The Main Menu
            printf("\n");
            printf("======================================================\n");
            printf("1. Create a new playlist\n");
            printf("2. Add a new song to an existing playlist\n");
            printf("3. Play all songs in the given playlist\n");
            printf("4. Play a song from the playlist, given its id\n");
            printf("5. Play a song from the playlist, given its name\n");
            printf("6. Count the number of occurrences of a note in a given song\n");
            printf("7. Delete a song from the playlist, given its id\n");
            printf("8. Delete the entire playlist\n");
            printf("9. Exit\n");
            printf("======================================================\n");

            // Prompts User To Enter Their Choice
            printf("Enter your choice: ");
            //scanf("%d", &choice);

            // Validates User Input
            // Used scanf Return Values Found At https://www.ibm.com/docs/en/i/7.4?topic=functions-scanf-read-data
            if (scanf("%d", &choice) != 1) { 

                // Prints Type Error Message
                printf("Invalid Type!!\n");
    
                // Clear Input Buffer
                while (getchar() != '\n');
    
                break;
            }

            // Validates User Input
            if(choice < 1 || choice > 9){
                printf("Invalid Choice!!\n");
            }

        }while(choice < 1 || choice > 9);

        switch(choice){

            case 1:
                // Function To Create Playlist
                numPlaylistSongs = createPlayList(&playlist, fileName);

                // If The Function Returns -1 The File Cannot Be Opened
                if(numPlaylistSongs == -1){
                    printf("File Unsuccessfully Read\n");
                }

                // Tells The User How Many Songs Are In The Playlist
                printf("Number of songs in the playlist: %d \n", numPlaylistSongs);

                break;

            case 2:

                // Prompts User To Enter A Value For Where The Song Will Be Added
                printf("Enter the value for beginOrEnd: ");
                scanf("%d", &beginOrEnd);

                // Function To Add A Song To The Playlist
                songAdded = addNewSong(&playlist, beginOrEnd);

                // Tells User If And Where The Song Is Added To The Playlist
                if(songAdded == true && beginOrEnd == 1){
                    printf("\nSong added at the begining!\n");
                }
                else if(songAdded == true && beginOrEnd == 2){
                    printf("\nSong added at the end!\n");
                }
                else{
                    printf("\nSong was not added\n");
                }

                break;

            case 3:

                // Function To Print The Playlist 
                playPlayList(playlist);

                break;

            case 4:

                // Clear Input Buffer 
                while ((c = getchar()) != '\n');

                // Prompts User To Enter A Song ID
                printf("Enter the id of the song you want to play: ");
                scanf("%d", &givenSongId);
                printf("\n");

                // Function To Play A Song Given Its ID
                songIdFound = playSongGivenId(playlist, givenSongId);

                // Funtion Returns -1 If The Song ID Is Not Found
                if(songIdFound == -1){
                    printf("Song not found!!\n");
                }

                break;

            case 5:

                // Clear Input Buffer
                while ((c = getchar()) != '\n');

                // Prompts User To Enter A Song Name
                printf("Enter the name of the song you want to play: ");
                fgets(givenSongName, MAX_LENGTH, stdin);

                // Removes The Newline Character From The String
                givenSongName[strcspn(givenSongName, "\n")] = 0;
                
                printf("\n");

                // Function To Play A Song Given Its Name
                songNameFound = playSongGivenName(playlist, givenSongName);

                // Funtion Returns -1 If The Song Name Is Not Found
                if(songNameFound == -1){
                    printf("Song not found!!\n");
                }

                break;

            case 6:

                // Prompts User To Enter A Song ID To Find The Number Of Notes In It
                printf("Enter the id of the song you want to count the notes in: ");
                scanf("%d", &givenSongId);

                printf("\n");

                // Prompts User To Enter A Note To Count
                printf("Enter the note you want to count: ");
                scanf("%s", noteToCount);

                // Validates User Input To Be On One Of The Given Notes
                if(strcmp(noteToCount, "do") != 0 && strcmp(noteToCount, "re") != 0 && strcmp(noteToCount, "mi") != 0 && strcmp(noteToCount, "fa") != 0 && strcmp(noteToCount, "sol") != 0 && strcmp(noteToCount, "la") != 0 && strcmp(noteToCount, "ti") != 0){
                    printf("\nSong not found!!\n");
                    break;
                }

                printf("\n");

                // Function To Count The Number Of Notes In A Song
                noteCount = countNotesInASong(playlist, givenSongId, noteToCount); 

                // Funtion Returns -1 If The Song ID Is Not Found
                if(noteCount == -1){
                    printf("Song not found!!\n");         
                }

                // Tells The User How Mnay Times The Note Appears
                else{
                    printf("Number of times the note appears: %d\n", noteCount);
                }

                break;
            
            case 7:

                // Prompts User To Enter The Song ID To Delete
                printf("Enter the id of the song you want to delete: ");
                scanf("%d", &givenSongId);
                printf("\n");

                // Function To Delete A Song From The Playlist
                songIdFound = deleteASongGivenId(&playlist, givenSongId);

                // Funtion Returns -1 If The Song ID Is Not Found
                if(songIdFound == -1){
                    printf("Song not found!!\n");
                }

                else{
                    printf("Song Deleted!!\n");
                }

                break;

            case 8:

                // Function To Delete The Entire Playlist
                deletePlayList(&playlist);
                
                printf("\nDeleting Playlist ♫♫♫\n");
                break;
            
            case 9:
                printf("Goodbye\n");
                break;
        }
    
    }while(choice != 9);


    return 0;
}