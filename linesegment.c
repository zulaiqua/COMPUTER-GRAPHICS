#include<stdio.h>
#include<GL/glut.h>
void myInit()
{
glClearColor(0.0,0.0,0.0,0.0);
glClear(GL_COLOR_BUFFER_BIT);
glMatrixMode(GL_PROJECTION);
gluOrtho2D(0.0,200.0,0.0,200.0);
}
void linesegment()
{
glBegin(GL_LINES);
glVertex2i(180,15);
glVertex2i(10,145);
glEnd();
glFlush();
}
void main(int argc,char *argv[])
{
printf("name:zulaiqua\n usn:4MT19CS183\n");
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(0,0);
glutInitWindowSize(500,500);
glutCreateWindow("displaying a line");
myInit();
glutDisplayFunc(linesegment);
glutMainLoop();
}




















































































































