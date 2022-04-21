#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
using namespace std;

#define PI 3.14159265
int theta = 270;

// defines the class camera
class Camera
{
public:
	Camera();
	float x_coordinate;
	float y_coordinate;
	float z_coordinate;
};

// Global camera.
Camera camera;

float centerx_coordinate = -20;
float centery_coordinate = 10;
float centerz_coordinate = 0;

// Camera constructor.
Camera::Camera()
{
	x_coordinate = -20;
	y_coordinate = 10;
	z_coordinate = 40;
}

void draw_horse(float x, float y, float z)
{
	// horse main body
	glPushMatrix();
	float color[] = {0.58, 0.29, 0.05};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
	glTranslatef(x, y, z);
	glScalef(10, 4, 4);
	glutSolidCube(1);
	glPopMatrix();

	//  legs  start
	glPushMatrix();
	glTranslatef(x - 4.5, y - 4, z + 2);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x - 4.5, y - 4, z - 2);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 4.5, y - 4, z + 2);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glTranslatef(x + 4.5, y - 4, z - 2);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	// legs ends

	glPushMatrix();
	float color1[] = {0.58, 0.29, 0.15};
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1);
	glTranslatef(x + 5, y + 4, z);
	glRotatef(-45, 0, 0, 1);
	glScalef(2, 5, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1);
	glTranslatef(x + 7, y + 4, z);
	glRotatef(45, 0, 0, 1);
	glScalef(2.2, 3.2, 2.2);
	glutSolidCube(1);
	glPopMatrix();
}

void drawScene(void)
{
	glColor3f(0.0, 0.0, 0.0); // set the color to black
	glLoadIdentity();		  // reset the current matrix to the identity matrix

	glEnable(GL_LIGHTING);								   // enable lighting
	glEnable(GL_LIGHT0);								   // enable light 0
	glEnable(GL_LIGHT0);								   // enable light 1
	GLfloat light_ambient[] = {0.2f, 0.2f, 0.2f, 1.0f};	   // ambient light
	GLfloat light_diffuse[] = {0.8f, 0.8f, 0.8f, 1.0f};	   // diffuse light
	GLfloat light_specular[] = {0.5f, 0.5f, 0.5f, 1.0f};   // specular light
	GLfloat light_position[] = {-1.5f, 1.0f, -4.0f, 1.0f}; // light position
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);	   // set the ambient light
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);	   // set the diffuse light
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);	   // set the specular light
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);	   // set the light position

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // set the display mode
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);		   // clear the color buffer and the depth buffer
	glEnable(GL_DEPTH_TEST);								   // enable the depth test
	gluLookAt(camera.x_coordinate, camera.y_coordinate, camera.z_coordinate,
			  centerx_coordinate, centery_coordinate, centerz_coordinate,
			  0.0, 1.0, 0.0); // set the camera position
	draw_horse(0, 10, 4);	  // draw the horse

	glPushMatrix();										   // push the matrix
	float color[] = {0.41, 0.55, 0.137};				   // set the color to brown
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color); // set the material to brown
	glTranslatef(0, 2.5, 0);							   // move the horse up
	glScalef(200, 1, 200);								   // scale the horse
	glutSolidCube(1);									   // draw the cube
	glPopMatrix();										   // pop the matrix
	glFlush();											   // flush the buffer
}

// Initialization routine.
void setup(void)
{
	glClearColor(1.0, 1.0, 1.0, 0.0);
	camera = Camera();
}

// OpenGL window reshape routine.
void resize(int w, int h)
{
	glViewport(0, 0, w, h);						 // Set viewport to entire window
	glMatrixMode(GL_PROJECTION);				 // Switch to projection matrix
	glLoadIdentity();							 // Reset projection matrix
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 200.0); // Set perspective projection viewing frustum
	glMatrixMode(GL_MODELVIEW);					 // Switch to modelview matrix
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27: // ESC key
		exit(0);
		break;

	case 'w': // forward
		camera.x_coordinate += cos((theta)*PI / (float)180);
		camera.z_coordinate += sin((theta)*PI / (float)180);

		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
		glutPostRedisplay();
		break;

	case 's': // backward
		camera.x_coordinate -= cos((theta)*PI / (float)180);
		camera.z_coordinate -= sin((theta)*PI / (float)180);
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
		glutPostRedisplay();
		break;

	case 'a': // left
		theta = ((theta - 5) % 360 + 360) % 360;
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
		glutPostRedisplay();
		break;

	case 'd': // right
		theta = ((theta + 5) % 360 + 360) % 360;
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
		glutPostRedisplay();
		break;

	default: // do nothing
		break;
	}
}

void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN) // Pressing Key Down Arrow
	{
		camera.y_coordinate--;
		centery_coordinate--;
	}
	if (key == GLUT_KEY_UP) // Pressing Key Up Arrow
	{
		camera.y_coordinate++;
		centery_coordinate++;
	}
	if (key == GLUT_KEY_RIGHT) // Pressing Key Right Arrow
	{
		camera.x_coordinate += cos((theta + 90) * PI / (float)180);
		camera.z_coordinate += sin((theta + 90) * PI / (float)180);
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
	}
	if (key == GLUT_KEY_LEFT) // Pressing Key Left Arrow
	{
		camera.x_coordinate -= cos((theta + 90) * PI / (float)180);
		camera.z_coordinate -= sin((theta + 90) * PI / (float)180);
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
	}
	glutPostRedisplay(); // Redrawing the scene
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);									   // Initialize GLUT
	glutInitContextVersion(4, 3);							   // Set up OpenGL version
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);		   // Set up compatibility
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH); // Display mode
	glEnable(GL_DEPTH_TEST);								   // Enable depth testing

	cout << " -> USER INTERACTION\n ";
	cout << " -> w for zoom in\n-> s for zoom out \n"; 
	cout << " -> a for turning camera in anticlockwise direction\n ";
	cout << " -> d for turning camera in  clockwise direction\n ";
	cout << " -> left arrow for moving left \n";
	cout << " -> right arrow for moving right \n";
	cout << " -> up arrow for moving up \n";
	cout << " -> down arrow for down left \n";

	glutInitWindowSize(1000, 1000);	  // Set the window size
	glutInitWindowPosition(100, 100); // Set the window position
	glutCreateWindow("3D - Horse");	  // Create the window
	glutDisplayFunc(drawScene);		  // Register the callback function to do the drawing
	glutReshapeFunc(resize);		  // Register the callback function to do the resizing
	glutKeyboardFunc(keyInput);		  // Register the callback function to do the keyboard input
	glutSpecialFunc(specialKeyInput); // Register the callback function to do the special input
	glewExperimental = GL_TRUE;		  // Needed for core profile
	glewInit();						  // Initialize GLEW
	setup();						  // Call the function to setup the rendering context
	glutMainLoop();					  // Start the main loop
}
