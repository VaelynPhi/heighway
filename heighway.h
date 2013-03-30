#define BUFFER_OFFSET(i) ((char *)NULL + (i))
#define SZ_V 2*sizeof(GLfloat)

void renderScene();
void changeSize(int w, int h);
void processNormalKeys(unsigned char key, int x, int y);
void initVBO();
void compute(int n = 10);
void heighwayMain(int *argc, char **argv);

