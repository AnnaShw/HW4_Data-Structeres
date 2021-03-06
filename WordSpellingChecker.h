#pragma once
#include "HashTable.h"
#define _CRT_SECURE_NO_WARNINGS

typedef struct SpellingSuggestion SpellingSuggestion;


struct SpellingSuggestion {
	char* originalWord;
	LinkedList* suggestions;
	SpellingSuggestion* next;
};


int wordSpellingChecker(HashTable* dictionaryTable);
int isWordInDictionary(HashTable* dictionaryTable, char* word);
LinkedList* addSpaceCheck(HashTable* dictionaryTable, char* word);
LinkedList* replaceCharacterCheck(HashTable* dictionaryTable, char* word);
LinkedList* deleteCharacterCheck(HashTable* dictionaryTable, char* word);
LinkedList* addCharacterCheck(HashTable* dictionaryTable, char* word);
LinkedList* switchAdjacentCharacterCheck(HashTable* dictionaryTable, char* word);
LinkedList* getWordSuggestions(HashTable* dictionaryTable, char* word);


//HFunc
void FindingDuplicates(LinkedList* splenditList);
void concatenateLists(LinkedList* lst1, LinkedList* lst2);
//void deleteNULLNode(LinkedList* lst);

class WorldSpellingChecker
{
};

