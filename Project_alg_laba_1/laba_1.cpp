// Заменить все пробелы в строке на символ подчеркивания
// («_»), если строка содержит хотя бы одну цифру. 
//  Иначе — заменить их на «-».
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdio>
#include <cstring>

void mainFunk(char str[]) {
    bool hasDigit = false;
    int length = std::strlen(str);

    for (int i = 0; i < length; ++i) {
        if (isdigit(str[i])) {
            hasDigit = true;
            break;
        }
    }

    char replacement = hasDigit ? '_' : '-';

    for (int i = 0; i < length; ++i) {
        if (str[i] == ' ') {
            str[i] = replacement;
        }
    }
    str[length] = '\0';
}

int funk1() {
    const int maxLength = 100;
    char inputString[maxLength];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxLength);

    int length = 0;
    while (inputString[length] != '\0') {
        ++length;
    }

    mainFunk(inputString);

    std::cout << "Processed string: " << inputString << std::endl;

    return 0;
}

int funk2() {
    const int maxLength = 100;
    char inputString[maxLength];

    std::cout << "Enter a string: ";
    std::cin.getline(inputString, maxLength);

    int length = 0;
    while (inputString[length] != '\0') {
        ++length;
    }

    mainFunk(inputString);

    std::cout << "Processed string: " << inputString << std::endl;

    return 0;
}

int funk3() {
    const char* inputFileName = "input.txt";
    const char* outputFileName = "output.txt";
    const int maxLength = 100;
    char inputString[maxLength];



    FILE* inputFile = fopen(inputFileName, "r");
    if (inputFile == nullptr) {
        std::cerr << "Error opening input file" << std::endl;
        return 1;
    }

    if (fgets(inputString, maxLength, inputFile) == nullptr) {
        std::cerr << "Error reading from input file" << std::endl;
        fclose(inputFile);
        return 1;
    }
    fclose(inputFile);


    char* newlinePos = strchr(inputString, '\n');
    if (newlinePos != nullptr) {
        *newlinePos = '\0';
    }


    mainFunk(inputString);


    FILE* outputFile = fopen(outputFileName, "w");
    if (outputFile == nullptr) {
        std::cerr << "Error opening output file" << std::endl;
        return 1;
    }

    if (fputs(inputString, outputFile) == EOF) {
        std::cerr << "Error writing to output file" << std::endl;
        fclose(outputFile);
        return 1;
    }
    fclose(outputFile);

    std::cout << "Processed string written to " << outputFileName << std::endl;

    return 0;
}


void main() {
    funk3();
}