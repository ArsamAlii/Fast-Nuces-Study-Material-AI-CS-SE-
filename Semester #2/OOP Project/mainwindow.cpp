#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "loginpage.h"
//#include"databaseutils.h"

#include<QMessageBox>



MainWindow::MainWindow(QWidget *parent)//parameterised constructor by default
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    this->setStyleSheet("background-color: white; color: black;");
    ui->setupUi(this);

    setupDatabaseConnection(myData);//assigned in mainwindow.h


    if(myData.isOpen()){
        ui->Status->setText("Connected to Database");
    }// shows in mainwindow.ui if connected to database or not
    else {
        ui->Status->setText("Failed to connect to Database");
    }

    ui->PasswordTxt->setEchoMode(QLineEdit::Password);



}

MainWindow::~MainWindow()//destructor defined to delte ui
{
    delete ui;
}


void MainWindow::on_account_Creation_clicked()
{
    // Check if the database connection is open
    if (!myData.isOpen()) {
        QMessageBox::critical(this, "Database Error", "Database connection is not open.");
        return;
    }

    // if the username already exists
    QSqlQuery checkQuery(myData);
    checkQuery.prepare("SELECT COUNT(*) FROM UserInfo WHERE username = ?");//check if that username already exist
    //         prepare gives path count the usename from top to bittim frim thr table "userinfo" where it check username

    checkQuery.addBindValue(ui->UserTxt->text());//assigning value which user wrote as useranme

    if (!checkQuery.exec()) {//if value not gone in database then issue
        QMessageBox::warning(this, "Error 404!", "Database server does not exist");
        return;
    }

    if (checkQuery.next()) {
        int count = checkQuery.value(0).toInt();

        if (count != 0) {
            QMessageBox::warning(this, "Username Exists", "Username already exists. Please choose a different username.");
        }

        // INSERT functionality from CRUD
        QSqlDatabase::database().transaction();//allows to either complete whole trans or fail the whole
        QSqlQuery QueryInsertData(myData);

        QueryInsertData.prepare("INSERT INTO UserInfo(username,password,Image_Name,Image_Data) VALUES(:username,:password,:Image_Name,:Image_Data)");



        while (ui->full_name->text().isEmpty()||ui->UserTxt->text().isEmpty() || ui->PasswordTxt->text().isEmpty()||ui->f_name->text().isEmpty()||ui->mother_name->text().isEmpty()) {
            if (QMessageBox::Cancel == QMessageBox::information(this, "Empty Slot(s) Detected","All Slots are Mendatory to Fill.", QMessageBox::Cancel)) {
                return;
            }

        }


        QueryInsertData.bindValue(":username",ui->UserTxt->text()); //usertxt converted into tect and stored in usernmae
        QueryInsertData.bindValue(":password", ui->PasswordTxt->text());

        if (QueryInsertData.exec()) {

            QFile File ("D:/DESKTOP/OOP proj done/oop proj files/QtWitharsam.txt");
            if (File.open(QIODevice::Append))
            {
                QTextStream stream (&File);
                stream<< "User Full Name: "<<ui->full_name->text();
                stream << " || ";
                stream << "Father Name: "<<ui->f_name->text();
                stream << " || ";
                stream << "Mother Name: "<<ui->mother_name->text()<<"\n\n\n";
                File.close();
            }

            QSqlDatabase::database().commit();// check if the data stored in database is permenantly saved
            QMessageBox::information(this, "Account Created", "Now You can log into your account");

            ui->UserTxt->clear();
            ui->PasswordTxt->clear();
            ui->f_name->clear();
            ui->mother_name->clear();
            ui->full_name->clear();

        } else {
            QMessageBox::critical(this, "Error 404!", QueryInsertData.lastError().text());
        }


    }
}
// operator overloading
QDebug operator+(QDebug debug, const LoginPage* newWindoww) {
    debug << "Value of newWindow: " << newWindoww;
    return debug;
}


void MainWindow::on_handle_Signin_clicked()
{
    MainWindow::close();

    // Create and show the login page
    LoginPage *newWindow = new LoginPage();
    newWindow->show();

    newWindow = nullptr; // deallocate the space from heap(dynamic memory)

    qDebug()+newWindow;

}
