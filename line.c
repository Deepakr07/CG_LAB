#include<stdio.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<math.h>

double x1,y11,x2,y2,steps,dx,dy,x,y,m,xincr,yincr,p,t;

void init(){
			
	glClearColor(0,0,0,0);
	gluOrtho2D(0,500,0,500);

}
int rounding(double x){
	return floor(x+0.5);
		


}

void display(){
	glColor3f(1,0,0);
	glPointSize(2);
	glClear(GL_COLOR_BUFFER_BIT);
	dx = x2-x1;
	dy = y2-y11;
	steps = abs(dx)>abs(dy)?abs(dx):abs(dy);
	xincr = dx/(float)steps;
	yincr = dy/(float)steps;
	if(dx == 0)
	m = dy;
	else 
	m = dy/dx;
	x = x1;
	y = y11;
	glBegin(GL_POINTS);
	glVertex2i(x,y);	
	glEnd();
	glBegin(GL_POINTS);
	
	for(int i = 0 ; i< steps; i++){
		x+=xincr;
		y+=yincr;
		glVertex2i(rounding(x),rounding(y));
	}	
	glEnd();
	glFlush();
}


void bresenhams() {
    glColor3f(1, 0, 0);
    glPointSize(2);
    glClear(GL_COLOR_BUFFER_BIT);
    dx = x2 - x1;
    dy = y2 - y11;
    xincr = 1;
    yincr = 1;
    if (dx == 0) {
        m = dx;
    } else {
        m = dy / dx;
    }

    if (m >= 0) {
        if (x1 > x2) {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y11;
            y11 = y2;
            y2 = t;
        }

        p = 2 * dy - dx;
        x = x1;
        y = y11;

        glBegin(GL_POINTS);
        while (x <= x2) {
            glVertex2i(x, y);

            if (p < 0) {
                x += xincr;
                y = y;
                p = p + 2 * dy;
            } else {
                x += xincr;
                y += yincr;
                p = p + 2 * (dy - dx);
            }
        }
        glEnd();
        glFlush();
    } else {
        if (x1 > x2) {
            t = x1;
            x1 = x2;
            x2 = t;

            t = y11;
            y11 = y2;
            y2 = t;
        }

        p = 2 * dx - dy;
        x = x1;
        y = y11;

        glBegin(GL_POINTS);
        while (y <= y2) {
            glVertex2i(x, y);

            if (p < 0) {
                y += yincr;
                x = x;
                p = p + 2 * dx;
            } else {
                x += xincr;
                y += yincr;
                p = p + 2 * (dx - dy);
            }
        }
        glEnd();
        glFlush();
    }
}

	

int main(int argc,char *argv[]){
	
	printf("Enter the coordinates of the line ");
	scanf("%lf%lf%lf%lf",&x1,&y11,&x2,&y2);
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(200,300);
	glutInitWindowSize(600,600);
	glutCreateWindow("Line Algos");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;

}
