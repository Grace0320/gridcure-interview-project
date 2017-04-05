#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>


struct meterData{
	char* date;	
	int hour;
	int min;
	float use;
	float netGrid;
	struct meterData* next; 
};
	
struct house{ 
	int num;
	struct meterData* dataHead;
	struct house* next;
};

int parseCSV();
void draw(void);
