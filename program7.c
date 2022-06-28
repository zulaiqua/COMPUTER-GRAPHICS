#include<stdio.h>
#include<stdbool.h>
#include<GL/glut.h>
#define outcode int
float xvmin=200,yvmin=200,xvmax=300,yvmax=300;
float xmin,ymin,xmax,ymax;
float x0,yy0,x1,yy1;
const int RIGHT=2;
const int LEFT=1;
const int TOP=8;
const int BOTTOM=4;
int computeoutcode(float x,float y);
void CSLCAD(float x0,float yy0,float x1,float yy1)
{
int outcode0,outcode1,outcodeout;
bool accept=false,done=false;
outcode0=computeoutcode(x0,yy0);
outcode1=computeoutcode(x1,yy1);
do
{
if((outcode0|outcode1)==0)
{
accept=true;
done=true;
}
else if((outcode0 & outcode1)!=0)
done=true;
else
{
double x,y;
outcodeout=outcode0?outcode0:outcode1;
if(outcodeout & TOP)
{
x=x0+(x1-x0)*(ymax-yy0)/(yy1-yy0);
y=ymax;
}
else if(outcodeout & BOTTOM)
{
x=x0+(x1-x0)*(ymin-yy0)/(yy1-yy0);
y=ymin;
}
else if(outcodeout & RIGHT)
{
y=yy0+(yy1-yy0)*(xmax-x0)/(x1-x0);
x=xmax;
}
else
{
y=yy0+(yy1-yy0)*(xmin-x0)/(x1-x0);
x=xmin;
}
if(outcodeout==outcode0)
{
x0=x;
yy0=y;
outcode0=computeoutcode(x0,yy0);
}
else
{
x1=x;
yy1=y;
outcode1=computeoutcode(x1,yy1);
}
}
}while(!done);
if(accept)
{
double Sx=(xvmax-xvmin)/(xmax-xmin);
double Sy=(yvmax-yvmin)/(ymax-ymin);
double vx0=xvmin+(x0-xmin)*Sx;
double vyy0=yvmin+(yy0-xmin)*Sy;
double vx1=xvmin+(x1-xmin)*Sx;
double vyy1=yvmin+(yy1-xmin)*Sx;
glColor3f(1.0,0.0,0.0);
glBegin(GL_LINE_LOOP);
glVertex2f(xvmin,yvmin);
glVertex2f(xvmax,yvmin);
glVertex2f(xvmax,yvmax);
glVertex2f(xvmin,yvmax);
glEnd();
glColor3f(0.0,0.0,1.0);
glBegin(GL_LINES);
glVertex2d(vx0,vyy0);
glVertex2d(vx1,vyy1);
glEnd();
}
}
int computeoutcode(float x,float y)
{
int code=0;
if(y>ymax)
code=code|TOP;
else if(y<ymin)
code=code|BOTTOM;
if(x>xmax)
code=code|RIGHT;
else if(x<xmin)
code=code|LEFT;
return code;
}
void drawline()
{
glBegin(GL_LINES);
glVertex2f(x0,yy0);
glVertex2f(x1,yy1);
glEnd();
}
void drawrect()
{
glBegin(GL_LINE_LOOP);
glVertex2f(xmin,ymin);
glVertex2f(xmax,ymin);
glVertex2f(xmax,ymax);
glVertex2f(xmin,ymax);
glEnd();
}
void display()
{
glColor3f(1.0,0.0,0.0);
drawline();
glColor3f(0.0,0.0,1.0);
drawrect();
CSLCAD(x0,yy0,x1,yy1);
glFlush();
}
void myInit()
{
glClearColor(1.0,1.0,1.0,1.0);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1.0,0.0,0.0);
glPointSize(1.0);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,499.0,0.0,499.0);
}
int main(int argc,char *argv[])
{
printf("Enter the end points of the clipping window\n");
scanf("%f %f %f %f",&xmin,&ymin,&xmax,&ymax);
printf("Enter the end points\n");
scanf("%f %f %f %f",&x0,&yy0,&x1,&yy1);
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowSize(500,500);
glutInitWindowPosition(0,0);
glutCreateWindow("4MT19CS183,Cohen-Sutherland Line Clipping");
glutDisplayFunc(display);
myInit();
glutMainLoop();
return 0;
}


