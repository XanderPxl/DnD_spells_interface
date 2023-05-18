#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>



struct Result 
{
  char *index;
  char *name;
  char *url;
  char *range;
  char *material;
  char *duration;
  char *casting_time;
  
};


char * strsep (char **stringp, const char *delim);



struct Result parse(char *file)
{
	struct Result results = {0};
	FILE *filePointer = fopen( file, "r" );
	if (filePointer == NULL) // Check if file is succesfully opened
	{
		perror("File opening failed"); // Print error
		exit(-1);                     // Stop program
	}
	char buffer[1024];    // Prepare a line buffer
	char *parsing = NULL; // Prepare helper pointer for strsep
	int counter = 0;      // Prepare helper counter for printing
	char check[6] = "count";
	while (!feof(filePointer)) // Keep reading file till EndOfFile is reached
	{
		if (fgets(buffer, sizeof(buffer), filePointer) == NULL) // Read one line (stops on newline or eof), will return NULL on
        {
		  fclose( filePointer ); // eof or fail
		  break; // Stop reading
		}
		parsing = buffer; // Point to buffer (reset)
		char *token = strsep(&parsing, "\"");
		while (token) // If token exists
		{
			token = strsep(&parsing, "\""); // Find next token
			//printf("token = '%s'\n", token);
			if (token != NULL) // als dit teken uberhaubt bestaat dan...
			{
			
				if (strcmp(token, "index") == 0 && results.index == NULL) 
				{
				  char *index = strtok(&parsing[2], ",");
				  results.index = (char*)calloc(strlen(index), sizeof(char));
				  strcpy(results.index, index);
				  printf("index = %s\n", results.index);
				  
				} 
				
				else if (strcmp(token, "name") == 0 && results.name == NULL) 
				{
				  char *name = strtok(&parsing[2], ",");
				  results.name = (char*)calloc(strlen(name), sizeof(char));
				  strcpy(results.name, name);
				  printf("name = %s\n", results.name);
				} 
				else if (strcmp(token, "url") == 0 && results.url == NULL) 
				{
				  char *url = strtok(&parsing[2], ",");
				  results.url = (char*)calloc(strlen(url), sizeof(char));
				  strcpy(results.url, url);
				  printf("url = %s\n", results.url);
				} 
				else if (strcmp(token, "range") == 0) 
				{
				  char *range = strtok(&parsing[2], ",");
				  results.range = (char*)calloc(strlen(range), sizeof(char));
				  strcpy(results.range, range);
				  printf("range = %s\n", results.range);
				} 
				else if (strcmp(token, "material") == 0) 
				{
				  char *material = strtok(&parsing[2], ",");
				  results.material = (char*)calloc(strlen(material), sizeof(char));
				  strcpy(results.material, material);
				  printf("material = %s\n", results.material);
				} 
				
				else if (strcmp(token, "duration") == 0) 
				{
				  char *duration = strtok(&parsing[2], ",");
				  results.duration = (char*)calloc(strlen(duration), sizeof(char));
				  strcpy(results.duration, duration);
				  printf("duration = %s\n", results.duration);
				}
				
				else if (strcmp(token, "casting_time") == 0) 
				{
				  char *casting_time = strtok(&parsing[2], ",");
				  results.casting_time = (char*)calloc(strlen(casting_time), sizeof(char));
				  strcpy(results.casting_time, casting_time);
				  printf("casting_time = %s\n", results.casting_time);
				  
				}
				 
				
				
			}
		}
	}

	
	free(results.index);
    free(results.name);
    free(results.url);

	free(results.range);
	free(results.material);
	//free(results.pt_area_of_effect->size);
	//free(results.ritual);
	free(results.duration);
	//free(results.concentration);
	free(results.casting_time);
	//free(results.level);
	

	
	
	return results;
}








    /* Copyright (C) 1992-2023 Free Software Foundation, Inc.
      This file is part of the GNU C Library.
    
       The GNU C Library is free software; you can redistribute it and/or
       modify it under the terms of the GNU Lesser General Public
       License as published by the Free Software Foundation; either
       version 2.1 of the License, or (at your option) any later version.
    
       The GNU C Library is distributed in the hope that it will be useful,
      but WITHOUT ANY WARRANTY; without even the implied warranty of
      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
      Lesser General Public License for more details.
   
      You should have received a copy of the GNU Lesser General Public
      License along with the GNU C Library; if not, see
      <https://www.gnu.org/licenses/>.  */

char * strsep (char **stringp, const char *delim)
   {
     char *begin, *end;
   
     begin = *stringp;
     if (begin == NULL)
       return NULL;
   
     /* Find the end of the token.  */
     end = begin + strcspn (begin, delim);
   
     if (*end)
       {
         /* Terminate the token and set *STRINGP past NUL character.  */
         *end++ = '\0';
         *stringp = end;
       }
     else
       /* No more delimiters; this is the last token.  */
       *stringp = NULL;
   
     return begin;
   }

