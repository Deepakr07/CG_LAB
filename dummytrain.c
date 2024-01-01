#include <GL/glut.h>
#include <GL/glu.h>
#include <stdio.h>

float trainPositionX = 0.0; // Initial position of the train

void init() {
    glClearColor(1, 1, 1, 0);
    gluOrtho2D(0, 500, 0, 500);
}

void drawTrain() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Update train position for animation
    trainPositionX += 1.0; // Adjust the speed as needed

    // Restart animation when the train goes outside the track
    if (trainPositionX > 500) {
        trainPositionX = -200; // Set to an initial position off-screen
    }

    // Draw the first bogey
    glBegin(GL_POLYGON);
    glColor3f(1, 0, 0);
    glVertex2i(100 + trainPositionX, 50);
    glVertex2i(200 + trainPositionX, 50);
    glVertex2i(200 + trainPositionX, 150);
    glVertex2i(100 + trainPositionX, 150);
    glEnd();

    // Draw the connection link
    glBegin(GL_POLYGON);
    glColor3f(0, 0, 0);
    glVertex2i(200 + trainPositionX, 75);
    glVertex2i(250 + trainPositionX, 75);
    glVertex2i(250 + trainPositionX, 100);
    glVertex2i(200 + trainPositionX, 100);
    glEnd();

    // Draw the second bogey
    glBegin(GL_POLYGON);
    glColor3f(0, 1, 0);
    glVertex2i(250 + trainPositionX, 50);
    glVertex2i(350 + trainPositionX, 50);
    glVertex2i(350 + trainPositionX, 150);
    glVertex2i(250 + trainPositionX, 150);
    glEnd();

    // Draw the tracks
    glBegin(GL_LINES);
    glColor3f(0, 0, 0);
    glVertex2i(0, 50);
    glVertex2i(500, 50);
    glVertex2i(0, 30);
    glVertex2i(500, 30);
    glEnd();

    glFlush();
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitWindowPosition(300, 400);
    glutInitWindowSize(400, 400);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Train Animation");
    init();
    glutDisplayFunc(drawTrain);
    glutIdleFunc(drawTrain); // Register the drawTrain function for continuous animation
    glutMainLoop();
    return 0;
}

