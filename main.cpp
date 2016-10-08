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
	glColor3f(0,0,1);
    glBegin(GL_POINT);
    for ( float angulo = 0; angulo <= 2*PI; angulo+=incremento)
	{

		x =( .3) * cos (angulo);
		y =( .3) * sin (angulo);
		glVertex2f(x,y);
		A[cont]=x;
		cont+=1;
		A[cont]=y;
		cont+=1;

	}
	glEnd();

	glBegin(GL_LINE_STRIP);
	for (int x=0; x<numero_de_segmentos*2; x+=2)
    {
       glVertex2f(A[x],A[x+1]);
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

