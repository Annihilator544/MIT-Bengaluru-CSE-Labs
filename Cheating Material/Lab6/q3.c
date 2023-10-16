#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Global variables
char input[100];
int position = 0;

// Function to check if a character is a terminal symbol
bool isTerminal(char c) {
    return (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == 'e');
}

// Function to parse the 'S' non-terminal
bool parseS();

// Function to parse the 'A' non-terminal
bool parseA();

// Function to parse the 'B' non-terminal
bool parseB();

// Function to handle errors
void error() {
    printf("Error at position %d: Unexpected token '%c'\n", position, input[position]);
}

// Function to consume a character
void consume(char expected) {
    if (input[position] == expected) {
        position++;
    } else {
        error();
    }
}

// Recursive descent parser for 'A'
bool parseA() {
    if (input[position] == 'b') {
        consume('b');
        return true;
    } else if (input[position] == 'a') {
        consume('a');
        return parseB() && parseA();
    }
    return false;
}

// Recursive descent parser for 'B'
bool parseB() {
    if (input[position] == 'd') {
        consume('d');
        return true;
    }
    return false;
}

// Recursive descent parser for 'S'
bool parseS() {
    if (input[position] == 'a') {
        consume('a');
        if (parseA()) {
            consume('c');
            if (parseB()) {
                consume('e');
                return true;
            }
        }
    }
    return false;
}

int main() {
    printf("Enter a string: ");
    scanf("%s", input);

    if (parseS() && input[position] == '\0') {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed!\n");
    }

    return 0;
}
