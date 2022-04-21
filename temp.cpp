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
	// float color[] = { 0.65 , 0.49 , 0.24 };
	float color[] = { 0.58 , 0.29 , 0.05 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
	//glColor3f(0.65 , 0.49 , 0.24);
	glTranslatef(x, y, z);
	glScalef(10, 4, 4);
	glutSolidCube(1);
	glPopMatrix();

	//  legs  start
	glPushMatrix();
	//	glColor3f(0.45,0.29 , 0.04 );
	glTranslatef(x - 4.5, y - 4, z + 2);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	//  glColor3f(0.45,0.29 , 0.04 );
	glTranslatef(x - 4.5, y - 4, z - 2);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	//	glColor3f(0.45,0.29 , 0.04 );
	glTranslatef(x + 4.5, y - 4, z + 2);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	//	glColor3f(0.45,0.29 , 0.04 );
	glTranslatef(x + 4.5, y - 4, z - 2);
	glScalef(1, 4, 1);
	glutSolidCube(1);
	glPopMatrix();

	// legs ends

	glPushMatrix();
	float color1[] = { 0.58 , 0.29 , 0.15 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1);
	//glColor3f(0.55 , 0.39 , 0.14);
	glTranslatef(x + 5, y + 4, z);
	glRotatef(-45, 0, 0, 1);
	glScalef(2, 5, 2);
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	//  glColor3f(0.45,0.29 , 0.04 );
	// float color2[] = { 0.35,0.91 , 0.64 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1);
	glTranslatef(x + 7, y + 4, z);
	glRotatef(45, 0, 0, 1);
	glScalef(2.2, 3.2, 2.2);
	glutSolidCube(1);
	glPopMatrix();
}


void drawScene(void)
{
	//  glClear(GL_COLOR_BUFFER_BIT   );
	glColor3f(0.0, 0.0, 0.0);
	glLoadIdentity();


	//$$$$$$$$$$$$$$$$$$$4
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT0);
	GLfloat light_ambient[] = { 0.2f, 0.2f, 0.2f, 1.0f };
	GLfloat light_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f };
	GLfloat light_specular[] = { 0.5f, 0.5f, 0.5f, 1.0f };
	GLfloat light_position[] = { -1.5f, 1.0f, -4.0f, 1.0f };
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	//$$$$$$$$$$$$$$$$$$$$4


	//###############
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	//#########################33
	gluLookAt(camera.x_coordinate, camera.y_coordinate, camera.z_coordinate,
		centerx_coordinate, centery_coordinate, centerz_coordinate,
		0.0, 1.0, 0.0);
	draw_horse(0, 10, 4);

	glPushMatrix();
	float color[] = { 0.41 , 0.55 , 0.137 };
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
	//glColor3f( 0.41 , 0.55 , 0.137 );
	glTranslatef(0, 2.5, 0);
	glScalef(200, 1, 200);
	glutSolidCube(1);
	glPopMatrix();

	glFlush();
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
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-1.0, 1.0, -1.0, 1.0, 1.0, 200.0);
	glMatrixMode(GL_MODELVIEW);
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 27:
		exit(0);
		break;

		// it moves the camera  towards objects
	case 'w':
		//camera.z_coordinate --  ;
		camera.x_coordinate += cos((theta)*PI / (float)180);
		camera.z_coordinate += sin((theta)*PI / (float)180);

		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
		glutPostRedisplay();
		break;


		// it moves away the camera from objects
	case 's':
		//camera.z_coordinate ++ ;
		camera.x_coordinate -= cos((theta)*PI / (float)180);
		camera.z_coordinate -= sin((theta)*PI / (float)180);
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
		glutPostRedisplay();
		break;

	case 'a':
		theta = ((theta - 5) % 360 + 360) % 360;
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
		glutPostRedisplay();
		break;

	case 'd':
		theta = ((theta + 5) % 360 + 360) % 360;
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
		glutPostRedisplay();
		break;


	default:
		break;
	}
}


void specialKeyInput(int key, int x, int y)
{
	if (key == GLUT_KEY_DOWN)
	{
		camera.y_coordinate--;
		centery_coordinate--;
	}
	if (key == GLUT_KEY_UP)
	{
		camera.y_coordinate++;
		centery_coordinate++;
	}
	if (key == GLUT_KEY_RIGHT)
	{
		camera.x_coordinate += cos((theta + 90) * PI / (float)180);
		camera.z_coordinate += sin((theta + 90) * PI / (float)180);
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
	}
	if (key == GLUT_KEY_LEFT)
	{
		camera.x_coordinate -= cos((theta + 90) * PI / (float)180);
		camera.z_coordinate -= sin((theta + 90) * PI / (float)180);
		centerx_coordinate = camera.x_coordinate + cos(theta * PI / (float)180);
		centerz_coordinate = camera.z_coordinate + sin(theta * PI / (float)180);
	}
	glutPostRedisplay();
}




// Main routine.
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	// glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  //$$$$$$$$$$$$$$$$$$
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glEnable(GL_DEPTH_TEST);


	cout << "INTERACTION \n press w for zoom in \n press s for zoom out \n";
	cout << " press a for turning camera in anticlockwise direction\n ";
	cout << "press d for turning camera in  clockwise direction\n ";
	cout << "press left arrow for moving left \n";
	cout << "press right arrow for moving right \n";
	cout << "press up arrow for moving up \n";
	cout << "press down arrow for down left \n";


	//$$$$$$$$$$$$$$$$$$$$$$$$
	glutInitWindowSize(1000, 1000);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("box.cpp");
	glutDisplayFunc(drawScene);
	glutReshapeFunc(resize);
	glutKeyboardFunc(keyInput);
	glutSpecialFunc(specialKeyInput);
	glewExperimental = GL_TRUE;
	glewInit();
	setup();
	glutMainLoop();
}