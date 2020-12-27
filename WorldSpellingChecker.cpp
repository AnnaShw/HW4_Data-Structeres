#include "WordSpellingChecker.h"


int wordSpellingChecker(HashTable* dictionaryTable)
{
	return 1;
}

int isWordInDictionary(HashTable* dictionaryTable, char* word)
{
	if (search(dictionaryTable, word))
		return 1;

	return 0;

}


