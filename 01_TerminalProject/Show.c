#include <ncurses.h>
#include <stdlib.h>

#define DX 3

void main(int argc, char **argv) {
    WINDOW *win;
    int c = 0;

    FILE *src;
    if (argc != 2) {
        printf("Filename missing\n");
        exit(EXIT_FAILURE);
    }
    src = fopen (argv[1], "r");
    if (src == NULL) {
        printf("Wrong filename\n");
        exit(EXIT_FAILURE);
    }

    char string[300];
    int i = 0;

    initscr();
    noecho();
    cbreak();
    printw("File: %s", argv[1]);
    refresh();

    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
    keypad(win, TRUE);
    scrollok (win, TRUE);
    box(win, 0, 0); 
    wmove(win, 2, 0);
    int window_size = LINES - 2 * DX - 2;
    i = 0;
    while (i < window_size && fgets(string, 300, src)) {
        wprintw(win, "  %s", string);
        box(win, 0, 0); 
        wrefresh(win);
        ++i;
    }
    while((c = wgetch(win)) != 27) {
        if (c == 32 && fgets(string, 300, src)) {
            wprintw(win, "  %s", string);
            box(win, 0, 0); 
            wrefresh(win);
        }
    }
    fclose(src);
    endwin();
}
