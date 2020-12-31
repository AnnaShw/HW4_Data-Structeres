#define _CRT_SECURE_NO_WARNINGS
#include "WordSpellingChecker.h"
#include<stdio.h>

int const max = 20;

int parseWordsToTable(char* path, HashTable* ht);

SpellingSuggestion* spellingCheck(char* text, HashTable* temp_table);

//HelpFunc
SpellingSuggestion* BuildSpelling(HashTable* temp_table, char* str);
void PrintSpellingSuggestion(SpellingSuggestion* temp);



int main()
{
	/*char* text = "iam afraid youare about to become teh immexdiate pst president of teh eing alive club ha ha glados";
	SpellingSuggestion* spellingSuggestions = spellingCheck(text);
	printSpellingSuggestions(spellingSuggestions);*/

	char path[] = "dictionary.txt";

	HashTable*temp_table = initTable(4, 1);

	if (parseWordsToTable(path, temp_table))
		printf("Well done\n");
	
	
	char word[] = "iam afraid youare about to become teh immexdiate pst president of teheing alive club ha ha glados";
	SpellingSuggestion* temp = spellingCheck(word, temp_table);
	PrintSpellingSuggestion(temp);

	
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
		buffer[strlen(buffer) - 1] = '\0';
		//Insert line by line and check for bugs(input problems
		
		if (insert(ht, buffer) == 0)
			return 0;
	}

	
	fclose(ifp);
	
	return 1;
}


SpellingSuggestion* spellingCheck(char* text, HashTable* temp_table)
{	
	
	char newString[20][20];
	int i; int j = 0; int size = 0;

	for (i = 0; i <= (strlen(text)); i++)
	{
		// if space or NULL found, assign NULL into newString[ctr]
		if (text[i] == ' ' || text[i] == '\0')
		{
			newString[size][j] = '\0';
			size++;  //for next word
			j = 0;    //for next word, init index to 0
		}
		else
		{
			newString[size][j] = text[i];
			j++;
		}
	}


	SpellingSuggestion* temp = (SpellingSuggestion*)malloc(sizeof(SpellingSuggestion));

	temp = BuildSpelling(temp_table, newString[0]);
	printf("\n Strings or words after split by space are :\n");
	for (i = 1; i < size; i++)
	{
		temp->next = BuildSpelling(temp_table, newString[i]);
		temp = temp->next;
	}
		
	return temp;
}


//Help func
void PrintSpellingSuggestion(SpellingSuggestion* temp)
{
	while (temp->next != NULL)
	{
		printf("The word %s was misspelled.Did you mean : ", temp->originalWord);
		PrintList(temp->suggestions);

		temp = temp->next;
	}
}


SpellingSuggestion* BuildSpelling(HashTable* temp_table,char* str)
{
	SpellingSuggestion* node = NULL;
	node = (SpellingSuggestion*)malloc(sizeof(SpellingSuggestion));
	if (node == NULL)
		exit(1);

	if (str != NULL)
	{
		node->originalWord = (char*)malloc(strlen(str) + 1);
		if (node->originalWord == NULL)
			exit(1);

		strcpy(node->originalWord, str);

		node->suggestions = getWordSuggestions(temp_table, str);
		
		node->next = NULL;
	}

	return node;
}