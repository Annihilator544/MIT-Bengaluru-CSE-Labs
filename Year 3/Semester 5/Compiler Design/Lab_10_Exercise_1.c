// A C program to implement the intermediate code for the given postfix expression
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// A structure to represent a stack node
struct StackNode {
    char data; // The data stored in the node
    struct StackNode* next; // The pointer to the next node
};

// A function to create a new stack node
struct StackNode* newNode(char data) {
    struct StackNode* node = (struct StackNode*)malloc(sizeof(struct StackNode)); // Allocate memory for the node
    node->data = data; // Assign the data to the node
    node->next = NULL; // Set the next pointer to NULL
    return node; // Return the node
}

// A function to check if the stack is empty
int isEmpty(struct StackNode* root) {
    return root == NULL; // Return true if the root is NULL, false otherwise
}

// A function to push an element to the stack
void push(struct StackNode** root, char data) {
    struct StackNode* node = newNode(data); // Create a new node with the data
    node->next = *root; // Set the next pointer of the node to the current root
    *root = node; // Set the root to the node
    //printf("Pushed %c to stack\n", data); // Print a message
}

// A function to pop an element from the stack
char pop(struct StackNode** root) {
    if (isEmpty(*root)) // Check if the stack is empty
        return '\0'; // Return a null character
    struct StackNode* temp = *root; // Store the current root in a temporary variable
    *root = (*root)->next; // Set the root to the next node
    char popped = temp->data; // Store the data of the popped node
    free(temp); // Free the memory of the popped node
    //printf("Popped %c from stack\n", popped); // Print a message
    return popped; // Return the popped data
}

// A function to peek the top element of the stack
char peek(struct StackNode* root) {
    if (isEmpty(root)) // Check if the stack is empty
        return '\0'; // Return a null character
    return root->data; // Return the data of the top node
}

// A function to check if a character is an operand
int isOperand(char c) {
    return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'); // Return true if the character is a letter, false otherwise
}

// A function to generate the intermediate code for the given postfix expression
void generateCode(char* postfix) {
    struct StackNode* stack = NULL; // Create an empty stack
    int label = 1; // Initialize a label counter
    for (int i = 0; i < strlen(postfix); i++) { // Loop through the postfix expression
        char c = postfix[i]; // Get the current character
        if (isOperand(c)) { // If the character is an operand
            push(&stack, c); // Push it to the stack
        }
        else { // If the character is an operator
            char op1 = pop(&stack); // Pop the first operand from the stack
            char op2 = pop(&stack); // Pop the second operand from the stack
            char temp = 't'; // Create a temporary variable
            printf("%c = %c %c %c\n", temp, op2, c, op1); // Print the intermediate code for the operation
            push(&stack, temp); // Push the temporary variable to the stack
            if (i < strlen(postfix) - 1) { // If the expression is not over
                printf("IF %c GOTO L%d\n", temp, label); // Print the intermediate code for the conditional jump
                printf("GOTO L%d\n", label + 1); // Print the intermediate code for the unconditional jump
                printf("L%d: ", label); // Print the label
                label += 2; // Increment the label counter by 2
            }
        }
    }
    printf("L%d: \n", label); // Print the final label
}

// A function to test the program
int main() {
    char postfix[] = "ab+c*de-fg-h+/*"; // A sample postfix expression
    printf("The postfix expression is: %s\n", postfix); // Print the postfix expression
    printf("The intermediate code is:\n"); // Print a message
    generateCode(postfix); // Generate the intermediate code for the postfix expression
    return 0; // Return 0 to indicate successful execution
}
