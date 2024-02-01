#include <stdio.h>
#include <stdlib.h>	
#include <time.h>
#include <string.h>

#define MAX_WORD_LENGTH 100

char *getRandomWord(const char *filename) {
	FILE *fp = fopen(filename, "r");

	if (fp == NULL) {
		perror("Erro ao abrir o arquivo");
        exit(EXIT_FAILURE);
	}

	srand((unsigned int)time(NULL));

	int lineNumber = 0;
	char ch;
	while ((ch = fgetc(fp)) != EOF) {
		if (ch == '\n') lineNumber++;
	}

	rewind(fp);

	int lineToRead = rand() % lineNumber;
	int actualLine = 0;

	char *word = (char *)malloc(MAX_WORD_LENGTH * sizeof(char));

	while (actualLine < lineToRead && fgets(word, MAX_WORD_LENGTH, fp) != NULL) {
		actualLine++;
	}

	int size = strlen(word);

	if (word[size - 1] == '\n') {
		word[size - 1] = '\0';
	}

	fclose(fp);
	return word;
}
