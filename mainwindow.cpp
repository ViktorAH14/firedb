#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbcreator.h"
#include "signalingform.h"
#include "singleform.h"

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

void MainWindow::showSignalingForm()
{
    SignalingForm *addSignalingDeparture = new SignalingForm();
    connect(addSignalingDeparture, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    addSignalingDeparture->setWindowTitle(trUtf8("Add exit to the alarm"));
    addSignalingDeparture->exec();
}

void MainWindow::showDepTypeTable()
{
    QString tableName = "DeparturesType";
    QString columnName = "Вид выезда";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'DeparturesType'"));
    editDepTypeTable->exec();
}

void MainWindow::showDistrictsTable()
{
    QString tableName = "Districts";
    QString columnName = "Район";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'Districts'"));
    editDepTypeTable->exec();
}

void MainWindow::showVehicleTypeTable()
{
    QString tableName = "VehicleType";
    QString columnName = "Вид транспортного средства";
    SingleForm *editVehicleTypeTable = new SingleForm(tableName, columnName);
    connect(editVehicleTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editVehicleTypeTable->setWindowTitle(trUtf8("Editing table 'VehicleType'"));
    editVehicleTypeTable->exec();
}

void MainWindow::showVentilationTypeTable()
{
    QString tableName = "VentilationType";
    QString columnName = "Тип вентиляции";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'VentilationType'"));
    editDepTypeTable->exec();
}

void MainWindow::showTypeASRTable()
{
    QString tableName = "TypeASR";
    QString columnName = "Тип аварийно-спасательных работ";
    SingleForm *editTypeASRTable = new SingleForm(tableName, columnName);
    connect(editTypeASRTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editTypeASRTable->setWindowTitle(trUtf8("Editing table 'TypeASR'"));
    editTypeASRTable->exec();
}

void MainWindow::showExistingASFTable()
{
    QString tableName = "ExistingASF";
    QString columnName = "Аварийно-спасательные формирования";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'ExistingASF'"));
    editDepTypeTable->exec();
}

void MainWindow::showFireResistanceTable()
{
    QString tableName = "FireResistance";
    QString columnName = "Степень огнестойкости";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'FireResistance'"));
    editDepTypeTable->exec();
}

void MainWindow::showHeatingTypeTable()
{
    QString tableName = "HeatingType";
    QString columnName = "Вид отопления";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'HeatingType'"));
    editDepTypeTable->exec();
}

void MainWindow::showOwnTypeTable()
{
    QString tableName = "OwnType";
    QString columnName = "Вид собственности";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'OwnType'"));
    editDepTypeTable->exec();
}

void MainWindow::showSecondDamagedFactorsTable()
{
    QString tableName = "SecondDamagedFactors";
    QString columnName = "Вторичные поражающие факторы";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'SeconDamagedFactors'"));
    editDepTypeTable->exec();
}

void MainWindow::showSourceInfTable()
{
    QString tableName = "SourceInf";
    QString columnName = "Источник информации";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'SourceInf'"));
    editDepTypeTable->exec();
}

void MainWindow::showRatingTable()
{
    QString tableName = "Rating";
    QString columnName = "Оценка РТП";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'Rating'"));
    editDepTypeTable->exec();
}

void MainWindow::showTrainingTypeTable()
{
    QString tableName = "TrainingType";
    QString columnName = "Вид тренировки";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'TrainingType'"));
    editDepTypeTable->exec();
}

void MainWindow::showTypeInstrumentTable()
{
    QString tableName = "TypeInstrument";
    QString columnName = "Тип инструмента";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'TypeInstrument'"));
    editDepTypeTable->exec();
}

void MainWindow::showTypeObjectTable()
{
    QString tableName = "TypeObject";
    QString columnName = "Тип объекта";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'TypeObject'"));
    editDepTypeTable->exec();
}

void MainWindow::showTypeUnuccountingFireTable()
{
    QString tableName = "TypeUnuccountingFire";
    QString columnName = "Вид неучётного пожара";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'TypeUnuccountingFire'"));
    editDepTypeTable->exec();
}

void MainWindow::showTypeTrafficAccidentTable()
{
    QString tableName = "TypeTrafficAccident";
    QString columnName = "Вид ДТП";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'TypeTrafficAccident'"));
    editDepTypeTable->exec();
}

void MainWindow::showAccidentAlertTable()
{
    QString tableName = "AccidentAlert";
    QString columnName = "Средство оповещения";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'AccidentAlert'"));
    editDepTypeTable->exec();
}

void MainWindow::showBarrelTypeTable()
{
    QString tableName = "BarrelType";
    QString columnName = "Вид ствола";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'BarrelType'"));
    editDepTypeTable->exec();
}

void MainWindow::showCauseFireTable()
{
    QString tableName = "CauseFire";
    QString columnName = "Причина пожара";
    SingleForm *editDepTypeTable = new SingleForm(tableName, columnName);
    connect(editDepTypeTable, SIGNAL(modelChanged()), this, SLOT(updateModel()));
    editDepTypeTable->setWindowTitle(trUtf8("Editing table 'CauseFire'"));
    editDepTypeTable->exec();
}

void MainWindow::updateModel()
{
    m_model->select();
    ui->tableViewMain->resizeColumnsToContents();
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
