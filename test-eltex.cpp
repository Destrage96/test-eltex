#define _CRT_SECURE_NO_WARNINGS
#include "stdio.h"
#include <locale.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum
{
	RANDOM_CHAR = 0,
	RANDOM_NUMBER,
	RANDOM_MAX_TYPE,
};

int Random(int min, int max) {
	if (max < min) {
		int tmp = min;
		min = max;
		max = tmp;
	}
	return rand() % (max - min + 1) + min;
}

char RandomChar() {
	return (char)Random('A', 'Z');
}

char RandomNumber() {
	return (char)Random('0', '9');
}

char RandomSymbol() {
	int type = rand() % RANDOM_MAX_TYPE;
	switch (type) {
	case RANDOM_CHAR:
		return RandomChar();
	case RANDOM_NUMBER:
		return RandomNumber();
	default:
		return RandomNumber();
	}
}

int main()
{
	int current;
	char inputData[32];
	char enterdChar;
	char enterdCharTwo;
	char* charArray;
	int index;
	int repeatChar = 0;
	int repeatCharTwo = 0;

	setlocale(LC_ALL, "Rus");
	printf("Введите число: ");
	scanf("%31s", inputData);
	sscanf(inputData, "%d", &current);

	charArray = (char*)malloc((current * sizeof(char)) + 1);
	memset(charArray, 0, ((current * sizeof(char)) + 1)); //Выделение памяти

	for (index = 0; index < current; index++)
	{
		charArray[index] = RandomSymbol();
	}

	printf("%s \n", charArray);// Вывод элементов массива

	printf("Введите символ: ");
	scanf("%31s", inputData);
	sscanf(inputData, "%c", &enterdChar);// для исключения проблемы переноса строки в windows


	printf("Введите второй символ: ");
	scanf("%31s", inputData);
	sscanf(inputData, "%c", &enterdCharTwo);

	for (index = 0; index < current; index++)
	{
		if (!isdigit(charArray[index]))
		{
			charArray[index] = enterdChar;
			repeatChar++;
		}
		else
		{
			charArray[index] = enterdCharTwo;
			repeatCharTwo++;
		}
	}

	printf("%s \n", charArray);// Вывод элементов массива

	printf("символ %c повторяется %d раз \n", enterdChar, repeatChar);
	printf("символ %c повторяется %d раз", enterdCharTwo, repeatCharTwo);

	free(charArray);
	return 0;
}