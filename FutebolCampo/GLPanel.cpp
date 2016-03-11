#include "GLPanel.h"
#include "GeometricObjects.h"
#include <QMouseEvent>

#include <stdio.h>

GLPanel::GLPanel(QWidget *parent) : QOpenGLWidget(parent)
{

}

void GLPanel::Draw()
{
    GeometricObjects ob;
    if(this->reta == 0){
        if(this->clique%2==0){
        ob.equacaoReta(this->x1,this->y1,this->x2,this->y2, this->red, this->green, this->blue, this->esp);
//        printf("clque = %d",this->clique);
        }
        ob.desenhaCampoEquacaoReta();

    }else if(this->reta == 1){
        if(this->clique%2==0){
        ob.bresenham(this->x1,this->y1,this->x2,this->y2, this->red, this->green, this->blue, this->esp);
        }
        ob.desenhaCampoBresenham();

    }
    update();
}

//MouseEvent
void GLPanel::mouseMoveEvent(QMouseEvent *evento)
{
    this->x = evento->x();
    this->y = evento->y();
    makeCurrent();
    doneCurrent();
    emit MousePos();
}

void GLPanel::mousePressEvent(QMouseEvent *evento)
{

    if(clique%2 == 1 && this->clique != 0){
        this->x1 = evento->x();
        this->y1 = evento->y();
    }else if(clique%2 == 0){
        this->x2 = evento->x();
        this->y2 = evento->y();
        paintGL();
    }
    this->clique++;
    emit MousePressed();
}

void GLPanel::leaveEvent(QEvent *)
{
    emit MouseLeft();
}


//OpenGL
void GLPanel::initializeGL()
{
    glClearColor(0.5,0.7,0.0,.0);
}

void GLPanel::resizeGL(int w, int h)
{
    this->windowHeigth = h;
   this->windowWidth = w;

   glViewport(0,0,w,h);
   glMatrixMode(GL_PROJECTION);
   glLoadIdentity();

   glOrtho(0,w,0,h,1,-1);
   glMatrixMode(GL_MODELVIEW);
   glLoadIdentity();
}

void GLPanel::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    Draw();
}

void GLPanel::valueRed(double red)
{
    this->red = red;
}

void GLPanel::valueGreen(double green)
{
       this->green = green;
}

void GLPanel::valueBlue(double blue)
{

    this->blue = blue;
}

void GLPanel::valueEsp(int esp)
{
    this->esp = esp;
}

void GLPanel::valueEqReta(bool value)
{
    if(value){
        this->reta = 0;
    }
}

void GLPanel::valueBresen(bool value)
{
    if(value){
        this->reta = 1;
    }

}


