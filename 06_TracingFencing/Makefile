GENERATES = move *.o *~ o.* libprotect.so *.txt

all:	move

move: move.c

libprotect.so: libprotect.c
	gcc -shared -fPIC -o libprotect.so libprotect.c -ldl

test: move libprotect.so
	./test1.sh
	./test2.sh
	./test3.sh
	./test4.sh
	./test5.sh
	./test6.sh

clean:
	rm -rf $(GENERATES)