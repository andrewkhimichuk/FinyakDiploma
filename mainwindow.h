#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAxObject>
#include <QRadioButton>
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
    void showTwoPics();
    void on_testabcButton_clicked();
    void showChooseLetter();
    void on_nextabcButton_clicked();

    void on_outputButton_clicked();

    void on_exitabcButton_clicked();

    void on_an_studyButton_clicked();

    void on_nextStdAnmlBttn_clicked();

    void on_exitanButton_clicked();

    void on_veg_studyButton_clicked();

    void on_fr_studyButton_clicked();

    void on_test1vegetableButton_clicked();

    void on_test2vegetableButton_clicked();

    void on_exitstudyBttn_clicked();

    void on_exit_test_abcButton_clicked();

    void on_test1fruitButton_clicked();

    void on_test2fruitButton_clicked();

    void on_test1anButton_clicked();

    void on_test2anButton_clicked();

    void on_test1vegButton_clicked();

    void on_test2vegButton_clicked();

    void on_yes_abcButton_clicked();

    void on_no_abcButton_clicked();

    void on_next_test_abcButton_clicked();

private:
    void showLetter(int);
    void showAnimal(int);
    void saveDataToDB();
    void showFruit(int);
    void showVeg(int);

    int current_abc;
    int current_type;

    int crrnt_std_frst;
    int crrnt_std_sknd;
    int crrnt_std_score;
    int crrnt_abc_nmbrs;

    int crrnt_test_answer;
    QVector<QRadioButton*> testButtons;

    QMovie *mv;
    Ui::MainWindow *ui;
    User *crrntUser;
};

#endif // MAINWINDOW_H
