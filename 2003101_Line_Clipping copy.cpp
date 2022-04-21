/*

    CS440 - Computer Graphics

    This code is written as an assignment under prof Dr. Venkatesh Kamat.

    Author: Adarsh Anand

    Roll No: 2003101

    1. Given series of line segments and a rectangular clipping window, clip the line against the clipping window using Sutherland-Cohen line clipping algorithm.

*/
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <stdlib.h>
#include <stdio.h>

// Global variables
static int slices = 16, stacks = 16;
int click = 0, nxyget = 0;
bool checking = true;
int zone;
int x0, y0, x1, y1;
int x0Click, y0Click, x1Click, y1Click;
int gp = 60, xl = -320, yl = -240, xr = 319, yr = 239;
int xmax = xr - gp, xmin = xl + gp, ymax = yr - gp, ymin = yl + gp;
bool writen = false;

int making_code(int x, int y)
{ // Making code for the zone of the point (x,y)
  // Converting binary numbers to decimal
    int code = 0;
    if (y > ymax)
        code += 8;
    else if (y < ymin)
        code += 4;
    if (x > xmax)
        code += 2;
    else if (x < xmin)
        code += 1;
    return code;
}

void get_zone(int x0, int y0, int x1, int y1)
{ // Get the zone of the line
    int dX = x1 - x0;
    int dY = y1 - y0;
    if (dX >= 0 && dY >= 0)
    {
        if (dX > dY)
            zone = 0;
        else
            zone = 1;
    }
    else if (dX < 0 && dY >= 0)
    {
        if (abs(dX) > dY)
            zone = 3;
        else
            zone = 2;
    }
    else if (dX < 0 && dY < 0)
    {
        if (abs(dX) > abs(dY))
            zone = 4;
        else
            zone = 5;
    }
    else if (dX >= 0 && dY < 0)
    {
        if (dX > abs(dY))
            zone = 7;
        else
            zone = 6;
    }
}
>=
void drawingLines(int x0, int y0, int x1, int y1, int zone)
{ // Drawing the lines
    int dX = x1 - x0;
    int dY = y1 - y0;
    int x = x0, y = y0;
    int d = 2 * dY - dX;
    int dE = 2 * dY, dNE = 2 * (dY - dX);
    // glVertex2i(x,y);
    while (x < x1)
    {
        if (d < 0)
        {
            x++;
            d += dE;
        }
        else
        {
            x++;
            y++;
            d += dNE;
        }
        if (zone == 0)
            glVertex2i(x, y);
        else if (zone == 1)
            glVertex2i(y, x);
        else if (zone == 2)
            glVertex2i(-y, x);
        else if (zone == 3)
            glVertex2i(-x, y);
        else if (zone == 4)
            glVertex2i(-x, -y);
        else if (zone == 5)
            glVertex2i(-y, -x);
        else if (zone == 6)
            glVertex2i(y, -x);
        else if (zone == 7)
            glVertex2i(x, -y);
    }
}
void drawingLines(int x0, int y0, int x1, int y1)
{ // Drawing the lines
    get_zone(x0, y0, x1, y1);
    if (zone == 0)
    {
        drawingLines(x0, y0, x1, y1, zone);
    }
    else if (zone == 1)
    {
        drawingLines(y0, x0, y1, x1, zone);
    }
    else if (zone == 2)
    {
        // glColor3f(0,0,1);
        drawingLines(y0, -x0, y1, -x1, zone);
    }
    else if (zone == 3)
    {
        // glColor3f(1,1,0);
        drawingLines(-x0, y0, -x1, y1, zone);
    }
    else if (zone == 4)
    {
        // glColor3f(1,0,1);
        drawingLines(-x0, -y0, -x1, -y1, zone);
    }
    else if (zone == 5)
    {
        // glColor3f(0,1,1);
        drawingLines(-y0, -x0, -y1, -x1, zone);
    }
    else if (zone == 6)
    {
        // glColor3f(1,1,1);
        drawingLines(-y0, x0, -y1, x1, zone);
    }
    else if (zone == 7)
    {
        // glColor3f(0.6,0.5,0.4);
        drawingLines(x0, -y0, x1, -y1, zone);
    }
}
void mouse(int button, int state, int mousex, int mousey)
{ // Mouse function for the click
    int x, y;
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
    {
        checking = true;
        x = mousex - 320;
        y = 240 - mousey;
        if (click == 0)
        {
            x0Click = x0 = x;
            y0Click = y0 = y;
            click = 1;
            nxyget = 0;
        }
        else if (click == 1)
        {
            x1Click = x1 = x;
            y1Click = y1 = y;
            click = 2;
            writen = false;
        }
        else
        {
            x0Click = x0 = x;
            y0Click = y0 = y;
            click = 1;
            nxyget = 0;
        }
        printf("%d %d %d %d\n", x0, y0, x1, y1);
    }
    glutPostRedisplay();
}
void CohenSutherLand()
{ // Cohen-SutherLand algorithm for the line
    int code0, code1, code;
    int x, y;
    int top = 8, bottom = 4, left = 1, right = 2;
    code0 = making_code(x0, y0);
    code1 = making_code(x1, y1);
    while (1)
    {
        if (!(code0 | code1))
        {
            nxyget = 1;
            drawingLines(x0, y0, x1, y1);
            if (!writen)
                printf("Completely Accepted\n"), writen = true;
            break;
        }
        else if (code0 & code1)
        {
            if (!writen)
                printf("Completely Rejected\n"), writen = true;
            break;
        }
        else
        {
            if (!writen)
                printf("Partially Accepted\n"), writen = true;
            if (code0)
                code = code0;
            else
                code = code1;
            if (code & top)
            {
                y = ymax;
                x = x0 + ((y - y0) * (x1 - x0)) / (y1 - y0);
            }
            else if (code & bottom)
            {
                y = ymin;
                x = x0 + ((y - y0) * (x1 - x0)) / (y1 - y0);
            }
            else if (code & left)
            {
                x = xmin;
                y = y0 + ((x - x0) * (y1 - y0)) / (x1 - x0);
            }
            else
            {
                x = xmax;
                y = y0 + ((x - x0) * (y1 - y0)) / (x1 - x0);
            }
            if (code == code0)
            {
                x0 = x;
                y0 = y;
                code0 = making_code(x0, y0);
            }
            else if (code == code1)
            {
                x1 = x;
                y1 = y;
                code1 = making_code(x1, y1);
            }
        }
    }
}
static void resize(int width, int height)
{                                                  // Resize function for the window
    const float ar = (float)width / (float)height; // aspect ratio
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-320, 319, -240, 239, -1, 1);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

