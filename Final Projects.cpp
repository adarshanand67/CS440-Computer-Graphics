#include <cstdlib>
#include <iostream>
#include <cmath>
#include <vector>
#include <fstream>
#include <GL/glew.h>
#include <GL/freeglut.h>
using namespace std;


 #define PI 3.14159265
 int theta  = 270 ;
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

float centerx_coordinate = -20 ;
float centery_coordinate = 10 ;
float centerz_coordinate = 0 ;


// Camera constructor.
Camera::Camera()
{
	x_coordinate = -20;
  y_coordinate = 10 ;
  z_coordinate = 40 ;
}

void draw_horse( float x , float y , float z )
{
  // horse main body
	glPushMatrix();
  float color[] = { 0.65 , 0.49 , 0.24  } ;
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color ) ;
	//glColor3f(0.65 , 0.49 , 0.24);
  glTranslatef( x , y , z );
	glScalef(10 , 4 ,4 );
  glutSolidCube(1);
  glPopMatrix();

//  legs  start
	glPushMatrix();
//	glColor3f(0.45,0.29 , 0.04 );
  glTranslatef( x -4.5 , y - 4 , z + 2 );
	glScalef(1 , 4 ,1 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
//  glColor3f(0.45,0.29 , 0.04 );
  glTranslatef( x -4.5 , y - 4 , z - 2 );
	glScalef(1 , 4 ,1 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
//	glColor3f(0.45,0.29 , 0.04 );
  glTranslatef(  x +4.5 , y - 4 , z + 2 );
	glScalef(1 , 4 ,1 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
//	glColor3f(0.45,0.29 , 0.04 );
  glTranslatef( x+4.5 , y - 4 , z  - 2 );
	glScalef(1 , 4 ,1 );
	glutSolidCube(1);
	glPopMatrix();

// legs ends

	glPushMatrix();
  float color1[] = { 0.55 , 0.39 , 0.14  } ;
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
	//glColor3f(0.55 , 0.39 , 0.14);
	glTranslatef(  x+ 5 , y + 4  , z   );
	glRotatef(-45 ,0,0,1);
	glScalef(2 , 5 ,2 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
//  glColor3f(0.45,0.29 , 0.04 );
float color2[] = { 0.45,0.29 , 0.04  } ;
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color2 ) ;
  glTranslatef( x + 7 , y + 4  , z   );
	glRotatef(45 ,0,0,1);
	glScalef(2.2 , 3.2 ,2.2 );
	glutSolidCube(1);
	glPopMatrix();
}


void arjun( float x , float y , float z )
{

	glPushMatrix();

  float color[] = { 0.,0. , 0.0 ,0.0  } ;
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color ) ;
	//glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y  , z  );
	glScalef( 2  , 4 ,2 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y+ 3  , z  );
	glutSolidSphere(1,20,20);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y-4  , z +1   );
	glScalef( 1  , 4 ,1 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y -4 , z  - 1   );
	glScalef( 1  , 4 ,1 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y  , z  - 1   );
	glScalef( 0.5  , 4 ,0.5 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y  , z  + 1   );
	glScalef( 0.5 , 4 ,0.5 );
	glutSolidCube(1);
	glPopMatrix();

}

void lord_krishna( float x , float y , float z )
{
	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y  , z  );
	glScalef( 2  , 4 ,2 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y+ 3  , z  );
	glutSolidSphere(1,20,20);
	glPopMatrix();


	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y-4  , z +1   );
	glScalef( 1  , 4 ,1 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y -4 , z  - 1   );
	glScalef( 1  , 4 ,1 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x  , y  , z  - 1   );
	glScalef( 1  , 4 ,1 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0 , 0 , 0);
	glTranslatef( x + 2 , y + 2  , z  + 1   );
	glScalef( 4  , 1 ,1 );
	glutSolidCube(1);
	glPopMatrix();
}
void draw_chariot( float x , float y , float z )
{
	// BASE OF CHARIOT
	glPushMatrix();
  float color[] = { 0.81 , 0.71 , 0.23  } ;
  float color1[] = { 0.61 , 0.51 , 0.03 } ;
  float color2[] = { 0.1,0.1,0.1 };
  float color3[] = { 0.35 , 0.16 , 0.14 };

  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color ) ;


	// glColor3f( 0.81 , 0.71 , 0.23  );
	glTranslatef( x  , y  , z  );
	glScalef( 22  , 2 ,12 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color ) ;
	glTranslatef( x + 12.5  , y - 0.5   , z  );
	glScalef( 5  ,  1  , 1  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color ) ;
	glTranslatef( x + 15.5  , y - 0.5   , z  );
	glScalef( 1  ,  1  , 32  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
	glTranslatef( x + 20  , y - 0.5   , z  + 16  );
	glScalef( 10  ,  1  , 1  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
	glTranslatef( x + 20  , y - 0.5   , z  - 16  );
	glScalef( 10  ,  1  , 1  );
	glutSolidCube(1);
	glPopMatrix();

// lower z_axis beam under horses
	glPushMatrix();
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color3 ) ;
	glTranslatef( x + 25.5  , y - 0.5   , z    );
	glScalef( 1.1  ,  1.1  , 33  );
	glutSolidCube(1);
	glPopMatrix();

// upper z -axis beam above horses
	glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color3 ) ;
	glTranslatef( x + 25.5  , y + 4    , z    );
	glScalef( 1.1  ,  1.1  , 33  );
	glutSolidCube(1);
	glPopMatrix();


  // vertical horse capture beams  starts
	glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color3 ) ;
	glTranslatef( x + 25.5  , y + 2     , z    );
	glScalef( 1  , 4  , 1  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color3 ) ;
	glTranslatef( x + 25.5  , y + 2     , z + 8   );
	glScalef( 1  , 4  , 1  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color3 ) ;
	glTranslatef( x + 25.5  , y + 2     , z + 16   );
	glScalef( 1  , 4  , 1  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color3 ) ;
	glTranslatef( x + 25.5  , y + 2     , z  - 8   );
	glScalef( 1  , 4  , 1  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color3 ) ;
	glTranslatef( x + 25.5  , y + 2     , z  - 16   );
	glScalef( 1  , 4  , 1  );
	glutSolidCube(1);
	glPopMatrix();
