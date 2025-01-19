#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include<QtSql>
#include<QtDebug>
#include<QFile>
#include<QDir>
#include<QDebug>
#include<QString>
#include<QTextStream>

#include <QSqlDatabase>


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    friend void setupDatabaseConnection(QSqlDatabase& db); // friend function


private slots://for functions
    void on_account_Creation_clicked();

    void on_handle_Signin_clicked();

    void on_account_Creation_released();

private://data types
    Ui::MainWindow *ui;
    QSqlDatabase myData;
};

void setupDatabaseConnection(QSqlDatabase& db); //setupDatabaseConnection

#endif // MAINWINDOW_H
