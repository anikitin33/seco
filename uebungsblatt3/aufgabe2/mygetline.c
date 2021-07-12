#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "mygetline.h"
#define INIT_LENGTH 12
  
ssize_t mygetline(char **lineptr, size_t *n, FILE *stream){
	
	if(lineptr == NULL || n == NULL){
		
		return -1;
		
	}
	
	if(*lineptr == NULL || *n == 0){
		
		*n = INIT_LENGTH;
		*lineptr = (char *) malloc (INIT_LENGTH);
		
		if(*lineptr == NULL){
			return -1;
		}
		
	}
	
	int c = 0;
	char *new_lineptr = NULL;
	size_t current_lenght = 0;
	
	while((c = fgetc(stream)) != EOF){
		
		if(current_lenght >= *n){
			
			*n = stream->_IO_read_end - stream->_IO_read_base;
			new_lineptr = (char *) realloc (*lineptr, *n);
			
			if(new_lineptr == NULL){
				return -1;
			}
			
			*lineptr = new_lineptr;
			//printf("Ich habe reallokiert: %ld\n", *n);
			
		}
		
		memcpy(*lineptr + current_lenght, &c, sizeof(char));
		
		current_lenght++;
		if(c == '\n'){
				break;
		}
	}	
	
	return current_lenght;

}
