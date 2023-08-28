#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Look Dad, my first PROTOTYPE!
char CaesarCipher(char original[], int shift);

int main() {
    char original[100];
    int shift;

    // Input string
    printf("Enter your original string here: ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = 0;

    // Decide the key shift number
    printf("Enter the shift value here: ");
    scanf("%d", &shift);
    getchar();

    // Print translated text:
    printf("\nYour cyphered text is:\n");
    printf("%c", CaesarCipher(original, shift));
    printf("\n");

    printf("\nPress ENTER to exit ");
    getchar();

    return 0;
}

// Caesar Cipher Function
char CaesarCipher(char original[], int shift) {
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

// Note to self: decodeShift = 26 - (shift % 26)
