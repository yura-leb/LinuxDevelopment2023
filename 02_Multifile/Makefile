GENERATES = prog prog-a prog-so liboutput_static.a liboutput.so *.text *.o *~ o.*
CFLAGS=-fPIC

all:	prog prog-a prog-so

prog:	const.o fun.o prog.o

prog-a: prog.o liboutput_static.a
	cc -L. $< -loutput_static -o $@

prog-so:	prog.o liboutput.so
	cc -L. prog.o -loutput -o $@

fun.o:	outlib.h

liboutput_static.a:	fun.o const.o
	ar -rcs $@ $^

liboutput.so: const.o fun.o
	cc -shared $^ -o $@

test: test1 test2 test3 

test1:	prog prog-a prog-so
	./prog > $@.text 2> /dev/null; ./prog-a > $@-a.text 2> /dev/null; LD_LIBRARY_PATH=`pwd` ./prog-so > $@-so.text 2> /dev/null;
	cmp $@.text $@-a.text
	cmp $@.text $@-so.text
	cmp $@-a.text $@-so.text

test2:	prog prog-a prog-so
	./prog 1 > $@.text 2> /dev/null; ./prog-a 1 > $@-a.text 2> /dev/null; LD_LIBRARY_PATH=`pwd` ./prog-so 1 > $@-so.text 2> /dev/null;
	cmp $@.text $@-a.text; 
	cmp $@.text $@-so.text; 
	cmp $@-a.text $@-so.text;

test3:	prog prog-a prog-so
	./prog 1 2 3 > $@.text 2> /dev/null; ./prog-a 1 2 3 > $@-a.text 2> /dev/null; LD_LIBRARY_PATH=`pwd` ./prog-so 1 2 3 > $@-so.text 2> /dev/null;
	cmp $@.text $@-a.text; 
	cmp $@.text $@-so.text; 
	cmp $@-a.text $@-so.text;

clean:
	rm -rf $(GENERATES)