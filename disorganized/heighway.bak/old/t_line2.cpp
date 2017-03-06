#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
using namespace std;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))
#define NUM_V 4

typedef struct{ GLfloat location[3]; GLfloat colour[4];/* GLubyte padding[4]; */} Vertex;
void renderScene();
void changeSize(int w, int h);
void processNormalKeys(unsigned char key, int x, int y);
void initVBO();
void buildData();
Vertex verts[NUM_V];
GLuint vboID;

void renderScene(){ glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glPushMatrix();
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glEnableClientState(GL_COLOR_ARRAY); glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12)); glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	glDrawArrays(GL_LINE_STRIP,0,4);
	glDisableClientState(GL_COLOR_ARRAY); glDisableClientState(GL_VERTEX_ARRAY); glPopMatrix(); glutSwapBuffers();
}

void initVBO(){ glGenBuffers(1, &vboID); glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * NUM_V, NULL, GL_STATIC_DRAW); glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex) * NUM_V, verts);
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12)); glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
}

void buildData(){
	verts[0].location[0]	= -1;	verts[0].location[1]	= -1;	verts[0].location[2]	=  0;
	verts[1].location[0]	=  1;	verts[1].location[1]	= -1;	verts[1].location[2]	=  0;
	verts[2].location[0]	=  1;	verts[2].location[1]	=  1;	verts[2].location[2]	=  0;
	verts[3].location[0]	= -1;	verts[3].location[1]	=  1;	verts[3].location[2]	=  0;

	for (int i = 0; i < NUM_V; i++){
		verts[i].colour[0] = 0.0;
		verts[i].colour[1] = 0.0;
		verts[i].colour[2] = 0.0;
		verts[i].colour[i%3] = 1.0;
		verts[i].colour[3] = 1.0;
	}
}

void changeSize(int w, int h){ if(h==0) h=1; float ratio = 1.0 * w / h;
	glMatrixMode(GL_PROJECTION); glLoadIdentity(); glViewport(0, 0, w, h); gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity(); gluLookAt(0.0, 0.0, 5.0,0.0, 0.0,-1.0,0.0, 1.0, 0.0);
}

void processNormalKeys(unsigned char key, int x, int y){ if (key == 27) exit(0); }

int main (int argc, char * argv[]){	glutInit(&argc, argv);	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);	glutInitWindowPosition(100, 100);	glutInitWindowSize(320, 320);	glutCreateWindow("VBO Example");	glutDisplayFunc(renderScene);	glutIdleFunc(renderScene);	glutReshapeFunc(changeSize);	glutKeyboardFunc(processNormalKeys);	glEnable(GL_DEPTH_TEST);	buildData();	initVBO();	glutMainLoop();	return 0; }

