#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QKeyEvent>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <time.h>
#include <QString>
#include <fstream>
#include <QIcon>
#include <Qpixmap>
#include <QPushbutton>
#include <QMessageBox>
#include <QLabel>

using namespace std;
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label_3->setText(QString::number(score));
    ui->label_5->setText(QString::number(step));
    ui->label_12->hide();
    add();
    //start count
    eat();
}
MainWindow::~MainWindow()
{
    emit quit(star,score);
}

int MainWindow::arr[10][10]={0};
int MainWindow::checkarr[10][10]={0};
int MainWindow::savearr[10][10]={0};
int MainWindow::first=0;
int MainWindow::second=0;
int MainWindow::score=0;
int MainWindow::f=0;
int MainWindow::step=20;
int MainWindow::star=0;

void MainWindow::add(){
    srand(time(0));
    int a=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            a = rand()%5+1;    
            if(arr[i][j]==0)
               arr[i][j]=a;
            //cout<<arr[i][j]<<"  ";
        }
           // cout<<endl;
    }
    //cout<<endl;
    pic();
}

void MainWindow::pic(){
    //display icon of candy
    QIcon pics[21]={QIcon(":/pics/pic1.png"),
                   QIcon(":/pics/pic2.png"),
                   QIcon(":/pics/pic3.png"),
                   QIcon(":/pics/pic4.png"),
                   QIcon(":/pics/pic5.png"),
                   QIcon(":/pics/pic6.png"),
                   QIcon(":/pics/pic7.png"),
                   QIcon(":/pics/pic8.png"),
                   QIcon(":/pics/pic9.png"),
                   QIcon(":/pics/pic10.png"),
                   QIcon(":/pics/pic11.png"),
                   QIcon(":/pics/pic12.png"),
                   QIcon(":/pics/pic13.png"),
                   QIcon(":/pics/pic14.png"),
                   QIcon(":/pics/pic15.png"),
                   QIcon(":/pics/pic16.png"),
                   QIcon(":/pics/pic17.png"),
                   QIcon(":/pics/pic18.png"),
                   QIcon(":/pics/pic19.png"),
                   QIcon(":/pics/pic20.png"),
                   QIcon(":/pics/pic21.png")};


    for(int k=0;k<21;k++){
       if(arr[0][0]==k+1)
            ui->pushButton->setIcon(pics[k]);
       if(arr[0][1]==k+1)
            ui->pushButton_2->setIcon(pics[k]);
       if(arr[0][2]==k+1)
            ui->pushButton_3->setIcon(pics[k]);
       if(arr[0][3]==k+1)
            ui->pushButton_4->setIcon(pics[k]);
       if(arr[0][4]==k+1)
            ui->pushButton_5->setIcon(pics[k]);
       if(arr[0][5]==k+1)
            ui->pushButton_6->setIcon(pics[k]);
       if(arr[0][6]==k+1)
            ui->pushButton_7->setIcon(pics[k]);
       if(arr[0][7]==k+1)
            ui->pushButton_8->setIcon(pics[k]);
       if(arr[0][8]==k+1)
            ui->pushButton_9->setIcon(pics[k]);
       if(arr[0][9]==k+1)
            ui->pushButton_10->setIcon(pics[k]);
       if(arr[1][0]==k+1)
            ui->pushButton_11->setIcon(pics[k]);
       if(arr[1][1]==k+1)
            ui->pushButton_12->setIcon(pics[k]);
       if(arr[1][2]==k+1)
            ui->pushButton_13->setIcon(pics[k]);
       if(arr[1][3]==k+1)
            ui->pushButton_14->setIcon(pics[k]);
       if(arr[1][4]==k+1)
            ui->pushButton_15->setIcon(pics[k]);
       if(arr[1][5]==k+1)
            ui->pushButton_16->setIcon(pics[k]);
       if(arr[1][6]==k+1)
            ui->pushButton_17->setIcon(pics[k]);
       if(arr[1][7]==k+1)
            ui->pushButton_18->setIcon(pics[k]);
       if(arr[1][8]==k+1)
            ui->pushButton_19->setIcon(pics[k]);
       if(arr[1][9]==k+1)
            ui->pushButton_20->setIcon(pics[k]);
       if(arr[2][0]==k+1)
            ui->pushButton_21->setIcon(pics[k]);
       if(arr[2][1]==k+1)
            ui->pushButton_22->setIcon(pics[k]);
       if(arr[2][2]==k+1)
            ui->pushButton_23->setIcon(pics[k]);
       if(arr[2][3]==k+1)
            ui->pushButton_24->setIcon(pics[k]);
       if(arr[2][4]==k+1)
            ui->pushButton_25->setIcon(pics[k]);
       if(arr[2][5]==k+1)
            ui->pushButton_26->setIcon(pics[k]);
       if(arr[2][6]==k+1)
            ui->pushButton_27->setIcon(pics[k]);
       if(arr[2][7]==k+1)
            ui->pushButton_28->setIcon(pics[k]);
       if(arr[2][8]==k+1)
            ui->pushButton_29->setIcon(pics[k]);
       if(arr[2][9]==k+1)
            ui->pushButton_30->setIcon(pics[k]);
       if(arr[3][0]==k+1)
            ui->pushButton_31->setIcon(pics[k]);
       if(arr[3][1]==k+1)
            ui->pushButton_32->setIcon(pics[k]);
       if(arr[3][2]==k+1)
            ui->pushButton_33->setIcon(pics[k]);
       if(arr[3][3]==k+1)
            ui->pushButton_34->setIcon(pics[k]);
       if(arr[3][4]==k+1)
            ui->pushButton_35->setIcon(pics[k]);
       if(arr[3][5]==k+1)
            ui->pushButton_36->setIcon(pics[k]);
       if(arr[3][6]==k+1)
            ui->pushButton_37->setIcon(pics[k]);
       if(arr[3][7]==k+1)
            ui->pushButton_38->setIcon(pics[k]);
       if(arr[3][8]==k+1)
            ui->pushButton_39->setIcon(pics[k]);
       if(arr[3][9]==k+1)
            ui->pushButton_40->setIcon(pics[k]);
       if(arr[4][0]==k+1)
            ui->pushButton_41->setIcon(pics[k]);
       if(arr[4][1]==k+1)
            ui->pushButton_42->setIcon(pics[k]);
       if(arr[4][2]==k+1)
            ui->pushButton_43->setIcon(pics[k]);
       if(arr[4][3]==k+1)
            ui->pushButton_44->setIcon(pics[k]);
       if(arr[4][4]==k+1)
            ui->pushButton_45->setIcon(pics[k]);
       if(arr[4][5]==k+1)
            ui->pushButton_46->setIcon(pics[k]);
       if(arr[4][6]==k+1)
            ui->pushButton_47->setIcon(pics[k]);
       if(arr[4][7]==k+1)
            ui->pushButton_48->setIcon(pics[k]);
       if(arr[4][8]==k+1)
            ui->pushButton_49->setIcon(pics[k]);
       if(arr[4][9]==k+1)
            ui->pushButton_50->setIcon(pics[k]);
       if(arr[5][0]==k+1)
            ui->pushButton_51->setIcon(pics[k]);
       if(arr[5][1]==k+1)
            ui->pushButton_52->setIcon(pics[k]);
       if(arr[5][2]==k+1)
            ui->pushButton_53->setIcon(pics[k]);
       if(arr[5][3]==k+1)
            ui->pushButton_54->setIcon(pics[k]);
       if(arr[5][4]==k+1)
            ui->pushButton_55->setIcon(pics[k]);
       if(arr[5][5]==k+1)
            ui->pushButton_56->setIcon(pics[k]);
       if(arr[5][6]==k+1)
            ui->pushButton_57->setIcon(pics[k]);
       if(arr[5][7]==k+1)
            ui->pushButton_58->setIcon(pics[k]);
       if(arr[5][8]==k+1)
            ui->pushButton_59->setIcon(pics[k]);
       if(arr[5][9]==k+1)
            ui->pushButton_60->setIcon(pics[k]);
       if(arr[6][0]==k+1)
            ui->pushButton_61->setIcon(pics[k]);
       if(arr[6][1]==k+1)
            ui->pushButton_62->setIcon(pics[k]);
       if(arr[6][2]==k+1)
            ui->pushButton_63->setIcon(pics[k]);
       if(arr[6][3]==k+1)
            ui->pushButton_64->setIcon(pics[k]);
       if(arr[6][4]==k+1)
            ui->pushButton_65->setIcon(pics[k]);
       if(arr[6][5]==k+1)
            ui->pushButton_66->setIcon(pics[k]);
       if(arr[6][6]==k+1)
            ui->pushButton_67->setIcon(pics[k]);
       if(arr[6][7]==k+1)
            ui->pushButton_68->setIcon(pics[k]);
       if(arr[6][8]==k+1)
            ui->pushButton_69->setIcon(pics[k]);
       if(arr[6][9]==k+1)
            ui->pushButton_70->setIcon(pics[k]);
       if(arr[7][0]==k+1)
            ui->pushButton_71->setIcon(pics[k]);
       if(arr[7][1]==k+1)
            ui->pushButton_72->setIcon(pics[k]);
       if(arr[7][2]==k+1)
            ui->pushButton_73->setIcon(pics[k]);
       if(arr[7][3]==k+1)
            ui->pushButton_74->setIcon(pics[k]);
       if(arr[7][4]==k+1)
            ui->pushButton_75->setIcon(pics[k]);
       if(arr[7][5]==k+1)
            ui->pushButton_76->setIcon(pics[k]);
       if(arr[7][6]==k+1)
            ui->pushButton_77->setIcon(pics[k]);
       if(arr[7][7]==k+1)
            ui->pushButton_78->setIcon(pics[k]);
       if(arr[7][8]==k+1)
            ui->pushButton_79->setIcon(pics[k]);
       if(arr[7][9]==k+1)
            ui->pushButton_80->setIcon(pics[k]);
       if(arr[8][0]==k+1)
            ui->pushButton_81->setIcon(pics[k]);
       if(arr[8][1]==k+1)
            ui->pushButton_82->setIcon(pics[k]);
       if(arr[8][2]==k+1)
            ui->pushButton_83->setIcon(pics[k]);
       if(arr[8][3]==k+1)
            ui->pushButton_84->setIcon(pics[k]);
       if(arr[8][4]==k+1)
            ui->pushButton_85->setIcon(pics[k]);
       if(arr[8][5]==k+1)
            ui->pushButton_86->setIcon(pics[k]);
       if(arr[8][6]==k+1)
            ui->pushButton_87->setIcon(pics[k]);
       if(arr[8][7]==k+1)
            ui->pushButton_88->setIcon(pics[k]);
       if(arr[8][8]==k+1)
            ui->pushButton_89->setIcon(pics[k]);
       if(arr[8][9]==k+1)
            ui->pushButton_90->setIcon(pics[k]);
       if(arr[9][0]==k+1)
            ui->pushButton_91->setIcon(pics[k]);
       if(arr[9][1]==k+1)
            ui->pushButton_92->setIcon(pics[k]);
       if(arr[9][2]==k+1)
            ui->pushButton_93->setIcon(pics[k]);
       if(arr[9][3]==k+1)
            ui->pushButton_94->setIcon(pics[k]);
       if(arr[9][4]==k+1)
            ui->pushButton_95->setIcon(pics[k]);
       if(arr[9][5]==k+1)
            ui->pushButton_96->setIcon(pics[k]);
       if(arr[9][6]==k+1)
            ui->pushButton_97->setIcon(pics[k]);
       if(arr[9][7]==k+1)
            ui->pushButton_98->setIcon(pics[k]);
       if(arr[9][8]==k+1)
            ui->pushButton_99->setIcon(pics[k]);
       if(arr[9][9]==k+1)
            ui->pushButton_100->setIcon(pics[k]);

    }
}

