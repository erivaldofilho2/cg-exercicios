#ifndef GLPANEL_H
#define GLPANEL_H

#include <QObject>
#include <QOpenGLWidget>

class GLPanel : public QOpenGLWidget
{
    Q_OBJECT

public:
    explicit GLPanel(QWidget *parent = 0);

    void Draw();

    //Funcoes padrão do QMouseEvent
    void mouseMoveEvent(QMouseEvent *evento);
    void mousePressEvent(QMouseEvent *evento);
    void leaveEvent(QEvent *);

    int x, y;
    int xc, yc;
    int x1 = 0, y1 = 0, x2 = 0, y2 = 0;

    double red=0.0,green=0.0,blue=0.0;

    int pontos[8][2];

    int clique = 0;
    int esp = 0;

    // Se equacao da reta valor = 0, se Bresenhan valor = 1
    int reta=0;

private:
    int windowHeigth;
    int windowWidth;

    //Funcoes padrão do QOpenGLWidget
protected:
    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();

signals:
    void MousePressed();
    void MousePos();
    void MouseLeft();


public slots:
    void valueRed(double red);
    void valueGreen(double green);
    void valueBlue(double blue);
    void valueEsp(int esp);

   void valueBresen(bool value);
   void valueEqReta(bool value);
};

#endif // GLPANEL_H
