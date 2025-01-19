//#include "databaseutils.h"//open header file

#include"mainwindow.h"
#include"loginpage.h"
#include"useraccount.h"

#include <QSqlError> // Include for QSqlError if database not open output error

#include <QSql> // to use qt in sql
#include <QMessageBox> //for popup message

void setupDatabaseConnection(QSqlDatabase& db) {

    db = QSqlDatabase::addDatabase("QSQLITE", "qt_sql_default_connection");// path created for sql database
    db.setDatabaseName("D:/DESKTOP/OOP proj done/oop proj files/database1.db");// location of database function for path

    // if the database not opened
    if (!db.open()) {
        QMessageBox::critical(nullptr, "Database Error",db.lastError().text());//pop up message used
        //         :: syntax(heading, error message)  .text() converts error into readable form
    }
}
