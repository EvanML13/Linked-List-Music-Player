#include "../include/givenA3.h"

int playSongGivenId(A3Song *headLL, int givenSongId){

    // Itterates Through All The IDs In The Linked List
    while(headLL != NULL){

        // If The Song ID Matches The Given Song ID
        if(headLL->songId == givenSongId){

            // Prints The Songs Infromation
            printf("Song ID: %d\n", headLL->songId);
            printf("Song Name: %s\n", headLL->songName);

            printf("Notes: ");

            // Itterates Through All The Notes
            for(int i = 0; i < 21; i++){

                // Prints The Notes
                printf("%s", headLL->songNotes[i]);

                // Prints The Period To Seperate The Notes But Not One At The End
                if(i < 20){
                    printf(".");
                }
            }
            printf("\n\n");

            return 1;
        }

        // Move To The Next Song
        headLL = headLL->nextSong;
    }
    
    return -1;
}