#include <GL/glut.h>
#include <stdio.h>

float red[4]={0},green[4]={0},blue[4]={0},temp[3]={0};

void init(void){
	glClearColor(0.0,0.0,0.0,.0);
	glMatrixMode(GL_PROJECTION);
	glOrtho(0.0,500.0,0.0,400,-1.0,1.0);

	red[0] = 0.0;
	green[0] = 0.0;
	blue[0] = 1.0;

	red[1] = 1.0;
	green[1] = 0.0;
	blue[1] = 0.0;

	red[2] = 1.0;
	green[2] = 1.0;
	blue[2] = 0.0;

	red[3] = 0.0;
	green[3] = 1.0;
	blue[3] = 0.0;
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


	glColor3f(red[0],green[0],blue[0]);
	glBegin(GL_TRIANGLES);
		glVertex2f(250.0f,250.0f);
		glVertex2f(230.0f,200.0f);
		glVertex2f(270.0f,200.0f);
	glEnd();


	glColor3f(red[1],green[1],blue[1]);
	glBegin(GL_TRIANGLES);
		glVertex2f(250.0f,250.0f);
		glVertex2f(300.0f,270.0f);
		glVertex2f(300.0f,230.0f);
	glEnd();

	glColor3f(red[2],green[2],blue[2]);
	glBegin(GL_TRIANGLES);
		glVertex2f(250.0f,250.0f);
		glVertex2f(230.0f,300.0f);
		glVertex2f(270.0f,300.0f);
	glEnd();

	glColor3f(red[3],green[3],blue[3]);
	glBegin(GL_TRIANGLES);
		glVertex2f(250.0f,250.0f);
		glVertex2f(200.0f,270.0f);
		glVertex2f(200.0f,230.0f);
	glEnd();
	glFlush();
}
void mouse_click(int button, int state, int x, int y)
{
	if ( state == GLUT_DOWN ) {
		
			switch ( button ) {
				case GLUT_LEFT_BUTTON:
					temp[0] = red[3];
					temp[1] = green[3];
					temp[2] = blue[3];

					red[3] = red[2];
					green[3] = green[2];
					blue[3] = blue[2];

					red[2] = red[1];
					green[2] = green[1];
					blue[2] = blue[1];

					red[1] = red[0];
					green[1] = green[0];
					blue[1] = blue[0];

					red[0] = temp[0];
					green[0] = temp[1];
					blue[0] = temp[2];

					glutPostRedisplay();
					break;

				case GLUT_RIGHT_BUTTON:
					temp[0] = red[0];
					temp[1] = green[0];
					temp[2] = blue[0];

					red[0] = red[1];
					green[0] = green[1];
					blue[0] = blue[1];

					red[1] = red[2];
					green[1] = green[2];
					blue[1] = blue[2];

					red[2] = red[3];
					green[2] = green[3];
					blue[2] = blue[3];

					red[3] = temp[0];
					green[3] = temp[1];
					blue[3] = temp[2];

					glutPostRedisplay();
					break;

				default:
					break;
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
