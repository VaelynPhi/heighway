#include <stdio.h>
#include <string.h>
#include <GL/glut.h>

int width = 600; int height = 600; int xc=0; int yc=0; int sz=100;
char *hei; int hs; int i; char it=4; int tra;

void re(){ xc=0; yc=0; }; void mv(int toX, int toY){ xc=toX; yc=toY; }
void up(){ glBegin(GL_LINES); glVertex2f(xc,yc); yc+=sz; glVertex2f(xc,yc); glEnd(); }
void rt(){ glBegin(GL_LINES); glVertex2f(xc,yc); xc+=sz; glVertex2f(xc,yc); glEnd(); }
void dn(){ glBegin(GL_LINES); glVertex2f(xc,yc); yc-=sz; glVertex2f(xc,yc); glEnd(); }
void lt(){ glBegin(GL_LINES); glVertex2f(xc,yc); xc-=sz; glVertex2f(xc,yc); glEnd(); }
void (*a[])(void) = {up, rt, dn, lt };

void msg(int ex, int wy, char *message){
 glRasterPos2f(ex, wy);
 int i; int sl = (int) strlen(message);
 for(i=0; i<sl; i++){ glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, message[i]); }
}

void doIt(char *h, int t){ for(i=0; i<t; i++){} }

void drawHei(){ for(i=0; i<hs; i++){ a[ hei[i] ](); } }

void mkHei(){
 hei = malloc( tra*sizeof(char) );
 hei[0]=0; hs=1;
 while(it--){
  doIt(hei,hs);
 }
}
void prep(){  tra = 2<<it;
// printf("%i %i %i\n",it,(it<<2),(2<<it));
}
void display(void){ glClear(GL_COLOR_BUFFER_BIT);
// msg(0, 24, "Hello World!");// mkHei();// drawHei();
 glFlush();
}

void init(void){ prep(); glClearColor (0.0, 0.0, 0.0, 0.0); glMatrixMode(GL_PROJECTION); glLoadIdentity(); gluOrtho2D(-width,width,-height,height); }
int main(int argc, char** argv){ glutInit(&argc, argv); glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); glutInitWindowSize(width, height); glutInitWindowPosition(100, 100); glutCreateWindow("Linear.");
 init();
 glutDisplayFunc(display); glutMainLoop(); return 0;
}
