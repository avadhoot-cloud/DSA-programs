#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100

// Stack to handle operands
double operandStack[MAX_STACK_SIZE];
int top = -1;

// Push 
void pushOperand(double value) {
    if (top < MAX_STACK_SIZE - 1) {
        operandStack[++top] = value;
    } else {
        printf("Stack overflow\n");
        exit(1);
    }
}

// Pop
double popOperand() {
    if (top >= 0) {
        return operandStack[top--];
    } else {
        printf("Stack underflow\n");
        exit(1);
    }
}
double performOperation(char operator, double operand1, double operand2) {
    switch (operator) {
        case '+':
            return operand1 + operand2;
        case '-':
            return operand1 - operand2;
        case '*':
            return operand1 * operand2;
        case '/':
            if (operand2 != 0) {
                return operand1 / operand2;
            } else {
                printf("Division by zero\n");
                exit(1);
            }
        default:
            printf("Invalid operator\n");
            exit(1);
    }
}

// Check if a character is an operator
int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

// Evaluate the postfix expression
double evaluatePostfixExpression(const char *postfixExpression) {
    int length = strlen(postfixExpression);
    for (int i = 0; i < length; i++) {
        if (isdigit(postfixExpression[i])) {
            double operand = 0;
            while (isdigit(postfixExpression[i])) {
                operand = operand * 10 + (postfixExpression[i] - '0');
                i++;
            }
            pushOperand(operand);
            i--;
        } else if (isOperator(postfixExpression[i])) {
            double operand2 = popOperand();
            double operand1 = popOperand();
            double result = performOperation(postfixExpression[i], operand1, operand2);
            pushOperand(result);
        }
    }
    return popOperand();
}

int main() {
    char infixExpression[100];
    printf("Enter an infix expression: ");
    scanf("%s", infixExpression);

    // Convert infix expression to postfix expression
    // (You can use the Shunting Yard algorithm for this)

    // Evaluate the postfix expression
    double result = evaluatePostfixExpression(postfixExpression);
    printf("Result: %.2f\n", result);

    return 0;
}
