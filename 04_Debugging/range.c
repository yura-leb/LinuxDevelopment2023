#include <stdio.h>
#include <stdlib.h>

void range(int start, int stop, int step) {
    if (start < stop) {
        for (int i = start; i < stop; i += step) {
            printf("%d\n", i);
        }
    } else {
        for (int i = start; i > stop; i += step) {
            printf("%d\n", i);
        }
    }
    return;
}

int main(int argc, char *argv[]) {
    int start = 0, stop = 0, step = 1; 
    switch (argc) {
        case 1:
            printf("help\n");
            return 0;
        case 2:
            stop = atoi(argv[1]);
            break;
        case 3:
            start = atoi(argv[1]);
            stop = atoi(argv[2]);
            break;
        case 4:
            start = atoi(argv[1]);
            stop = atoi(argv[2]);
            step = atoi(argv[3]);
            break;
        default:
            printf("Range has 0 to 3 parameters, given %d\n", argc-1);
            return 0;
    }
    if (step == 0) {
        printf("Step must be non-zero\n");
        return 0;
    }
    if ((step < 0 && start < stop) || (step > 0 && start > stop)) {
        printf("Incorrect combination of parameters start = %d, stop = %d, step = %d\n", start, stop, step);
        return 0;
    }
    range(start, stop, step);
    return 0;

}