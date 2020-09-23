#include "dcmapp.h"
#include "ui_dcmapp.h"
#include "ui_dcmapp.h"

DCMapp::DCMapp(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::DCMapp)
{
    ui->setupUi(this);
}

void DCMapp::appcall(QString appPath)
{
    QStringList arguments ;
    QStringList extractedarguments;
    arguments <<"-h";
    QProcess myProcess;
   if(!QFile::exists(appPath)){
       qDebug() << "print an error";
   };
    myProcess.start(appPath, arguments);
    myProcess.waitForFinished(); // sets current thread to sleep and waits for the Process end
    QString output(myProcess.readAllStandardOutput());
    //qDebug() << output;
    int i = 0;
    while(i < output.size()){
    if((output[i] == "-") && (output[i+1] == "-")){
        QString arg = "";
        while(output[i] != " "){
            arg.append(output[i]);
          i++;
          //i am thinking to make the mouse event to read description here
        }
        if(output[i] == " "){
            extractedarguments.append(arg);
        }
    }
    i++;
}

    //qDebug() << extractedarguments;
    int j = 0;
    QWidget * wdg = new QWidget(this);
    //wdg->setMaximumHeight(1000);
    QVBoxLayout *vlay = new QVBoxLayout(wdg);
    //make them global
    QLabel *Labals[extractedarguments.size()];
    QCheckBox *Checkboxs[extractedarguments.size()];
    QLineEdit *Textboxs[extractedarguments.size()];


while(j < extractedarguments.size() ){
    QHBoxLayout *varrg  = new QHBoxLayout();
    vlay->addLayout(varrg);
    Labals[j] = new QLabel(extractedarguments.at(j));
    Checkboxs[j]= new QCheckBox();
    Textboxs[j] = new QLineEdit("");
    varrg->addWidget(Labals[j]);
    varrg->addWidget(Textboxs[j]);
    varrg->addWidget( Checkboxs [j]);


    j++;
}
QScrollArea *scrollarea = new QScrollArea();
scrollarea->setWidget(wdg);
    setCentralWidget(scrollarea);

QPushButton * excute = new QPushButton();

vlay->addWidget(excute);

// I am trying to connect the excute button to on_execute_clicked()
}

void DCMapp::on_execute_clicked(){

/*    QStringList checkedarguments;
    QProcess ProcessWithArg;
   if(!QFile::exists(appPath)){
       qDebug() << "print an error";
   };
 execute function
while(j < extractedarguments.size() ){
    if(DCMapp::Checkboxs[j]->isChecked()){

        checkedarguments.append(QString(Labals[j]->text()) + QString(" ") + QString(Textboxs[j]->text()));
    }
        j++;
    }




ProcessWithArg.start(appPath, checkedarguments);
ProcessWithArg.waitForFinished(); // sets current thread to sleep and waits for theProcess end
QString outputwitharg(ProcessWithArg.readAllStandardOutput());
qDebug() << outputwitharg;*/

}
DCMapp::~DCMapp()

{
    delete ui;
}


void DCMapp::on_pushButton_clicked()
{
    QString appPath =("C:\\ProgramData\\chocolatey\\bin\\dcmdump.exe");
    DCMapp::appcall(appPath);
}
