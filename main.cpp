#include <GL/glut.h>
#include <cmath>

float WinHei = 400;
float WinWid = 800;
bool mouse = true;
int mx, my;

void createTriangle(int x, int y) {
    glColor3ub(255, 0, 0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0 + x, 0 * sqrt(3) + y);
    glVertex2f(-100.0 + x, -100 * sqrt(3) + y);
    glVertex2f(100.0 + x, -100 * sqrt(3) + y);
    glEnd();
    glFlush();
}

void display(void) {
        glClearColor(37.0 / 255.0, 133.0 / 255.0, 75.0 / 255.0, 1.0);
        glClear(GL_COLOR_BUFFER_BIT);
        glFlush();
}

void MousePressed(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON) {
        if (state == GLUT_DOWN) {
            display();
            createTriangle(x - WinWid/2, -y+WinHei/2);
            mouse = false;
        } else if (state == GLUT_UP) {
            display();
            mouse = true;
        }
    }
}

void Reshape(int w, int h) {
    WinWid = w;
    WinHei = h;

    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -200.0, 200.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void Initialize(void) {
    glClearColor(37.0 / 255.0, 133.0 / 255.0, 75.0 / 255.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-WinWid / 2, WinWid / 2, -WinHei / 2, WinHei / 2, -200.0, 200.0);
}

void getCurrentPos(int x, int y) {
    mx = x - WinWid/2;
    my = -y + WinHei/2;
    if (mouse == false){
        display();
        createTriangle(mx, my);
    }
}

int main(int argc, char **argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WinWid, WinHei);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("Pretty triangle");
    glutDisplayFunc(display);
    glutReshapeFunc(Reshape);
    glutMouseFunc(MousePressed);
    glutMotionFunc(getCurrentPos);
    Initialize();
    glutMainLoop();
}