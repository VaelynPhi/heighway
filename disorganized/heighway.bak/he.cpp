#include <iostream>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <GL/freeglut.h>
using namespace std;

#define BUFFER_OFFSET(i) ((char *)NULL + (i))
#define NUM_V 4
#define NUM_E 7*NUM_V
#define SZ_V 7*sizeof(GLfloat)
#define SZ_T NUM_V*SZ_V

void renderScene();
void changeSize(int w, int h);
void processNormalKeys(unsigned char key, int x, int y);
void initVBO();
void buildData();
GLuint vboID;
//GLfloat vs[NUM_E];

GLfloat vs[NUM_E] = {
-1,-1, 0, 1.0,1.0,1.0,1.0,
 1,-1, 0, 1.0,1.0,1.0,1.0,
 1, 1, 0, 1.0,1.0,1.0,1.0,
-1, 1, 0, 1.0,1.0,1.0,1.0
};

void buildData(){
//	vs[ 0]= -1;	vs[ 1]= -1;	vs[ 2]=  0;	vs[ 3]=1.0;	vs[ 4]=1.0;	vs[ 5]=1.0;	vs[ 6]=1.0;
//	vs[ 7]=  1;	vs[ 8]= -1;	vs[ 9]=  0;	vs[10]=1.0;	vs[11]=1.0;	vs[12]=1.0;	vs[13]=1.0;
//	vs[14]=  1;	vs[15]=  1;	vs[16]=  0;	vs[17]=1.0;	vs[18]=1.0;	vs[19]=1.0;	vs[20]=1.0;
//	vs[21]= -1;	vs[22]=  1;	vs[23]=  0;	vs[24]=1.0;	vs[25]=1.0;	vs[26]=1.0;	vs[27]=1.0;
}

void renderScene(){ glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); glPushMatrix();
	glTranslatef(0,0,-10);
	glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glEnableClientState(GL_COLOR_ARRAY); glEnableClientState(GL_VERTEX_ARRAY);

	glColorPointer(4, GL_FLOAT, SZ_V, BUFFER_OFFSET(12));
	glVertexPointer(3, GL_FLOAT, SZ_V, BUFFER_OFFSET(0));

	glDrawArrays(GL_LINE_STRIP,0,NUM_V);
	glDisableClientState(GL_COLOR_ARRAY); glDisableClientState(GL_VERTEX_ARRAY); glPopMatrix(); glutSwapBuffers();
}

void initVBO(){ glGenBuffers(1, &vboID); glBindBuffer(GL_ARRAY_BUFFER, vboID);
	glBufferData(GL_ARRAY_BUFFER, SZ_T, NULL, GL_STATIC_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, SZ_T, vs);
	glColorPointer(4, GL_FLOAT, SZ_V, BUFFER_OFFSET(12)); // 4 bytes = 1 GLfloat
	glVertexPointer(3, GL_FLOAT, SZ_V, BUFFER_OFFSET(0));
}

void changeSize(int w, int h){ if(h==0) h=1; float ratio = 1.0 * w / h;
	glMatrixMode(GL_PROJECTION); glLoadIdentity(); glViewport(0, 0, w, h); gluPerspective(45, ratio, 1, 1000);
	glMatrixMode(GL_MODELVIEW); glLoadIdentity(); gluLookAt(0.0, 0.0, 5.0,0.0, 0.0,-1.0,0.0, 1.0, 0.0);
}

void processNormalKeys(unsigned char key, int x, int y){ if (key == 27) exit(0); }

int main (int argc, char * argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(320, 320);
	glutCreateWindow("VBO Example");
	glutDisplayFunc(renderScene);
	glutIdleFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutKeyboardFunc(processNormalKeys);
	glEnable(GL_DEPTH_TEST);
	buildData();
	initVBO();
	glutMainLoop();
	return 0;
}
