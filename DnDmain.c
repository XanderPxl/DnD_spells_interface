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

int main(void)
{
	
	char *file = "SpellResult.json";
	parse(file);
	
	
	/*
	struct Result tempResult = parse(file);
	struct newNode *head = NULL;
	newNode.index = tempResult.index;
	newNode.name = tempResult.name;
	newNode.url = tempResult.url;
	newNode.range = tempResult.range;
	newNode.material = tempResult.material;
	newNode.duration = tempResult.duration;
	newNode.casting_time = tempResult.casting_time;
	
	for (int i = 0; i < 2; i++)
	{
		if( head == NULL )
		{
			head = (struct newNode *)calloc( 1, sizeof( struct newNode ) );
			head->index = tempResult.index;
			head->name = tempResult.name;
			head->url = tempResult.url;
			head->range = tempResult.range;
			head->material = tempResult.material;
			head->duration = tempResult.duration;
			head->casting_time = tempResult.casting_time;
			head->next = head;
		}
		else
		{
			struct newNode *pointer = (struct newNode *)calloc( 1, sizeof( struct newNode ) );
			file = "acid-splash.json";
			tempResult = parse(file);
			
			pointer->index = tempResult.index;
			pointer->name = tempResult.name;
			pointer->url = tempResult.url;
			pointer->range = tempResult.range;
			pointer->material = tempResult.material;
			pointer->duration = tempResult.duration;
			pointer->casting_time = tempResult.casting_time;
			pointer->next = head;
			
		}
		
	}
	
	//free(pointer);
	free(head);
	*/
	return 0;
}
