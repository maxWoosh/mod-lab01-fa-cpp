// Copyright 2022 UNN-IASR
#include "fun.h"
#include <cctype>
#include <cmath>

unsigned int faStr1(const char *str) {
    unsigned int count = 0;
    bool inWord = false;
    bool lastDigit = false;
    while (*str) {
        if (std::isalpha(*str) || std::isdigit(*str)) {
            if (!inWord) {
                inWord = true;
                while (std::isalpha(*str) || std::isdigit(*str)) {
                    if (std::isdigit(*str)) {
                        inWord = false;
                        ++str;
                    }
                    ++str;
                }
                if (inWord) ++count;
            }
        } else {
            inWord = false;
            ++str;
        }
    }
    return count;
}
unsigned int faStr2(const char* str) {
    unsigned int count = 0;
    bool validity = true;
    int startIndex = -1;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (startIndex != -1) {
                if (!('a' <= str[i] && str[i] <= 'z')) {
                    validity = false;
                }
            } else {
                if (!('A' <= str[i] && str[i] <= 'Z')) {
                    validity = false;
                }
                startIndex = i;
            }
        } else {
            if (validity && startIndex != -1) {
                count++;
            }
            startIndex = -1;
            validity = true;
        }
    }
    if (validity && startIndex != -1) {
        count++;
    }
    return count;
}
unsigned int faStr3(const char *str) {
    unsigned int wordCount = 0;
    unsigned int totalLength = 0;
    bool inWord = false;
    while (*str) {
        if (std::isalpha(*str)) {
            if (!inWord) {
                inWord = true;
                ++wordCount;
            }
            ++totalLength;
        } else {
            inWord = false;
        }
        ++str;
    }
    unsigned int averageLength = 0;
    if (wordCount != 0) {
        averageLength = totalLength / wordCount;
    }
    if (totalLength % wordCount * 2 >= wordCount) {
        averageLength += 1;
    }
    return averageLength;
}
