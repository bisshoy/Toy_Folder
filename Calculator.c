#include <stdio.h>

int main() {
    char op;
    double first, second;

    //CHOOSE OPERANDS
    printf("Enter your equation: ");
    scanf("%lf %c %lf", &first, &op, &second);

    //SWITCH BRANCH FOR OPERATION
    switch (op) {
        case '+': 
            printf("%.2lf + %.2lf = %.2lf\n", first, second, first + second);
            break;
        case '-': 
            printf("%.2lf - %.2lf = %.2lf\n", first, second, first - second);
            break;
        case '*': 
            printf("%.2lf * %.2lf = %.2lf\n", first, second, first * second);
            break;
        case '/': 
            printf("%.2lf / %.2lf = %.2lf\n", first, second, first / second);
            break; 
        //IN CASE OF INVALID OPERATOR
        default: 
            printf("Error! operator is invalid!\n");
    }

    return 0;
    
} 

