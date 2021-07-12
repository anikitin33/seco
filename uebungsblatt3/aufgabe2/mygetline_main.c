#include <stdlib.h>
#include <stdio.h>
#define INIT_LENGTH 12
#include "mygetline.h"

int main(){
	
	FILE *fd;
   
	char *datei = "/home/swt/dev/c/20seco04/uebungsblatt3/aufgabe2/test_file.txt";
	
	if ( (fd = fopen(datei,"r")) == NULL) {
      fprintf(stderr, "\nKonnte Datei %s nicht öffnen!", datei);
      return EXIT_FAILURE;
   }
	
	ssize_t bytes_read = 0;  
	size_t bytes_number = 1;
	
	char *string = (char *) malloc (bytes_number);
  
	bytes_read = mygetline(&string, &bytes_number, fd);
	
	printf("(%ld)(%ld) >%s<", bytes_read,bytes_number, string);
		
	bytes_read = mygetline(&string, &bytes_number, fd);
	
	printf("(%ld)(%ld) >%s<", bytes_read,bytes_number, string);
	
	bytes_read = mygetline(&string, &bytes_number, fd);
	
	printf("(%ld)(%ld) >%s<", bytes_read,bytes_number, string);
	
	bytes_read = mygetline(&string, &bytes_number, fd);
	
	printf("(%ld)(%ld) >%s<", bytes_read,bytes_number, string);
	
	free(string);
	
	return 0;

}
