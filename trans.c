#include<stdio.h>
#include<GL/glut.h>
#include<math.h>

double tx,ty,x1,x2,y11,y2,theta,a,b,c,sx,sy,d,shx,shy;

void init()
{

	glClearColor(0,0,0,0);
	gluOrtho2D(-450,450,-450,450);
	
}

void translate()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0,1,0);
	glVertex2i(x1,y11);
	glVertex2i(x2,y2);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2i(x1+tx,y11+ty);
	glVertex2i(x2+tx,y2+ty);
	glEnd();
	glFlush();


}


void rotate()
{	 a = x1;
	 b = y11;
	 c = x1+(x2-x1)*cos(theta)-(y2-y11)*sin(theta);
	 d = y11+(x2-x1)*sin(theta)+(y2-y11)*cos(theta);
	
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0,1,0);
	glVertex2i(x1,y11);
	glVertex2i(x2,y2);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2i(a,b);
	glVertex2i(c,d);
	glEnd();
	glFlush();


}
void scaling()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0,1,0);
	glVertex2i(x1,y11);
	glVertex2i(x2,y2);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2i(x1*sx,y11*sy);
	glVertex2i(x2*sx,y2*sy);
	glEnd();
	glFlush();


}

void xShear()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0,1,0);
	glVertex2i(x1,y11);
	glVertex2i(x2,y2);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2i(x1+y11*shx,y11);
	glVertex2i(x2+y2*shx,y2);
	glEnd();
	glFlush();


}
void yShear()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0,1,0);
	glVertex2i(x1,y11);
	glVertex2i(x2,y2);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2i(x1,y11+x1*shy);
	glVertex2i(x2,y2+x2*shy);
	glEnd();
	glFlush();


}

void xReflection()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0,1,0);
	glVertex2i(x1,y11);
	glVertex2i(x2,y2);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2i(x1,-y11);
	glVertex2i(x2,-y2);
	glEnd();
	glFlush();


}
void yReflection()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0,1,0);
	glVertex2i(x1,y11);
	glVertex2i(x2,y2);
	glEnd();
	
	glBegin(GL_LINES);
	glColor3f(0,0,1);
	glVertex2i(-x1,y11);
	glVertex2i(-x2,y2);
	glEnd();
	glFlush();


}

int main(int argc , char *argv[])
{
	int option;
	printf("Enter the coordinates of the line ");
	scanf("%lf%lf%lf%lf",&x1,&y11,&x2,&y2);
	
	printf("Enter an Option\n 1. Translation \n2.Rotation \n3.Scaling \n4.X Shear \n5. Y Shear \n6. X  Reflection \n7. Y Reflection");
	scanf("%d",&option);
	
	switch(option)
	{
		case 1: printf("enter the translation vectors tx and ty ");
				scanf("%lf%lf",&tx,&ty);
				glutInit(&argc,argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
				glutInitWindowPosition(500,500);
				glutInitWindowSize(600,600);
				glutCreateWindow("Basic Transformations");
				init();
				glutDisplayFunc(translate);
				glutMainLoop();
				break;
		case 2: printf("enter the theta value ");
				scanf("%lf",&theta);
				theta = 3.14*theta/180;
				glutInit(&argc,argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
				glutInitWindowPosition(500,500);
				glutInitWindowSize(600,600);
				glutCreateWindow("Basic Transformations");
				init();
				glutDisplayFunc(rotate);
				glutMainLoop();
				break;
		case 3: printf("enter the Scaling vectors sx and sy ");
				scanf("%lf%lf",&sx,&sy);
				glutInit(&argc,argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
				glutInitWindowPosition(500,500);
				glutInitWindowSize(600,600);
				glutCreateWindow("Basic Transformations");
				init();
				glutDisplayFunc(scaling);
				glutMainLoop();
				break;
		case 4: printf("enter the x shear factor ");
				scanf("%lf",&shx);
				glutInit(&argc,argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
				glutInitWindowPosition(500,500);
				glutInitWindowSize(600,600);
				glutCreateWindow("Basic Transformations");
				init();
				glutDisplayFunc(xShear);
				glutMainLoop();
				break;						
		case 5: printf("enter the y shear factor ");
				scanf("%lf",&shy);
				glutInit(&argc,argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
				glutInitWindowPosition(500,500);
				glutInitWindowSize(600,600);
				glutCreateWindow("Basic Transformations");
				init();
				glutDisplayFunc(yShear);
				glutMainLoop();
				break;
							
		case 6:
				glutInit(&argc,argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
				glutInitWindowPosition(500,500);
				glutInitWindowSize(600,600);
				glutCreateWindow("Basic Transformations");
				init();
				glutDisplayFunc(xReflection);
				glutMainLoop();
				break;
				
		case 7: 
				glutInit(&argc,argv);
				glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);	
				glutInitWindowPosition(500,500);
				glutInitWindowSize(600,600);
				glutCreateWindow("Basic Transformations");
				init();
				glutDisplayFunc(yReflection);
				glutMainLoop();
				break;								
	}
	
	return 0;
		
}
