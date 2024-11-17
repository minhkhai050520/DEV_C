# Định nghĩa các file đối tượng
objects = main.o push_pop.o getop.o getch_ungetch.o

# Quy tắc để tạo file thực thi "final"
final: $(objects)
	cc -o final $(objects)

# Quy tắc tạo các file .o từ các file .c
main.o: main.c myLib.h
	cc -c main.c -o main.o

push_pop.o: push_pop.c myLib.h
	cc -c push_pop.c -o push_pop.o

getop.o: getop.c myLib.h
	cc -c getop.c -o getop.o

getch_ungetch.o: getch_ungetch.c myLib.h
	cc -c getch_ungetch.c -o getch_ungetch.o

# Quy tắc dọn dẹp file
.PHONY: clean
clean:
	del /f final.exe *.o
