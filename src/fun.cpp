// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cstring>
#include <cctype>
#include <cmath>

bool containsDigits(const char* word) {
    for (int i = 0; i < strlen(word); i++) {
        if (isdigit(word[i])) {
            return true;
        }
    }
    return false;
}

bool isValidWord(const char* word) {
    if (strlen(word) == 0) {
        return false;
    }

    for (int i = 0; i < strlen(word); i++) {
        if (!isalpha(word[i])) {
            return false;
        }
    }
    return true;
}


unsigned int faStr1(const char *str) {
    unsigned int count = 0;

    const char* delim = " ";
    char* token = strtok(const_cast<char*>(str), delim);

    while (token != NULL) {
        if (!containsDigits(token) && isValidWord(token)) {
            count++;
        }
        token = strtok(NULL, delim);
    }

    return count;
}

unsigned int faStr2(const char *str) {
    unsigned int count = 0;

    const char* delim = " ";
    char* token = strtok(const_cast<char*>(str), delim);

    while (token != NULL) {
        if (isupper(token[0])) {
            bool isValid = true;
            for (int i = 1; i < strlen(token); i++) {
                if (!islower(token[i])) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                count++;
            }
        }
        token = strtok(NULL, delim);
    }

    return count;
}

unsigned int faStr3(const char *str) {
    int wordCount = 0;
    int charCount = 0;

    const char* delim = " ";
    char* token = strtok(const_cast<char*>(str), delim);

    while (token != NULL) {
        if (strlen(token) > 0) {
            wordCount++;
            charCount += strlen(token);
        }
        token = strtok(NULL, delim);
    }

    if (wordCount == 0) {
        return 0;
    }
    else {
        return round((double)charCount / wordCount);
    }
}
