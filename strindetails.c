#include <stdio.h>
#include <string.h>

void count(char* str)
{
	int vowels = 0, consonants = 0,words= 1;

	int i;
	char ch;
	for (i = 0; str[i] != '\0'; i++) {

		ch = str[i];
		if (ch == 'a' || ch == 'e'
			|| ch == 'i' || ch == 'o'
			|| ch == 'u' || ch == 'A'
			|| ch == 'E' || ch == 'I'
			|| ch == 'O' || ch == 'U')
			vowels++;

		else if (ch == ' ')
			words++;

		else

			consonants++;
	}

	printf("\nVowels: %d", vowels);
	printf("\nConsonants: %d", consonants);
    printf("\nWords: %d", words);
}

int main()
{
	char str[50];
    printf("Enter String : ");
    
    fgets(str, sizeof(str), stdin);

    if (str[strlen(str) - 1] == '\n') {
        str[strlen(str) - 1] = '\0';
    }
	printf("String: %s", str);

	count(str);

	return 0;
}
