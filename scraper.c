#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "meter.h"

int parseCSV(struct house* head){
	FILE *fp;
	int i;
	char* filename = malloc(sizeof(char*));
	struct house *node = head;

	for (i = 0; i < 10; i++){
		char* j = malloc(sizeof(char)*4);
		if (i == 9) j = "10";
		else sprintf(j, "0%d", i + 1); 
		
		sprintf(filename, "home%s.txt", j);
		fp = fopen(filename, "r");
			
		if (fp == NULL) {
			perror("Can't open file:");	
			return -1;	
		}
		
		node->num = i+1;
		node->dataHead = malloc(sizeof(struct meterData));
		struct meterData *measure = node->dataHead;
		measure->date = (char*)malloc(sizeof(char)*15);

		if (i == 9) node->next = NULL;
		else {
			node->next = malloc(sizeof(struct house));
			node = node->next;
		}	

		char line[70];
		char* tmp;
		tmp = fgets(line, 70, fp);
		
		//while: every line gets put into a struct.
		while(tmp != NULL) {
			sscanf(line, "%s %d:%d;%f;%f\n", measure->date, &measure->hour, &measure->min,&measure->use, &measure->netGrid);
						
			measure->next = malloc(sizeof(struct meterData));
			measure = measure->next;
			measure->date = (char*)malloc(sizeof(char)*15);
			tmp = fgets(line, 70, fp);
		}	
		fclose(fp);
	}

	return 0;
}
