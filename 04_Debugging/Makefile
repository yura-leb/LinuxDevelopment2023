GENERATES = range *.o *~ o.* test_1_12.txt test_100_100_3.txt

all:	range

range: range.c
	gcc -g -o0 $^ -o $@

test: 
	gdb -quiet -silent -batch --command=gdb_1_12 --args ./range | grep '^@@@' | cut -c 4- > test_1_12.txt
	gdb -quiet -silent -batch --command=gdb_100_100_3 --args ./range | grep '^@@@' | cut -c 4- > test_100_100_3.txt
	cmp test_1_12.txt standard_1_12.txt 
	cmp test_100_100_3.txt standard_100_100_3.txt

clean:
	rm -rf $(GENERATES)