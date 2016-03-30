#include <GL/glut.h>
#include <stdio.h>


// Define o vetor que desenha os pixel em um poligono de 32x32, como cada linha tem 32bit, ele divide esses bits em 
// 4 grupos de 8 bits e tronsformas esses 8 bits em hexadecimal. Na linha 8 (por exemplo), temos que 00000000110001000010001100000000, 
// equivalerá à seqüência "0x0, 0xc4, 0x23, 0x0".

GLubyte tux[] = {
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x7f,  0xfe,  0x0, 
 0x0,  0xc4,  0x23,  0x0, //Linha 8 
 0x1,  0x83,  0x21,  0x80, 
 0x1,  0x7,  0xe0,  0x80, 
 0x1,  0x7,  0xf0,  0x80, 
 0x1,  0x8f,  0xf9,  0x80, 
 0x0,  0xff,  0xff,  0x0, 
 0x0,  0x4f,  0xf1,  0x0, 
 0x0,  0x6f,  0xf1,  0x0, 
 0x0,  0x2f,  0xf3,  0x0, 
 0x0,  0x27,  0xe2,  0x0, 
 0x0,  0x30,  0x66,  0x0, 
 0x0,  0x1b,  0x1c,  0x0, 
 0x0,  0xb,  0x88,  0x0, 
 0x0,  0xb,  0x98,  0x0, 
 0x0,  0x8,  0x18,  0x0, 
 0x0,  0xa,  0x90,  0x0, 
 0x0,  0x8,  0x10,  0x0, 
 0x0,  0xc,  0x30,  0x0, 
 0x0,  0x6,  0x60,  0x0, 
 0x0,  0x3,  0xc0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0, 
 0x0,  0x0,  0x0,  0x0
};

GLfloat r,g,b; //Define variaveis float para OpemGL

//Declaração das funções
void init(void);
void display(void);
void keyboard(unsigned char key, int x, int y);
void mouse(int button, int state, int x, int y);

int main(int argc, char** argv){
  glutInit(&argc, argv);
  glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
  glutInitWindowSize (256, 256); //Define o tamanho da janela
  glutInitWindowPosition (100, 100); //Define a posição que a janela vai abrir
  glutCreateWindow ("Preenchendo regiões");//Define o titulo da janela
  init();
  glutDisplayFunc(display); //Chama a função que faz o densenho na tela
  glutKeyboardFunc(keyboard); //Chama a função de interação com o teclado
  glutMouseFunc(mouse); //Chama a função de intereção com o mouse
  glutMainLoop(); // Deixa a janela em loop
  return 0;
}

void init(void){
  glClearColor(1.0, 1.0, 1.0, 1.0); // Define a cor de fundo da janela
  glOrtho (0, 256, 0, 256, -1 ,1); //Define as coordenadas da janela
  r=0; g=1; b=0;
}

void display(void){
  int i;
  glClear(GL_COLOR_BUFFER_BIT);
  glDisable(GL_POLYGON_STIPPLE);

  //Desenha o primeiro quadrado
  glPolygonMode(GL_BACK, GL_LINE); //Define que o poligono será desenhada apenas com a linha de contorno externo
  glColor3f(1.0, 0.0, 0.0); //Define a cor corrente
  glBegin(GL_POLYGON); // Inicia o desenho do poligo com os vertices abaixo
  glVertex2i(30,226);  glVertex2i(113,226); //Vertices do poligono
  glVertex2i(113,143); glVertex2i(30,143); 
  glEnd();// Com o fechamento do poligono, o poligo vai ser desenhado com os vertices que estão entre glBegin(GL_POLYGON)
          //e glEnd()

  //Desenha o segundo quadrado
  glPolygonMode(GL_BACK, GL_FILL);
  glColor3f(r, g, b);
  glBegin(GL_POLYGON);
  glVertex2i(143,226); glVertex2i(226,226);
  glVertex2i(226,143); glVertex2i(143,143); 
  glEnd();

  //Desenha o terceiro quadrado definindo uma cor em cada vertice com isso o OpenGL interpola estas cores 
  //para compor as tonalidades no interior do polígono, resultando no efeito observado.
  glBegin(GL_POLYGON);
  glColor3f(1.0, 0.0, 0.0);  glVertex2i(30,113);  
  glColor3f(0.0, 1.0, 0.0);  glVertex2i(113,113);
  glColor3f(0.0, 0.0, 1.0);  glVertex2i(113,30);  
  glColor3f(1.0, 1.0, 0.0);  glVertex2i(30,30); 
  glEnd();

  //Desenha o quarto quadrado
  glEnable(GL_POLYGON_STIPPLE); //Habilita a possibilidade de desenha dentro do poligono usando padrões de desenho
  glColor3f(1.0, 0.0, 1.0); 
  glPolygonStipple(tux); // chama a função que desenha dentro do poligono, passando o array tux[] dos pontos
                         // que vão ser desenhados 
  glBegin(GL_POLYGON); //Desenha o poligono
  glVertex2i(143,113); glVertex2i(226,113);
  glVertex2i(226,30); glVertex2i(143,30); 
  glEnd();
  glFlush();
  glutSwapBuffers();
}

//Função que finaliza o programa se a tecla 'esc'(27) for pressionada.
void keyboard(unsigned char key, int x, int y){
  switch (key) {
  case 27:
	exit(0);
	break;
  }
}

//Função que trata as iterações com o mouse
void mouse(int button, int state, int x, int y){
  switch (button) {
  case GLUT_LEFT_BUTTON: // se botão esquerdo pressionado
	if (state == GLUT_DOWN) {  // Quando estiver precionado pra baixo
	  r=(GLfloat)rand()/(RAND_MAX+1.0); //muda o valor do r de somando um valor_aleatorio + 1.
	  g=(GLfloat)rand()/(RAND_MAX+1.0); // Isso faz com as cores no quadrado mude
	  b=(GLfloat)rand()/(RAND_MAX+1.0);
	  glutPostRedisplay();
	}
	break;
  }
}