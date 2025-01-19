#ifndef LOGINPAGE_H
#define LOGINPAGE_H

#include <QWidget>
#include<QtSql>
#include<QtDebug>
#include"useraccount.h"

#include <QSqlDatabase>



namespace Ui {
class LoginPage;
}

class LoginPage : public QWidget
{
    Q_OBJECT

public:
    explicit LoginPage(QWidget *parent = nullptr);
    ~LoginPage();

    friend void setupDatabaseConnection(QSqlDatabase& db); // friend function


private slots:
    void on_handle_Login_clicked();

    void on_move_to_create_clicked();

private:
    Ui::LoginPage *ui;
    QSqlDatabase myData;

};

void setupDatabaseConnection(QSqlDatabase& db); //setupDatabaseConnection

#endif // LOGINPAGE_H
