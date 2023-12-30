#include<GL/glut.h>
#include<stdio.h>
#include<GL/glu.h>

double x1,y1,x2,y2,dx,dy,m,p;
void init(){

	glClearColor(0,0,0,0);	
	gluOrtho2D(0,500,0,500);
}

void draw(){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
	double x,y,incx,incy;
	dx = x2-x1;
	incx = 1;
	incy = 1;
	if(x1>x2) incx = -1;
	if(y1>y2) incy = -1;
	if(dx<0) dx = -dx;
	
	dy = y2-y1;
	if(dy<0) dy = -dy;
	if(dx==0)
		m = dy;
	
	else 
		m = dy/dx;
	p = 2*dy - dx;
	x = x1;
	y = y1;
	glBegin(GL_POINTS);
	if(x1<x2){while(x<=x2){
	glVertex2i(x,y);
	x = x+incx;
	if(p<0){
	y = y;
	p = p+2*dy;
	
	}
	else{
	y+=incy;
	p = p+2*dy - 2*dx;
	
	}
	
	}}
	else{
	while(x>=x2){
	glVertex2i(x,y);
	x = x+incx;
	if(p<0){
	y = y;
	p = p+2*dy;
	
	}
	else{
	y+=incy;
	p = p+2*dy - 2*dx;
	
	}
	
	}}
	glEnd();
	glFlush();
}




int main(int argc,char*argv[]){
	printf("Enter x1,y1,x2,y2");
	scanf("%lf%lf%lf%lf",&x1,&y1,&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200,250);
	glutInitWindowSize(600,600);
	glutCreateWindow("Bresenhams Line Drawing algo");
	init();
	glutDisplayFunc(draw);
	glutMainLoop();
	return 0;
}
