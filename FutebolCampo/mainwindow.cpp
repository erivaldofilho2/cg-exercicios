#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "GLPanel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->glwidget, SIGNAL(MousePos()), this, SLOT(MouseCurrentPos()) );
    connect(ui->glwidget, SIGNAL(MousePressed()), this, SLOT(MousePressed()) );
    connect(ui->glwidget, SIGNAL(MouseLeft()), this, SLOT(Mouseleft()) );

    connect(ui->boxRed, SIGNAL(valueChanged(double)), ui->glwidget, SLOT(valueRed(double)));
    connect(ui->boxBlue, SIGNAL(valueChanged(double)), ui->glwidget, SLOT(valueBlue(double)));
    connect(ui->boxGreen, SIGNAL(valueChanged(double)), ui->glwidget, SLOT(valueGreen(double)));

    connect(ui->boxEsp, SIGNAL(valueChanged(int)), ui->glwidget, SLOT(valueEsp(int)));

    connect(ui->radioBresen, SIGNAL(toggled(bool)), ui->glwidget, SLOT(valueBresen(bool)));
    connect(ui->radioEqReta, SIGNAL(toggled(bool)), ui->glwidget, SLOT(valueEqReta(bool)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

//Implementacoes de slots
void MainWindow::MouseCurrentPos()
{
    ui->lbPosicao->setText(QString ("X= %1, Y= %2")
                                      .arg(ui->glwidget->x)
                                      .arg(ui->glwidget->y));

    ui->lbEvento->setText("Mouse em movimento!");
}

void MainWindow::MousePressed()
{
    ui->lbEvento->setText(QString("Mouse pressionado! X=%1, Y=%2")
                                        .arg(ui->glwidget->x1)
                                        .arg(ui->glwidget->y1));

}

void MainWindow::Mouseleft()
{
    ui->lbEvento->setText("Mouse fora da tela!");
}


