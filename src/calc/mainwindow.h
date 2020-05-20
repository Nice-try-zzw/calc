//author:Nice_try
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <map>
#include <stack>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
private slots:

    bool jud(QString sh);

    void init();

    void work(char wit);

    void fslove(QString sh);

    void makeit();

    void on_pbtnfou_clicked();

    void on_pbtnpoint_clicked();

    void on_pbtnans_clicked();

    void on_pbtnclear_clicked();

    void on_pbtnhuo_clicked();

    void on_pbtn1_clicked();

    void on_pbtn2_clicked();

    void on_pbtn3_clicked();

    void on_pbtn4_clicked();

    void on_pbtn5_clicked();

    void on_pbtn6_clicked();

    void on_pbtn7_clicked();

    void on_pbtn8_clicked();

    void on_pbtn9_clicked();

    void on_pbtn0_clicked();

    void on_pbtnplus_clicked();

    void on_pbtnjian_clicked();

    void on_pbtncheng_clicked();

    void on_pbtnchu_clicked();

    void on_pbtnbing_clicked();

    void on_pbtnzuo_clicked();

    void on_pbtnyou_clicked();

    void on_pbtnback_clicked();

    void runError();
private:
    Ui::MainWindow *ui;
    QString sh,rsh;
    map<char, int> ys;
    stack<char> stk_ch;
    stack<double> stk_di;
    int err = 0;//是否出现错误
    int solve[10][10];//第一维表示待入栈运算符 第二表示栈顶运算符
    //值为1 表示栈顶运算符出栈进行操作
    //值为0 表示待入栈运算符入栈
    //值为2 表示待入栈运算符出栈  栈顶运算符出栈  （）以及##
    int ans;
};
#endif // MAINWINDOW_H
