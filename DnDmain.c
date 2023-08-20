#include "DnDparse.h"

struct classes_def
{
	char *index;
	char *name;
	char *url;
};

struct school_def
{
	char *index;
	char *name;
	char *url;
};

struct subclasses_def
{
	char *index;
	char *name;
	char *url;
};

struct newNode
{
	char *index;
	char *name;
	char *url;
	char *range;
	char *material;
	char *duration;
	char *casting_time;

	bool rituals;
	bool concentration;
	
	int level;
	
	struct school_def schools;
	struct classes_def classes;
	struct subclasses_def subclasses;
	
	struct newNode *next;
};

void printHead( struct newNode *head );

void next(struct newNode **head, char *userInput)
{
	if( head != NULL )
		{
			
			if( strcmp(userInput, "next") == 0)
			{
				*head = (*head)->next;
				printHead(*head);
			}
		}
}

void exitProg(struct newNode **head, char *userInput, int *quit)
{
	
	if(strcmp(userInput, "exit") == 0)
	{
		while (head != NULL)
		{
			struct newNode *pointer = (*head)->next;
			(*head)->next = pointer->next;
			if( pointer == *head )
			{
				head = NULL;
			}
			free( pointer );
		}
		*quit = 1;
		printf("finished exitProg");
	}
	//return quit;
}

void delete(struct newNode **head, char *userInput, int *quit)
{
	if( *head != NULL )
	{
		if( strcmp(userInput, "delete") == 0)
		{
			struct newNode *pointer = (*head)->next;
			(*head)->next = pointer->next;
			if( pointer == *head )
			{
				*head = NULL;
				*quit = 1;
			}
			free( pointer );
			//printHead(head);
		}
		
	}
}

void add(struct newNode **head, char *userInput)
{
	if( head != NULL )
		{
			
			if( strcmp(userInput, "add") == 0)
			{
				struct newNode *pointer = (struct newNode *)calloc( 1, sizeof( struct newNode ) );
				
				struct Result tempResult = parse("aid.json");
				pointer->index        = tempResult.index;
				pointer->name         = tempResult.name;
				pointer->url          = tempResult.url;
				pointer->range        = tempResult.range;
				pointer->material     = tempResult.material;
				pointer->duration     = tempResult.duration;
				pointer->casting_time = tempResult.casting_time;
				
				pointer->rituals      = tempResult.rituals;
				pointer->concentration= tempResult.concentration;
				pointer->level        = tempResult.level;
				
				pointer->classes.index = tempResult.classes1.index;
				//results.classes1.index
				
				pointer->next         = (*head)->next;
				(*head)->next         = pointer;
				
				printHead(*head);
			}
		}
	
}



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
	head->rituals      = tempResult.rituals;
	head->concentration= tempResult.concentration;
	head->level        = tempResult.level;
	
	head->classes.index = tempResult.classes1.index;
	
	head->next = head;
	
	
	
	int quit = 2;
	char userInput[7] = {0, 0, 0, 0, 0, 0, 0};
	
	
	printHead(head);
	//printf("passed printHead");
	while (quit != 1)
	{
		printf("in while loop");
		printf("What do you want to do?\n");
		printf("(add)  (delete)  (next)  (exit)\n");
		(void)scanf("%s", userInput);
		next(&head, userInput);
		//printf("passed next\n");
		add(&head, userInput);
		//printf("passed add\n");
		delete(&head, userInput, &quit);
		//printf("passed delete\n");
		//quit = exitProg(&head, userInput, quit);
		exitProg(&head, userInput, &quit);
		//printf("passed exitProg\n");

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
	printf("rituals = %d\n", head->rituals);
	printf("concentration = %d\n", head->concentration);
	printf("level = %d\n", head->level);
	printf("Classes:\n");
	printf("Index = %s\n", head->classes.index);
	printf("---------------------------------------------------------\n");
}
