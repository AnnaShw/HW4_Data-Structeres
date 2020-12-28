#include "WordSpellingChecker.h"


int wordSpellingChecker(HashTable* dictionaryTable)
{
	return 1;
}

int isWordInDictionary(HashTable* dictionaryTable, char* word)
{
	//if (search(dictionaryTable, word))
		return 1;

	return 0;

}


LinkedList* addSpaceCheck(HashTable* dictionaryTable, char* word)
{

	LinkedList* checkList = BuildNode(NULL);

	int len = strlen(word);
	

	for (int i = 1; i < len; i++)
	{
		char* buffer = (char*)malloc(len + 1);
		char* bufferF = (char*)malloc(len + 1);
		char* bufferS = (char*)malloc(len + 1);

		//FirstPART--------------------------
		for (int j = 0; j < i; j++)
		{
			bufferF[j] = word[j];
			buffer[j] = word[j];
		}

		bufferF[i] = '\0';
		buffer[i] = ' ';

		printf("%s", bufferF);
		
		if (!isWordInDictionary(dictionaryTable, bufferF))
		{
			free(bufferF);
			continue;
		}
			
		//SecondPart-----------------------------------
		for (int k = i, j = 0; k < len; k++, j++)
		{
			bufferS[j] = word[k];
			buffer[k+1] = word[k];
		}

		bufferS[len - i] = '\0';
		buffer[len + 1] = '\0';
		printf("%s", bufferS);

		if (!isWordInDictionary(dictionaryTable, bufferS))
		{
			free(bufferS);
			continue;
		}

		
		checkList = addToStart(checkList, buffer);

		//Free
		free(bufferF);
		free(bufferS);
	}

	return checkList;

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