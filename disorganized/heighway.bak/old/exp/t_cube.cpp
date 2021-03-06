#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
using namespace std;

typedef struct{ // Vertex structure
	GLfloat location[3];	//  0 3	// glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	GLfloat colour[4];	// 12 4 // glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(32));
	GLubyte padding[4];	// 28 1 // up to 32
} Vertex;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))

void renderScene();
void changeSize(int w, int h);
void processNormalKeys(unsigned char key, int x, int y);
void initVBO();
void buildCube();

Vertex verts[24];	// We're making a cube, 6 faces * 4 verticies per face
GLubyte index[36];	// 2 Triangles per face (possible to use quads, but they're being phased out of OpenGL3, so we're using triangles instead)
GLuint vboID;
GLuint indexVBOID;

int main (int argc, char * argv[]){	glutInit(&argc, argv);	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);	glutInitWindowPosition(100, 100);	glutInitWindowSize(320, 320);	glutCreateWindow("VBO Example");	glutDisplayFunc(renderScene);	glutIdleFunc(renderScene);	glutReshapeFunc(changeSize);	glutKeyboardFunc(processNormalKeys);	glEnable(GL_DEPTH_TEST);	buildCube();	initVBO();	glutMainLoop();	return 0; }

void renderScene(){ glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glPushMatrix();
	glBindBuffer(GL_ARRAY_BUFFER, vboID);	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);
	glEnableClientState(GL_COLOR_ARRAY);	glEnableClientState(GL_VERTEX_ARRAY);
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));	
// Draw: (Primative (Triangles, Quads, Triangle Fans etc), # of elements to draw, type of each element, start offset)
	glDrawElements(GL_TRIANGLES, 36, GL_UNSIGNED_BYTE, BUFFER_OFFSET(0));
	glDisableClientState(GL_COLOR_ARRAY);	glDisableClientState(GL_VERTEX_ARRAY);	glPopMatrix();	glutSwapBuffers();
}

void changeSize(int w, int h){ if(h==0) h=1; float ratio = 1.0 * w / h;
	glMatrixMode(GL_PROJECTION); glLoadIdentity(); glViewport(0, 0, w, h); gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity(); gluLookAt(0.0, 0.0, 5.0,0.0, 0.0,-1.0,0.0, 1.0, 0.0);
}

void processNormalKeys(unsigned char key, int x, int y){ if (key == 27) exit(0); }

void initVBO(){
	glGenBuffers(1, &vboID); glBindBuffer(GL_ARRAY_BUFFER, vboID); // Bind the buffer (vertex array data)
	glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex) * 24, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(Vertex) * 24, verts);
	
	glColorPointer(4, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(12));
	glVertexPointer(3, GL_FLOAT, sizeof(Vertex), BUFFER_OFFSET(0));
	
	glGenBuffers(1, &indexVBOID); glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexVBOID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, 36 * sizeof(GLubyte), index, GL_STATIC_DRAW);
}

void buildCube(){
// Top
	verts[0].location[0]	=  1;	verts[0].location[1]	=  1;	verts[0].location[2]	= -1;
	verts[1].location[0]	= -1;	verts[1].location[1]	=  1;	verts[1].location[2]	= -1;
	verts[2].location[0]	= -1;	verts[2].location[1]	=  1;	verts[2].location[2]	=  1;
	verts[3].location[0]	=  1;	verts[3].location[1]	=  1;	verts[3].location[2]	=  1;
// Bottom
	verts[4].location[0]	=  1;	verts[4].location[1]	= -1;	verts[4].location[2]	=  1;
	verts[5].location[0]	= -1;	verts[5].location[1]	= -1;	verts[5].location[2]	=  1;
	verts[6].location[0]	= -1;	verts[6].location[1]	= -1;	verts[6].location[2]	= -1;
	verts[7].location[0]	=  1;	verts[7].location[1]	= -1;	verts[7].location[2]	= -1;
// Front
	verts[8].location[0]	=  1;	verts[8].location[1]	=  1;	verts[8].location[2]	=  1;
	verts[9].location[0]	= -1;	verts[9].location[1]	=  1;	verts[9].location[2]	=  1;
	verts[10].location[0]	= -1;	verts[10].location[1]	= -1;	verts[10].location[2]	=  1;
	verts[11].location[0]	=  1;	verts[11].location[1]	= -1;	verts[11].location[2]	=  1;
// Back
	verts[12].location[0]	=  1;	verts[12].location[1]	= -1;	verts[12].location[2]	= -1;
	verts[13].location[0]	= -1;	verts[13].location[1]	= -1;	verts[13].location[2]	= -1;
	verts[14].location[0]	= -1;	verts[14].location[1]	=  1;	verts[14].location[2]	= -1;
	verts[15].location[0]	=  1;	verts[15].location[1]	=  1;	verts[15].location[2]	= -1;
// Left
	verts[16].location[0]	= -1;	verts[16].location[1]	=  1;	verts[16].location[2]	=  1;
	verts[17].location[0]	= -1;	verts[17].location[1]	=  1;	verts[17].location[2]	= -1;
	verts[18].location[0]	= -1;	verts[18].location[1]	= -1;	verts[18].location[2]	= -1;
	verts[19].location[0]	= -1;	verts[19].location[1]	= -1;	verts[19].location[2]	=  1;
// Right
	verts[20].location[0]	=  1;	verts[20].location[1]	=  1;	verts[20].location[2]	= -1;
	verts[21].location[0]	=  1;	verts[21].location[1]	=  1;	verts[21].location[2]	=  1;
	verts[22].location[0]	=  1;	verts[22].location[1]	= -1;	verts[22].location[2]	=  1;
	verts[23].location[0]	=  1;	verts[23].location[1]	= -1;	verts[23].location[2]	= -1;
// Colours
	for (int i = 0; i < 24; i++){
		verts[i].colour[0] = 1.0;
		verts[i].colour[1] = 1.0;
		verts[i].colour[2] = 1.0;
		verts[i].colour[3] = 1.0;
	}

// Index Array (define our triangles); A Face looks like (numbers are the array index number of the vertex)
	index[0]  =  0;	index[1]  =  1;	index[2]  =  2;	index[3]  =  2;	index[4]  =  3;	index[5]  =  0;
	index[6]  =  4;	index[7]  =  5;	index[8]  =  6;	index[9]  =  6;	index[10] =  7;	index[11] =  4;
	index[12] =  8;	index[13] =  9;	index[14] = 10;	index[15] = 10;	index[16] = 11;	index[17] =  8;
	index[18] = 12;	index[19] = 13;	index[20] = 14;	index[21] = 14;	index[22] = 15;	index[23] = 12;
	index[24] = 16;	index[25] = 17;	index[26] = 18;	index[27] = 18;	index[28] = 19;	index[29] = 16;
	index[30] = 20;	index[31] = 21;	index[32] = 22;	index[33] = 22;	index[34] = 23;	index[35] = 20;
	// +--+
	// |12|
	// |03|
	// +--+
}
