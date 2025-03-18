#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX 100

typedef struct {
    char text[MAX];
    int top;
} DelimiterStack;

// Function to create and initialize the stack
DelimiterStack* createStack() {
    DelimiterStack* stack = (DelimiterStack*)malloc(sizeof(DelimiterStack));
    stack->top = -1;
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(DelimiterStack* stack) {
    return stack->top == -1;
}

// Function to push an item onto the stack
void push(DelimiterStack* stack, char item) {
    if (stack->top >= MAX - 1) {
        printf("Stack overflow\n");
        return;
    }
    stack->text[++stack->top] = item;
}

// Function to pop an item from the stack
char pop(DelimiterStack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return '\0'; // Return a null character if stack is empty
    }
    return stack->text[stack->top--];
}

// Function to check if a closing delimiter matches the top of the stack
bool checkMatch(DelimiterStack* stack, char closing) {
    if (isEmpty(stack)) {
        return false;
    }
    char opened = pop(stack);
    if ((opened == '{' && closing == '}') ||
        (opened == '(' && closing == ')') ||
        (opened == '[' && closing == ']')) {
        return true;
    }
    return false;
}

// Function to check if delimiters in the string are balanced
bool delimiterChecking(char str[]) {
    int n = strlen(str);
    DelimiterStack* stack = createStack();
	int i;
    for ( i = 0; i < n; i++) {
        char ch = str[i];
        if (ch == '{' || ch == '(' || ch == '[') {
            push(stack, ch);
        } else if (ch == '}' || ch == ')' || ch == ']') {
            if (!checkMatch(stack, ch)) {
                free(stack);
                return false;
            }
        }
    }
    
    bool balanced = isEmpty(stack);
    free(stack);
    return balanced;
}

int main() {
    char str[] = "({}[])";

    if (delimiterChecking(str)) {
        printf("Delimiters are balanced\n");
    } 
	else {
        printf("Delimiters are not balanced\n");
    }

    return 0;
}

