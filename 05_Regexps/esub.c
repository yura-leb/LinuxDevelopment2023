#include <stdio.h>
#include <stdlib.h>
#include <regex.h>
#include <ctype.h>

#define MAXGR 10
#define ERRBUF_SIZE 256

void process_error(int err, regex_t *preg) {
    char errbuf[ERRBUF_SIZE];
    regerror(err, preg, errbuf, ERRBUF_SIZE);
    fprintf(stderr, "%s\n", errbuf);
}

int check_substitution(char *substitution, regmatch_t *bags) {
    char *c;
    int is_bag = 0;
    c = substitution;
    while (*c) {
        if (*c == '\\') {
            is_bag = 1;
            c++;
            if (*c == '\\') {
                is_bag = 0;
            }
        }
        if (is_bag) {
            if (!isdigit(*c)) {
                fprintf(stderr, "Incorrect bag number: not number\n");
                return 1;
            }

            int bag_num = *c - '0';
            if (bags[bag_num].rm_so < 0) {
                fprintf(stderr, "Such bag number does not exist: %d\n", bag_num);
                return 2;
            }

            is_bag = 0;
        }
        c++;
    }

    if (is_bag) {
        fprintf(stderr, "Single \\ can't be in the end of substitution\n");
        return 3;
    }

    return 0;
}

void print_result(char *string, char *substitution, regmatch_t *bags) {
    char *c;
    int is_bag = 0;
    for (int i = 0; i < bags[0].rm_so; i++) {
        printf("%c", string[i]);
    }
    c = substitution;
    while(*c) {
        if (*c == '\\') {
            c++;
            if (!(*c == '\\')) {
                is_bag = 1;
            }
        }
        if (is_bag) {
            int bag_num = *c - '0';
            int s = (int) bags[bag_num].rm_so;
            int e = (int) bags[bag_num].rm_eo;
            for (int i = s; i < e; i++) {
                printf("%c", string[i]);
            }
            is_bag = 0;
        } else {
            printf("%c", *c);
        }
        c++;
    }

    printf("%s\n", string + bags[0].rm_eo);
}


int main(int argc, char *argv[]) {
    char *buf;
    size_t len = 0;
    int chars;
    regex_t preg;
    regmatch_t bags[MAXGR];

    if (argc != 4) {
        fprintf(stderr, "Incorrect number of parameters: %d, must be 3\n", atoi(argv[0]), argc);
        return 1;
    }
    char *regexp = argv[1];
    char *substitution = argv[2];
    char *string = argv[3];

    int res = regcomp(&preg, regexp, REG_EXTENDED);
    if (res != 0) {
        process_error(res, &preg);
        regfree(&preg);
        return 2;
    }

    res = regexec(&preg, string, MAXGR, bags, 0);

    if (res == 0) {
        regfree(&preg);
        if (check_substitution(substitution, bags) == 0) {
            print_result(string, substitution, bags);
            return 0;
        } else {
            return 3;
        }
    } else if (res == REG_NOMATCH) {
        printf("%s\n", string);
        regfree(&preg);
        return 0;
    } else {
        process_error(res, &preg);
        regfree(&preg);
        return 4;
    }

    return 0;
}
