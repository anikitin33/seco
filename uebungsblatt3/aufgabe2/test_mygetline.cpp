#include <gtest/gtest.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

extern "C" {
	#include "mygetline.h"
}

TEST(misc, mygetline)
{
	FILE *fd1;
   
	char *datei1 = "/home/swt/dev/c/20seco04/uebungsblatt3/aufgabe2/test_file.txt";
	
	if ( (fd1 = fopen(datei1,"r")) == NULL) {
      fprintf(stderr, "\nKonnte Datei %s nicht öffnen!", datei1);
      return;
   }
   
   FILE *fd2;
   
	char *datei2 = "/home/swt/dev/c/20seco04/uebungsblatt3/aufgabe2/test_file.txt";
	
	if ( (fd2 = fopen(datei2,"r")) == NULL) {
      fprintf(stderr, "\nKonnte Datei %s nicht öffnen!", datei2);
      return;
   }
   
	ssize_t bytes_read1 = 0;  
	size_t bytes_number1 = 64;
	//size_t and ssize_t are unsigned int types.
	char *string1 = (char *) malloc (bytes_number1);
	
	ssize_t bytes_read2 = 0;  
	size_t bytes_number2 = 1;
	//size_t and ssize_t are unsigned int types.
	char *string2 = (char *) malloc (bytes_number2);
	
	bytes_read1 = mygetline(&string1, &bytes_number1, fd1);
	bytes_read2 = getline(&string2, &bytes_number2, fd2);
	
	ASSERT_EQ(0,strcmp(string1, string2));
	
	bytes_read1 = mygetline(&string1, &bytes_number1, fd1);
	bytes_read2 = getline(&string2, &bytes_number2, fd2);
	
	printf("(%ld)(%ld) %s", bytes_read1,bytes_number1, string1);
	printf("(%ld)(%ld) %s", bytes_read2,bytes_number2, string2);
	
	ASSERT_EQ(0,strcmp(string1, string2));
	
	free(string1);
	free(string2);
   
}
