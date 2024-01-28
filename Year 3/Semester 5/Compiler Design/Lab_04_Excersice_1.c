#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a structure for symbol table entries
struct SymbolEntry {
    char name[50]; // Identifier name
    // Add other attributes as needed (e.g., type, scope, value)
    struct SymbolEntry* next; // Pointer to the next entry
};

// Initialize the symbol table
struct SymbolEntry* symbolTable = NULL;

// Function to insert an identifier into the symbol table
void insertSymbol(const char* identifier) {
    struct SymbolEntry* newEntry = (struct SymbolEntry*)malloc(sizeof(struct SymbolEntry));
    strcpy(newEntry->name, identifier);
    newEntry->next = symbolTable;
    symbolTable = newEntry;
}

// Function to search for an identifier in the symbol table
int searchSymbol(const char* identifier) {
    struct SymbolEntry* current = symbolTable;
    while (current != NULL) {
        if (strcmp(current->name, identifier) == 0) {
            return 1; // Found
        }
        current = current->next;
    }
    return 0; // Not found
}

int main() {
    // Example usage:
    insertSymbol("x");
    insertSymbol("y");
    insertSymbol("z");

    // Search for an identifier
    const char* searchIdentifier = "y";
    if (searchSymbol(searchIdentifier)) {
        printf("%s found in the symbol table.\n", searchIdentifier);
    } else {
        printf("%s not found in the symbol table.\n", searchIdentifier);
    }

    // Print the entire symbol table (for demonstration purposes)
    struct SymbolEntry* current = symbolTable;
    printf("Symbol Table:\n");
    while (current != NULL) {
        printf("%s\n", current->name);
        current = current->next;
    }

    // Clean up: Free memory (not necessary in this simple example)
    while (symbolTable != NULL) {
        struct SymbolEntry* temp = symbolTable;
        symbolTable = symbolTable->next;
        free(temp);
    }

    return 0;
}
