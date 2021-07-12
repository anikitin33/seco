#include "myqueue.h"
#include <stdio.h>

#include <string.h>

int main() {
	
	char command[20];
	int v = 0;
	
	queue  *q = NULL;
	 
	while(1){
		printf("Was soll gemacht werden? (enter, leave, front, is_empty, quit) \n");
		scanf("%s %d", command, &v);
		
		if(strcmp(command, "enter") == 0){
			
			q  = enter(q, v);
			
		}else if(strcmp(command, "leave") == 0){
			
			q = leave(q);
			
		}else if(strcmp(command, "front") == 0){
			
			int a = front(q);
			
		}else if(strcmp(command, "is_empty") == 0){
			
			int b = is_empty(q);
			
		}else if(strcmp(command, "quit") == 0){
			
			break;
		}else{
			printf("Falsche Eingabe, was soll gemacht werden? (enter, leave, front, is_empty, quit) \n");
		}
	}
	
	return 0;

}



