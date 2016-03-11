#include "GeometricObjects.h"
#include <stdio.h>
#include <cmath>


GeometricObjects::GeometricObjects()
{

}

void GeometricObjects::equacaoReta(int x1, int y1, int x2, int y2, double red, double green, double blue, int esp)
{
    int x,y,tmp;
    float a;
    int dx = abs(x2 - x1);
    int dy = abs(y2 - y1);

    x1 = getX(x1);
    y1 = getY(y1);
    x2 = getX(x2);
    y2 = getY(y2);

    if (x2 < x1){
        tmp = x1;
        x1 = x2;
        x2 = tmp;
        tmp = y1;
        y1 = y2;
        y2 = tmp;
    }

    if(y2 < y1){
        y1 = -y1;
        y2 = -y2;
    }

    if(dx < dy){

        a = (float)(y2-y1)/(x2-x1);

          //  printf(" 1 a igual a  %f\n",a);

        for (x = x1;  x <= x2; x++) {

            y = (y1 + (int)a*(x - x1));

//            printf("(%d,%d)\n",x,y);
            glColor3f(red,green,blue);
            glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
            glPointSize(esp);
            glBegin(GL_POINTS);
                glVertex2d(getX(x), getY(y));
            glEnd();
        }

    } else if(dx > dy){
        a = (float)(x2-x1)/(y2-y1);
        // printf("2 a igual a  %f\n",a);
        for (y = y1;  y <= y2; y++) {

            x = (x1 +(int)a*(y - y1));

            glColor3f(red,green,blue);
            glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
            glPointSize(esp);
            glBegin(GL_POINTS);
                glVertex2d(getX(x), y);
            glEnd();
        }
    }
}

void GeometricObjects::bresenham(int x1, int y1, int x2, int y2, double red, double green, double blue, int esp){

    int dx, dy, incX, incY, incE, incNE, d;

    dx = abs(x2 - x1);
    dy = abs(y2 - y1);

    if (x1 > x2) {
        incX = -1;
    }
    else {
        incX = 1;
    }
    if (y1 > y2){
        incY = -1;
    }
    else {
        incY = 1;
    }

    if (dx >= dy) {
        incE  = 2*dy;
        incNE = incE - (2*dx);
        d    = incE - dx;
        for (; dx>=0; dx--) {
            glColor3f(red,green,blue);
            glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
            glPointSize(esp);
            glBegin(GL_POINTS);
                glVertex2d(getX(x1), getY(y1));
            glEnd();
            if (d > 0) {
                x1+=incX;
                y1+=incY;
                d+=incNE;
            }
            else {
                x1+=incX;
                d+=incE;
            }
        }
    }
    else {
        incE = 2*dx;
        incNE = incE - (2*dy);
        d = incE - dy;
        for (; dy>=0; dy--) {
            glColor3f(red,green,blue);
            glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
            glPointSize(esp);
            glBegin(GL_POINTS);
                glVertex2d(getX(x1), getY(y1));
            glEnd();
            if (d > 0) {
                x1+=incX;
                y1+=incY;
                d+=incNE;
            }
            else {
                y1+=incY;
                d+=incE;
            }
        }
    }
}


void GeometricObjects::circulo(int xc, int yc, int raio) {

    int x, y;

    //quantidade de pontos que serao tracados, quando maior, mais definido
    float circle = 500;
    double pi = 3.1415;
    float angulo;

    for (int i = 0; i < circle; i++) {
        angulo = - pi*(i/circle);
        x = xc - cos(angulo)*raio;
        y = yc - sin(angulo)*raio;

        glColor3f(1,1,1);
          glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
          glPointSize(1);
          glBegin(GL_POINTS);
              glVertex2d(getX(x), getY(y));
        glEnd();
    }
    for (int i = 0; i < circle; i++) {
        angulo =  pi*(i/circle);
        x = xc - cos(angulo)*raio;
        y = yc - sin(angulo)*raio;

        glColor3f(1,1,1);
          glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
          glPointSize(1);
          glBegin(GL_POINTS);
              glVertex2d(getX(x), getY(y));
        glEnd();
    }

}

//void GeometricObjects::pontoMedioCirculo(int raio)
//{
//    int x, y;
//    float d;
//    x = 300;
//    y=300+raio;
//    d = 5/4 - raio;
//    glColor3f(1,1,1);
//      glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
//      glPointSize(1);
//      glBegin(GL_POINTS);
//          glVertex2d(getX(x), getY(y));
//    glEnd();

//    while (y > x) {
//        if(d <0){
//            d = d+2*x+3;
//            x++;
//        }else{
//            d = d+2*(x-y)+5;
//            x++;
//            y--;
//        }
//        glColor3f(1,0,0);
//          glBlendFunc(GL_DST_ALPHA,GL_ONE_MINUS_DST_ALPHA);
//          glPointSize(1);
//          glBegin(GL_POINTS);
//              glVertex2d(getX(x), getY(y));
//        glEnd();
//    }

//}

void GeometricObjects::desenhaCampoEquacaoReta()
{
    equacaoReta(200,300,500,300,1,1,1,2);
    equacaoReta(200,100,500,100,1,1,1,2);

    equacaoReta(200,100,200,300,1,1,1,2);
    equacaoReta(500,100,500,300,1,1,1,2);
    equacaoReta(350,100,350,300,1,1,1,2);

    equacaoReta(200,100,500,100,1,1,1,2);

    equacaoReta(200,150,250,150,1,1,1,2);
    equacaoReta(200,250,250,250,1,1,1,2);
    equacaoReta(250,150,250,250,1,1,1,2);

    equacaoReta(450,150,500,150,1,1,1,2);
    equacaoReta(450,250,500,250,1,1,1,2);
    equacaoReta(450,150,450,250,1,1,1,2);

    equacaoReta(450,150,450,250,1,1,1,2);
    circulo(350,200,50);

//     pontoMedioCirculo(20);
}

void GeometricObjects::desenhaCampoBresenham()
{
    bresenham(200,300,500,300,1,1,1,2);
    bresenham(200,100,500,100,1,1,1,2);

    bresenham(200,100,200,300,1,1,1,2);
    bresenham(500,100,500,300,1,1,1,2);
    bresenham(350,100,350,300,1,1,1,2);

    bresenham(200,100,500,100,1,1,1,2);

    bresenham(200,150,250,150,1,1,1,2);
    bresenham(200,250,250,250,1,1,1,2);
    bresenham(250,150,250,250,1,1,1,2);

    bresenham(450,150,500,150,1,1,1,2);
    bresenham(450,250,500,250,1,1,1,2);
    bresenham(450,150,450,250,1,1,1,2);
    circulo(350,200,50);
    circulo(350,200,5);

//    pontoMedioCirculo(20);


}

int GeometricObjects::getX(int x)
{
    return x;
}

int GeometricObjects::getY(int y)
{
    return 400-y;
}
