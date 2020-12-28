#include"LinkedList.h"


void PrintList(LinkedList* head)
{
	LinkedList* temp = head;
	printf("\nThe list is: ");
	while (temp != NULL)
	{
		printf("%s ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
LinkedList* BuildNode(char* str)
{
	LinkedList* node = NULL;
	node = (LinkedList*)malloc(sizeof(LinkedList));
	if (node == NULL)
		exit(1);

	if (str != NULL) 
	{
		node->data = (char*)malloc(strlen(str) + 1);
		if (node->data == NULL)
			exit(1);

		strcpy(node->data, str);

		node->next = NULL;
	}

	else 
	{
		node->data = NULL;
		node->next = NULL;
	}

	return node;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
LinkedList* addToStart(LinkedList* head, char* str)
{
	LinkedList* new_elem = BuildNode(str);

	new_elem->next = head;
	
	return new_elem;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
LinkedList* FreeList(LinkedList* head) 
{
	LinkedList* temp;
	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
	return NULL;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
LinkedList* DeleteElement(LinkedList* head,char* str)
{
	LinkedList* previous = head, * current = head->next;
	if (head == NULL)
		return head;
	if (strcmp(head->data, str)==0)
	{
		LinkedList* temp = head;
		head = head->next;
		free(temp);
		return head;
	}
	while (previous != NULL)
	{
		if (strcmp(head->data, str) == 0)
			break;
		current = previous;
		previous = previous->next;
	}
	if (previous != NULL)
		current->next = previous->next;
	free(previous);
	return head;
}
//-------------------------------------------------------------------------------------------------------------------------------------------------------
int isInList(LinkedList* PHead, char* str) 
{
	int flag = 1;
	if (PHead == NULL) return 0;

	while (flag == 1 && PHead->data!=NULL)
	{
		if (strcmp(PHead->data, str) == 0) 
		{
			
			return 1;
		}
		else if (PHead->next == NULL) {

			
			return 0;
		}
		PHead = PHead->next;
	}


	return 0;
 }
//-------------------------------------------------------------------------------------------------------------------------------------------------------