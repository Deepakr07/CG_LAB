#include <stdio.h>
#include <GL/glut.h>

int X_origin, Y_origin, rx, ry;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 1.0, 1.0);
    glPointSize(2.0);

    int x = 0, y = ry;
    float dx, dy, p1, p2;
    p1 = (ry * ry) - (rx * rx * ry) + (0.25 * rx * rx);
    dx = 2 * ry * ry * x;
    dy = 2 * rx * rx * y;

    glBegin(GL_POINTS);
    while (dx < dy) {
        x++;
        if (p1 < 0) {
            dx += 2 * ry * ry;
            p1 += dx + (ry * ry);
        } else {
            y--;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            p1 += dx - dy + (ry * ry);
        }
        glVertex2i(X_origin + x, Y_origin - y);
        glVertex2i(X_origin - x, Y_origin - y);
        glVertex2i(X_origin + x, Y_origin + y);
        glVertex2i(X_origin - x, Y_origin + y);
    }

    p2 = ((ry * ry) * ((x + 0.5) * (x + 0.5))) + ((rx * rx) * ((y - 1) * (y - 1))) - (rx * rx * ry * ry);
    while (y > 0) {
        y--;
        if (p2 > 0) {
            dy -= 2 * rx * rx;
            p2 += (rx * rx) - dy;
        } else {
            x++;
            dx += 2 * ry * ry;
            dy -= 2 * rx * rx;
            p2 += dx - dy + (rx * rx);
        }
        glVertex2i(X_origin + x, Y_origin - y);
        glVertex2i(X_origin - x, Y_origin - y);
        glVertex2i(X_origin + x, Y_origin + y);
        glVertex2i(X_origin - x, Y_origin + y);
    }
    glEnd();

    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0, 700.0, 0.0, 700.0);
}

int main(int argc, char **argv) {
    printf("Enter X_origin, Y_origin, and two radii:\n");
    scanf("%d%d%d%d", &X_origin, &Y_origin, &rx, &ry);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Ellipse Drawing");
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(1600, 1700);
    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

