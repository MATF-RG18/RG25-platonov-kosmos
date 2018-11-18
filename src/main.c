/* 	Racunarska grafika  
	Projekat: Platonov kosmos
	Student: Miloš Krsmanović, 263/2015
*/
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <time.h>
#include <math.h>

//Zbog bolje citljivosti, ovde cu definisati sve 
//konstante koje su u upotrebi
#define esc 27
#define sirina_prozora 1000
#define duzina_prozora 500
#define NazivAplikacije "Platonov kosmos"

static void on_keyboard(unsigned char key, int x1, int y1);
void on_display(void);
void on_reshape(int width, int height);
void init();


int main(int argc, char** argv){
	//Inicijalizacija gluta
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	
	//Kreiranje prozora
	glutInitWindowSize(sirina_prozora, duzina_prozora);			
	glutInitWindowPosition(200, 100); //Srediti
	glutCreateWindow(NazivAplikacije);
	
	//Inicijalizacija on display funkcija
	glutDisplayFunc(on_display);
	glutReshapeFunc(on_reshape);
	glutKeyboardFunc(on_keyboard);
	init();

    // OpenGL inicijalizacija 
    glClearColor(0, 0, 0, 0);

	//Glavna petlja
	glutMainLoop();
	return 0;
}

void on_keyboard(unsigned char key, int x1, int y1){
	
	switch (key){
	//Ako je pritisnut 'esc' izlazimo iz programa
	case esc:
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
	
	//Tetraedar - prvi pokusaj
    glBegin(GL_TRIANGLES);

    //Prednji trougao
    glColor3f(1.0f, 0.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);
    glVertex3f( -5.0f, -5.0f, 0.0f);
    glVertex3f( 5.0f,  -5.0f, 0.0f);

    //Desna strana
    glColor3f(1.0f, 0.5f, 0.0f); //narandzasta
    glVertex3f( 5.0f,  -5.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);
    glVertex3f( 0.0f,  -5.0f, -5.0f);

    //Leva Strana
    glColor3f(0.5f, 1.0f, 0.0f);//zelenkasta
    glVertex3f( -5.0f, -5.0f, 0.0f);
    glVertex3f(0.0f, 5.0f, 0.0f);
    glVertex3f( 0.0f,  -5.0f, -5.0f);

    //Donji trougao (baza)
    glColor3f(0.0f, 1.0f, 0.0f);
    glVertex3f( -5.0f, -5.0f, 0.0f);
    glVertex3f( 5.0f,  -5.0f, 0.0f);
    glVertex3f( 0.0f,  -5.0f, -5.0f);

    glEnd();
	glutSwapBuffers();
}

void on_reshape(int width, int height){
	glViewport(0,0,width,height);
	glLoadIdentity();
	gluPerspective(45, (float) width/height, 1, 50);
}

void init()
{

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-10.0f, 10.0f, -10.0f, 10.0f, -10.0f, 10.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}