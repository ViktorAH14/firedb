#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbcreator.h"
#include "table.h"
#include "tableiomapper.h"
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

    signalingTableView = new SingleTableView();
    signalingTableView->setWindowTitle(trUtf8("Signalling table"));

    departuresTypeView = new SingleTableView();//NOTE move
    departuresTypeView->setWindowTitle(trUtf8("Departure type table"));//NOTE move

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
    signalingTableView->exec();
}

void MainWindow::editDeparturesTypeTable()
{
    departuresTypeView->exec();//NOTE modify
}

void MainWindow::showSignalingForm()
{
    SignalingForm *addSignalingTable = new SignalingForm();
    addSignalingTable->setWindowTitle(trUtf8("Add departure to trigger the alarm"));
    addSignalingTable->setMapper(signalingMapper);
    addSignalingTable->exec();
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
    deleteModel();//NOTE !

    mainTable = new Table(0, "Main");
    mainTable->openTable();
    mainMapper = new TableIOMapper(mainTable);

    departuresTypeTable = new Table(0, "DeparturesType");//NOTE move
    departuresTypeTable->openTable();//NOTE move
    departuresTypeMapper = new TableIOMapper(departuresTypeTable);//NOTE move

    signalingTable = new Table(0, "Signaling");
    signalingTable->openTable();
    signalingTable->addRelation("DepTypeID", "DeparturesType", "DepTypeID", "DepType");
    signalingMapper = new TableIOMapper(signalingTable);
}

void MainWindow::setupView()
{
    signalingTableView->setMapper(signalingMapper);

    departuresTypeView->setMapper(departuresTypeMapper);//NOTE  move

    mainMapper->setView(ui->tableView);
//    ui->tableView->setColumnHidden(0, true);
    ui->tableView->resizeColumnsToContents();
}

void MainWindow::deleteModel()
{
    delete signalingMapper;
    delete departuresTypeMapper;//NOTE move
    delete mainMapper;

    delete mainTable;
    delete signalingTable;
    delete departuresTypeTable;
}
