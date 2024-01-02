#include<GL/glut.h>
#include<stdio.h>


double rx,ry,xcenter,ycenter,p1,p2,dx,dy;
double xCenter, yCenter,x,y;  // Center of ellipse

void myinit(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void setPixel(GLint x, GLint y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}
void drawEllipse(){

    p1 = (ry * ry) - (rx * rx * ry) + ((0.25) * rx * rx);
    

    x = 0;
    y = ry;
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    while (dx < dy) {
        setPixel(x + xCenter, y + yCenter);
        setPixel(-x + xCenter, y + yCenter);
        setPixel(-x + xCenter, -y + yCenter);
        setPixel(x + xCenter, -y + yCenter);

        if (p1 < 0) {
            x = x + 1;
            dx = 2 * ry * ry * x;
            p1 = p1 + (ry * ry) + dx;
        } else {
            y = y - 1;
            x = x + 1;
            dx = 2 * (ry * ry) * x;
            dy = 2 * (rx * rx) * y;
            p1 = p1 + (ry * ry) + dx - dy;
        }
    }
	p2 = ((ry * ry) * (x + 0.5) * (x + 0.5)) + (rx * rx * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    while (y > 0) {
        setPixel(x + xCenter, y + yCenter);
        setPixel(-x + xCenter, y + yCenter);
        setPixel(-x + xCenter, -y + yCenter);
        setPixel(x + xCenter, -y + yCenter);

        if (p2 > 0) {
            x = x;
            y = y - 1;
            dy = 2 * rx * rx * y;
            p2 = p2 - dy + rx * rx;
        } else {
            x = x + 1;
            y = y - 1;
            dx = 2 * ry * ry * x;
            dy = 2 * rx * rx * y;
            p2 = p2 - dy + rx * rx + dx;
        }
    }


}



void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);

    drawEllipse();

    glFlush();
}

int main(int argc, char **argv) {
    printf("Enter Center Of Ellipse:\n\n");

    printf("X-coordinate   : ");
    scanf("%lf", &xCenter);
    printf("\nY-coordinate : ");
    scanf("%lf", &yCenter);
    printf("\nEnter a Semi Major Axis  : ");
    scanf("%lf", &rx);
    printf("\nEnter a Semi Minor Axis  : ");
    scanf("%lf", &ry);

    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(10, 10);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Midpoint Ellipse Drawing Algorithm");
    myinit();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