void MainWindow::movedown(){
    //move down all the candy to fill up the space
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(j==9 && arr[j][i]==0 && arr[j-1][i]!=0){
                arr[j][i]=arr[j-1][i];
                arr[j-1][i]=arr[j-2][i];
                arr[j-2][i]=arr[j-3][i];
                arr[j-3][i]=arr[j-4][i];
                arr[j-4][i]=arr[j-5][i];
                arr[j-5][i]=arr[j-6][i];
                arr[j-6][i]=arr[j-7][i];
                arr[j-7][i]=arr[j-8][i];
                arr[j-8][i]=arr[j-9][i];
                arr[j-9][i]=0;
            }
            if(j==8 && arr[j][i]==0 && arr[j-1][i]!=0){
                arr[j][i]=arr[j-1][i];
                arr[j-1][i]=arr[j-2][i];
                arr[j-2][i]=arr[j-3][i];
                arr[j-3][i]=arr[j-4][i];
                arr[j-4][i]=arr[j-5][i];
                arr[j-5][i]=arr[j-6][i];
                arr[j-6][i]=arr[j-7][i];
                arr[j-7][i]=arr[j-8][i];
                arr[j-8][i]=0;
            }
            if(j==7 && arr[j][i]==0 && arr[j-1][i]!=0){
                arr[j][i]=arr[j-1][i];
                arr[j-1][i]=arr[j-2][i];
                arr[j-2][i]=arr[j-3][i];
                arr[j-3][i]=arr[j-4][i];
                arr[j-4][i]=arr[j-5][i];
                arr[j-5][i]=arr[j-6][i];
                arr[j-6][i]=arr[j-7][i];
                arr[j-7][i]=0;
            }
            if(j==6 && arr[j][i]==0 && arr[j-1][i]!=0){
                arr[j][i]=arr[j-1][i];
                arr[j-1][i]=arr[j-2][i];
                arr[j-2][i]=arr[j-3][i];
                arr[j-3][i]=arr[j-4][i];
                arr[j-4][i]=arr[j-5][i];
                arr[j-5][i]=arr[j-6][i];
                arr[j-6][i]=0;
            }
            if(j==5 && arr[j][i]==0 && arr[j-1][i]!=0){
                arr[j][i]=arr[j-1][i];
                arr[j-1][i]=arr[j-2][i];
                arr[j-2][i]=arr[j-3][i];
                arr[j-3][i]=arr[j-4][i];
                arr[j-4][i]=arr[j-5][i];
                arr[j-5][i]=0;
            }
            if(j==4 && arr[j][i]==0 && arr[j-1][i]!=0){
                arr[j][i]=arr[j-1][i];
                arr[j-1][i]=arr[j-2][i];
                arr[j-2][i]=arr[j-3][i];
                arr[j-3][i]=arr[j-4][i];
                arr[j-4][i]=0;
            }
            if(j==3 && arr[j][i]==0 && arr[j-1][i]!=0){
                arr[j][i]=arr[j-1][i];
                arr[j-1][i]=arr[j-2][i];
                arr[j-2][i]=arr[j-3][i];
                arr[j-3][i]=0;
            }
            if(j==2 && arr[j][i]==0 && arr[j-1][i]!=0){
                arr[j][i]=arr[j-1][i];
                arr[j-1][i]=arr[j-2][i];
                arr[j-2][i]=0;
            }
            if(j==1 && arr[j][i]==0 && arr[j-1][i]!=0){
                arr[j][i]=arr[j-1][i];
                arr[j-1][i]=0;
            }
        }
    }
}

