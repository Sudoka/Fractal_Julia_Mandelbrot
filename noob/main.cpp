#include <stdlib.h>
#include <GL/glut.h>
/* Try uncommenting this include line to compile on Max OSX
#include <GLUT/glut.h>
*/

#include <math.h>   // include math functions, such as sin, cos, M_PI
#include <iostream> // allow c++ style console printouts

using namespace std; // allow console printouts without std::

/*! GLUT display callback function */
void display(void);
/*! GLUT window reshape callback function */
void reshape(int, int);
/*! GLUT idle callback function */
void idle();

int main(int argc, char** argv)
{
  glutInit(&argc, argv);

  /* set the window size to 512 x 512 */
  glutInitWindowSize(512, 512);

  /* set the display mode to Red, Green, Blue and Alpha
    allocate a depth buffer
    enable double buffering
  */
  glutInitDisplayMode(GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);

  /* create the window (and call it Lab 1) */
  glutCreateWindow("Lab 1");

  /* set the glut display callback function
    this is the function GLUT will call every time
    the window needs to be drawn
  */
  glutDisplayFunc(display);

  /* set the glut reshape callback function
    this is the function GLUT will call whenever
    the window is resized, including when it is
    first created
  */
  glutReshapeFunc(reshape);
  
  glutIdleFunc(idle);

  /* set the default background color to black */
  glClearColor(0,0,0,1);

  /* enter the main event loop so that GLUT can process
    all of the window event messages
  */
  glutMainLoop();

  return 0;
}

/*! glut display callback function.  Every time the window needs to be drawn,
  glut will call this function.  This includes when the window size
  changes, or when another window covering part of this window is
  moved so this window is uncovered.
*/
void display()
{
  cerr << "display callback" << endl;

  /* clear the color buffer (resets everything to black) */
  glClear(GL_COLOR_BUFFER_BIT);
  
  glPushMatrix();
  glLoadIdentity();
  gluLookAt(0,0,0, 10,100,100,0,1,0);
  /* draw quad, takes 4 vertices */
  glBegin(GL_QUADS);   // alternatively: GL_TRIANGLES to draw triangles

    /* set the current drawing color to red */
    glColor3f(1, 1, 1);

    
    glVertex3f(1, -1, 0);
    glVertex3f(1, 1, 0);
    glVertex3f(-1, 1, 0);
	glVertex3f(-1, -1, 0);//left corner
  /* tell OpenGL we're done drawing quads */
  glEnd();
	
  glPopMatrix();
  /* swap the back and front buffers so we can see what we just drew */
  glutSwapBuffers();
}

/*! glut reshape callback function.  GLUT calls this function whenever
  the window is resized, including the first time it is created.
  You can use variables to keep track the current window size.
*/
void reshape(int width, int height)
{
  cerr << "reshape callback" << endl;

  /* tell OpenGL we want to display in a recangle that is the 
    same size as the window
  */
  glViewport(0,0,width,height);

  /* switch to the projection matrix */
  glMatrixMode(GL_PROJECTION);

  /* clear the projection matrix */
  glLoadIdentity();

  glFrustum(-10.0, 10.0, -10.0, 10.0, 5.0, 1000.0); // set perspective pr
  /* switch back to the model view matrix */
  glMatrixMode(GL_MODELVIEW);
}

/* Gets called whenever computer doesn't have anything else to do */
void idle() 
{
  cerr << "idle callback" << endl;
  display();     // call display callback, useful for animation
} 