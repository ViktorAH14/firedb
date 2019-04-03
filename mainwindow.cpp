#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbcreator.h"
#include "singletableview.h"
#include "signalingform.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newDB()
{
    QFileDialog fd;
    fd.setDefaultSuffix("db");
    fd.setWindowTitle(trUtf8("New database"));
    fd.setFileMode(QFileDialog::AnyFile);
    fd.setNameFilter(trUtf8("Database (*.db)"));
    if (fd.exec() == QDialog::Accepted) {
        if (fd.selectedFiles().count() > 0) {
            dbName = fd.selectedFiles().at(0);
            setWindowTitle(trUtf8("Fire department departures - ") + dbName);
            createDB(dbName);
            createModel();
            setupView();
        }
    }
}

void MainWindow::openDB()
{
    QFileDialog fd;
    fd.setDefaultSuffix("db");
    fd.setWindowTitle(trUtf8("Open database"));
    fd.setFileMode(QFileDialog::AnyFile);
    fd.setNameFilter(trUtf8("Database (*.db)"));
    if (fd.exec() == QDialog::Accepted) {
        if (fd.selectedFiles().count() > 0) {
            dbName = fd.selectedFiles().at(0);
            setWindowTitle(trUtf8("Fire department departures - ") + dbName);
            connectDB(dbName);
            createModel();
            setupView();
        }
    }

}

void MainWindow::editSignalingTable()
{
}

void MainWindow::editDeparturesTypeTable()
{
}

void MainWindow::showSignalingForm()
{

}

bool MainWindow::connectDB(const QString &dbName)
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");
    db.setHostName("localhost");
    db.setDatabaseName(dbName);
    if (!db.open()) {
        QMessageBox::critical(this, trUtf8("Error"), db.lastError().text());
        return false;
    }
    return true;
}

bool MainWindow::createDB(const QString &dbName)
{
    if (!connectDB(dbName)) {
        return false;
    }
    DBCreator db;
    if (!db.newDeparturesDB()) {
        QMessageBox::critical(this, trUtf8("Error"), trUtf8("Unable to create database"));
    }
    return true;
}

void MainWindow::createModel()
{

}

void MainWindow::setupView()
{

}