void MainWindow::eat(){
    //如果三消的是炸彈
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){

            int ii=16,jj=1;
            while(ii<21 && jj<6){
                //橫排的橫炸彈
                if((arr[i][j]==ii && arr[i][j+1]==jj && arr[i][j+2]==jj) || (arr[i][j+1]==ii && arr[i][j]==jj && arr[i][j+2]==jj) || (arr[i][j+2]==ii && arr[i][j+1]==jj && arr[i][j]==jj)){  
                    for(int k=0;k<10;k++)
                        arr[i][k]=50;
                }

                //直排的直炸彈
                if((arr[j][i]==ii-5 && arr[j+1][i]==jj && arr[j+2][i]==jj) || (arr[j][i]==jj && arr[j+1][i]==ii-5 && arr[j+2][i]==jj) || (arr[j][i]==jj && arr[j+1][i]==jj && arr[j+2][i]==ii-5)){
                    for(int k=0;k<10;k++)
                        arr[k][i]=50;
                }

                //直排的橫炸彈
                if(arr[j][i]==ii && arr[j+1][i]==jj && arr[j+2][i]==jj){
                    for(int k=0;k<10;k++)
                        arr[j][k]=50;
                }
                if(arr[j][i]==jj && arr[j+1][i]==ii && arr[j+2][i]==jj){
                    for(int k=0;k<10;k++)
                        arr[j+1][k]=50;
                }

                if(arr[j][i]==jj && arr[j+1][i]==jj && arr[j+2][i]==ii){
                    for(int k=0;k<10;k++)
                        arr[j+2][k]=50;
                }

                //橫排的直炸彈
                if(arr[i][j]==ii-5 && arr[i][j+1]==jj && arr[i][j+2]==jj){
                    for(int k=0;k<10;k++)
                        arr[k][j]=50;
                }
                if(arr[i][j+1]==ii-5 && arr[i][j]==jj && arr[i][j+2]==jj){
                    for(int k=0;k<10;k++)
                        arr[k][j+1]=50;
                }
                if(arr[i][j+2]==ii-5 && arr[i][j+1]==jj && arr[i][j]==jj){
                    for(int k=0;k<10;k++)
                        arr[k][j+2]=50;
                }
                ii++;
                jj++;
            }
            ii=16;
            jj=1;
        }
    }


    //如果是方形炸彈
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            int iii=6,jjj=1;
            while(iii<11 && jjj<6){

                if(arr[i][j]==iii && arr[i][j+1]==jjj && arr[i][j+2]==jjj){
                    arr[i-1][j-1]=50;
                    arr[i-1][j]=50;
                    arr[i-1][j+1]=50;
                    arr[i][j-1]=50;
                    arr[i][j]=50;
                    arr[i][j+1]=50;
                    arr[i+1][j-1]=50;
                    arr[i+1][j]=50;
                    arr[i+1][j+1]=50;
                }
                if(arr[i][j+1]==iii && arr[i][j]==jjj && arr[i][j+2]==jjj){
                    arr[i-1][j]=50;
                    arr[i-1][j+1]=50;
                    arr[i-1][j+2]=50;
                    arr[i][j]=50;
                    arr[i][j+1]=50;
                    arr[i][j+2]=50;
                    arr[i+1][j]=50;
                    arr[i+1][j+1]=50;
                    arr[i+1][j+2]=50;
                }
                if(arr[i][j+2]==iii && arr[i][j+1]==jjj && arr[i][j]==jjj){
                    arr[i-1][j+1]=50;
                    arr[i-1][j+2]=50;
                    arr[i-1][j+3]=50;
                    arr[i][j+1]=50;
                    arr[i][j+2]=50;
                    arr[i][j+3]=50;
                    arr[i+1][j+1]=50;
                    arr[i+1][j+2]=50;
                    arr[i+1][j+3]=50;
                }
                if(arr[j][i]==iii && arr[j+1][i]==jjj && arr[j+2][i]==jjj){
                    arr[j-1][i-1]=50;
                    arr[j-1][i]=50;
                    arr[j-1][i+1]=50;
                    arr[j][i-1]=50;
                    arr[j][i]=50;
                    arr[j][i+1]=50;
                    arr[j+1][i-1]=50;
                    arr[j+1][i]=50;
                    arr[j+1][i+1]=50;
                }
                if(arr[j+1][i]==iii && arr[j][i]==jjj && arr[j+2][i]==jjj){
                    arr[j][i-1]=50;
                    arr[j][i]=50;
                    arr[j][i+1]=50;
                    arr[j+1][i-1]=50;
                    arr[j+1][i]=50;
                    arr[j+1][i+1]=50;
                    arr[j+2][i-1]=50;
                    arr[j+2][i]=50;
                    arr[j+2][i+1]=50;
                }
                if(arr[j+2][i]==iii && arr[j][i]==jjj && arr[j+1][i]==jjj){
                    arr[j+1][i-1]=50;
                    arr[j+1][i]=50;
                    arr[j+1][i+1]=50;
                    arr[j+2][i-1]=50;
                    arr[j+2][i]=50;
                    arr[j+2][i+1]=50;
                    arr[j+3][i-1]=50;
                    arr[j+3][i]=50;
                    arr[j+3][i+1]=50;
                }
                iii++;
                jjj++;
            }
            iii=6;
            jjj=1;
        }
    }

    //33吃
    for(int i =0;i<10;i++){
        for(int j=0;j<8;j++){
            if(arr[i][j]==arr[i][j+1] && arr[i][j+1]==arr[i][j+2] && arr[i][j]==arr[i+1][j] && arr[i+1][j]==arr[i+2][j]){
                if(arr[i][j]==1)
                    arr[i][j]=6;
                if(arr[i][j]==2)
                    arr[i][j]=7;
                if(arr[i][j]==3)
                    arr[i][j]=8;
                if(arr[i][j]==4)
                    arr[i][j]=9;
                if(arr[i][j]==5)
                    arr[i][j]=10;
                arr[i][j+1]=50;
                arr[i][j+2]=50;
                arr[i+1][j]=50;
                arr[i+2][j]=50;
            }
            if(arr[i][j]==arr[i][j+1] && arr[i][j+1]==arr[i][j+2] && arr[i][j+2]==arr[i+1][j+2] && arr[i+1][j+2]==arr[i+2][j+2]){
                if(arr[i][j+2]==1)
                    arr[i][j+2]=6;
                if(arr[i][j+2]==2)
                    arr[i][j+2]=7;
                if(arr[i][j+2]==3)
                    arr[i][j+2]=8;
                if(arr[i][j+2]==4)
                    arr[i][j+2]=9;
                if(arr[i][j+2]==5)
                    arr[i][j+2]=10;
                arr[i][j+1]=50;
                arr[i][j]=50;
                arr[i+1][j+2]=50;
                arr[i+2][j+2]=50;
            }
            if(arr[i][j]==arr[i][j+1] && arr[i][j+1]==arr[i][j+2] && arr[i][j+2]==arr[i+1][j+2] && arr[i+1][2]==arr[i+2][j+2]){
                if(arr[i][j]==1)
                    arr[i][j]=6;
                if(arr[i][j]==2)
                    arr[i][j]=7;
                if(arr[i][j]==3)
                    arr[i][j]=8;
                if(arr[i][j]==4)
                    arr[i][j]=9;
                if(arr[i][j]==5)
                    arr[i][j]=10;
                arr[i][j+1]=50;
                arr[i][j+2]=50;
                arr[i-1][j]=50;
                arr[i-2][j]=50;
            }
            if(arr[i][j]==arr[i][j+1] && arr[i][j+1]==arr[i][j+2] && arr[i][j+2]==arr[i-1][j+2] && arr[i-1][j+2]==arr[i-2][j+2]){
                if(arr[i][j+2]==1)
                    arr[i][j+2]=6;
                if(arr[i][j+2]==2)
                    arr[i][j+2]=7;
                if(arr[i][j+2]==3)
                    arr[i][j+2]=8;
                if(arr[i][j+2]==4)
                    arr[i][j+2]=9;
                if(arr[i][j+2]==5)
                    arr[i][j+2]=10;
                arr[i][j+1]=50;
                arr[i][j]=50;
                arr[i-1][j+2]=50;
                arr[i-2][j+2]=50;
            }
        }
    }


    //5個吃掉
    for(int i=0;i<10;i++){
        for(int j=0;j<6;j++){
            //橫排
            if(arr[i][j]==arr[i][j+1] && arr[i][j+1]==arr[i][j+2] && arr[i][j+2]==arr[i][j+3] && arr[i][j+3]==arr[i][j+4]){
                arr[i][j]=50;
                arr[i][j+1]=50;
                arr[i][j+2]=21;
                arr[i][j+3]=50;
                arr[i][j+4]=50;
            }
            //直排
            if(arr[j][i]==arr[j+1][i] && arr[j+1][i]==arr[j+2][i] && arr[j+2][i]==arr[j+3][i] && arr[j+3][i]==arr[j+4][i]){
                arr[j][i]=50;
                arr[j+1][i]=50;
                arr[j+2][i]=21;
                arr[j+3][i]=50;
                arr[j+4][i]=50;
            }
        }
    }
    //4個吃掉
    for(int i=0;i<10;i++){
        for(int j=0;j<7;j++){
            //橫排
            if(arr[i][j]==arr[i][j+1] && arr[i][j+1]==arr[i][j+2] && arr[i][j+2]==arr[i][j+3]){
                arr[i][j]=50;
                if(arr[i][j+1]==1)
                    arr[i][j+1]=16;
                if(arr[i][j+1]==2)
                    arr[i][j+1]=17;
                if(arr[i][j+1]==3)
                    arr[i][j+1]=18;
                if(arr[i][j+1]==4)
                    arr[i][j+1]=19;
                if(arr[i][j+1]==5)
                    arr[i][j+1]=20;
                arr[i][j+2]=50;
                arr[i][j+3]=50;
            }
            //直排
            if(arr[j][i]==arr[j+1][i] && arr[j+1][i]==arr[j+2][i] && arr[j+2][i]==arr[j+3][i]){
                arr[j][i]=50;
                if(arr[j+1][i]==1)
                    arr[j+1][i]=11;
                if(arr[j+1][i]==2)
                    arr[j+1][i]=12;
                if(arr[j+1][i]==3)
                    arr[j+1][i]=13;
                if(arr[j+1][i]==4)
                    arr[j+1][i]=14;
                if(arr[j+1][i]==5)
                    arr[j+1][i]=15;
                arr[j+2][i]=50;
                arr[j+3][i]=50;
            }
        }
    }
    //3個吃掉
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            //橫排
            if(arr[i][j]==arr[i][j+1] && arr[i][j+1]==arr[i][j+2]){
                arr[i][j]=50;
                arr[i][j+1]=50;
                arr[i][j+2]=50;
            }
            //直排
            if(arr[j][i]==arr[j+1][i] && arr[j+1][i]==arr[j+2][i]){
                arr[j][i]=50;
                arr[j+1][i]=50;
                arr[j+2][i]=50;
            }
        }
    }

