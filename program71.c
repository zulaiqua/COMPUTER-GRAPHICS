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
double Vx0
