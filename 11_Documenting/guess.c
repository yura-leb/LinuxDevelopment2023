/** @file guess.c
 * Guesses a number from 1 to 100 using binary search, even with roman numbers.
*/
#include <stdio.h>
#include <stdlib.h>
#include <libgen.h>
#include <libintl.h>
#include <locale.h>
#include <string.h>
#include "config.h"

#define LOCALE_PATH "."
#define _(STRING) gettext(STRING)

static char *roman_numbers[101] = {
    "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X", 
    "XI", "XII", "XIII", "XIV", "XV", "XVI", "XVII", "XVIII", "XIX", "XX", 
    "XXI", "XXII", "XXIII", "XXIV", "XXV", "XXVI", "XXVII", "XXVIII", "XXIX", "XXX", 
    "XXXI", "XXXII", "XXXIII", "XXXIV", "XXXV", "XXXVI", "XXXVII", "XXXVIII", "XXXIX", "XL",
    "XLI", "XLII", "XLIII", "XLIV", "XLV", "XLVI", "XLVII", "XLVIII", "XLIX", "L", 
    "LI", "LII", "LIII", "LIV", "LV", "LVI", "LVII", "LVIII", "LIX", "LX", 
    "LXI", "LXII", "LXIII", "LXIV", "LXV", "LXVI", "LXVII", "LXVIII", "LXIX", "LXX", 
    "LXXI", "LXXII", "LXXIII", "LXXIV", "LXXV", "LXXVI", "LXXVII", "LXXVIII", "LXXIX", "LXXX", 
    "LXXXI", "LXXXII", "LXXXIII", "LXXXIV", "LXXXV", "LXXXVI", "LXXXVII", "LXXXVIII", "LXXXIX", "XC", 
    "XCI", "XCII", "XCIII", "XCIV", "XCV", "XCVI", "XCVII", "XCVIII", "XCIX", "C"
};

/** Converts int number to roman number
 *
 * @param number value for conversion
 */
char *int_to_roman(int number) {
    if (number >= 1 && number <= 100) {
        return roman_numbers[number];
    } else {
        return "Number out of range";
    }
}

/** Converts roman number to int number
 *
 * @param number value for conversion
 */
char *roman_to_int(char *number) {
    for (int i = 1; i <= 100; i++) {
        if (strcmp(roman_numbers[i], number) == 0)
            return roman_numbers[i];
    }
    return NULL;
}

int main(int argc, char *argv[]) {
    int low = 1;
    int high = 100;
    int guess = 0;
    int attempts = 0;

	setlocale (LC_ALL, "");
	bindtextdomain ("guess", LOCALE_PATH);
	textdomain ("guess");

    int is_roman = 0;
    
    if (argc == 2) {
        if (strcmp(argv[1], "--help") == 0) {
            printf(_("Guesses a number from 1 to 100 using binary search, even with roman numbers.\n"));
            printf(_("Usage: number [-r]\n"));
            printf(_("\t-r\tuse roman numbers\n"));
            return 0;
        }
        if (strcmp(argv[1], "-r") == 0)
            is_roman = 1;
    }


    while (low != high) {
        guess = (low + high) / 2; 
        attempts++;

        printf(_("Is it greater than %d? Enter yes or no\n"), guess);
        char feedback[4]; // Buffer for "Yes" or "No"
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