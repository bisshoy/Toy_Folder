#include <stdio.h> 

int main() {
    int count1;
    int count2; 
    char operator; 

    printf("Please enter an operator [+ OR - OR * OR /]: ");
    scanf("%c", &operator);

    printf("Please enter two numbers: "); 
    scanf("%d%d", &count1, &count2);
    
    switch (operator) {
        case ('+'): 
            printf("%d + %d = %d\n", count1, count2, (count1 + count2));
            printf("Thank you for using Calcutron 1.0!\n");
            break;
        case ('-'): 
            printf("%d - %d = %d\n", count1, count2, (count1 - count2));
            printf("Thank you for using Calcutron 1.0!\n");
            break;
        case ('*'): 
            printf("%d * %d = %d\n", count1, count2, (count1 * count2));
            printf("Thank you for using Calcutron 1.0!\n");
            break; 
        case ('/'): 
            printf("%d / %d = %d\n", count1, count2, (count1 / count2));
            printf("Thank you for using Calcutron 1.0!\n");
            break; 
        default: 
            printf("Not a valid operator. Please try again!\n");
            break;

    }

    return 0;

} 
