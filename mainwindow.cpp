#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDate>
#include <Qfile>
#include <QMovie>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    crrntUser = NULL;
    current_type = 0;
    ui->abcButton->setCheckable(true);
    ui->testabcButton->setCheckable(true);
    ui->studyButton->setCheckable(true);
    ui->nextabcButton->setObjectName("nextabcButton");
    ui->exitabcButton->setObjectName("exitabcButton");
    ui->nextStdAnmlBttn->setObjectName("nextStdAnmlBttn");
    ui->exitanButton->setObjectName("exitanButton");
    ui->no_abcButton->setObjectName("no_abcButton");
    ui->exitstudyBttn->setObjectName("exitstudyBttn");
    ui->yes_abcButton->setObjectName("yes_abcButton");
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
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_testabcButton_clicked()
{
    ui->studyButton->setChecked(false);
    ui->abcButton->setChecked(false);
    ui->stackedWidget->setCurrentIndex(4);
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

void MainWindow::showAnimal(int num)
{
     current_abc = num;

     QString path = ":/quest/resources/animals/an_"+QString::number(num%4 + 1)+".jpg";
     QPixmap pic(path);
     if(pic.isNull())
        pic.load(":/quest/resources/default.jpg" );
     ui->anmlPic->setAlignment(Qt::AlignCenter);

     ui->anmlPic->setPixmap(pic.scaled(250,250,Qt::KeepAspectRatio));

     //ui->anmlPic->setPixmap(pic);

     if(mv) {delete mv; mv = NULL; ui->anmlGif->clear();}

     mv = new QMovie("resources/animals/an_"+QString::number(num%4 + 1)+".gif");
     mv->start();
     ui->anmlGif->setAttribute(Qt::WA_NoSystemBackground);
     ui->anmlGif->setMovie(mv);

     QString path2 = ":/quest/resources/animals/an_abc_"+QString::number(num%4 + 1)+".jpg";
     QPixmap pic2(path2);
     if(pic2.isNull())
        pic2.load(":/quest/resources/default.jpg" );
     ui->anmlWrd->setAlignment(Qt::AlignCenter);
     ui->anmlWrd->setPixmap(pic2);

}
void MainWindow::showFruit(int num)
{
     current_abc = num;

     QString path = ":/quest/resources/fruit/fr_"+QString::number(num%10 + 1)+".jpg";
     QPixmap pic(path);
     if(pic.isNull())
        pic.load(":/quest/resources/default.jpg" );
     ui->anmlPic->setAlignment(Qt::AlignCenter);

     ui->anmlPic->setPixmap(pic.scaled(250,250,Qt::KeepAspectRatio));

     //ui->anmlPic->setPixmap(pic);

     if(mv) {delete mv; mv = NULL; ui->anmlGif->clear();}

     mv = new QMovie("resources/fruit/fr_"+QString::number(num%10 + 1)+".gif");
     mv->start();
     ui->anmlGif->setAttribute(Qt::WA_NoSystemBackground);
     ui->anmlGif->setMovie(mv);

     QString path2 = ":/quest/resources/fruit/fr_abc_"+QString::number(num%10 + 1)+".jpg";
     QPixmap pic2(path2);
     if(pic2.isNull())
        pic2.load(":/quest/resources/default.jpg" );
     ui->anmlWrd->setAlignment(Qt::AlignCenter);
     ui->anmlWrd->setPixmap(pic2);

}
void MainWindow::showVeg(int num)
{
     current_abc = num;

     QString path = ":/quest/resources/vegetable/veg_"+QString::number(num%10 + 1)+".jpg";
     QPixmap pic(path);
     if(pic.isNull())
        pic.load(":/quest/resources/default.jpg" );
     ui->anmlPic->setAlignment(Qt::AlignCenter);

     ui->anmlPic->setPixmap(pic.scaled(250,250,Qt::KeepAspectRatio));

     //ui->anmlPic->setPixmap(pic);

     if(mv) {delete mv; mv = NULL; ui->anmlGif->clear();}

     mv = new QMovie("resources/vegetable/veg_"+QString::number(num%10 + 1)+".gif");
     mv->start();
     ui->anmlGif->setAttribute(Qt::WA_NoSystemBackground);
     ui->anmlGif->setMovie(mv);

     QString path2 = ":/quest/resources/vegetable/veg_abc_"+QString::number(num%10 + 1)+".jpg";
     QPixmap pic2(path2);
     if(pic2.isNull())
        pic2.load(":/quest/resources/default.jpg" );
     ui->anmlWrd->setAlignment(Qt::AlignCenter);
     ui->anmlWrd->setPixmap(pic2);

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

void MainWindow::on_an_studyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    mv = NULL;
    current_abc = 0;
    current_type = 1;
    showAnimal(current_abc);
}

void MainWindow::on_nextStdAnmlBttn_clicked()
{
    current_abc++;
    if (current_type == 1 )
       showAnimal(current_abc);
    if (current_type == 2 )
       showFruit(current_abc);
    if(current_type == 3 )
      showVeg(current_abc);
}

void MainWindow::on_exitanButton_clicked()
{
   ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_veg_studyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    mv = NULL;
    current_abc = 0;
    current_type = 3;
    showVeg(current_abc);
}

void MainWindow::on_fr_studyButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    mv = NULL;
    current_abc = 0;
    current_type = 2;
    showFruit(current_abc);
}

void MainWindow::on_test1vegetableButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_test2vegetableButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_exitstudyBttn_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_exit_test_abcButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_test1fruitButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_test2fruitButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_test1anButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_test2anButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}

void MainWindow::on_test1vegButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_test2vegButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);
}
