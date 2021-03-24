#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTabBar>
#include <QTableView>
#include <QErrorMessage>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>


namespace Ui { class MainWindow;}

class PersonModel : public QAbstractTableModel
{
    Q_OBJECT

    public:
        PersonModel(QObject *parent = 0);

        int rowCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;
        int columnCount(const QModelIndex &parent = QModelIndex()) const Q_DECL_OVERRIDE;

        QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;
        QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const Q_DECL_OVERRIDE;

    private:
        QList<QString> tm_person_id;
        QList<QString> tm_person_name;

};

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
private slots:
    void handleConnectPushButton();
    void handleSubmitPushButton();
    void updateTable();

private:
    QSqlDatabase db;
};
#endif // MAINWINDOW_H
