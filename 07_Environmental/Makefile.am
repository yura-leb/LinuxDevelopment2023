AMFLAGS = -Wall -O0 -g

bin_PROGRAMS=rhasher

rhasher_SOURCES=rhasher.c

test: rhasher
	cat rhasher.c | sha1sum | cut -d ' ' -f 1 > example.txt
	echo 'SHA1 rhasher.c' | ./rhasher > test.txt
	cat example.txt | grep -f test.txt

	cat rhasher.c | md5sum |  cut -d ' ' -f 1 > example.txt
	echo 'MD5 rhasher.c' | ./rhasher > test.txt
	cat example.txt | grep -f test.txt

gitclean:
	git clean -df