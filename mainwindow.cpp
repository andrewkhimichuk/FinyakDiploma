#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDate>
#include <Qfile>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    crrntUser = NULL;

    ui->abcButton->setCheckable(true);
    ui->testabcButton->setCheckable(true);
    ui->studyButton->setCheckable(true);
    ui->nextabcButton->setObjectName("nextabcButton");
    ui->exitabcButton->setObjectName("exitabcButton");
    QFile styleF;

    styleF.setFileName(":/qss/style.css");
    styleF.open(QFile::ReadOnly);
    QString qssStr = styleF.readAll();

    qApp->setStyleSheet(qssStr);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::saveDataToDB()
{
    QFile file("db.csv");
        if (!file.open(QFile::WriteOnly|QIODevice::Append)) {
            qDebug() << file.errorString();
        }
        else
        {
            QString sex = crrntUser->sex?"1":"0";
            QString defect = crrntUser->isDefect?"1":"0";

            QTextStream stream(&file);
            stream << crrntUser->name << ";" << crrntUser->surname << ";" <<
                      sex << ";" <<QString::number(crrntUser->age) << ";" <<
                      defect << ";" << QDate::currentDate().toString() << "\n";

            qDebug() << stream.readAll();
            file.close();
         }
}

void MainWindow::on_inputButton_clicked()
{
    crrntUser = new User();
    createUserData();
    saveDataToDB();
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
    current_abc = 0;
    ui->stackedWidget->setCurrentIndex(0);
    ui->studyButton->setChecked(false);
    ui->testabcButton->setChecked(false);
    QString path = ":/quest/resources/abc.jpg";
    QPixmap pic(path);
    ui->letter_abc->setAlignment(Qt::AlignCenter);
    ui->letter_abc->setPixmap(pic);
    int w =  ui->letter_abc->width();
    int h =  ui->letter_abc->height();
    ui->letter_abc->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
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

void MainWindow::showLetter(int num)
{
    current_abc = num;
    QString path = ":/quest/resources/"+QString::number(num%33 + 1)+".jpg";
    QPixmap pic(path);
    if(pic.isNull())
       pic.load(":/quest/resources/default.jpg" );
    ui->letter_abc->setAlignment(Qt::AlignCenter);
    ui->letter_abc->setPixmap(pic);
    int w =  ui->letter_abc->width();
    int h =  ui->letter_abc->height();

    ui->letter_abc->setPixmap(pic.scaled(w,h,Qt::KeepAspectRatio));
}

void MainWindow::on_nextabcButton_clicked()
{
    showLetter(current_abc);
    current_abc++;
}

void MainWindow::on_outputButton_clicked()
{
    close();
}

void MainWindow::on_exitabcButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}
