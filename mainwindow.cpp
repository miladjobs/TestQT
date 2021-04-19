#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->tabWidget->setCurrentIndex(0);
    ui->tabWidget->findChild<QTabBar *>()->hide();
    ui->lineEdit_4->setEchoMode(QLineEdit::Password);
    ui->lineEdit->setPlaceholderText("localhost");
    ui->lineEdit_2->setPlaceholderText("testQt");
    ui->lineEdit_3->setPlaceholderText("miladjobs");

    myPlayer = new Player();
    QObject::connect(myPlayer, SIGNAL(processedImage(QImage)),
                     this, SLOT(updatePlayerUI(QImage)));
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::handlePlayButton);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::handleLoadButton);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::handleSubmitPushButton);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::handleConnectPushButton);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::handleVideoTabButton);
}

MainWindow::~MainWindow()
{
    delete myPlayer;
    delete ui;
}

void MainWindow::handleConnectPushButton()
{
    if(ui->lineEdit->text().length() > 0 && ui->lineEdit_2->text().length() > 0 &&
       ui->lineEdit_3->text().length() > 0 && ui->lineEdit_4->text().length() > 0)
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(ui->lineEdit->text());
        db.setDatabaseName(ui->lineEdit_2->text());
        db.setUserName(ui->lineEdit_3->text());
        db.setPassword(ui->lineEdit_4->text());
        bool ok = db.open();
        if (ok) {
            updateTable();
            ui->tabWidget->setCurrentIndex(1);
        } else {
            QErrorMessage::qtHandler()->showMessage("Database not found");
        }
    } else{
        QErrorMessage::qtHandler()->showMessage("all data must be complete");
    }
}

void MainWindow::handleSubmitPushButton()
{
    if(ui->lineEdit_5->text().length() > 0)
    {
        QSqlQuery qSqlQuery;
        qSqlQuery.exec("insert into person (name) values ('" + ui->lineEdit_5->text() + "');");
        db.commit();
        updateTable();
        ui->lineEdit_5->setText("");
    } else{
        QErrorMessage::qtHandler()->showMessage("name can not be empty");
    }
}

void MainWindow::updateTable()
{
    auto *pModel = new PersonModel(this);
    ui->tableView->setModel(pModel);
    ui->tableView->horizontalHeader()->setVisible(true);
    ui->tableView->show();
}

PersonModel::PersonModel(QObject *parent) : QAbstractTableModel(parent)
{
    tm_person_id.clear();
    tm_person_id = QList<QString>();
    tm_person_name.clear();
    tm_person_name = QList<QString>();
    QSqlQuery qSqlQuery;
    qSqlQuery.exec("SELECT * FROM person;");
    while (qSqlQuery.next()){
        tm_person_id.append(qSqlQuery.value(0).toString());
        tm_person_name.append(qSqlQuery.value(1).toString());
    }
}

int PersonModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return tm_person_name.length()+1;
}

int PersonModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 2;
}

QVariant PersonModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Qt::DisplayRole) {
        return QVariant();
    }
    if (index.column() == 0) {
        if(index.row() >= tm_person_id.length()){
            return QVariant();
        }
        return tm_person_id[index.row()];
    } else if (index.column() == 1) {
        if(index.row() >= tm_person_name.length()){
            return QVariant();
        }
        return tm_person_name[index.row()];
    }
    return QVariant();
}

QVariant PersonModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        if (section == 0) {
            return QString("Id");
        } else if (section == 1) {
            return QString("Name");
        }
    }
    return QVariant();
}

void MainWindow::updatePlayerUI(QImage img)
{
    if (!img.isNull())
    {
        ui->label_8->setAlignment(Qt::AlignCenter);
        ui->label_8->setPixmap(QPixmap::fromImage(img).scaled(ui->label_8->size(), Qt::KeepAspectRatio, Qt::FastTransformation));
    }
}

void MainWindow::handleLoadButton() {
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open Video"), ".",
                                                    tr("Video Files (*.avi *.mpg *.mp4)"));
    if (!filename.isEmpty()){
        if (!myPlayer->LoadVideo(filename))
        {
            QMessageBox msgBox;
            msgBox.setText("The selected video could not be opened!");
            msgBox.exec();
        }
    }
}

void MainWindow::handlePlayButton()
{
    if (myPlayer->IsStopped())
    {
        myPlayer->Play();
        ui->pushButton_3->setText(tr("Stop"));
    }else
    {
        myPlayer->Stop();
        ui->pushButton_3->setText(tr("Play"));
    }
}

void MainWindow::handleVideoTabButton()
{
    ui->tabWidget->setCurrentIndex(2);
}