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
    bool inWord = false;
    int i = 0;
    float count = 0, count_s = 0;
    float lenght = 0;
    while (str[i] != '\0') {
        if (str[i] != ' ' && inWord == false) {
            inWord = true;
            count++;
        } else if (str[i] == ' ' && inWord == true) { inWord = false; }
        if (str[i] != ' ') { count_s++; }
        i++;
    }
    lenght = round(count_s / count);
    return lenght;
}
