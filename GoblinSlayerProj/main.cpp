#include "IncludeS.h"
#include "Terrain.h"

//global variables
static int gWinWidth = 1000;
static int gWinHeight = 600;
static unsigned int gViewMode = 0;

Terrain myTerrain;


void draw() {

	glClear(GL_COLOR_BUFFER_BIT);

	//draw terrain
	myTerrain.drawTerrain();

	glFlush();
}

void init() {
	//make the background look like the sky
	float blue[4] = { 0.5,0.5,1.0,0.0 };
	glClearColor(blue[0], blue[1], blue[2], blue[3]);

	//glShadeModel(GL_SMOOTH);

	//initial terrain
	myTerrain.initializeTerrain("Data/Texture/Terrain/sand.tga", "Data/Texture/Terrain/cactus.tga");

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// use depth buffer
	glEnable(GL_DEPTH_TEST);
	
}

void idle() {
	// call function which is registered for glutDisplayFunc
	glutPostRedisplay();	
}


void reshape(int width, int height)
{
	gWinWidth = width;
	gWinHeight = height;

	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, (GLfloat)width / (GLfloat)height, 0.1, 1000.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGB);
	
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(gWinWidth, gWinHeight);
	glutCreateWindow("GoblinSlayer");
	
	init();
	glutDisplayFunc(draw);
	//glutReshapeFunc(reshape);
	// 현재 처리하는 이벤트 없을 때, 넘겨 받은 함수 실행
	//glutIdleFunc(idle);
	// 키 입력
	//glutKeyboardFunc(keyboard);
	glutMainLoop();

	return 0;
}