# Project Summary
This project is an academic assignment focused on dynamic memory management, linked list manipulation, and function modularity in C. The program simulates a simple music playlist system where each song is stored as a node in a singly linked list. Users can create playlists from a CSV file, add or remove songs, count notes in a song, play songs by name or ID, and delete the playlist entirely. The design emphasizes pointer management, memory safety, and clean modular functions.

Loads musical notes and song metadata from a file (default: musicalNotes.csv), builds a linked list, and reports the total number of songs. The user can then call one of the following functionalities to manipulate the playlist: 
1. Add A New Song: The user can insert a new song at the beginning or end of the playlist
2. Play All Songs: Traverses the linked list and prints all songs in order
3. Play Song By ID: Searches the linked list for a song with a specific songId, if found, plays it by printing all stored notes
4. Play Song By Name: Searches the linked list for a song with a matching string name
5. Count Occurrences of a Musical Note: Given a songId and a note (e.g., "do", "re", "mi"), counts how many times the note appears in that song
6. Delete Song by ID: Removes a node from the linked list while preserving list structure
7. Delete Entire Playlist: Frees all allocated memory and resets the playlist to empty.

This project was completed in VSCode SOCS and uploaded to GitHub.

- December 12th, 2025
- Evan Leonard
