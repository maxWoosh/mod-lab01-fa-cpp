// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cstring>
#include <cctype>
#include <cmath>

unsigned int faStr1(const char* str) {
    unsigned int count = 0; // счетчик слов без цифр

    while (*str) {
        if (isalpha(*str)) {
            while (isalnum(*str)) {
                if (isdigit(*str)) {
                    break;
                }
                str++;
            }
            count++;
        } else {
            str++;
        }
    }

    return count;
}

unsigned int faStr2(const char* str) {
    unsigned int count = 0; // счетчик слов, удовлетворяющих условиям

    while (*str) {
        if (isupper(*str)) {
            while (isalpha(*str)) {
                if (islower(*str)) {
                    str++;
                } else {
                    break;
                }
            }
            count++;
        } else {
            str++;
        }
    }

    return count;
}

unsigned int faStr3(const char* str) {
    unsigned int totalLength = 0; // общая длина слов
    unsigned int wordCount = 0; // счетчик слов

    while (*str) {
        if (isalpha(*str)) {
            unsigned int length = 0;
            while (isalpha(*str)) {
                length++;
                str++;
            }
            totalLength += length;
            wordCount++;
        } else {
            str++;
        }
    }

    return totalLength / wordCount;
}
