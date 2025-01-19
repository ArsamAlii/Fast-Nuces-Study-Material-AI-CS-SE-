#include "useraccount.h"
#include "ui_useraccount.h"
//#include "databaseutils.h"
//#include "loginpage.h"
#include "mainwindow.h"
#include <QMessageBox>


UserAccount::UserAccount(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::UserAccount)
{
    ui->setupUi(this);
    this->setStyleSheet("background-color: white; color: black;");

    setupDatabaseConnection(myData);

    if (myData.open()) {
        ui->Status->setText("Connected to Database");
    } else {
        ui->Status->setText("Failed to connect to Database");
    }

}
// setter function
void UserAccount::setValue(const QString &value) {
    ui->user->setText(value);
}


UserAccount::~UserAccount()
{
    delete ui;
}

void UserAccount::on_browse_Image_clicked()
{
    myData.open();
    QString ImagePath = QFileDialog::getOpenFileName(this,tr("Select Image"),QCoreApplication::applicationDirPath(),tr("IMAGE Files (*.jpg *.png *.jpeg *.gif)"));
    //above funtion used by help of gpt to browse image
    QPixmap Image(ImagePath);

    if (Image.isNull()) {//if different imagr format then no file saved
        QMessageBox::critical(this, tr("Error"), tr("Failed to load image"));
    }

    QSize BrowseImageSize = ui->DisplayBrowse_bt->size();//qsize calc size
    if (Image.width() > BrowseImageSize.width() || Image.height() > BrowseImageSize.height()) {
        QPixmap scaledImage = Image.scaled(BrowseImageSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
        ui->DisplayBrowse_bt->setPixmap(scaledImage);
    } else {
        ui->DisplayBrowse_bt->setPixmap(Image);
    }


    // Save image data to buffer and database
        QBuffer ImageBufferData;
    if (ImageBufferData.open(QIODevice::ReadWrite))
    {
        Image.save(&ImageBufferData, QFileInfo(ImagePath).suffix().toLatin1());//help stackoverflow to make this func
    }

    QByteArray FinalDataToSave = ImageBufferData.buffer().toBase64();//imagr is stired in base 64

    QFileInfo FileInfo(ImagePath);

    QString ImageName = FileInfo.fileName();
    qDebug()<<"ImageName= "<<ImageName;

    QString fetch_username = ui->user->text();

    QSqlDatabase::database().transaction();

    //Performing update functionality
    // Performing SELECT to check if the username exists
    QSqlQuery checkUsernameQuery(myData);
    checkUsernameQuery.prepare("SELECT * FROM UserInfo WHERE username = :username");
    checkUsernameQuery.bindValue(":username", fetch_username);

    if (!checkUsernameQuery.exec()) {
        qDebug() << "Error checking username:" << checkUsernameQuery.lastError().text();
        return; // Exit function if there's an error
    }

    if (checkUsernameQuery.next()) {

        // UPDATE functionality from CRUD
        QSqlQuery updateQuery(myData);

        updateQuery.prepare("UPDATE UserInfo SET Image_Name=:Image_Name, Image_Data=:Image_Data WHERE username=:username");

        updateQuery.bindValue(":Image_Name", ImageName);
        updateQuery.bindValue(":Image_Data", FinalDataToSave);
       updateQuery.bindValue(":username", fetch_username);

        if (!updateQuery.exec()) {
            qDebug() << "Error updating image:" << updateQuery.lastError().text();
        } else {
            QSqlDatabase::database().commit();
           // qDebug() << "Image updated successfully";
        }
    }
    myData.close();
}


void UserAccount::on_handle_LogOut_released()
{
    UserAccount::close();

    MainWindow* opn = new MainWindow();
    opn->show();

    opn = nullptr;


}

void UserAccount::on_this_Account_Display_clicked()
{
    QByteArray ImageDataFromDatabase;
    QPixmap Image;
    QString ImageName;
    QString fetch_username = ui->user->text();

    myData.open();
    QSqlQuery QueryGetImage(myData);
    QueryGetImage.prepare("SELECT * FROM UserInfo WHERE username = :username");
    QueryGetImage.bindValue(":username", fetch_username);

    if (QueryGetImage.exec() && QueryGetImage.next()) // Check if query executed successfully and retrieved a row
    {
        ImageName = QueryGetImage.value("Image_Name").toString();
        ImageDataFromDatabase = QByteArray::fromBase64(QueryGetImage.value("Image_Data").toByteArray());
        QString extension = QFileInfo(ImageName).suffix().toLower();

        // Load the image based on the extension
        if (extension == "jpg" || extension == "jpeg") {
            Image.loadFromData(ImageDataFromDatabase, "JPG");
        } else if (extension == "png") {
            Image.loadFromData(ImageDataFromDatabase, "PNG");
        } else if (extension == "gif") {
            Image.loadFromData(ImageDataFromDatabase, "GIF");
        } else {
            QMessageBox::critical(this, tr("EMPTY"), tr("Image Does Not Exist"));
        }

        // size of the label box
        QSize labelSize = ui->Database_Displayed->size();

        // Scale the image only if its dimensions exceed the label's size
        if (Image.width() > labelSize.width() || Image.height() > labelSize.height())
        {
            QPixmap scaledImage = Image.scaled(labelSize, Qt::KeepAspectRatio, Qt::SmoothTransformation);
            ui->Database_Displayed->setPixmap(scaledImage);
        }
        else {
            ui->Database_Displayed->setPixmap(Image);
        }
    }
    else
    {
        QMessageBox::critical(this, tr("Error"), tr("Failed to retrieve image"));
    }
    myData.close();
    //ui->TableWidget_Display->resizeRowsToContents();

    Image.save(QCoreApplication::applicationDirPath() + "/Image_From_Database.jpg");
}


