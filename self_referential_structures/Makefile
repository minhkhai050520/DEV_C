
objects = getch_ungetch.o getword.o addtree.o treeprint.o\
	  talloc.o strdup.o main.o
final : $(objects)
	gcc -o final $(objects)
$(objects): myLib.h
.PHONY: clean
clean:
	del *.o final.exe

