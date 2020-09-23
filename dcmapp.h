#ifndef DCMAPP_H
#define DCMAPP_H

#include <QMainWindow>
#include <QProcess>
#include <QDir>
#include  <QLabel>
#include  <QScrollArea>
#include  <QDialog>
#include  <QAction>
#include  <QtPrintSupport/QPrinter>
#include  <QMenuBar>
#include  <QMessageBox>
#include  <QScrollBar>
#include  <QFileDialog>
#include  <QString>
#include  <QDebug>
#include  <QHBoxLayout>
#include  <QLineEdit>
#include  <QCheckBox>
#include  <QScrollArea>





class QAction;
class QLabel;
class QMenu;
class QScrollArea;
class QScrollBar;
class QProcess;
class QDir;



QT_BEGIN_NAMESPACE
namespace Ui { class DCMapp; }
QT_END_NAMESPACE

class DCMapp : public QMainWindow
{
    Q_OBJECT

public:
    DCMapp(QWidget *parent = nullptr);


    void appcall(QString appPath);

    ~DCMapp();

private slots:
    void on_pushButton_clicked();
    void on_execute_clicked();

private:
    Ui::DCMapp *ui;
    void createActions();

};
#endif // DCMAPP_H
