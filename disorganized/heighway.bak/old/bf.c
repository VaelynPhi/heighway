#include <string.h>
#include <GL/glut.h>

void output(int x, int y, char *string){
  int len, i;
  glRasterPos2f(x, y);
  len = (int) strlen(string);
  for(i = 0; i < len; i++){ glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_10, string[i]); }
}

void display(void){
  glClear(GL_COLOR_BUFFER_BIT);
  output(0, 24, "Message.");
  glutSwapBuffers();
}

void reshape(int w, int h){
  glViewport(0, 0, w, h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, w, h, 0);
  glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char **argv){
  int i, msg_submenu, color_submenu;

  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize(500, 150);
  glutCreateWindow("GLUT bitmap font example");
  glClearColor(0.0, 0.0, 0.0, 1.0);
  glutDisplayFunc(display);
  glutReshapeFunc(reshape);
  glutMainLoop();
  return 0;             /* ANSI C requires main to return int. */
}
