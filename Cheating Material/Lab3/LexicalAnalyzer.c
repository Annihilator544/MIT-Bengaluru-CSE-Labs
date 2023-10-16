#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

bool isKeyword(char *token) {
    char *keywords[] = {"if", "else", "while", "for", "int", "float", "return"};
    int numKeywords = sizeof(keywords) / sizeof(keywords[0]);

    for (int i = 0; i < numKeywords; i++) {
        if (strcmp(token, keywords[i]) == 0) {
            return true;
        }
    }

    return false;
}

bool isIdentifier(char *token) {
    if (!isalpha(token[0]) && token[0] != '_') {
        return false;
    }

    for (int i = 1; i < strlen(token); i++) {
        if (!isalnum(token[i]) && token[i] != '_') {
            return false;
        }
    }

    return true;
}

bool isNumericalConstant(char *token) {
    for (int i = 0; i < strlen(token); i++) {
        if (!isdigit(token[i]) && token[i] != '.') {
            return false;
        }
    }

    return true;
}

bool isStringLiteral(char *token) {
    if (token[0] == '"' && token[strlen(token) - 1] == '"') {
        return true;
    }

    return false;
}

bool isLogicalOperator(char *token) {
    char *logicalOperators[] = {"&&", "||", "!"};
    int numOperators = sizeof(logicalOperators) / sizeof(logicalOperators[0]);

    for (int i = 0; i < numOperators; i++) {
        if (strcmp(token, logicalOperators[i]) == 0) {
            return true;
        }
    }

    return false;
}

bool isArithmeticOperator(char *token) {
    char *arithmeticOperators[] = {"+", "-", "*", "/", "%"};
    int numOperators = sizeof(arithmeticOperators) / sizeof(arithmeticOperators[0]);

    for (int i = 0; i < numOperators; i++) {
        if (strcmp(token, arithmeticOperators[i]) == 0) {
            return true;
        }
    }

    return false;
}

bool isRelationalOperator(char *token) {
    char *relationalOperators[] = {"==", "!=", "<", ">", "<=", ">="};
    int numOperators = sizeof(relationalOperators) / sizeof(relationalOperators[0]);

    for (int i = 0; i < numOperators; i++) {
        if (strcmp(token, relationalOperators[i]) == 0) {
            return true;
        }
    }

    return false;
}


bool isOperator(char *token) {
    char *operators[] = {"+", "-", "*", "/", "=", "<", ">", "==", "<=", ">=", "&&", "||", "!"};
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    for (int i = 0; i < numOperators; i++) {
        if (strcmp(token, operators[i]) == 0) {
            return true;
        }
    }

    return false;
}

bool isSpecialSymbol(char symbol) {
    char specialSymbols[] = {';', '(', ')', '{', '}', '[', ']'};

    for (int i = 0; i < sizeof(specialSymbols); i++) {
        if (symbol == specialSymbols[i]) {
            return true;
        }
    }

    return false;
}

void main() {
    char input[] = "if ( x > 0 ) { return x + 5 ; }";
    char *token = strtok(input, " ");

    while (token != NULL) {
        if (isKeyword(token)) {
            printf("Keyword: %s\n", token);
        } else if (isIdentifier(token)) {
            printf("Identifier: %s\n", token);
        } else if (isNumericalConstant(token)) {
            printf("Numerical Constant: %s\n", token);
        } else if (isStringLiteral(token)) {
            printf("String Literal: %s\n", token);
        } else if (isArithmeticOperator(token)) {
            printf("Arithmetic Operator: %s\n", token);
        } else if (isLogicalOperator(token)) {
            printf("Logical Operator: %s\n", token);
        } else if (isRelationalOperator(token)) {
            printf("Relational Operator: %s\n", token);
        } else if (isSpecialSymbol(token[0])) {
            printf("Special Symbol: %s\n", token);
        }

        token = strtok(NULL, " ");
    }

}
