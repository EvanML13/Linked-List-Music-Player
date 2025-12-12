#include "../include/givenA3.h"
#include <strings.h>

int playSongGivenName(A3Song *headLL,char givenSongName[MAX_LENGTH]){

    // Itterates Through All The Names In The Linked List
    while(headLL != NULL){
        
        // If The Song Name Matches The Given Song Name
        // Learned About The strcasecmp Function From https://www.ibm.com/docs/en/i/7.3?topic=functions-strcasecmp-compare-strings-without-case-sensitivity
        if(strcasecmp(headLL->songName, givenSongName) == 0){

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