#include <stdio.h>
#include <stdlib.h>
#include "queue.h"
#include <string.h>

char *inputString(FILE* fp, size_t size){
//The size is extended by the input with the value of the provisional
    char *str;
    int ch;
    size_t len = 0;
    str = realloc(NULL, sizeof(char)*size);//size is start size
    if(!str)return str;
    while(EOF != (ch=fgetc(fp)) && ch != '\n'){
        str[len++]=ch;
        if(len==size){
            str = realloc(str, sizeof(char)*(size+=16));
            if(!str) return str;
        }
    }
    str[len++]='\0';
    
    //queue  *q = NULL;

    return realloc(str, sizeof(char)*len);
}

int main(void){
	queue  *q = NULL;
    char *m;
	char *pch;
	int longestString_lenght;
	char *longestString;
	
	while(1){
		printf("Was soll gemacht werden? (enter, leave, front, is_empty, quit) \n");
		m = inputString(stdin, 10);
		pch = strtok(m," ,.-");
		
		if(strcmp(pch, "enter") == 0){
			
			pch = strtok(NULL, " ,.-");
			while (pch != NULL)
			{
				
				q  = enter(q, pch);
				printf("%s entered \n", pch);
				
				pch = strtok(NULL, " ,.-");
			}
			
		}else if(strcmp(pch, "leave") == 0){
			
			if (q == NULL)continue;
			
			printf("%s left \n", q->value);
			
			longestString_lenght = strlen(q->value);
			longestString = q->value;
			
			while(q->next != NULL){
				q = leave(q);
				
				if(strlen(q->value) > longestString_lenght){
					
					 longestString_lenght = strlen(q->value);
					 longestString = q->value;
					 
				}
				printf("%s left \n", q->value);
				
			}
			
			printf("Longest String was %s\n", longestString);
			
		}else if(strcmp(pch, "front") == 0){
			
			int a = front(q);
			
		}else if(strcmp(pch, "is_empty") == 0){
			
			int b = is_empty(q);
			
		}else if(strcmp(pch, "quit") == 0){
			
			break;
		}else{
			printf("Falsche Eingabe, was soll gemacht werden? (enter, leave, front, is_empty, quit) \n");
		}
		
	}
	
	free(pch);
	free(m);
	
    return 0;
}
