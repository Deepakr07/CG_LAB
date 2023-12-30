
#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>

double tx,ty,x1,y11,x2,y2,sx,sy,theta;

void init()
{
	glClearColor(1,1,1,0);//white background color
	gluOrtho2D(0,600,0,600);	
}

void drawLineTranslate()
{
	 glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    
    glBegin(GL_LINES);
    glVertex2f(x1, y11);
    glVertex2f(x2, y2);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(x1 + tx, y11 + ty);
    glVertex2f(x2 + tx, y2 + ty);
    glEnd();
    
    glFlush();
}
void drawLineScale()
{
	 glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    
    glBegin(GL_LINES);
    glVertex2f(x1, y11);
    glVertex2f(x2, y2);
    glEnd();
    
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(x1 * sx, y11 * sy);
    glVertex2f(x2 * sx, y2 * sy);
    glEnd();
    
    glFlush();
}
void drawLineRotate()
{
	 glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1, 0, 0);
    double a,b,c,d;
    glBegin(GL_LINES);
    glVertex2f(x1, y11);
    glVertex2f(x2, y2);
    glEnd();
    a = x1;
    b = y11;
    c = x1+((x2-x1)*cos(theta)) - (y2-y11)*sin(theta);
    d = y11+(x2-x1)*sin(theta) + (y2-y11)*cos(theta);
    
    glColor3f(0, 1, 0);
    glBegin(GL_LINES);
    glVertex2f(a, b);
    glVertex2f(c, d);
    glEnd();
    
    glFlush();
}





int main(int argc,char*argv[]){
	int num,confirm;
			printf("Enter the coordinates of the line in order (x1,y11,x2,y2)");
										scanf("%lf%lf%lf%lf",&x1,&y11,&x2,&y2);
			printf("Enter the option 1.Translation 2.Scaling 3 Rotation");
			scanf("%d",&num);
			
			switch(num){
												
				case 1:			
										printf("Enter the translation vectors tx and ty");
										scanf("%lf%lf",&tx,&ty);
										glutInit(&argc,argv);
										glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
										glutInitWindowPosition(200,300);
										glutInitWindowSize(600,600);
										glutCreateWindow("Tranformations");
										init();	
										glutDisplayFunc(drawLineTranslate);
										glutMainLoop();
										break;
				case 2: 
										printf("Enter sx and sy");
										scanf("%lf%lf",&sx,&sy);				
										glutInit(&argc,argv);
										glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);							
										glutInitWindowPosition(200,300);
										glutInitWindowSize(600,600);
										glutCreateWindow("Scaling");
										init();	
										glutDisplayFunc(drawLineScale);
										glutMainLoop();
										break;									
			case 3:   	
										printf("Enter theta ");
										scanf("%lf",&theta);
										theta = theta*3.14/180;				
										glutInit(&argc,argv);
										glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);							
										glutInitWindowPosition(200,300);
										glutInitWindowSize(600,600);
										glutCreateWindow("Scaling");
										init();	
										glutDisplayFunc(drawLineRotate);
										glutMainLoop();
										break;					
	
			}


}
