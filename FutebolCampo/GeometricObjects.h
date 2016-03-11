#ifndef GEOMETRICOBJECTS_H
#define GEOMETRICOBJECTS_H

#include <QObject>
#include<QOpenGLWidget>

class GeometricObjects
{
public:
    GeometricObjects();
    void equacaoReta(int x1, int y1,int x2, int y2, double red, double green, double blue, int esp);
    void bresenham(int x1, int y1,int x2, int y2, double red, double green, double blue, int esp);

    void circulo(int xc, int yc, int raio);

//    void pontoMedioCirculo(int raio);

    void desenhaCampoEquacaoReta();
    void desenhaCampoBresenham();

    int getX(int x);
    int getY(int y);

};

#endif // GEOMETRICOBJECTS_H
