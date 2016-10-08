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
    int numero_de_segmentos=7; //Se define en cuantos segmentos ,se dividira la circunferencia.
    float incremento = ceil((2*PI)/numero_de_segmentos);
	glClear(GL_COLOR_BUFFER_BIT);
	float A[numero_de_segmentos*2];
	float x,y;
	int cont=0;
	int a=52;
	int b=62;
	glColor3f(0,0,1);
    glBegin(GL_POINT);
    for ( float angulo = 0; angulo <= 2*PI; angulo+=0.001)
	{
        //hiperbola abierta de derecha a izquierda
		x =(a * 1/cos(angulo))+45;
		y =(b * tan (angulo))+60;
		glVertex2f(x,y);

	}
	glEnd();
	glColor3f(1,0,1);
    glBegin(GL_POINT);
    for ( float angulo = 0; angulo <= 2*PI; angulo+=0.001)
	{
        //hiperbola abierta de arriba a abajo
		x =(a * tan(angulo))+45;
		y =(b * 1/cos(angulo))+60;
		glVertex2f(x,y);

	}
	glEnd();


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