// vertical horse capture beams ends

// front covers of chariot
	glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
	glTranslatef( x + 10.5  , y + 2     , z     );
	glScalef( 1.2  , 6.2  , 12.2  );
	glutSolidCube(1);
	glPopMatrix();

// upper x_axis beam
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color ) ;
	glTranslatef( x + 18 , y + 4    , z    );
	glScalef( 15 ,  1  , 1  );
	glutSolidCube(1);
	glPopMatrix();

// wheels start
	glPushMatrix();
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color2 ) ;
	glColor3f( 0.1,0.1,0.1);
	glTranslatef( x - 6  , y     , z  + 7   );
	glutSolidTorus(1 , 4 ,30 , 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0.1,0.1,0.1);
	glTranslatef( x - 6  , y     , z  - 7   );
	glutSolidTorus(1 , 4 ,30 , 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0.1,0.1,0.1);
	glTranslatef( x + 4  , y  -1    , z  - 7   );
	glutSolidTorus(1 , 3 ,30 , 30);
	glPopMatrix();

	glPushMatrix();
	glColor3f( 0.1,0.1,0.1);
	glTranslatef( x + 4  , y  -1   , z  + 7   );
	glutSolidTorus(1 , 3 ,30 , 30);
	glPopMatrix();
// wheels end

// pillars start
	glPushMatrix();
  //glColor3f(0,0 , 0 );
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
	glTranslatef( x -10  , y+7     , z + 5   );
	glScalef( 1  , 14  , 1  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
	glTranslatef( x -10  , y+7     , z - 5   );
	glScalef( 1  , 14  , 1  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
	glTranslatef( x   , y +7    , z + 5   );
	glScalef( 1  , 14  , 1  );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
	glTranslatef( x   , y +7    , z - 5   );
	glScalef( 1  , 14  , 1  );
	glutSolidCube(1);
	glPopMatrix();
// pillars end



// roof of chariot
	glPushMatrix();
	glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color ) ;
	glTranslatef( x  , y+ 14   , z  );
	glScalef( 22  , 2 ,13 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
  glTranslatef( x-5  , y+ 14   , z  );
	glRotatef(-90 ,1,0,0);
	glutSolidCone(6 ,10, 8 ,20 );
	glPopMatrix();

  // flag pole
	glPushMatrix();
	//glColor3f( 0.81 , 0.71 , 0.23);
  float color5[] = { 0,0,0};
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color5 ) ;
  glColor3f( 0 , 0 , 0);
  glTranslatef( x-5  , y+ 14 + 10+2   , z  );
	glScalef( 0.25  ,4 ,0.25 );
	glutSolidCube(1);
	glPopMatrix();

  // flag
	glPushMatrix();
  float color4[] = {1.0,0,0};
  glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color4 ) ;
	glColor3f( 1 , 0 , 0);
	glTranslatef( x-5 -3  , y+ 14 + 10+2 +1  , z  );
	glScalef( 6  ,2 ,0.25 );
	glutSolidCube(1);
	glPopMatrix();

	glPushMatrix();
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color1 ) ;
	glTranslatef( x + 5  , y+ 14   , z  );
	glRotatef(-90 ,1,0,0);
	glutSolidCone(6 ,7, 8 ,20 );
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
    GLfloat light_ambient[]  =  { 0.2f, 0.2f, 0.2f, 1.0f };
    GLfloat light_diffuse[]  =  { 0.8f, 0.8f, 0.8f, 1.0f };
    GLfloat light_specular[] =  { 0.5f, 0.5f, 0.5f, 1.0f };
    GLfloat light_position[] =  { -1.5f, 1.0f, -4.0f, 1.0f };
    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);
    //$$$$$$$$$$$$$$$$$$$$4


    //###############
    glutInitDisplayMode( GLUT_SINGLE | GLUT_RGBA  | GLUT_DEPTH );
    glClear(GL_COLOR_BUFFER_BIT  | GL_DEPTH_BUFFER_BIT );
    glEnable( GL_DEPTH_TEST );
    //#########################33
    gluLookAt( camera.x_coordinate , camera.y_coordinate , camera.z_coordinate ,
             centerx_coordinate  , centery_coordinate  , centerz_coordinate  ,
             0.0, 1.0, 0.0 );
