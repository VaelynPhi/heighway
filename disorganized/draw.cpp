#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
#include "heighway.h"

using namespace std;

GLuint vboID;
int nv=5;
int ne=2*nv;

GLfloat *vs;

void buildData(){
	vs = (GLfloat*) malloc(nv*SZ_V);

	vs[ 0] = 0;	vs[ 1] = 0;
	vs[ 2] = 0;	vs[ 3] = 1; //F
	vs[ 4] = 1;	vs[ 5] = 1;
	vs[ 6] = 1;	vs[ 7] = 0;
	vs[ 8] = 2;	vs[ 9] = 0;

}

void renderScene(){
	glClear(GL_COLOR_BUFFER_BIT); //	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glPushMatrix();
	glTranslatef(0,0,-10);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
//	glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_VERTEX_ARRAY);

//	glColorPointer(4, GL_FLOAT, SZ_V, BUFFER_OFFSET(12));
	glVertexPointer(2, GL_FLOAT, SZ_V, BUFFER_OFFSET(0));

	glDrawArrays(GL_LINE_STRIP,0,nv);
//	glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY); glPopMatrix(); glutSwapBuffers();
}

void initVBO(){
	glGenBuffers(1, &vboID);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, (nv*SZ_V), NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, (nv*SZ_V), vs);
//	glColorPointer(4, GL_FLOAT, SZ_V, BUFFER_OFFSET(12)); // 4 bytes = 1 GLfloat
	glVertexPointer(2, GL_FLOAT, SZ_V, BUFFER_OFFSET(0));
}

void changeSize(int w, int h){
 if(h==0) h=1;
 float ratio = 1.0 * w / h;
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 glViewport(0, 0, w, h);
 gluPerspective(45, ratio, 1, 1000);
 glMatrixMode(GL_MODELVIEW);
 glLoadIdentity();
// gluLookAt(0.0, 0.0, 5.0,0.0, 0.0,-1.0,0.0, 1.0, 0.0);
}

void processNormalKeys(unsigned char key, int x, int y){ if (key == 27) exit(0); }

void heighwayMain(int *argc, char **argv){
	glutInit(argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("Heighway Dragon");
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glEnable(GL_DEPTH_TEST);
	glDisable(GL_DEPTH_TEST);

	buildData();

	initVBO();
	glutMainLoop();
}
