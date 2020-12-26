#define _CRT_SECURE_NO_WARNINGS
#include "WordSpellingChecker.h"
#include<stdio.h>

int const max = 20;

int parseWordsToTable(char* path, HashTable* ht);

SpellingSuggestion* spellingCheck(char* text);
/*
	Add help functions here...
*/

int main()
{
	/*char* text = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
	SpellingSuggestion* spellingSuggestions = spellingCheck(text);
	printSpellingSuggestions(spellingSuggestions);*/

	char path[] = "dictionary.txt";

	HashTable*temp_table = initTable(5, 1);

	if (parseWordsToTable(path, temp_table))
		printf("Well done");

	return 0;
}


//Task3------------------------------------------
int parseWordsToTable(char* path, HashTable* ht)
{	
	FILE* ifp = fopen(path, "r");
	if (ifp == NULL) {
		printf("Can't open input file in.txt!\n");
		exit(1);
	}


	char buffer[max];

	// fgetc – read char from file
	while (fgets(buffer, max, ifp))
	{ 
		//Insert line by line and check for bugs(input problems
		PrintList(ht->hashTable[3].chain);
		if (insert(ht, buffer) == 0)
			return 0;
	}

	
	fclose(ifp);
	
	return 1;
}
