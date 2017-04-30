#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxObject>
#include <QFile>

struct User {
    QString name;
    QString surname;
    bool sex;
    int age;
    bool isDefect;
};

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_inputButton_clicked();
    void createUserData();
    void on_abcButton_clicked();
    void on_studyButton_clicked();
    void on_testabcButton_clicked();

    void on_nextButton_clicked();

private:
    void showLetter(int);
    void saveDataToDB();

    int current_abc;
    Ui::MainWindow *ui;
    User *crrntUser;
};

#endif // MAINWINDOW_H
