#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>


double r,xCenter,yCenter,p,x,y;
void init(){

	glClearColor(1,1,1,0);
	gluOrtho2D(0,600,0,600);
	glColor3f(1,0,0);
	

}

void drawPixel(double x, double y){
	glVertex2i(x + (int)xCenter, y + (int)yCenter);
	

}

void DrawCircle(){
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



int main(int argc, char *argv[]){

	printf("Enter the radius and center of the circle ");
	scanf("%lf%lf%lf",&r,&xCenter,&yCenter);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(400,400);
	glutInitWindowSize(800,800);
	glutCreateWindow("Circle Drawing");
	init();
	
	glutDisplayFunc(DrawCircle);
	glutMainLoop();
	return 0;
}




