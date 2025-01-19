#ifndef USERACCOUNT_H
#define USERACCOUNT_H

#include <QFileInfo>
#include <QWidget>
#include <QtDebug>
#include <QtSql>
#include <QTableWidgetItem>
#include <QBuffer>
#include <QFile>
#include <QFileInfo>
#include <QFileDialog>
#include <QPixmap>
#include <QByteArray>

#include <QSqlDatabase>


namespace Ui {
class UserAccount;
}

class UserAccount : public QWidget
{
    Q_OBJECT

public:
    explicit UserAccount(QWidget *parent = nullptr);
    void setValue(const QString &username_passed);

    ~UserAccount();

    friend void setupDatabaseConnection(QSqlDatabase& db); // friend function


private slots:
    void on_browse_Image_clicked();

    void on_handle_LogOut_released();

    void on_this_Account_Display_clicked();

private:
    Ui::UserAccount *ui;
    QSqlDatabase myData;
};

void setupDatabaseConnection(QSqlDatabase& db); //setupDatabaseConnection


#endif // USERACCOUNT_H
