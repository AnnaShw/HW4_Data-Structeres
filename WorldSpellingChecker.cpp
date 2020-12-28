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


LinkedList* replaceCharacterCheck(HashTable* dictionaryTable, char* word)
{
	LinkedList* checkList = BuildNode(NULL);

	int len = strlen(word);
	
	
	for (int i = 0; i < len; i++)
	{
		char* buffer = (char*)malloc(len);
		strcpy(buffer, word);

		for (char j = 'a'; j <= 'z'; j++)
		{
			
			buffer[i] = j;

			if ((strcmp(buffer,word)!=0) &&(isWordInDictionary(dictionaryTable, buffer)))
			{
				checkList = addToStart(checkList, buffer);
			}
		}

	}



	return checkList;

}


LinkedList* deleteCharacterCheck(HashTable* dictionaryTable, char* word)
{

	LinkedList* checkList = BuildNode(NULL);

	int len = strlen(word);
	

	for (int i = 0; i < len; i++)
	{
		char* buffer = (char*)malloc(len + 1);
		if (buffer == NULL)
			exit(1);

		int j = 0;
		int z = 0;
		while(j <= (len - 1))
		{
			if (j != i)
			{
				buffer[z] = word[j];
				j++;
				z++;
			}
			else
			{
				j++;
			}
		}
		
		buffer[len-1] = '\0';
		

		if (isWordInDictionary(dictionaryTable, buffer))
		{
			checkList = addToStart(checkList, buffer);
		}
		

	}



	return checkList;

}


LinkedList* addCharacterCheck(HashTable* dictionaryTable, char* word)
{
	LinkedList* checkList = BuildNode(NULL);

	int len = strlen(word);

	for (int i = 1; i < len+1; i++)
	{

		for (char j = 'a'; j <= 'z'; j++)
		{

			char* buffer = (char*)malloc(len + 1);

			//FIRST PART
			for (int k = 0; k < i; k++)
			{
				buffer[k] = word[k];
			}

			//CHAR ADD
			buffer[i] = j;

			//SECOND PART	
			for (int m = i; m < len; m++)
			{
				buffer[m + 1] = word[m];
			}

			buffer[len+1] = '\0';


			if(isWordInDictionary(dictionaryTable, buffer))
				checkList = addToStart(checkList, buffer);

		}

	}

	return checkList;
}


LinkedList* switchAdjacentCharacterCheck(HashTable* dictionaryTable, char* word)
{
	LinkedList* checkList = BuildNode(NULL);
	int len = strlen(word);

	int i = 0;
	while (i < len)
	{
		char* buffer = (char*)malloc(len);
		char help = (char)malloc(sizeof(char));

		if (help == NULL)
			exit(1);

		if (buffer == NULL)
			exit(1);

		strcpy(buffer, word);
		help = buffer[i + 1];
		buffer[i + 1] = buffer[i];
		buffer[i] = help;

		//check and add
		if (isWordInDictionary(dictionaryTable, buffer))
			checkList = addToStart(checkList, buffer);

		//Index
		i++;
	}
	return checkList;
}


LinkedList* getWordSuggestions(HashTable* dictionaryTable, char* word)
{
	LinkedList* splenditList = BuildNode(NULL);
	LinkedList* afterCHeck = BuildNode(NULL);

	afterCHeck = addCharacterCheck(dictionaryTable, word);
	
	afterCHeck->next = splenditList;
	splitList(afterCHeck);


	

	return splenditList;
}

//Hfunc
void splitList(LinkedList* splenditList)
{	
	while (splenditList->next->next != NULL) {
		if (strcmp(splenditList->data, splenditList->next->data) == 0)
			splenditList->next = splenditList->next->next;
	}
}