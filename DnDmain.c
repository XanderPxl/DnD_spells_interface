#include "DnDparse.h"



struct newNode
{
	char *index;
	char *name;
	char *url;
	char *range;
	char *material;
	char *duration;
	char *casting_time;
	
	struct newNode *next;
};

void printHead( struct newNode *head );

int main(void)
{
	
	char *file = "SpellResult.json";
	struct Result tempResult = parse(file);
	struct newNode *head = NULL;
	
	head = (struct newNode *)calloc( 1, sizeof( struct newNode ) );
	head->index = tempResult.index;

	head->name = tempResult.name;
	head->url = tempResult.url;
	head->range = tempResult.range;
	head->material = tempResult.material;
	head->duration = tempResult.duration;
	head->casting_time = tempResult.casting_time;
	head->next = head;
	
	
	
	int quit = 0;
	char userInput[7] = {0, 0, 0, 0, 0, 0, 0};
	
	printHead(head);
	while (quit != 1)
	{
		printf("What do you want to do?\n");
		printf("(add)  (delete)  (next)  (exit)\n");
		(void)scanf("%s", &userInput);
		if( head != NULL )
		{
			
			if( strcmp(userInput, "next") == 0)
			{
				head = head->next;
				printHead(head);
			}
			if( strcmp(userInput, "add") == 0)
			{
				struct newNode *pointer = (struct newNode *)calloc( 1, sizeof( struct newNode ) );
				
				tempResult = parse("aid.json");
				pointer->index = tempResult.index;
				pointer->name = tempResult.name;
				pointer->url = tempResult.url;
				pointer->range = tempResult.range;
				pointer->material = tempResult.material;
				pointer->duration = tempResult.duration;
				pointer->casting_time = tempResult.casting_time;
				pointer->next = head->next;
				head->next = pointer;
				
				printHead(head);
			}
			if( strcmp(userInput, "delete") == 0)
			{
				if( head != NULL )
				{
					struct newNode *pointer = head->next;
					head->next = pointer->next;
					if( pointer == head )
					{
						head = NULL;
					}
					free( pointer );
					//printHead(head);
				}
			}
			else if ( strcmp(userInput, "exit") == 0)
			{
				quit = 1;
				while (head != NULL)
				{
					struct newNode *pointer = head->next;
					head->next = pointer->next;
					if( pointer == head )
					{
						head = NULL;
					}
					free( pointer );
				}
				
			}
		}
	}
	

	
	
	
	//free(pointer);
	free(tempResult.index);
	free(tempResult.name);
	free(tempResult.url);
	free(tempResult.range);
	free(tempResult.material);
	free(tempResult.duration);
	free(tempResult.casting_time);
	
	
	return 0;
}

void printHead( struct newNode *head )
{
	printf("---------------------------------------------------------\n");
	printf("index = %s\n", head->index);
	printf("name = %s\n", head->name);
	printf("url = %s", head->url);
	printf("range = %s\n", head->range);
	printf("material = %s\n", head->material);
	printf("duration = %s\n", head->duration);
	printf("casting_time = %s\n", head->casting_time);
	printf("---------------------------------------------------------\n");
}
