#include <iostream> 
#include <cstring>

using namespace std;

// Returns -1 if substring not in string 
// Returns index (from 0) if substring is 
// found (at first occurrence) 
int stirstir(char* str1, char* str2) 
{
    int length = strlen(str2) - 1;
    int index = 0;

    if (*str1 == '\0') {
        cout << "ERROR: Empty parent string. Exited with code 1." << endl;
        exit(1);
    }

    if(*str2 == '\0') {
        cout << "ERROR: Empty substring. Exited with code 1." << endl;
        exit(1);
    }

    // If str1 isn't NULL 
    while (*str1) {

        // Check if first chars are now equal 
        if (*str1 == *str2) { 

            // If they are, begin the counting process
            int count = 0; 

            for (int i = 0; i < strlen(str2); i++) {
                if (*(str1 + i) == *(str2 + i)) {
                    count++;
                } else {
                    // Ensure it returns -1 if not all  
                    // are the same 
                    count--;
                }
            }

            if (count == strlen(str2)) {
                return index; 
            } 

        }

        // If they're not, move str1 pointer right one and 
        // increase index for final value 
        str1++;
        index++;

    }

    return -1;

}

int main()
{
    char str1[50] = "Bisshoy";
    char str2[10] = "ho";

    cout << stirstir(str1, str2) << endl;

    return 0;

}

