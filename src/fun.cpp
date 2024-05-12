// Copyright 2022 UNN-IASR
#include <iostream>
#include <cctype>
#include <cmath>

unsigned int faStr1(const char* str) {
    unsigned int wordsCount = 0;  
    bool inWord = false;  
    bool lastDigit = false;
    while (*str) {
        if (std::isalpha(*str) || std::isdigit(*str)) {
            if (!inWord) {
                inWord = true;
                while (std::isalpha(*str) || std::isdigit(*str)) {
                    if (std::isdigit(*str)) {
                        std::cout << "Digit: " << *str << std::endl;
                        inWord = false;
                        ++str;
                    }
                    ++str;
                }
                if (inWord) ++wordsCount;
            }
        }
        else {
            inWord = false;
            ++str;
        }
    }
    return wordsCount;
}

unsigned int faStr2(const char* str) {
    unsigned int wordsCount = 0;  
    bool validity = true; 
    int startIndex;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            if (startIndex != -1) {
                if (!('a' <= str[i] && str[i] <= 'z')) {
                    validity = false;
                }
            }
            else {
                if (!('A' <= str[i] && str[i] <= 'Z')) {
                    validity = false;
                }
                startIndex = i;
            }
        }
        else {
            if (validity && startIndex != -1) {
                wordsCount++;
            }
            startIndex = -1;
            validity = true;
        }
    }
    
    if (validity && startIndex != -1) {
        wordsCount++;
    }
    return wordsCount;
}

unsigned int faStr3(const char* str) {
    unsigned int totalLength = 0; 
    unsigned int wordCount = 0; 

    while (*str) {
        if (isalpha(*str)) {
            unsigned int length = 0;
            while (isalpha(*str)) {
                length++;
                str++;
            }
            totalLength += length;
            wordCount++;
        }
        else {
            str++;
        }
    }

    return totalLength / wordCount;
}
