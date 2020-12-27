#include "WordSpellingChecker.h"


int wordSpellingChecker(HashTable* dictionaryTable)
{
	return 1;
}

int isWordInDictionary(HashTable* dictionaryTable, char* word)
{
	////if (search(dictionaryTable, word))
		return 1;

	return 0;

}


LinkedList* addSpaceCheck(HashTable* dictionaryTable, char* word)
{
	LinkedList* new_words = BuildNode(NULL);
	int len = strlen(word);
	printf("strlen %d\n", len);
	
	for (int i = 1; i < len; i++) 
	{
		char* first_temp = (char*)malloc(sizeof(char) * i);
		if (first_temp == NULL)
			exit(1);

		char* second_temp = (char*)malloc(sizeof(char) * (len - i));
		if (second_temp == NULL)
			exit(1);

		//First el
		for (int j = 0; j < i; j++)
		{
			first_temp[j] = word[j];
		}


		first_temp[i] = '\n';

		//Sec el
		for (int k = i, s = 0; k < len; k++, s++)
		{
			second_temp[s] = word[k];
		}

		
		printf("Fword:%s , size: %d\n", first_temp, strlen(first_temp));
		printf("Sword:%s , size: %d\n", second_temp, strlen(second_temp));

		//send to function
		if (isWordInDictionary(dictionaryTable, first_temp) && isWordInDictionary(dictionaryTable, first_temp))
		{
			strcat(first_temp, " ");
			strcat(first_temp, second_temp);
			
			//CREATE LINKEDlIST contains split string
			new_words = addToStart(new_words, first_temp);

		}

		//clean temp words
		free(first_temp);
		free(second_temp);
	}

	PrintList(new_words);
	return new_words;
}
//
//LinkedList* replaceCharacterCheck(HashTable* dictionaryTable, char* word)
//{
//
//}
//
//LinkedList* deleteCharacterCheck(HashTable* dictionaryTable, char* word)
//{
//
//}
//
//LinkedList* addCharacterCheck(HashTable* dictionaryTable, char* word)
//{
//
//}
//
//LinkedList* switchAdjacentCharacterCheck(HashTable* dictionaryTable, char* word)
//{
//
//
//}
//
//LinkedList* getWordSuggestions(HashTable* dictionaryTable, char* word)
//{
//
//}