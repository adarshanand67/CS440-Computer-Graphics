#include <cstdlib>
#include <cmath>
#include <iostream>
#include <GL/glew.h>
#include <GL/freeglut.h>

using namespace std;
#define PI 3.14159265358979324

// ------ Global Variables ------
// static float R = 40.0; // Radius of circle.
// static float X = 50.0; // X-coordinate of center of circle.
// static float Y = 50.0; // Y-coordinate of center of circle.
// static int numVertices = 5; // Number of vertices on circle.

// Drawing routine declaration.
void drawScene(void)
{
    // ------ Draw scene here -------

    glClear(GL_COLOR_BUFFER_BIT);

    glFlush();
}

// Mouse callback routine.
void mouseControl(int button, int state, int x, int y)
{
    // ------ Mouse control here -------
    // if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)

    // 	// Store the clicked point in the points array after correcting from event to OpenGL co-ordinates.
    // 	points.push_back(Point(x, height - y, pointSize));

    // if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) exit(0);

    glutPostRedisplay();
}

// Mouse motion callback routine.
void mouseMotion(int x, int y)
{
    // ------ Mouse motion here -------
    // Update the location of the current point as the mouse moves with button pressed.
    // currentPoint.setCoords(x, height - y);

    glutPostRedisplay();
}

// Mouse wheel callback routine.
void mouseWheel(int wheel, int direction, int x, int y)
{
    // ------ Mousewheel callback routine -------
    // Increment/decrement size of current point (at the back of vector points)
    // // depending on the direction of rotation of the mouse wheel.

    // (direction > 0) ? tempSize++ : tempSize--;
    // points.back().setSize(tempSize);

    glutPostRedisplay();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
    // ----- Window Resize & Projections here -----
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, 0.0, h, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Keyboard input processing routine (normal keys).
void keyInput(unsigned char key, int x, int y)
{
    // ------ Keyboard input processing here -------
    switch (key)
    {
    case 27: // Escape key
        exit(0);
        break;
    default:
        break;
    }
}

// Callback routine for non-ASCII key entry.
void specialKeyInput(int key, int x, int y)
{
    // ------ Non-ASCII keyboard input processing here -------

    // if (key == GLUT_KEY_UP) Yvalue += 0.1;
    // if (key == GLUT_KEY_DOWN) Yvalue -= 0.1;
    // if (key == GLUT_KEY_LEFT) Xvalue -= 0.1;
    // if (key == GLUT_KEY_RIGHT) Xvalue += 0.1;
    // if(key == GLUT_KEY_PAGE_UP) Rvalue += 0.1;
    // if(key == GLUT_KEY_PAGE_DOWN) Rvalue -= 0.1;
    // if(key == GLUT_KEY_HOME) numVertices += 1;
    // if(key == GLUT_KEY_END) numVertices -= 1;
    // if(key == GLUT_KEY_F1) pointSize += 1;
    // if(key == GLUT_KEY_F2) pointSize -= 1;
    // glutPostRedisplay();
}

// The top menu callback function.
void top_menu(int id)
{
    if (id == 1)
        exit(0);
}

// The sub-menu callback function.
void color_menu(int id)
{
    if (id == 2)
    {
        square_color[0] = 1.0;
        square_color[1] = 0.0;
        square_color[2] = 0.0;
    }
    if (id == 3)
    {
        square_color[0] = 0.0;
        square_color[1] = 0.0;
        square_color[2] = 1.0;
    }
    if (id == 4)
    {
        square_color[0] = 0.0;
        square_color[1] = 1.0;
        square_color[2] = 0.0;
    }
    glutPostRedisplay();
}

// Routine to make the menu.
void makeMenu(void)
{
    // The sub-menu is created first (because it should be visible when the top
    // menu is created): its callback function is registered and menu entries added.
    int sub_menu;
    sub_menu = glutCreateMenu(color_menu);
    glutAddMenuEntry("Red", 2);
    glutAddMenuEntry("Blue", 3);
    // green
    glutAddMenuEntry("Green", 4);

    // The top menu is created: its callback function is registered and menu entries,
    // including a submenu, added.
    glutCreateMenu(top_menu);
    glutAddSubMenu("Color", sub_menu);
    glutAddMenuEntry("Quit", 1);

    // The menu is attached to a mouse button.
    glutAttachMenu(GLUT_RIGHT_BUTTON);
}

// Initialization routine.
void setup(void)
{
    // ------ Initialize scene here -------
    glClearColor(1.0, 1.0, 1.0, 0.0); // Background color to white.
    makeMenu();
}

// Routine to output interaction instructions to the C++ window.
void printInteraction(void)
{
    // ------ Interaction instructions here ------
    // cout << "Interaction:" << endl;
    // cout << "Press +/- to increase/decrease the number of vertices on the circle." << endl;
}

// Main routine.
int main(int argc, char **argv)
{
    printInteraction();    // Output instructions.
    glutInit(&argc, argv); // Initialize GLUT.

    glutInitContextVersion(4, 3);                              // Specify OpenGL version.
    glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);        // Specify compatibility profile.
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // Display mode.

    glutInitWindowSize(640, 480);     // Window size (pixels).
    glutInitWindowPosition(100, 100); // Position the window's initial top-left corner.
    glutCreateWindow("Adarsh Anand"); // Create window with the given title.

    // ------ Callback functions here ------
    glutDisplayFunc(drawScene); // Register display callback handler window re-paint.
    glutReshapeFunc(resize);    // Register reshape callback handler

    glutKeyboardFunc(keyInput);       // Register keyboard callback handler.
    glutSpecialFunc(specialKeyInput); // Register the callback function for non-ASCII key

    glutMouseFunc(mouseControl); // Register the mouse callback function.
    glutMotionFunc(mouseMotion); // Register the mouse motion callback function.
    // glutPassiveMotionFunc(mouseMotion);
    glutMouseWheelFunc(mouseWheel); // Register the mouse wheel callback function.

    glewExperimental = GL_TRUE; // Experimental feature.
    glewInit();                 // Initialize GLEW.
    setup();                    // Setup rendering context.
    glutMainLoop();             // Enter the event-processing loop.
}
