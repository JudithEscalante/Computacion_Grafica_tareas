#include <GL/glut.h>
#include <math.h>
#include <iostream>
using namespace std;
const float PI =3.141592653;
void init()
{
	glClearColor(1,1,1,0);
	glShadeModel(GLU_FLAT);
	glPointSize( 6.0 );
}
void display()
{
    float x1=7.5; //la primera coordenada
    float y1=3.6; //la primera coordenada
    float x2=10.6;//la segunda coordenada
    float y2= 13.7; //la segunda coordenada
    float dx=x2-x1, dy=y2-y1;
    float d=2*dy-dx;
    float incremento1=2*dy;
    float incremento2=2*(dy-dx);
    float xp=x1, yp=y1;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,1);
    glBegin(GL_POINT);
    glVertex2f(xp,yp);
    while (xp <= x2)
    {
        if(d<=0)
        {
            d=d+incremento1;
            xp+=1.0;
        }
        else{
            d=d+incremento2;
            xp+=1.0;
            yp+=1.0;
        }
        glVertex2f(xp,yp);
    }

	glEnd();



	glutSwapBuffers();
}
int main(int argc , char * argv[])
{
    int num;
	glutInit(& argc , argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

	// Window of drawing
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100 , 100);
	glutCreateWindow("Poligono regular");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

