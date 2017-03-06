#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
using namespace std;

typedef struct{ // Vertex structure
	GLfloat location[3];	//  0 3	// glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	GLfloat colour[4];	// 12 4 // glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(32));
//	GLubyte padding[4];	// 28 1 // up to 32
} Vertex;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

void renderScene();
void changeSize(int w, int h);
void processNormalKeys(unsigned char key, int x, int y);
void initVBO();
void buildCube();

Vertex verts[4];
GLubyte index[5];
GLuint vboID;
GLuint indexVBOID;

int main (int argc, char * argv[]){	glutInit(&argc, argv);	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);	glutInitWindowPosition(100, 100);	glutInitWindowSize(320, 320);	glutCreateWindow("VBO Example");	glutDisplayFunc(renderScene);	glutIdleFunc(renderScene);	glutReshapeFunc(changeSize);	glutKeyboardFunc(processNormalKeys);	glEnable(GL_DEPTH_TEST);	buildCube();	initVBO();	glutMainLoop();	return 0; }

void renderScene(){ glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glPushMatrix();
	glBindBuffer(GL_ARRAY_BUFFER, vboID);	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);
	glEnableClientState(GL_COLOR_ARRAY);	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));	
// Draw: (Primative (Triangles, Quads, Triangle Fans etc), # of elements to draw, type of each element, start offset)
	glDrawElements(GL_LINE_STRIP, 5, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	glDisableClientState(GL_COLOR_ARRAY);	glDisableClientState(GL_VERTEX_ARRAY);	glPopMatrix();	glutSwapBuffers();
}

void initVBO(){
	glGenBuffers(1, &vboID); glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind the buffer (vertex array data)
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 4, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex) * 4, verts);
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	glGenBuffers(1, &indexVBOID); glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 5 * sizeof(GLubyte), index, GL_STATIC_DRAW);
}

void buildCube(){
	verts[0].location[0]	= -1;	verts[0].location[1]	= -1;	verts[0].location[2]	=  0;
	verts[1].location[0]	=  1;	verts[1].location[1]	= -1;	verts[1].location[2]	=  0;
	verts[2].location[0]	=  1;	verts[2].location[1]	=  1;	verts[2].location[2]	=  0;
	verts[3].location[0]	= -1;	verts[3].location[1]	=  1;	verts[3].location[2]	=  0;
// Colours
	for (int i = 0; i < 4; i++){
		verts[i].colour[0] = 0.0;
		verts[i].colour[1] = 0.0;
		verts[i].colour[2] = 0.0;
		verts[i].colour[i%3] = 1.0;
		verts[i].colour[3] = 1.0;
	}

	index[0]= 0;
	index[1]= 1;
	index[2]= 2;
	index[3]= 3;
	index[4]= 0;
}

void changeSize(int w, int h){ if(h==0) h=1; float ratio = 1.0 * w / h;
	glMatrixMode(GL_PROJECTION); glLoadIdentity(); glViewport(0, 0, w, h); gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity(); gluLookAt(0.0, 0.0, 5.0,0.0, 0.0,-1.0,0.0, 1.0, 0.0);
}

void processNormalKeys(unsigned char key, int x, int y){ if (key == 27) exit(0); }
