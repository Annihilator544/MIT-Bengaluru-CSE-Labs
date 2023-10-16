#include <stdio.h>
#include <stdbool.h>
#include <string.h>

// Global variables
char input[100];
int position = 0;

// Function to check if a character is a terminal symbol
bool isTerminal(char c) {
    return (c == 'a' || c == 'b' || c == 'c' || c == 'd' || c == '(' || c == ')');
}

// Function to parse the 'S' non-terminal
bool parseS();

// Function to parse the 'U' non-terminal
bool parseU();

// Function to parse the 'V' non-terminal
bool parseV();

// Function to parse the 'W' non-terminal
bool parseW();

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

// Recursive descent parser for 'U'
bool parseU() {
    if (input[position] == '(') {
        consume('(');
        if (parseS()) {
            consume(')');
            return true;
        }
    } else if (input[position] == 'a') {
        consume('a');
        if (parseS()) {
            if(input[position] == 'b'){
                consume('b');
                return true;
            }
        }
    } else if (input[position] == 'd') {
        consume('d');
        return true;
    }
    return false;
}

// Recursive descent parser for 'V'
bool parseV() {
    if (input[position] == 'a') {
        consume('a');
        return parseV();
    }
    return true;  // epsilon production
}

// Recursive descent parser for 'W'
bool parseW() {
    if (input[position] == 'c') {
        consume('c');
        return parseW();
    }
    return true;  // epsilon production
}

// Recursive descent parser for 'S'
bool parseS() {
    return parseU() && parseV() && parseW();
}

int main() {
    printf("Enter a string: ");
    scanf("%s", input);

    if (parseS() && input[position] == '\n') {
        printf("Parsing successful!\n");
    } else {
        printf("Parsing failed!\n");
    }

    return 0;
}
