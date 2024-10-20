main: main.c thread1.c thread1.h
	gcc -o main main.c thread1.c thread1.h thread2.c thread2.h

clean:
	rm -f main