//author:Nice_try
#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include <QDebug>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    setFixedSize(523,591);
    ui->text->setText("please press the button");
    sh.clear();
    init();
    setFixedSize(this->width(),this->height());
//    ui->pbtn0->setStyleSheet("QPushButton:hover{background-color: rgb(20, 62, 134);border:none;color:rgb(255, 255, 255);}"
//                             "QPushButton:checked{background-color: rgb(0,0,0);border:none;color:rgb(0,0,0);}");
//    this->setObjectName("mainWindow");
//    this->setStyleSheet("#mainWindow{border-image:url(:/doc/1.jpg);}");
//    ui->pbtn0->setObjectName("pp");
//    ui->pbtn0->setStyleSheet("#pp{border-image:url(:/doc/0.jpg)}");

//    ui->pbtn1->setObjectName("pp");
//    ui->pbtn1->setStyleSheet("#pp{border-image:url(:/doc/1.jpg)}");

//    ui->pbtn2->setObjectName("pp");
//    ui->pbtn2->setStyleSheet("#pp{border-image:url(:/doc/2.jpg)}");

//    ui->pbtn3->setObjectName("pp");
//    ui->pbtn3->setStyleSheet("#pp{border-image:url(:/doc/3.jpg)}");

//    ui->pbtn4->setObjectName("pp");
//    ui->pbtn4->setStyleSheet("#pp{border-image:url(:/doc/4.jpg)}");

//    ui->pbtn5->setObjectName("pp");
//    ui->pbtn5->setStyleSheet("#pp{border-image:url(:/doc/5.jpg)}");

//    ui->pbtn6->setObjectName("pp");
//    ui->pbtn6->setStyleSheet("#pp{border-image:url(:/doc/6.jpg)}");

//    ui->pbtn7->setObjectName("pp");
//    ui->pbtn7->setStyleSheet("#pp{border-image:url(:/doc/7.jpg)}");

//    ui->pbtn8->setObjectName("pp");
//    ui->pbtn8->setStyleSheet("#pp{border-image:url(:/doc/8.jpg)}");

//    ui->pbtn9->setObjectName("pp");
//    ui->pbtn9->setStyleSheet("#pp{border-image:url(:/doc/9.jpg)}");

