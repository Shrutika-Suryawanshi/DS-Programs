#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Push operation */
void push(int value)
{
    if (top == MAX - 1)
    {
        printf("Stack Overflow\n");
    }
    else
    {
        top++;
        stack[top] = value;
    }
}

/* Pop operation */
int pop()
{
    int value;

    if (top == -1)
    {
        printf("Stack Underflow\n");
        return -1;
    }

    value = stack[top];
    top--;

    return value;
}

/* Postfix Evaluation */
int evaluatePostfix(char expression[])
{
    int i;
    int operand1, operand2, result;

    for (i = 0; expression[i] != '\0'; i++)
    {
        /* If character is a digit */
        if (isdigit(expression[i]))
        {
            push(expression[i] - '0');
        }

        /* If character is an operator */
        else
        {
            operand2 = pop();
            operand1 = pop();

            switch (expression[i])
            {
                case '+':
                    result = operand1 + operand2;
                    break;

                case '-':
                    result = operand1 - operand2;
                    break;

                case '*':
                    result = operand1 * operand2;
                    break;

                case '/':
                    result = operand1 / operand2;
                    break;

                case '%':
                    result = operand1 % operand2;
                    break;

                default:
                    printf("Invalid operator\n");
                    return -1;
            }

            push(result);
        }
    }

    return pop();
}

/* Main Function */
int main()
{
    char expression[MAX];
    int result;

    printf("Enter postfix expression: ");
    scanf("%s", expression);

    result = evaluatePostfix(expression);

    printf("Result = %d\n", result);

    return 0;
}