//eat all 8
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j]==50){
                arr[i][j]=0;
                score=score+20;
                ui->label_3->setText(QString::number(score));
                //star
                if(score>=15000){
                    ui->label_9->setPixmap(QPixmap(":/pics/pic22.png"));
                    star++;
                }
                if(score>=18000){
                    ui->label_11->setPixmap(QPixmap(":/pics/pic22.png"));
                    star++;
                }
                if(score>=20000){
                    ui->label_10->setPixmap(QPixmap(":/pics/pic22.png"));
                    star++;
                }
            }
        }
    }
    movedown();
    add();
//if still have 3 same then eat again
    for(int i=0;i<10;i++){
        for(int j=0;j<8;j++){
            if( (arr[i][j]==arr[i][j+1] && arr[i][j+1]==arr[i][j+2]) || (arr[j][i]==arr[j+1][i] && arr[j+1][i]==arr[j+2][i]) ){
                eat();
            }
            if(i==9 && j==7){
                break;
            }
        }
    }

    int check=0;
    //judge if checkarr = arr then arr will change back to savearr
    if(checkarr[0][0]!=0){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                if(checkarr[i][j]==arr[i][j])
                    check++;
            }
        }
    }

//if same:
    if(check==100){
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                arr[i][j]=savearr[i][j];
                if(arr[i][j]==78)
                    arr[i][j]=first;
                if(arr[i][j]==87)
                    arr[i][j]=second;
            }
        }
        step=step+1;
        ui->label_5->setText(QString::number(step));
    }
}

