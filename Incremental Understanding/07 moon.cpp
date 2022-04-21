/////////////////////////////////////////////////////////////////////
// circle.cpp
//
// This program draws a line loop with vertices equally apart on
// a fixed circle. The larger the number of vertices the better
// the loop approximates the circle.
//
// Interaction:
// Press +/- to increase/decrease the number of vertices of the loop.
//
// Sumanta Guha.
/////////////////////////////////////////////////////////////////////

#include <cstdlib>
#include <cmath>
#include <iostream>

#include <GL/glew.h>
#include <GL/freeglut.h>

#define PI 3.14159265358979324

// Globals.
static float R = 40.0;			 // Radius of circle.
static float X = 50.0;			 // X-coordinate of center of circle.
static float Y = 50.0;			 // Y-coordinate of center of circle.
static int numVertices = 200000; // Number of vertices on circle.

void drawSemiCircle(int R, int X, int Y)
{
	float t = 0; // Angle parameter.
	int i;

	glBegin(GL_TRIANGLE_FAN);
	glVertex3f(X, Y, 0.0);
	for (i = 0; i < numVertices; ++i)
	{
		glVertex3f(X + R * cos(t), Y + R * sin(t), 0.0);
		t += 1 * PI / numVertices; // Increment angle.
	}
	glEnd();
}

// Drawing routine.
void drawScene(void)
{
	float t = 0; // Angle parameter.
	int i;

	glClear(GL_COLOR_BUFFER_BIT);

	// Draw 2 semi-circles
	glColor3f(0, 0, 1); // Blue color.
	drawSemiCircle(40, 50, 50);

	glColor3f(1, 1, 1); // White color.
	drawSemiCircle(50, X, Y - 20);

	glFlush();
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

// Keyboard input processing routine.
// void keyInput(unsigned char key, int x, int y)
// {
// 	switch (key)
// 	{
// 	case 27:
// 		exit(0);
// 		break;
// 	case '+':
// 		numVertices++;
// 		glutPostRedisplay();
// 		break;
// 	case '-':
// 		if (numVertices > 3) numVertices--;
// 		glutPostRedisplay();
// 		break;
// 	default:
// 		break;
// 	}
// }

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
	std::cout << "Interaction:" << std::endl;
	std::cout << "Press +/- to increase/decrease the number of vertices on the circle." << std::endl;
}

// Main routine.
int main(int argc, char **argv)
{
	printInteraction();
	glutInit(&argc, argv);

	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("circle.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	// glutKeyboardFunc(keyInput);

	glewExperimental = GL_TRUE;
	glewInit();

	setup();

	glutMainLoop();
}
