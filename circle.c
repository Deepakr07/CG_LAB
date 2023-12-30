#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>

double r,xcenter,ycenter,p;

void init(){

	glClearColor(0,0,0,0);
	gluOrtho2D(0,600,0,600);	
	glColor3f(1,0,0);
}

void drawPixel(int x,int y){

	 glVertex2i(x + (int)xcenter, y + (int)ycenter);

}
void circle(){
	double x,y;
	glClear(GL_COLOR_BUFFER_BIT);
	p = 5/4 - r;
	x = 0;
	y = r;
	glBegin(GL_POINTS);
	drawPixel(x,y);
	while(y>x){
		if(p<0){
			
			x = x+1;
			y = y;
			
			p = p+2*x + 1;	
	

		}
	
		else{
		
			x = x+1;
			y = y-1;
			p = p + 2*(x-y) + 1;
		
	
		}

	drawPixel(x,y);
	drawPixel(y,x);
	drawPixel(y,-x);
	drawPixel(x,-y);
	drawPixel(-x,-y);
	drawPixel(-y,-x);
	drawPixel(-y,x);
	drawPixel(-x,y);

	}
	glEnd();
	glFlush();
}



int main(int argc,char*argv[]){

	printf("Enter the coordinates of the center");
	scanf("%lf%lf",&xcenter,&ycenter);
	printf("Enter the radius ");
	scanf("%lf",&r);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(500,200);
	glutInitWindowSize(800,800);
	glutCreateWindow("Circle Drwaing Algorithm");
	init();
	glutDisplayFunc(circle);
	glutMainLoop();
	return 0;

}
