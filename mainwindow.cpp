#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbcreator.h"
#include "singletableview.h"
#include "signalingform.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlError>
#include <QMessageBox>
#include <QFileDialog>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->dateEditFrom->setDate(QDate::currentDate());
    ui->dateEditTo->setDate(QDate::currentDate());

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

void MainWindow::sortData()
{
    m_model->setFilter(QString("DepDate BETWEEN '%1' AND '%2'")
                       .arg(ui->dateEditFrom->date().toString("yyyy-MM-dd"),
                            ui->dateEditTo->date().toString("yyyy-MM-dd")));
    m_model->select();
}

void MainWindow::editSignalingTable()
{
}

void MainWindow::editDeparturesTypeTable()
{
}

void MainWindow::showSignalingForm()
{
    SignalingForm *addSignalingDeparture = new SignalingForm();
    addSignalingDeparture->setWindowTitle(trUtf8("Add exit to the alarm"));
    addSignalingDeparture->exec();
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
    m_model = new QSqlTableModel(this);
    m_model->setTable("Main");
    m_model->select();
}

void MainWindow::setupView()
{
    ui->tableViewMain->setModel(m_model);
    ui->tableViewMain->resizeColumnsToContents();
    ui->tableViewMain->horizontalHeader()->setStretchLastSection(true);
    ui->dateEditFrom->setDate(QDate::currentDate());
    ui->dateEditTo->setDate(QDate::currentDate());
}
