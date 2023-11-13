#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include "config.h"

#define _(STRING) gettext(STRING)

int main(int argc, char *argv[]) {
    int low = 1;
    int high = 100;
    int userNumber;
    int guess;
    int attempts = 0;

	setlocale (LC_ALL, "");
	bindtextdomain (guess, LOCALE_PATH);
	textdomain (guess);

    while (low != high) {
        guess = (low + high) / 2; 
        attempts++;

        printf(_("Is it greater than %d? Enter yes or no\n"), guess);
        char feedback[3]; // Buffer for "Yes" or "No"
        int res = scanf("%s", feedback);

        if (strcmp(feedback, _("yes")) == 0) {
            low = guess + 1;
        } else if (strcmp(feedback, _("no")) == 0) {
            high = guess;
        } else {
            printf(_("Incorrect answer\n"));
        }
    }

    printf(_("Your number is: %d\n"), low);

    return 0;
}