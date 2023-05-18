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
	printf("index = %s\n", head->index);
	head->name = tempResult.name;
	printf("name = %s\n", head->name);
	head->url = tempResult.url;
	printf("url = %s\n", head->url);
	head->range = tempResult.range;
	printf("range = %s\n", head->range);
	head->material = tempResult.material;
	printf("material = %s\n", head->material);
	head->duration = tempResult.duration;
	printf("duration = %s\n", head->duration);
	head->casting_time = tempResult.casting_time;
	printf("casting_time = %s\n", head->casting_time);
	head->next = head;
	
	printf("\n\nindex = %s\n", head->index);
	//free(pointer);
	printHead(head);
	free(head);
	
	return 0;
}

void printHead( struct newNode *head )
{
	printf("\n\nindex = %s\n", head->index);
}


