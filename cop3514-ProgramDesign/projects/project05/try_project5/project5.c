#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_STRING_LEN 50

size_t my_strlen(const char* s) {
    if (s == NULL) return 0;
    const char* start = s;
    while (*s != '\0') {
        if (s - start > MAX_STRING_LEN){
            printf("Unable to find end of string or string too long\n");
            exit(EXIT_FAILURE);
        }
        s++;
    }
    return (s - start);
}

void my_strcpy(char* destination, char* source) {
    if (destination == NULL || source == NULL) return;
    char* start = source;
    while (*source != '\0') {
        if (source - start > MAX_STRING_LEN){
            printf("Unable to find end of string or string too long\n");
            exit(EXIT_FAILURE);
        }
        *destination = *source;
        destination++;
        source++;
    }
    *destination = '\0';
}

bool starts_with_word(char* sentence, char* word) {
    if (sentence == NULL || word == NULL) return false;
    if (my_strlen(sentence) < my_strlen(word)) return false;
    while (*word != '\0') {
        if (*sentence != *word) return false;
        sentence++;
        word++;
    }
    return true;
}

bool overwrite_with_word(char* start, char* replacement) {
    if (start == NULL || replacement == NULL) return false;
    if (my_strlen(start) < my_strlen(replacement)) return false;
    while (*replacement != '\0'){
        *start = *replacement;
        start++;
        replacement++;
    }
    return true;
}

void overwrite_all_words(char* sentence, char* word, char* replacement) {
    if (sentence == NULL || word == NULL || replacement == NULL) return;
    if (my_strlen(word) != my_strlen(replacement)) return;
    if (my_strlen(word) > my_strlen(sentence)) return;
    while (*sentence != '\0') {
        if (starts_with_word(sentence, word)){
            overwrite_with_word(sentence, replacement);
            sentence += (my_strlen(replacement));
        } else {
            sentence++;
        }
    }
}

void remove_end_newline(char* s) {
    char* p = s;
    while (*p != '\0') {
        if (*p == '\n') {
            *p = '\0';
            break;
        }
        p++;
    }
}

int main(int argc, char** argv) {
    char sentence[MAX_STRING_LEN * 2 + 1];
    char word[MAX_STRING_LEN + 1];
    char replacement[MAX_STRING_LEN + 1];

    size_t len_sentence = my_strlen(argv[1]);
    size_t len_word = my_strlen(argv[2]);
    size_t len_replacement = my_strlen(argv[3]);

    if (len_sentence == 0 || len_word == 0 || len_replacement == 0){
        printf("Unable to process your input\n");
        exit(EXIT_FAILURE);
    }
    if (len_word != len_replacement){
        printf("Unable to process your input\n");
        exit(EXIT_FAILURE);
    }
    if (len_sentence < len_word){
        printf("Unable to process your input\n");
        exit(EXIT_FAILURE);
    }

    my_strcpy(sentence, argv[1]);
    my_strcpy(word, argv[2]);
    my_strcpy(replacement, argv[3]);
    
    overwrite_all_words(sentence, word, replacement);

    printf("%s\n", sentence);

    return EXIT_SUCCESS;
}