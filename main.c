#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

int in_str_i(char *haystack, char needle) {
	for (int i = 0; haystack[i] != '\0'; ++i) {
		if (tolower(haystack[i]) == tolower(needle)) {
			return 1;
		} 
	}

	return 0;
}

void replace_str(char *str1, char *str2, char letter) {
	for (int i = 0; str1[i] != '\0'; ++i) {
		if (tolower(str1[i]) == tolower(letter)) {
			str2[i] = tolower(letter);
		}
	}
}

char *copy_string_encoded(char *str) {
	size_t len = strlen(str);
	char *encoded = (char *)malloc(len + 1);

	if (encoded == NULL) {
		fprintf(stderr, "Error allocating memory for the encoded word.\n");
		exit(EXIT_FAILURE);
	}

	for (size_t i = 0; i < len; ++i) {
		encoded[i] = '_';
	}

	encoded[len] = '\0';

	return encoded;
}

int strings_are_equal_i(char *str1, char *str2) {
	for (int i = 0; str1[i] != '\0'; ++i) {
		if (tolower(str1[i]) != tolower(str2[i])) return 0;
	}

	return 1;
}

int main() {
	char word[] = "hangman";
	char *enc_word = copy_string_encoded(word);
	int attempts = 5;
	char letter;
	int index;

	printf("Welcome to Hangman in C. To exit, just type CTRL+C.\n\n");

	printf("This word has %i letters.\n", (int) strlen(word));
	printf("Word: %s\n\n", enc_word);

	while (1) {
		printf("---------------------------\n");
		printf("Your guess: ");
		int c;
		scanf(" %c", &letter);
		while ((c = getchar()) != '\n' && c != EOF);
		printf("\n");

		if (in_str_i(word, letter)) {
			replace_str(word, enc_word, letter);
			printf("Word: %s\n\n", enc_word);
		} else {
			printf("There's no \"%c\". Try again.\n", letter);
			attempts--;
		}


		printf("Attempts: %i.\n", attempts);
		printf("---------------------------\n\n");

		if (attempts == 0) {
			printf("You lost. The secret word are: \"%s\".\n\n", word);
			break;
		}

		if (strings_are_equal_i(word, enc_word)) {
			printf("Congratulations! You won with %i attempts remaining.\n\n", attempts);
			break;
		}
	}

	return 0;
}
