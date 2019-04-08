#include "trainingform.h"
#include "ui_trainingform.h"

#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QSqlQuery>
#include <QSqlRecord>

#include <QDebug>

TrainingForm::TrainingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainingForm)
{
    ui->setupUi(this);

    ui->dateEditDeparture->setDate(QDate::currentDate());
    ui->timeEditDeparture->setTime(QTime::currentTime());

    createModel();
    m_model->insertRow(m_model->rowCount(QModelIndex()));
    m_mapper->toLast();
    ui->lineEditDepType->setText("тренировка");
}

TrainingForm::~TrainingForm()
{
    delete ui;
}

void TrainingForm::addTrainingDeparture()
{
    m_mapper->submit();

    QString deptypeID = "SELECT * FROM DeparturesType WHERE (DepType = '%1')";
    QSqlQuery queryDepType;
    queryDepType.exec(deptypeID.arg(ui->lineEditDepType->text()));
    QSqlRecord recDepType = queryDepType.record();
    int nameColDepType = recDepType.indexOf("DepTypeID");
    queryDepType.next();
    int rowDepType = m_model->rowCount(QModelIndex()) - 1;
    m_model->setData(m_model->index(rowDepType, 1), queryDepType.value(nameColDepType).toInt());

    QString trainingID = "SELECT * FROM TrainingType WHERE (TrainingType = '%1')";
    QSqlQuery queryTraining;
    queryTraining.exec(trainingID.arg(ui->comboBoxTrainingType->currentText()));
    QSqlRecord recTraining = queryTraining.record();
    int nameColTraining = recTraining.indexOf("TrainingTypeID");
    queryTraining.next();
    int rowTraining = m_model->rowCount(QModelIndex()) - 1;
    m_model->setData(m_model->index(rowTraining, 2), queryTraining.value(nameColTraining).toInt());

    m_model->submitAll();
    emit modelChanged();
    this->close();
}

void TrainingForm::resizeLineEditAddress()
{
    QString text = ui->lineEditAddress->text();
    QFont font("", 0);
    QFontMetrics fm(font);
    int pixelsWide = fm.width(text);
    int pixelsHigh = fm.height();
    ui->lineEditAddress->setFixedSize(pixelsWide, pixelsHigh);
    this->adjustSize();
}

void TrainingForm::createModel()
{
    m_model = new QSqlRelationalTableModel(this);
    m_model->setTable("Training");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->setRelation(1, QSqlRelation("DeparturesType", "DepTypeID", "DepType"));
    m_model->setRelation(2, QSqlRelation("TrainingType", "TrainingTypeID", "TrainingType"));
    m_model->select();

    m_mapper = new QDataWidgetMapper(this);
    m_mapper->setModel(m_model);
    ui->comboBoxTrainingType->setModel(m_model->relationModel(2));
    ui->comboBoxTrainingType->setModelColumn(1);
    m_mapper->addMapping(ui->lineEditDepType, 1);
    m_mapper->addMapping(ui->comboBoxTrainingType, 2);
    m_mapper->addMapping(ui->lineEditAddress, 3);
    m_mapper->addMapping(ui->dateEditDeparture, 4);
    m_mapper->addMapping(ui->timeEditDeparture, 5);
    m_mapper->addMapping(ui->dateEditArrival, 6);
    m_mapper->addMapping(ui->timeEditArrival, 7);
    m_mapper->addMapping(ui->dateEditReturn, 8);
    m_mapper->addMapping(ui->timeEditReturn, 9);
    m_mapper->addMapping(ui->plainTextEditDescription, 10);
    m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}
