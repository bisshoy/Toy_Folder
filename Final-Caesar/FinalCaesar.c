// completed on October 22, 2021
// Bisshoy Anwar 

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <ctype.h> 

// Prototype 
char CaesarCypher(char original[], int shift);

// Driver Function 
int main() {
    char sentenceSize;      // Size of message 
    int length;             // Determines memory allocated  
    int shift;              // Shift value 
    char answer[10];        // Cypher or Decypher? 
    
    // s (100 bytes), m (1000 bytes), or l (10000 bytes)
    printf("How long of a sentence? [s/m/l]: ");
    scanf("%c", &sentenceSize);
    getchar();

    // Modifies allocated memory based on sentence length
    switch (sentenceSize) {
        case ('s'): 
            length = 100;
            break;
        case ('m'):
            length = 1000;
            break;
        case ('l'):
            length = 10000;
            break;
        default: 
            printf("ERROR: Size input not recognized.\n");
            break;
    }

    // Allocates memory for original sentence 
    // sizeof(char) is 1; this is just for style 
    char *original = (char*) malloc(length * sizeof(char)); 

    // In case of faulty memory allocation 
    if (original == NULL) {
        printf("ERROR: Memory not allocated.\n"); 
        exit(0);
    }

    // Cypher or Decypher Decision 
    printf("Do you want to cypher or decypher? [cypher/decypher]: ");
    fgets(answer, sizeof(answer), stdin);
    answer[strcspn(answer, "\n")] = 0;

    // For cyphering 
    if (strcmp(answer, "cypher") == 0) {
        // Input original string 
        printf("Enter your original string here: "); 
        fgets(original, length * sizeof(original), stdin);
        original[strcspn(original, "\n")] = 0;
        
        // Decide the key shift number 
        printf("Enter the shift value here: ");
        scanf("%d", &shift); 

        // Print translated text 
        printf("\nYour cyphered text is:\n");
        printf("%c\n", CaesarCypher(original, shift));
    }

    // For decyphering 
    else if (strcmp(answer, "decypher") == 0) {
        
        // Input cyphered string 
        printf("Enter your cyphered string here: "); 
        fgets(original, length * sizeof(original), stdin);
        original[strcspn(original, "\n")] = 0;
        
        // Decide the key shift number 
        printf("Enter the original shift value here: ");
        scanf("%d", &shift); 

        // Decode shift value 
        int decodeShift = 26 - (shift % 26); 

        // Print translated text 
        printf("\nYour cyphered text is:\n");
        printf("%c\n", CaesarCypher(original, decodeShift));
    }

    // In case of invalid decision 
    else {
        printf("ERROR: decision not recognized.\n");
    }

    // Free memory 
    free(original);
    return 0;
}


// Caesar Cypher Function 
char CaesarCypher(char original[], int shift) {
    // Iterate through all elements of original[] 
    for (int i = 0; i < strlen(original); i++) {
        // For lowercase letters 
        if (islower(original[i])) {
            // Leave non-letters alone! 
            if (original[i] >= 32 && original[i] <= 64 || original[i] >= 91 && original[i] <= 96 || original[i] >= 123 && original[i] <= 126) {
                original[i] = original[i];
            }

            else {
                original[i] = (((int) original[i] - 97 + shift) % 26) + 97;
            } 
        }

        // For uppercase letters 
        else {
            // Leave non-letters alone! 
            if (original[i] >= 32 && original[i] <= 64 || original[i] >= 91 && original[i] <= 96 || original[i] >= 123 && original[i] <= 126) {
                original[i] = original[i];
            }

            // Replace each character with the shifted character
            else {
                original[i] = (((int) original[i] - 65 + shift) % 26) + 65;
            } 
        }

        printf("%c", original[i]); 

    }
}
