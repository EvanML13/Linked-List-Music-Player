#include "../include/givenA3.h"

int countNotesInASong(A3Song *headLL, int givenSongId, char whichNote[4]){

    int count = 0; 

    // Itterates Through The Linked List
    while(headLL != NULL){

        // If The Song ID Matches The Given Song ID
        if(headLL->songId == givenSongId){

            // Itterates Through All The Notes
            for(int i = 0; i < 21; i++){

                // If The Note Matches The Given Note
                if(strcmp(headLL->songNotes[i], whichNote) == 0){

                    // Increase Count
                    count++;
                }
            }

            // Returns The Count Of The Number Of Times That Note Appears
            return count;
        }

        // Move To The Next Song
        headLL = headLL->nextSong;
    }

    return -1;
} 