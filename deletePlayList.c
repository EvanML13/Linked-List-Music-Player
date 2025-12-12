#include "../include/givenA3.h"

void deletePlayList(A3Song **headLL){

    // Itterates Through The Linked List
    while(*headLL != NULL){

        // Create A Temporary Pointer To The Current Node
        A3Song *temp = *headLL;

        // Move The Head Pointer To The Next Node
        *headLL = (*headLL)->nextSong;

        // Free The Allocated Memory 
        free(temp);
    }

    // Set The Head Pointer To NULL
    *headLL = NULL;
}