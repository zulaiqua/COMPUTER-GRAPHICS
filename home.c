#include <stdio.h>
#include <GL/glut.h>
void myInit()
{
 	glClearColor(0.0,0.0,0.0,0.0);
 	glClear(GL_COLOR_BUFFER_BIT);
 	glMatrixMode(GL_PROJECTION);
 	gluOrtho2D(0.0,200.0,0.0,200.0);
}
void linesegment()
{
glColor3f(1,0,0);
glBegin(GL_LINES);
glVertex2i(170,100);
glVertex2i(150,125);
glVertex2i(50,50);
glVertex2i(170,50);
glVertex2i(50,100);
glVertex2i(50,50);
glVertex2i(80,50);
glVertex2i(80,100);
glVertex2i(50,100);
glVertex2i(65,125);
glVertex2i(65,125);
glVertex2i(80,100);
glVertex2i(65,125);
glVertex2i(150,125);
glVertex2i(50,100);
glVertex2i(170,100);
glVertex2i(170,50);
glVertex2i(170,100);
glVertex2i(130,50);
glVertex2i(130,90);
glVertex2i(110,50);
glVertex2i(110,90);
glVertex2i(110,90);
glVertex2i(130,90);
glVertex2i(110,50);
glVertex2i(130,50);
glVertex2i(85,95);
glVertex2i(85,85);
glVertex2i(105,95);
glVertex2i(105,85);
glVertex2i(85,95);
glVertex2i(105,95);
glVertex2i(105,85);
glVertex2i(85,85);
glEnd();
glBegin(GL_LINE_STRIP);
glVertex2i(50,140);
glVertex2i(52,142);
glVertex2i(53,138);
glVertex2i(55,142);
glEnd();
glFlush();
}
void main(int argc, char * argv[])
{
 	glutInit(&argc,argv);
 	glutInitDisplayMode( GLUT_SINGLE| GLUT_RGB);
 	
 	glutInitWindowPosition(0,0);
 	glutInitWindowSize(750,750);
        glutCreateWindow("Displaying a points");
	myInit();
	glutDisplayFunc(linesegment);
	glutMainLoop();
}


