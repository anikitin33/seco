#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define INIT_LENGTH 12

int main(int argc, char * argv[]){
	
	if(argc < 2){
		fprintf(stderr, "Kein Suchbegriff eingegeben!\n");
		return EXIT_FAILURE;
	}
	
	char * needle;
	needle = argv[1];
	
	
	
	FILE *fd;
   
	char *datei = "/home/SWT-LABOR/2060696/nethome/SeCo/20seco04/uebungsblatt3/aufgabe3/allkeys.txt";
	
	if ((fd = fopen(datei,"r")) == NULL) {
      fprintf(stderr, "Konnte Datei %s nicht öffnen!\n", datei);
      return EXIT_FAILURE;
   }
	
	ssize_t bytes_read = 0;  
	size_t bytes_number = 500;
	
	char *string = NULL;
	char *ret;
	
	size_t counter = 0;
	char *number_as_string;
	long number_as_int;
	const char delimiter[2] = ";";
	char *ptr;
	
	char *highest_number_as_string = NULL;
	long highest_number_as_int = -1;
	
	while((bytes_read = getline(&string, &bytes_number, fd)) > 0){
		
		if(*string == '#'){
			continue;
		}
		if(*string == '\n'){
			continue;
		}
		if(*string == '@'){
			continue;
		}
		
		if ((ret = strstr(string, needle)) != NULL){
			counter++;
			number_as_string = strtok(string, delimiter);
			number_as_int = strtol(number_as_string, &ptr, 16);
			
			if(number_as_int >= highest_number_as_int){
				highest_number_as_int = number_as_int;
				
				if(highest_number_as_string == NULL || strlen(highest_number_as_string) <= strlen(number_as_string)){
					highest_number_as_string = realloc(highest_number_as_string, strlen(number_as_string)+1);
				}
				
				strcpy(highest_number_as_string, number_as_string);
			}
			
			
		}
		
	}
	
	if (counter > 0){
		printf("Anzahl Treffer: %ld, Höchster Treffer Hex - Dez: %s - %ld\n", counter, highest_number_as_string, highest_number_as_int);
	}else{
		printf("Keine Treffer!\n");
	}
	
	free(string);
	free(highest_number_as_string);
	fclose(fd);
	
	return 0;

}
