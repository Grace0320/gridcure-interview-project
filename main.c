#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include "meter.h"

struct house *head;

GLfloat handx = 600;
GLfloat handy = 45;
GLfloat del = 55;

GLfloat hhandx = 600;
GLfloat hhandy = 70;
GLfloat hang = 0;

GLfloat hy[10] = {525,525,525,525,525,525,525,525,525,525} ;

GLfloat ay = 525;
float aytmp;
GLfloat a2y = 430;
GLfloat at = 0;
float a2ytmp;
GLfloat hyG[3] = {525, 525, 525};

int redisplay = 0;
int hourChange = 0;
int done = 0;

GLfloat final = 0.0;
float calc = 0;

void displayRect() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glColor3f(1.0f, 1.0f, 0.0f);
	glRectf(100.0f,525.0f, 150.0f, 150.0f);
	glutSwapBuffers();
}

void displayAxes(){
	glLineWidth(5.5);
	glColor3f( 1,1,1);
	glBegin(GL_LINES);
	glVertex3f(100,430,0);
	glVertex3f(580,430,0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(100,525,0);
	glVertex3f(100,100,0);
	glEnd();
	
	glBegin(GL_TRIANGLES);
	glVertex3f(100, 90, 0);
	glVertex3f(90, 105, 0);
	glVertex3f(110, 105, 0);

	glVertex3f(100, 535, 0);
	glVertex3f(90, 520, 0);
	glVertex3f(110, 520, 0);
	glEnd();
}

void tenUseRects(){
	glBegin(GL_QUADS);
	
	glColor3f( 1,0,0);
	glVertex3f(100,430,0);
	glVertex3f(140,430,0);
	glVertex3f(140,hy[0],0);
	glVertex3f(100,hy[0],0);

	glColor3f( 1,0,0);
	glVertex3f(140,430,0);
	glVertex3f(180,430,0);
	glVertex3f(180,hy[1],0);
	glVertex3f(140,hy[1],0);

	glColor3f( 1,0,0);
	glVertex3f(180,430,0);
	glVertex3f(220,430,0);
	glVertex3f(220,hy[2],0);
	glVertex3f(180,hy[2],0);

	glColor3f(1,0,0);
	glVertex3f(220,430,0);
	glVertex3f(260,430,0);
	glVertex3f(260,hy[3],0);
	glVertex3f(220,hy[3],0);

	glColor3f(1,0,0);
	glVertex3f(260,430,0);
	glVertex3f(300,430,0);
	glVertex3f(300,hy[4],0);
	glVertex3f(260,hy[4],0);

	glColor3f(1,0,0);
	glVertex3f(300,430,0);
	glVertex3f(340,430,0);
	glVertex3f(340,hy[5],0);
	glVertex3f(300,hy[5],0);

	glColor3f(1,0,0);
	glVertex3f(340,430,0);
	glVertex3f(380,430,0);
	glVertex3f(380,hy[6],0);
	glVertex3f(340,hy[6],0);

	glColor3f(1,0,0);
	glVertex3f(380,430,0);
	glVertex3f(420,430,0);
	glVertex3f(420,hy[7],0);
	glVertex3f(380,hy[7],0);

	glColor3f(1,0,0);
	glVertex3f(420,430,0);
	glVertex3f(460,430,0);
	glVertex3f(460,hy[8],0);
	glVertex3f(420,hy[8],0);

	glColor3f(1,0,0);
	glVertex3f(460,430,0);
	glVertex3f(500,430,0);
	glVertex3f(500,hy[9],0);
	glVertex3f(460,hy[9],0);

	glColor3f(0,0,1);
	glVertex3f(500,430,0);
	glVertex3f(540,430,0);
	glVertex3f(540,ay,0);
	glVertex3f(500,ay,0);

	glColor3f(1,1,0);
	glVertex3f(540,430,0);
	glVertex3f(580,430,0);
	glVertex3f(580,a2y,0);
	glVertex3f(540,a2y,0);

	glEnd();

}

void threeGridRects(){
	glBegin(GL_QUADS);
	
	glColor3f( 0,1,0);
	glVertex3f(140,430,0);
	glVertex3f(180,430,0);
	glVertex3f(180,hyG[0],0);
	glVertex3f(140,hyG[0],0);

	glColor3f( 0,1,0);
	glVertex3f(180,430,0);
	glVertex3f(220,430,0);
	glVertex3f(220,hyG[1],0);
	glVertex3f(180,hyG[1],0);

	glColor3f( 0,1,0);
	glVertex3f(260,430,0);
	glVertex3f(300,430,0);
	glVertex3f(300,hyG[2],0);
	glVertex3f(260,hyG[2],0);
	
	glEnd();
}

void clock() {
		//filled circle
	float x1,y1,x2,y2;
	float angle;
	double radius=60;
	 
	x1 = 600;
	y1 = 100;
	glColor3f(1,1,1);
	 
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
	 
	glColor3f(1, 1, 1);
	for (angle=0.0f;angle<2*3.141598f;angle+=3.14159/360)
	{
		x2 = x1+sin(angle)*radius;
		y2 = y1+cos(angle)*radius;
		glVertex2f(x2,y2);
	}
	glEnd();
	
	//filled circle
	float x22, y22;
	float angle1;
	double radius1=5;
	 
	glColor3f(0,0,0.0);
	 
	glBegin(GL_TRIANGLE_FAN);
	glVertex2f(x1,y1);
	 
	glColor3f(0, 0, 0);
	for (angle1=0.0f;angle1<2*3.141598f;angle1+=3.14159/360)
	{
		x22 = x1+sin(angle1)*radius1;
		y22 = y1+cos(angle1)*radius1;
		glVertex2f(x22,y22);
	}
	glEnd();
	

	glLineWidth(2.5);
	glColor3f(0.5,0.5,0.5);

	glBegin(GL_LINES);
	glVertex2f(x1, y1);
	glVertex2f(handx, handy);
	glColor3f(0.5	,0.5,0.5);
	glVertex2f(x1,y1);
	glVertex2f(hhandx, hhandy);
	glEnd();
	
}

void axisLabels(){
	GLvoid *font_style = GLUT_BITMAP_TIMES_ROMAN_24;
	glRasterPos3f (30, 80, 0);
	char* ylabel  = "Power [kW]";
	char* xlabel = malloc(sizeof(char)*7);
	int xpos = 115;
	int i;
	for (i = 0; ylabel[i] != '\0'; i++)
		glutBitmapCharacter(font_style, ylabel[i]);
	
	for (i = 1; i < 11; i ++) {
		glRasterPos3f (xpos, 535, 0);
		xpos += 40;
		sprintf(xlabel,"%d",i);
		glutBitmapCharacter(font_style, xlabel[0]);
		if (xlabel[1] != '\0') glutBitmapCharacter(font_style, xlabel[1]);
	}
	
	xlabel = "House Number";
	glRasterPos3f (275, 565, 0);
	for( i = 0; xlabel[i] != '\0'; i++)
		glutBitmapCharacter(font_style, xlabel[i]);
}

void legend(){
	glBegin(GL_QUADS);
	
	glColor3f(1, 0, 0);
	glVertex3f(15, 140, 0);
	glVertex3f(25, 140, 0);
	glVertex3f(25, 150, 0);
	glVertex3f(15, 150, 0);

	glColor3f(0, 1, 0);
	glVertex3f(15, 175, 0);
	glVertex3f(25, 175, 0);
	glVertex3f(25, 185, 0);
	glVertex3f(15, 185, 0);	
	
	glColor3f(0, 0, 1);
	glVertex3f(15, 210, 0);
	glVertex3f(25, 210, 0);
	glVertex3f(25, 220, 0);
	glVertex3f(15, 220, 0);

	glColor3f(1, 1, 0);
	glVertex3f(15, 245, 0);
	glVertex3f(25, 245, 0);
	glVertex3f(25, 255, 0);
	glVertex3f(15, 255, 0);	
	glEnd();	

	
	char* red = "Total Use";
	char* green = "Net on Grid";
	char* blue = "Average Use";
	char* yellow = "Average Net";
	char* yell2 = "on Grid";
	char* yell3 = "(PV only)";
	int i;
	glColor3f(1, 1, 1);
	GLvoid *font_style = GLUT_BITMAP_HELVETICA_10;
	glRasterPos3f (33, 150, 0);
	for (i=0; red[i] != '\0'; i++) 
		glutBitmapCharacter(font_style, red[i]);
	
	glRasterPos3f (33, 185, 0);
	for (i=0; green[i] != '\0'; i++) 
		glutBitmapCharacter(font_style, green[i]);

	glRasterPos3f (33, 220, 0);
	for (i=0; blue[i] != '\0'; i++) 
		glutBitmapCharacter(font_style, blue[i]);

	glRasterPos3f (33, 255, 0);
	for (i=0; yellow[i] != '\0'; i++) 
		glutBitmapCharacter(font_style, yellow[i]);

	glRasterPos3f (33, 270, 0);
	for (i=0; yell2[i] != '\0'; i++) 
		glutBitmapCharacter(font_style, yell2[i]);

	glRasterPos3f (33, 285, 0);
	for (i=0; yell3[i] != '\0'; i++) 
		glutBitmapCharacter(font_style, yell3[i]);
} 

void finalText(){
	if (final == 1.0){
		if(calc == 0) {
			at = at/(674*10);
			calc=1;
		}
		char* ave = malloc(sizeof(char)*100);
		sprintf(ave, "Average Total use at any given time: %f kW", at);		
		GLvoid *font_style = GLUT_BITMAP_HELVETICA_18;

		glColor3f(1, 1, 1);
		glRasterPos3f (150,200, 0);
		int i;
		for (i=0; ave[i] != '\0'; i++) 
			glutBitmapCharacter(font_style, ave[i]);
		
	}	
}
	

void draw(void) {
	struct house *home;
	glLoadIdentity();
	glOrtho( 0,700,600,0,0.0f,100.0f);
	glClearColor( 0,0,0,0.5f);
	glClearDepth( 1.0f);
	glClear(GL_COLOR_BUFFER_BIT |GL_DEPTH_BUFFER_BIT);
	
	displayAxes();
	axisLabels();
	legend();
	tenUseRects();
	threeGridRects();
	clock();
	finalText();	
	glFlush();	
	

	home = head;
	if (redisplay % 30 == 0 && done == 0) {
		int i = 0;		
		for(i = 0; i < 10; i++){
			hy[i] = 430 - (home->dataHead->use)*50;
			at += home->dataHead->use;
			if (i==1) {
				hyG[0] = 430 - (home->dataHead->netGrid)*50;
				a2ytmp += home->dataHead->netGrid*50/3;
			}
			else if (i==2){
				hyG[1] = 430 - (home->dataHead->netGrid)*50;
				a2ytmp += home->dataHead->netGrid*50/3;
			}
			else if (i==4){
				hyG[2] = 430 - (home->dataHead->netGrid)*50;
				a2ytmp += home->dataHead->netGrid*50/3;
			}		
			else aytmp += home->dataHead->use*50/10;
			if (home->dataHead->next != NULL) home->dataHead = home->dataHead->next;
			else done = 1;
			if (home->next != NULL) home = home->next;
		}

		ay = 430 - aytmp;
		aytmp = 0;
		a2y = 430 - a2ytmp;
		a2ytmp = 0;
		if (handy > 100) {
			handx -= del;
			handy -= del;
		}
		else if (handy<100) {
			handx += del;
			handy += del;
		}
		else if (handx < 600) {
			handx+=del;
			handy -=del;
		}
		else {
			handx -= del;
			handy += del;
		}

		hhandx = 600 + sin(hang)*35;
		hhandy = 100 - cos(hang)*35;
		hang += 3.14159/48;
	}
	else if (done == 1) {
		final = 1.0;
	}
	glutPostRedisplay();
	redisplay += 1;
}

//Main program

int main(int argc, char **argv) {
	head = malloc(sizeof(struct house));
	parseCSV(head);

	glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_SINGLE);
    glutInitWindowPosition(100, 25);
    glutInitWindowSize(700,600);
    glutCreateWindow("Power consumption in Austin homes");
    //Call to the drawing function
    glutDisplayFunc(draw);
		
	glutMainLoop();
    
    return 0;

}
