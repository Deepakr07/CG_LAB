#include <GL/glut.h>
#include<stdio.h>
#include<math.h>
double xstart,ystart,xend,yend;
float xincr,yincr;
double steps,dx,dy;

float roundto(float x){
 return floor(x+0.5);

}
void display() {
  
    
     glColor3f(1, 0, 0);
    
    dx = xend - xstart;
    dy = yend - ystart;
    
    steps = abs(dx) >= abs(dy) ? abs(dx) : abs(dy);
    
    xincr = dx / (float)steps;
    yincr = dy / (float)steps;

    float x = xstart;
    float y = ystart;
	glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    glVertex2d(roundto(x), roundto(y));

    for (int i = 0; i < steps; i++) {
        x += xincr;
        y += yincr;
        glVertex2d(roundto(x), roundto(y));
    }
    glEnd();

    glFlush();
}

void init() {
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(0,800,0,600);
    //glFlush(); // Use glFlush to execute the pipeline commands immediately
}

int main(int argc, char *argv[]) {
	printf("Enter the line endpoints");
	scanf("%lf%lf%lf%lf",&xstart,&ystart,&xend,&yend);
    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(300, 400);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); // Use single buffering
    glutCreateWindow("Basic OpenGL Program");

    init();

    glutDisplayFunc(display);

    glutMainLoop();
    return 0;
}