void MainWindow::swap(){
    //for record array and check judgement(same is not allow to swap ) before swap
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            savearr[i][j]=arr[i][j];
        }
    }

    //if is choc then all the same = 10
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(first==21){
                if(arr[i][j]==second||arr[i][j]==78||arr[i][j]==87)
                    arr[i][j]=50;
            }
            if(second==21){
                if(arr[i][j]==first||arr[i][j]==78||arr[i][j]==87)
                    arr[i][j]=50;
            }
        }
    }

    //start swap
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(arr[i][j]==78)
                arr[i][j]=second;
            if(arr[i][j]==87)
                arr[i][j]=first;
        }
    }

    step=step-1;//if change is available then step-1
    ui->label_5->setText(QString::number(step));

    if(step==0){
       ui->label_12->setPixmap(QPixmap(":/pics/gameover.png"));
       ui->label_12->show();
    }

    pic();
    //record array after swap
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            checkarr[i][j]=arr[i][j];
        }
    }
    eat();
}

void MainWindow::on_pushButton_101_clicked()
{
    //signal
    emit quit(star,score);
    this->close();
}

void MainWindow::GetArray_From_Number(){
    //judge that pushbutton is from which array
    int k=101;

    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            if(f==k && first==0 && second==0){
                first = arr[i][j];
                arr[i][j]=78;//78 record first
            }
            else if(f==k && first!=0 && second==0){
                second = arr[i][j];
                arr[i][j]=87;//87 record second
            }
            k++;
        }
    }
    k=101;

    if(first!=0 && second!=0){
        swap();
        first=0;
        second=0;
        eat();

    }
}

