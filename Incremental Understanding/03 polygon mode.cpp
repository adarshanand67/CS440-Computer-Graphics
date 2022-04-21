#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;
#define PI 3.14159265358979324

// Globals.
// static float R = 40.0; // Radius of circle.
// static float X = 75; // X-coordinate of center of circle.
// static float Y = 75; // Y-coordinate of center of circle.
// static int numVertices = 5; // Number of vertices on circle.

static float vertices[] = {
    10.0,90.0,0.0,
    10.0,10.0,0.0,
    35.0,75.0,0.0,
    30.0,10.0,0.0,
    90.0,90.0,0.0,
    80.0,40.0,0.0
};

static float colors[] = {
    1.0,0.0,0.0,
    0.0,1.0,0.0,
    0.0,0.0,1.0,
    1.0,1.0,0.0,
    1.0,0.0,1.0,
    0.0,1.0,1.0
};



// Drawing routine.
void drawScene(void)
{
    // draw square
    glClear(GL_COLOR_BUFFER_BIT);

    // Set polygon mode.
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    // Red
    glColor3f(1.0, 0.0, 0.0);

    // Draw a polygon.
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; i++)
    {
        glArrayElement(i); //glVertex3fv(vertices[i], colors[i]);
    }
    glEnd();

    glFlush();
}

// Initialization routine.
void setup(void)
{
    glClearColor(1.0, 1.0, 1.0, 0.0); // Background color to white.

    // Enable two vertex arrays: one for vertices and one for colors.
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_COLOR_ARRAY);

    // Specify locations for the co-ordinates and color arrays.
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glColorPointer(3, GL_FLOAT, 0, colors);
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
    // cout << "Interaction:" << endl;
    // cout << "Press +/- to increase/decrease the number of vertices on the circle." << endl;
}

// Main routine.
int main(int argc, char** argv)
{
    printInteraction();    // Output instructions.
    glutInit(&argc, argv); // Initialize GLUT.

    glutInitContextVersion(4, 3);                       // Specify OpenGL version.
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE); // Specify compatibility profile.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);       // Display mode.
    glewExperimental = GL_TRUE;                         // Experimental feature.

    glutInitWindowSize(640, 480);     // Window size (pixels).
    glutInitWindowPosition(100, 100); // Position the window's initial top-left corner.
    glutCreateWindow("Adarsh Anand"); // Create window with the given title.

    glutDisplayFunc(drawScene); // Register display callback handler for window re-paint.
    glutReshapeFunc(resize);    // Register reshape callback handler for window re-size.
    // glutKeyboardFunc(keyInput);

    glewInit();     // Initialize GLEW.
    setup();        // Setup rendering context.
    glutMainLoop(); // Enter the event-processing loop.
}
