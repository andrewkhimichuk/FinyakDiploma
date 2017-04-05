#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    crrntUser = NULL;

    ui->abcButton->setCheckable(true);
    ui->testabcButton->setCheckable(true);
    ui->studyButton->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveDataToDB()
{

}

void MainWindow::on_inputButton_clicked()
{
    crrntUser = new User();
    createUserData();
    qDebug() << ui->mainWidget->currentIndex();
    ui->mainWidget->setCurrentIndex(0);
}

void MainWindow::createUserData()
{
    crrntUser->name     = ui->userName->text();
    crrntUser->surname  = ui->surname->text();
    crrntUser->sex      = ui->Buttonman->isChecked();
    crrntUser->age      = ui->age->value();
    crrntUser->isDefect = ui->Buttonyes->isChecked();
}

void MainWindow::on_abcButton_clicked()
{
    ui->studyButton->setChecked(false);
    ui->testabcButton->setChecked(false);
}

void MainWindow::on_studyButton_clicked()
{
    ui->testabcButton->setChecked(false);
    ui->abcButton->setChecked(false);
}

void MainWindow::on_testabcButton_clicked()
{
    ui->studyButton->setChecked(false);
    ui->abcButton->setChecked(false);
}