//以下100個是100圖案的PUSHBUTTON
// f is the value that record the pushbutton, let the getarray function know which array is it.
void MainWindow::on_pushButton_clicked(){
    f=101;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_2_clicked(){
    f=102;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_3_clicked(){
    f=103;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_4_clicked(){
    f=104;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_5_clicked(){
    f=105;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_6_clicked(){
    f=106;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_7_clicked(){
    f=107;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_8_clicked(){
    f=108;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_9_clicked(){
    f=109;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_10_clicked(){
    f=110;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_11_clicked(){
    f=111;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_12_clicked(){
    f=112;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_13_clicked(){
    f=113;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_14_clicked(){
    f=114;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_15_clicked(){
    f=115;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_16_clicked(){
    f=116;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_17_clicked(){
    f=117;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_18_clicked(){
    f=118;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_19_clicked(){
    f=119;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_20_clicked(){
    f=120;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_21_clicked(){
    f=121;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_22_clicked(){
    f=122;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_23_clicked(){
    f=123;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_24_clicked(){
    f=124;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_25_clicked(){
    f=125;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_26_clicked(){
    f=126;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_27_clicked(){
    f=127;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_28_clicked(){
    f=128;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_29_clicked(){
    f=129;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_30_clicked(){
    f=130;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_31_clicked(){
    f=131;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_32_clicked(){
    f=132;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_33_clicked(){
    f=133;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_34_clicked(){
    f=134;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_35_clicked(){
    f=135;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_36_clicked(){
    f=136;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_37_clicked(){
    f=137;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_38_clicked(){
    f=138;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_39_clicked(){
    f=139;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_40_clicked(){
    f=140;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_41_clicked(){
    f=141;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_42_clicked(){
    f=142;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_43_clicked(){
    f=143;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_44_clicked(){
    f=144;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_45_clicked(){
    f=145;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_46_clicked(){
    f=146;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_47_clicked(){
    f=147;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_48_clicked(){
    f=148;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_49_clicked(){
    f=149;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_50_clicked(){
    f=150;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_51_clicked(){
    f=151;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_52_clicked(){
    f=152;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_53_clicked(){
    f=153;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_54_clicked(){
    f=154;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_55_clicked(){
    f=155;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_56_clicked(){
    f=156;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_57_clicked(){
    f=157;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_58_clicked(){
    f=158;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_59_clicked(){
    f=159;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_60_clicked(){
    f=160;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_61_clicked(){
    f=161;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_62_clicked(){
    f=162;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_63_clicked(){
    f=163;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_64_clicked(){
    f=164;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_65_clicked(){
    f=165;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_66_clicked(){
    f=166;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_67_clicked(){
    f=167;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_68_clicked(){
    f=168;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_69_clicked(){
    f=169;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_70_clicked(){
    f=170;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_71_clicked(){
    f=171;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_72_clicked(){
    f=172;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_73_clicked(){
    f=173;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_74_clicked(){
    f=174;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_75_clicked(){
    f=175;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_76_clicked(){
    f=176;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_77_clicked(){
    f=177;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_78_clicked(){
    f=178;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_79_clicked(){
    f=179;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_80_clicked(){
    f=180;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_81_clicked(){
    f=181;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_82_clicked(){
    f=182;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_83_clicked(){
    f=183;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_84_clicked(){
    f=184;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_85_clicked(){
    f=185;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_86_clicked(){
    f=186;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_87_clicked(){
    f=187;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_88_clicked(){
    f=188;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_89_clicked(){
    f=189;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_90_clicked(){
    f=190;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_91_clicked(){
    f=191;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_92_clicked(){
    f=192;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_93_clicked(){
    f=193;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_94_clicked(){
    f=194;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_95_clicked(){
    f=195;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_96_clicked(){
    f=196;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_97_clicked(){
    f=197;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_98_clicked(){
    f=198;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_99_clicked(){
    f=199;
    GetArray_From_Number();
}
void MainWindow::on_pushButton_100_clicked(){
    f=200;
    GetArray_From_Number();
}
