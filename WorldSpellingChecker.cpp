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
	
	for (int i = 1; i < len; i++) 
	{
		char* first_temp = (char*)malloc(sizeof(char) *(i+1));

		if (first_temp == NULL)
			exit(1);

		char* second_temp = (char*)malloc(sizeof(char) * (len - i+1));
		if (second_temp == NULL)
			exit(1);

		//First el
		for (int j = 0; j < i; j++)
		{
			first_temp[j] = word[j];
		}


		first_temp[i] = '\0';

		//Sec el
		for (int k = i, s = 0; k < len; k++, s++)
		{
			second_temp[s] = word[k];
		}
		second_temp[len-i] = '\0';

		

		//send to function
		if (isWordInDictionary(dictionaryTable, first_temp) && isWordInDictionary(dictionaryTable, first_temp))
		{
			strcat(first_temp, " ");
			strcat(first_temp, second_temp);
			free(second_temp);
			//CREATE LINKEDlIST contains split string
			new_words = addToStart(new_words, first_temp);
			//free(first_temp);
		}

		//clean temp words
		
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