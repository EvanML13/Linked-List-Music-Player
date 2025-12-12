#include "../include/givenA3.h"

void playPlayList(A3Song *headLL){

    printf("\n");

    // Traverses The Linked List
    A3Song *current = headLL;

    // Itterates Through All Nodes
    while(current != NULL){

        // Prints The Song ID And Song Name 
        printf("Song ID: %d\n", current->songId);
        printf("Song Name: %s\n", current->songName);

        printf("Notes: ");

        // Itterates Through All The Notes
        for(int i = 0; i < 21; i++){
            // Prints The Notes
            printf("%s", current->songNotes[i]);

            // Prints The Period To Seperate The Notes But Not One At The End
            if(i < 20){
                printf(".");
            }
        } 
        printf("\n\n");

        // Moves To The Next Song In The Playlist
        current = current->nextSong;
    }
}