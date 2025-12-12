bin/musicalLL: src/playSongGivenName.o src/playSongGivenId.o src/playPlayList.o src/mainA3.o src/deletePlayList.o src/deleteASongGivenId.o src/createPlayList.o src/countNotesInASong.o src/addNewSong.o
	gcc -Wall -std=c99	src/playSongGivenName.o src/playSongGivenId.o src/playPlayList.o src/mainA3.o src/deletePlayList.o src/deleteASongGivenId.o src/createPlayList.o src/countNotesInASong.o src/addNewSong.o -o bin/musicalLL

src/playSongGivenName.o: src/playSongGivenName.c include/givenA3.h
	gcc -Wall -std=c99 -c src/playSongGivenName.c -o src/playSongGivenName.o 

src/playSongGivenId.o: src/playSongGivenId.c include/givenA3.h
	gcc -Wall -std=c99 -c src/playSongGivenId.c -o src/playSongGivenId.o 

src/playPlayList.o: src/playPlayList.c include/givenA3.h
	gcc -Wall -std=c99 -c src/playPlayList.c -o src/playPlayList.o 

src/mainA3.o: src/mainA3.c include/givenA3.h
	gcc -Wall -std=c99 -c src/mainA3.c -o src/mainA3.o 

src/deletePlayList.o: src/deletePlayList.c include/givenA3.h
	gcc -Wall -std=c99 -c src/deletePlayList.c -o src/deletePlayList.o 		

src/deleteASongGivenId.o: src/deleteASongGivenId.c include/givenA3.h
	gcc -Wall -std=c99 -c src/deleteASongGivenId.c -o src/deleteASongGivenId.o 

src/createPlayList.o: src/createPlayList.c include/givenA3.h
	gcc -Wall -std=c99 -c src/createPlayList.c -o src/createPlayList.o 

src/countNotesInASong.o: src/countNotesInASong.c include/givenA3.h
	gcc -Wall -std=c99 -c src/countNotesInASong.c -o src/countNotesInASong.o 

src/addNewSong.o: src/addNewSong.c include/givenA3.h
	gcc -Wall -std=c99 -c src/addNewSong.c -o src/addNewSong.o 

clean:
	rm src/*.o bin/musicalLL