draw_horse(0 , 10 , 4 );
draw_horse(0 , 10 , 12 );
draw_horse(0 , 10 , -12 );
draw_horse(0 , 10 , -4 );
draw_chariot(-25 , 8 , 0 ) ;
arjun( -30 , 14 , 3);
lord_krishna( -25 , 16 , 0 );

glPushMatrix();
float color[] = { 0.41 , 0.55 , 0.137  } ;
glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color ) ;
//glColor3f( 0.41 , 0.55 , 0.137 );
glTranslatef( 0,2.5,0  );
glScalef(200  ,1 ,200 );
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
  case 'w' :
    //camera.z_coordinate --  ;
		camera.x_coordinate += cos( (theta ) *PI / (float )180  ) ;
		camera.z_coordinate += sin( (theta) *PI / (float )180   );

		centerx_coordinate = camera.x_coordinate + cos (theta *PI / (float )180 );
		centerz_coordinate = camera.z_coordinate + sin( theta *PI / (float )180 );
    glutPostRedisplay();
    break;


// it moves away the camera from objects
  case 's' :
    //camera.z_coordinate ++ ;
		camera.x_coordinate -= cos( (theta ) *PI / (float )180  ) ;
		camera.z_coordinate -= sin( (theta) *PI / (float )180   );
		centerx_coordinate = camera.x_coordinate + cos (theta *PI / (float )180 );
		centerz_coordinate = camera.z_coordinate + sin( theta *PI / (float )180 );
    glutPostRedisplay();
    break;

		case 'a' :
		theta = ( ( theta - 5 )% 360 + 360 )%360 ;
		centerx_coordinate = camera.x_coordinate + cos (theta *PI / (float )180 );
		centerz_coordinate = camera.z_coordinate + sin( theta *PI / (float )180 );
		glutPostRedisplay();
		break;

		case 'd':
		theta = ( ( theta + 5 )% 360 + 360 )%360 ;
		centerx_coordinate = camera.x_coordinate + cos (theta *PI / (float )180 );
		centerz_coordinate = camera.z_coordinate + sin( theta *PI / (float )180 );
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
    camera.y_coordinate -- ;
    centery_coordinate -- ;
  }
	if (key == GLUT_KEY_UP)
  {
    camera.y_coordinate ++ ;
    centery_coordinate ++ ;
  }
  if(  key == GLUT_KEY_RIGHT  )
  {
		camera.x_coordinate += cos( (theta+90) *PI / (float )180  ) ;
		camera.z_coordinate += sin( (theta+90) *PI / (float )180   );
    centerx_coordinate = camera.x_coordinate + cos (theta *PI / (float )180 );
		centerz_coordinate = camera.z_coordinate + sin( theta *PI / (float )180 );
  }
  if(  key == GLUT_KEY_LEFT  )
  {
    camera.x_coordinate -= cos( (theta+90) *PI / (float )180  ) ;
		camera.z_coordinate -= sin( (theta+90) *PI / (float )180   );
    centerx_coordinate = camera.x_coordinate + cos (theta *PI / (float )180 );
		centerz_coordinate = camera.z_coordinate + sin( theta *PI / (float )180 );
  }
	glutPostRedisplay();
}




// Main routine.
int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitContextVersion(4, 3);
	glutInitContextProfile(GLUT_COMPATIBILITY_PROFILE);
	// glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
  //$$$$$$$$$$$$$$$$$$
  glutInitDisplayMode( GLUT_SINGLE | GLUT_RGBA  | GLUT_DEPTH );
  glEnable( GL_DEPTH_TEST );


  cout<< "INTERACTION \n press w for zoom in \n press s for zoom out \n";
  cout<<" press a for turning camera in anticlockwise direction\n ";
  cout<<"press d for turning camera in  clockwise direction\n " ;
  cout<< "press left arrow for moving left \n";
  cout<< "press right arrow for moving right \n";
  cout<< "press up arrow for moving up \n";
  cout<< "press down arrow for down left \n";


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
