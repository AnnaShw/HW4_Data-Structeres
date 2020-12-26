#include "HashTable.h"
#include <string.h>

//Task1------------------------------------------------


int constantStringHashFunction(char* str)
{
	return 3;
}


int accumulateStringHashFunction(char* str)
{
	if (str == NULL)
		return 0;

	int total = 0;
	int len = strlen(str);
	for (int i = 0; i < len; i++)
	{
		total += (int)str[i];
	}

	return total;
}

int improvedHashFunction(char* str)
{
	if (str == NULL)
		return 0;

	int n = strlen(str);
	int total = 0;

	for (int i = 0, j = n-1; i < n; i++,j--)
	{
		total += ((int)str[i])*pow(31,j);
	}

	return total;
}


//Task 2 -------------------

HashTable* initTable(int tableSize, int hashFunction)
{
	//Alocation of hashTable in heap
	HashTable* h_table = (HashTable*)malloc(sizeof(HashTable));
	if (h_table == NULL)
		exit(1);

	//alocation of linkedlist(array)of hashTab elements
	h_table->hashTable = (HashTableElement*)malloc(tableSize*sizeof(HashTableElement));
	if (h_table->hashTable == NULL)
		exit(1);

	for (int i = 0; i < tableSize; i++)
	{
		//chain in each HashElemnt is alocated to null
		h_table->hashTable[i].key = i;
		h_table->hashTable[i].chain = BuildNode(NULL);
	}

	h_table->hashFunction = hashFunction;
	h_table->tableSize = tableSize;
	h_table->cellsTaken = 0;
	h_table->numOfElements = 0;

	return h_table;

}

int hash(char* str, HashTable* ht)
{
	int num_hfun = ht->hashFunction;
	int number = 0;

	if(num_hfun==1)
		number = constantStringHashFunction(str);

	else if(num_hfun==2)
		number = accumulateStringHashFunction(str);

	else if(num_hfun==3)
		number = improvedHashFunction(str);

	if (number < 0)
		number *= -1;

	int index = number % ht->tableSize;

	return index;

}


int insert(HashTable* ht, char* str)
{
	if (str == NULL)
		return 0;

	if (search(ht, str) == 1)
		return 0;

	//inbdex where we put it
	int index = hash(str, ht);
	if (ht->hashTable[index].chain->data == NULL)
		ht->cellsTaken += 1;

	ht->hashTable[index].chain = addToStart(ht->hashTable[index].chain, str);
	
	ht->numOfElements += 1;
	return 1;
}

int deleteElement(HashTable* ht, char* str)
{
	if (str == NULL)
		return 0;

	if (search(ht, str) == 0)
		return 0;

	//inbdex where we put it
	int index = hash(str, ht);
	ht->hashTable[index].chain = DeleteElement(ht->hashTable[index].chain, str);
	if (ht->hashTable[index].chain == NULL)
		ht->cellsTaken -= 1;
	ht->numOfElements -= 1;

	return 1;
}


int search(HashTable* hy, char* str)
{
	if (str == NULL)
		return 0;

	//index that thay may be there
	int j = hash(str,hy);

	//go over chains in each elements 
	if (isInList(hy->hashTable[j].chain, str))
		return 1;//found!

	//str not here
	return 0;
}




