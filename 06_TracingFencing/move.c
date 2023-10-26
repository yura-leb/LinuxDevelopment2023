#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf("Incorrect number of parameters: must be %d\n", argc);
        return 1;
    }

    FILE *input_file, *output_file;
    char character;

    input_file = fopen(argv[1], "r");
    if (input_file == NULL) {
        printf("Error opening the input file.\n");
        return 2;
    }

    output_file = fopen(argv[2], "w");
    if (output_file == NULL) {
        printf("Error opening the output file.\n");
        fclose(input_file);
        return 3;
    }

    while ((character = fgetc(input_file)) != EOF) {
        fputc(character, output_file);
    }

    fclose(input_file);
    fclose(output_file);

    if (remove(argv[1]) != 0) {
        printf("Error deleting the input file.\n");
        return 4;
    }

    return 0;
}