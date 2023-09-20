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

    char strings[500][200];
    int i = 0;
    while(fgets(strings[i], 200, src)) {
        i++;
    }
    int strings_len = i;

    initscr();
    noecho();
    cbreak();
    printw("File: %s", argv[1]);
    refresh();

    win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
    keypad(win, TRUE);
    scrollok (win, TRUE);
    box(win, 0, 0); 
    wmove(win, 1, 0);
    int number_of_strings = strings_len < LINES - 2 * DX - 1 ? strings_len : LINES - 2 * DX - 1;
    for (i = 0; i < number_of_strings; ++i) {
        wprintw(win, "  %s", strings[i]);
        box(win, 0, 0); 
        wrefresh(win);
    }
    i = 0;
    while((c = wgetch(win)) != 27) {
        if (c == 32 && i < strings_len) {
            wprintw(win, "  %s", strings[i]);
            ++i;
            box(win, 0, 0); 
            wrefresh(win);
        }
    }
    fclose(src);
    endwin();
}
