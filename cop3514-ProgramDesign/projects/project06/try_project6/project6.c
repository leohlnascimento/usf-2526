#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE_FILENAME 64
#define READ_CHUNK_SIZE 30

int is_positive_int(char *str);

int main(int argc, char *argv[]) {

    // Error 1
    if (argc != 3) {
        printf("Usage: ./a.out <input filename> <output file size>\n");
        exit(1);
    }

    // Error 2
    if (!is_positive_int(argv[2]) || atoi(argv[2]) <= 0) {
        printf("Error: 2nd argument must be a positive integer.\n");
        return 2;
    }

    char *input_filename = argv[1];
    int max_lines = atoi(argv[2]);

    FILE *fp_in = fopen(input_filename, "r");

    // Error 3
    if (fp_in == NULL) {
        printf("Error opening input file '%s'\n", input_filename);
        return 3;
    }

    char buffer[READ_CHUNK_SIZE];
    char output_filename[MAX_SIZE_FILENAME];

    FILE *fp_out = NULL;

    int file_index = 1;
    int line_count = 0;

    sprintf(output_filename, "%d.chunk.txt", file_index);
    fp_out = fopen(output_filename, "w");

    // Error 4

    if (fp_out == NULL) {
        printf("Error creating output file: %s\n", output_filename);
        fclose(fp_in);
        return 4;
    }

    while (fgets(buffer, READ_CHUNK_SIZE, fp_in) != NULL) {

        fputs(buffer, fp_out);

        // Only count line if newline found
        if (strchr(buffer, '\n') != NULL) {
            line_count++;
        }

        // If reached max lines → new file
        if (line_count == max_lines) {
            fclose(fp_out);

            file_index++;
            line_count = 0;

            sprintf(output_filename, "%d.chunk.txt", file_index);
            fp_out = fopen(output_filename, "w");

            if (fp_out == NULL) {
                printf("Error creating output file: %s\n", output_filename);
                fclose(fp_in);
                return 4;
            }
        }
    }

    // Close last file
    if (fp_out != NULL) {
        fclose(fp_out);
    }

    fclose(fp_in);
    return 0;
}

int is_positive_int(char *str) {
    if (*str == '\0') return 0;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] < '0' || str[i] > '9') return 0;
    }
    return 1;
}