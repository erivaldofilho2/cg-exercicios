#include <GL/glut.h>
#include <stdio.h>

float red,green,blue;
int clique;

void init(void){
	glClearColor(0.0,0.0,0.0,.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0,500.0,0.0,400,-1.0,1.0);
	red=0.0;
	green=0.0;
	blue=0.0;
	clique = 0;
}


void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,1.0,1.0);

	glBegin(GL_POLYGON);
	glVertex3f(249.0f,250.0f,-1.0f);
	glVertex3f(251.0f,250.0f,-1.0f);
	glVertex3f(249.0f,100.0f,-1.0f);
	glVertex3f(251.0f,100.0f,-1.0f);
	glEnd();


	glColor3f(red+0.0,green+0.0,1.0-blue);
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f,250.0f);
	glVertex2f(230.0f,200.0f);
	glVertex2f(270.0f,200.0f);
	glEnd();

	
	glColor3f(1.0-red,green+0.0,blue+0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f,250.0f);
	glVertex2f(230.0f,300.0f);
	glVertex2f(270.0f,300.0f);
	glEnd();

	glColor3f(1.0-red,1.0-green,blue+0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f,250.0f);
	glVertex2f(200.0f,270.0f);
	glVertex2f(200.0f,230.0f);
	glEnd();

	glColor3f(red+0.0,1.0-green,blue+0.0);
	glBegin(GL_TRIANGLES);
	glVertex2f(250.0f,250.0f);
	glVertex2f(300.0f,270.0f);
	glVertex2f(300.0f,230.0f);
	glEnd();

	glFlush();
}
void mouse_click(int button, int state, int x, int y)
{
	if ( state == GLUT_DOWN ) {
		clique ++;	
		if(clique <= 8){
			switch ( button ) {
				case GLUT_LEFT_BUTTON:

				exit( 0 );
				case GLUT_RIGHT_BUTTON:
				red = red + 0.1;
				green = green + 0.1;
				blue = blue + 0.1;
				glutPostRedisplay();
				break;
				default:
				break;
			}
		} 
		else {
			red=0.0;
			green=0.0;
			blue=1.0;
			clique = 0;
		}
	}

}
int main(int argc, char** argv){
	glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 400);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Flor de Abril");

	init();
	glutMouseFunc(mouse_click); 

	glutDisplayFunc(display);
	glutMainLoop();

	return 0;

}
