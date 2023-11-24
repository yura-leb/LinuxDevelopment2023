GENERATES = esub *.o *~ o.* maze maze1 maze2 maze3 maze1.c maze2.c maze3.c

all:	maze

maze: maze.c
	gcc $^ -o $@

clean:
	rm -rf $(GENERATES)