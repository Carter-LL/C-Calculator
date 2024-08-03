#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void main()
{
    printf("Welcome to C-Calculator. Please input number + operation + numer below  \n");
    printf("Example, 1 + 1: \n");

    char equation[200];
    scanf("%s", equation);

    printf("Got Input:|%s|\n", equation);

    char operation;
    const char* operators[] = {"+", "-", "*", "/"};

    // Calculate the number of elements in the array
    int numOperators = sizeof(operators) / sizeof(operators[0]);

    //Determine the operator
    for(int i = 0; i < numOperators; i++) 
    {
        if(strstr(equation, operators[i]) != 0x0)
        {
            operation = operators[i][0];
            printf("found %c\n", operation);
            break;
        } 
        else 
        {
            printf("not found %s \n", operators[i]);
        }
    }

    //Split the numbers
    char delimiter[2] = {operation, '\0'};
    char* split = strtok(equation, delimiter);

    int numbers[2];

    int index = 0;
    while (split != NULL) {
        numbers[index] = atoi(split);
        printf("Number = %d\n", numbers[index]);
        split = strtok(NULL, delimiter); // Continue tokenizing the rest of the string
        index++;
    }

    //Do math
    int output;
    switch(operation)
    {
        case '+':
            output = numbers[0] + numbers[1];
            printf("Your answer is: %d", output);
        break;

        case '-':
            output = numbers[0] - numbers[1];
            printf("Your answer is: %d", output);
        break;

        case '*':
            output = numbers[0] * numbers[1];
            printf("Your answer is: %d", output);
        break;

        case '/':
            output = numbers[0] / numbers[1];
            printf("Your answer is: %d", output);
        break;
    }
}