//    ui->pbtnans->setObjectName("pp");
//    ui->pbtnans->setStyleSheet("#pp{border-image:url(:/doc/ans.jpg)}");
}
void MainWindow::init()
{
    ys['+'] = 1;ys['-'] = 1;
    ys['*'] = 2;ys['/'] = 2;
    ys['('] = 3;
    ys[')'] = 4;
    ys['#'] = 0;
    ys['|'] = 5;ys['&'] = 5;
    ys['!'] = 6;
    //以上是先给各个运算符编号
    for(int i=0;i<=7;i++)
        for(int j=0;j<=7;j++)
            solve[i][j]=-1;
    solve[1][0] = 0;
    solve[1][1] = 1;
    solve[1][2] = 1;
    solve[1][3] = 0;
    // solve[1][4] = 1;
    //由于‘）’根本不会入栈 所以不存在4作为第二维出现
    //以下注释掉的组合均是不会出现的情况
    solve[1][5] = 1;

    solve[2][0] = 0;
    solve[2][1] = 0;
    solve[2][2] = 1;
    solve[2][3] = 0;
    // solve[2][4] = ;
    solve[2][5] = 0;

    solve[3][0] = 0;
    solve[3][1] = 0;
    solve[3][2] = 0;
    solve[3][3] = 0;
    // solve[3][4] = 1;
    solve[3][5] = 0;

    // solve[4][0] = 1;
    //不会存在这种情况
    solve[4][1] = 1;
    solve[4][2] = 1;
    solve[4][3] = 2;
    solve[4][5] = 1;
    // solve[4][4] = 1;

    solve[0][0] = 2;
    solve[0][1] = 1;
    solve[0][2] = 1;
    // solve[0][3] = 0;
    // solve[0][4] = 2;
    solve[0][5] = 1;

    solve[5][0] = 0;
    solve[5][1] = 1;
    solve[5][2] = 1;
    solve[5][3] = 0;
    // solve[5][4]=
    solve[5][5] = 1;
    return ;
}
void MainWindow::work(char wit)
{
    char top = stk_ch.top();
    if (solve[ys[wit]][ys[top]] == 0)
    {
        stk_ch.push(wit);
        return;
    }
    while (solve[ys[wit]][ys[top]] == 1)
    {
        double num2 = stk_di.top();
        stk_di.pop();
        double num1 = stk_di.top();
        stk_di.pop();
        switch(top){
            case '+':
                num1 += num2;
                break;
            case '-':
                num1 -= num2;
                break;
            case '*':
                num1 *= num2;
                break;
            case '/':
                num1 /= num2;
                break;
            case '&':
                num1 = num1 && num2;
                break;
            case '|':
                num1 = num1 || num2;
                break;
        }
        stk_di.push(num1);
        stk_ch.pop();
        top = stk_ch.top();
    }
    if(solve[ys[wit]][ys[top]]==-1)
    {
        err=2;
        runError();
        return ;
    }
    if (solve[ys[wit]][ys[top]] == 0)
    {
        stk_ch.push(wit);
        return;
    }
    if (solve[ys[wit]][ys[top]] == 2)
        stk_ch.pop();
}
void MainWindow::runError()
{
    if(err==1)
        ui->text->setText("Not supported & and | yet");
    if(err==2)
        ui->text->setText("Operator is illegal");
    if(err==3)
        ui->text->setText("don't make any Chinese");
    if(err==4)
        ui->text->setText("please press the button");
}
void MainWindow::fslove(QString sh)
{
    err=0;
    string str=sh.toStdString();
//    if(str.size()!=str.length())
//    {
//        ui->text->setText("don't make any Chinese");
//        err=3;
//        return ;
//    }
    str = '#' + str + '#';
    stk_ch.push('#');
    for (int i = 1; i < int(str.length()); i++)
    {
        if (isdigit(str[i]))
        {
            int flag = 1, pflag = 1;
            if (ys[str[i - 1]] == 1 && (str[i - 2] == '(' || str[i - 2] == '#'))
            {
                if (str[i - 1] == '-')
                    flag = -1;
                stk_ch.pop();
            }
            if (str[i - 1] == '!')
                pflag = 0, stk_ch.pop();
            int di = 0;
            while (isdigit(str[i]))
            {
                di *= 10;
                di += str[i] - '0';
                i++;
            }
            di *= flag;
            if (!pflag)
                di = (di == 0) ? 1 : 0;
            stk_di.push(di);
        }
        if (str[i] == ' '||str[i]=='\n')
            continue;
        if (ys[str[i]] == 5 && str[i] == str[i + 1])
            i++;
        else
            if(ys[str[i]] == 5)
            {
                err = 1;
                runError();
                return ;
            }

        work(str[i]);
    }
//    cout << stk_di.top();
    ans=stk_di.top();
    while(!stk_ch.empty())
        stk_ch.pop();
    while(!stk_di.empty())
        stk_di.pop();
}
MainWindow::~MainWindow()
{
    delete ui;
}
void MainWindow::makeit()
{
    ui->text->setText(sh);
}
void MainWindow::on_pbtnhuo_clicked()
{
    sh+='|';
    makeit();
}
void MainWindow::on_pbtn0_clicked()
{
    sh+='0';
    makeit();
}
bool MainWindow::jud(QString sh)
{

    for(int i=0;i<int(sh.length());i++)
    {
        if(sh[i]>='0'&&sh[i]<='9')
            continue;
        if(sh[i]!='+'&&sh[i]!='-')
        if(sh[i]!='*'&&sh[i]!='/')
        if(sh[i]!='|'&&sh[i]!='&')
        if(sh[i]!='('&&sh[i]!=')')
        if(sh[i]!=' '&&sh[i]!='\n')
        {
            err=3;
            runError();
            return 0;
        }
    }
    return 1;
}
void MainWindow::on_pbtnans_clicked()
{
    err=0;
    rsh=ui->text->toPlainText();

    if(rsh!=NULL&&jud(rsh))
    {

        fslove(rsh);
//        qDebug()  <<  rsh;
        sh=QString::number(ans,10);
        ui->text->setText(sh);
        return ;
    }
    if(sh!=NULL&&jud(sh))
        fslove(sh);
    if(err)
        return;
    if(sh==NULL)
    {
        err=4;
        runError();
    }
    sh=QString::number(ans,10);
    ui->text->setText(sh);
}
void MainWindow::on_pbtnpoint_clicked()
{
//    sh+='.';
//    makeit();
    ui->text->setText("No floating point data support");
}
void MainWindow::on_pbtn1_clicked()
{
    sh+='1';
    makeit();
}
void MainWindow::on_pbtn2_clicked()
{
    sh+='2';
    makeit();
}
void MainWindow::on_pbtn3_clicked()
{
    sh+='3';
    makeit();
}
void MainWindow::on_pbtn4_clicked()
{
    sh+='4';
    makeit();
}
void MainWindow::on_pbtn5_clicked()
{
    sh+='5';
    makeit();
}
void MainWindow::on_pbtn6_clicked()
{
    sh+='6';
    makeit();
}
void MainWindow::on_pbtn7_clicked()
{
    sh+='7';
    makeit();
}
void MainWindow::on_pbtn8_clicked()
{
    sh+='8';
    makeit();
}
void MainWindow::on_pbtn9_clicked()
{
    sh+='9';
    makeit();
}
void MainWindow::on_pbtnclear_clicked()
{
    sh.clear();
    makeit();
}
void MainWindow::on_pbtncheng_clicked()
{
    sh+='*';
    makeit();
}
void MainWindow::on_pbtnchu_clicked()
{
    sh+='/';
    makeit();
}
void MainWindow::on_pbtnplus_clicked()
{
    sh+='+';
    makeit();
}
void MainWindow::on_pbtnjian_clicked()
{
    sh+='-';
    makeit();
}
void MainWindow::on_pbtnbing_clicked()
{
    sh+='&';
    makeit();
}
void MainWindow::on_pbtnzuo_clicked()
{
    sh+='(';
    makeit();
}
void MainWindow::on_pbtnback_clicked()
{
    if(sh!=NULL)
        sh = sh.left(sh.size()-1),makeit();
    else
        ui->text->setText("this is empty!!!");
}
void MainWindow::on_pbtnyou_clicked()
{
    sh+=')';
    makeit();
}
