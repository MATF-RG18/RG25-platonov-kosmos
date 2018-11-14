/* 	Racunarska grafika  
	Projekat: Platonov kosmos
	Student: Miloš Krsmanović, 263/2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>

static void on_keyboard(unsigned char key, int x1, int y1);
void on_display(void);
void on_reshape(int width, int height);


int main(int argc, char** argv){
	//Inicijalizacija gluta
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	
	//Kreiranje prozora
	glutInitWindowSize(1000, 500);			
	glutInitWindowPosition(200, 100); //Srediti
	glutCreateWindow(argv[0]);
	
	//Inicijalizacija on display funkcija
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutKeyboardFunc(on_keyboard);

	//Glavna petlja
	glutMainLoop();
	return 0;
}

void on_keyboard(unsigned char key, int x1, int y1){
	
	switch (key){
	//Ako je pritisnut 'esc' izlazimo iz programa
	case 27:
		exit(EXIT_SUCCESS);
		break;

	case 't':
	case 'T':
	//Uz klik misa uklanja tetraedar
		//TODO
    break;
	
	
	case 'h':
	case 'H':
	//Uz klik misa uklanja heksaedar
		//TODO
    break;
	
	case 'o':
	case 'O':
	//Uz klik misa uklanja oktaedar
		//TODO
    break;	

	case 'd':
	case 'D':
	//Uz klik misa uklanja dodekaedar
		//TODO
    break;    

	case 'i':
	case 'I':
	//Uz klik misa uklanja ikosaedar
		//TODO
    break;
  }
}

void on_display(void){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	
	glutSwapBuffers();
}

void on_reshape(int width, int height){
	glViewport(0,0,width,height);
	glLoadIdentity();
	gluPerspective(45, (float) width/height, 1, 50);
}
