#include "../include/givenA3.h"

int deleteASongGivenId(A3Song **headLL, int givenSongId){

    // Itterates Through The Linked List
    while(*headLL != NULL){

        // If The Song ID Matches The Given Song ID
        if((*headLL)->songId == givenSongId){

            // Create A Temporary Pointer To The Current Node
            A3Song *temp = *headLL;

            // Move The Head Pointer To The Next Node
            *headLL = (*headLL)->nextSong;

            // Free The Allocated Memory
            free(temp);

            return 1;
        }

        // Move To The Next Song
        headLL = &((*headLL)->nextSong);
    }
    
    return -1;
}