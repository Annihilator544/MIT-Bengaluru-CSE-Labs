#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Global variables
char input[100];
int position = 0;

// Function to check if a character is a terminal symbol
bool isTerminal(char c) {
    return (c == 'a' || c == '>' || c == '(' || c == ')');
}

// Function to check if a character is a non-terminal symbol
bool isNonTerminal(char c) {
    return (c == 'S' || c == 'T');
}

// Function to parse the 'S' non-terminal
bool parseS();

// Function to parse the 'T' non-terminal
bool parseT();

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

// Recursive descent parser for 'T'
bool parseT() {
    if (input[position] == '(') {
        consume('(');
        if (parseT()) {
            consume(',');
            if (parseS()) {
                consume(')');
                return true;
            }
        }
    } else if (input[position] == 'a') {
        consume('a');
        return true;
    }
    return false;
}

// Recursive descent parser for 'S'
bool parseS() {
    if (input[position] == 'a') {
        return parseT();
    } else if (input[position] == '>') {
        consume('>');
        return true;
    } else if (input[position] == '(') {
        consume('(');
        if (parseT()) {
            consume(')');
            return true;
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
