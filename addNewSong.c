#include "../include/givenA3.h"

bool addNewSong(A3Song **headLL, int beginOrEnd){

    char songName[MAX_LENGTH];
    int nameLength, randomNumber, songID;
    bool isUnique;
    int c;

    // Clear Input Buffer 
    while ((c = getchar()) != '\n');

    // Prompts User To Enter The Name Of The Song
    printf("Song name: ");
    fgets(songName, MAX_LENGTH, stdin);

    if(beginOrEnd != 1 && beginOrEnd != 2){
        printf("\nInvalid beginOrEnd value passed!!.");
        return false;
    }

    // Removes The New Line Character
    songName[strcspn(songName, "\n")] = '\0';

    // Creates A New Song Node
    A3Song *newSong = malloc(sizeof(A3Song));

    // Adds The Song Name To The Song Name Node
    strcpy(newSong->songName, songName);

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

        // Itterates Through All Nodes
        while(current != NULL){

            // If The Song ID Already Exists Then Create Another Random Song ID
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

    // Iterates Through Each Song Note
    for(int i = 0; i < 21; i++){

        // Generates A Random Number For Each Of The 7 Notes
        randomNumber = rand() % 7 + 1;

        // Assigns The Notes
        if(randomNumber == 1){
            strcpy(newSong->songNotes[i], "do");
        }

        else if(randomNumber == 2){
            strcpy(newSong->songNotes[i], "re");
        }

        else if(randomNumber == 3){
            strcpy(newSong->songNotes[i], "mi");
        }

        else if(randomNumber == 4){
            strcpy(newSong->songNotes[i], "fa");
        }

        else if(randomNumber == 5){
            strcpy(newSong->songNotes[i], "sol");
        }

        else if(randomNumber == 6){
            strcpy(newSong->songNotes[i], "la");
        }

        else if(randomNumber == 7){
            strcpy(newSong->songNotes[i], "ti");
        }
    }

    // If User Wants The Song To Be Added To The End Of The Playlist
    if(beginOrEnd == 1){

        // If The Linked List Is Empty
        if(*headLL == NULL){
            // The Head Is The Only Node And It Is Set To The New Song
            *headLL = newSong;
            newSong->nextSong = NULL;
        }

        // If The Linked List Is Not Empty
        else{
            // Adds The New Song To The Top Of The Linked List
            newSong->nextSong = *headLL;
            *headLL = newSong;
        }
    }

    // If User Wants The Song To Be Added To The Begining Of The Playlist
    else if(beginOrEnd == 2){

        // If The Linked List Is Empty
        if(*headLL == NULL){
            // The Head Is The Only Node And It Is Set To The New Song
            *headLL = newSong;
            newSong->nextSong = NULL;
        }

        // If The Linked List Is Not Empty
        else{

            A3Song *current = *headLL;

            // Itterates Through All Nodes
            while(current->nextSong != NULL){
                current = current->nextSong;
            }

            // Adds The New Song To The End Of The Linked List
            current->nextSong = newSong;
            newSong->nextSong = NULL;
        }
    }

    else{
        return false;
    }

    // Prints The Song Added To The Playlist
    printf("\n");
    printf("Song ID: %d\n", newSong->songId);
    printf("Song Name: %s\n", newSong->songName);
    printf("Notes: ");
    for(int i = 0; i < 21; i++){
        printf("%s ", newSong->songNotes[i]);
    }
    printf("\n");

    return true;
}