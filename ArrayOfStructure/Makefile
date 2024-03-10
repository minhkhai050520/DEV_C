final: binsearch.o getch_ungetch.o getword.o main.o
	gcc -o final binsearch.o getch_ungetch.o getword.o main.o

binsearch.o: binsearch.c myLibrary.h
	gcc -c binsearch.c
getch_ungetch.o: getch_ungetch.c myLibrary.h
	gcc -c getch_ungetch.c myLibrary.h
getword.o: getword.c myLibrary.h
	gcc -c getword.c

clean:
	del final.exe binsearch.o getch_ungetch.o getword.o main.o