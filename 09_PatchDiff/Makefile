GENERATES = *.o *~ o.* maze maze1 maze2 maze3 maze1.c maze2.c maze3.c

all:	maze1 maze2 maze3

maze: maze.c
	gcc $^ -o $@

maze1: maze1.c
	gcc $^ -o $@

maze2: maze2.c
	gcc $^ -o $@

maze3: maze3.c
	gcc $^ -o $@

maze1.c: maze.c maze1.patch
	cp maze.c maze1.c
	patch maze1.c < maze1.patch

maze2.c: maze1.c maze2.patch
	cp maze1.c maze2.c
	patch maze2.c < maze2.patch

maze3.c: maze2.c maze3.patch
	cp maze2.c maze3.c
	patch maze3.c < maze3.patch

run:
	./maze1 6
	./maze2 "# " 5
	./maze3 4 "# " 7

clean:
	rm -rf $(GENERATES)