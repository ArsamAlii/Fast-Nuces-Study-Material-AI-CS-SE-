#include "loginpage.h"
#include "ui_loginpage.h"

#include "mainwindow.h"
#include"useraccount.h"
//#include"databaseutils.h"
#include"mainwindow.h"

#include<QMessageBox>

LoginPage::LoginPage(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LoginPage)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white; color: black;");

    setupDatabaseConnection(myData);

    if(myData.isOpen()){
        ui->Status->setText("Connected to Database");
    }
    else {
        ui->Status->setText("Failed to connect to Database");
    }

}


LoginPage::~LoginPage()
{
    delete ui;
}

void LoginPage::on_handle_Login_clicked()
{

    if (!myData.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database connection is not open.");
        return;
    }
    QString InputUsername ,InputPassword ;

    InputUsername = ui->inputUsername_text->text();
    InputPassword = ui->inputPassword_text->text();

    bool loggedIn = false;//initialise

    QSqlDatabase::database().transaction();
    QSqlQuery query(myData);

    query.prepare("SELECT * FROM UserInfo WHERE username = :username AND password = :password");
    query.bindValue(":username", InputUsername);//comparing username
    query.bindValue(":password", InputPassword);

    if (!query.exec()) {
        QMessageBox::warning(this, "Error 404!", "Database server does not exist");
        return;
    }

    if (query.exec()) {

        if (query.next()) {
            QSqlDatabase::database().commit();//either to fully return or fail
            QMessageBox::information(this, "Successful Login", "Correct username and password are entered");
            loggedIn = true;
        }
        else {
            QMessageBox::warning(this, "Login", "Invalid username or password");
        }
    }
    else {
        QMessageBox::critical(this, "Error", "Failed to execute the query. Error: " + query.lastError().text());
    }

    if (loggedIn) {
       LoginPage::close();
        UserAccount *page2 = new UserAccount();

        page2->setValue(InputUsername);//setter used to pass username
        page2->show();

        page2 = nullptr;
    }
}

void LoginPage::on_move_to_create_clicked()
{
    // Hide the current LoginPage window
    LoginPage::close();

    // Create and show the MainWindow window
    MainWindow *mov = new MainWindow();
    mov->show();

    mov = nullptr; // deallocate memory
}