static void display(void)
{
    // display function for the window

    glClear(GL_COLOR_BUFFER_BIT);
    glColor3d(0.51, 0.31, 0.61);

    glBegin(GL_LINES);
    glVertex2i(xl + gp, yl + gp);
    glVertex2i(xl + gp, yr - gp);
    glVertex2i(xl + gp, yr - gp);
    glVertex2i(xr - gp, yr - gp);
    glVertex2i(xr - gp, yr - gp);
    glVertex2i(xr - gp, yl + gp);
    glVertex2i(xr - gp, yl + gp);
    glVertex2i(xl + gp, yl + gp);
    glEnd();

    glPointSize(9.0);

    glBegin(GL_POINTS);
    if (click == 1)
    { // if click is 1 then draw the first point
        glVertex2i(x0Click, y0Click);
    }
    else if (nxyget == 0 and click == 2)
    { // if click is 2 then draw the second point
        glVertex2i(x0Click, y0Click);
        glVertex2i(x1Click, y1Click);
    }
    else if (nxyget == 1 and click == 2)
    { // if click is 2 then draw the second point and the line
        glVertex2i(x0Click, y0Click);
        glVertex2i(x1Click, y1Click);
        glVertex2i(x0, y0);
        glVertex2i(x1, y1);
    }
    glEnd();

    glPointSize(6.0);

    glBegin(GL_POINTS);
    if (click == 2)
    { // if click is 2 then draw the second point and the line
        glColor3f(1, 0, 0);
        drawingLines(x0Click, y0Click, x1Click, y1Click);

        glColor3f(1, 1, 1);
        CohenSutherLand();
    }
    glEnd();

    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv); // Initialize GLUT

    glutInitWindowSize(640, 480);   // Set the window's initial width & height
    glutInitWindowPosition(10, 10); // Position the window's initial top-left corner

    glutInitDisplayMode(GLUT_RGB);                                   // Enable double buffered mode
    glutCreateWindow("Adarsh Anand - CSE 2003101 - Clipping lines"); // Create window with the given title

    glutReshapeFunc(resize); // Register callback handler for window re-size event

    glutDisplayFunc(display);
    glutMouseFunc(mouse);

    glutMainLoop(); // Enter the infinite event-processing loop
}