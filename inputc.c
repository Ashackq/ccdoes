#include <stdio.h>

int main() {
    char input[100]; // Create a character array to store the input string

    printf("Enter a string: ");
    scanf("%s", input); // Read a string from the user and store it in 'input'

    printf("You entered: %s\n", input); // Print the stored string

    return 0;
}