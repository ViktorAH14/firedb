#include "signalingform.h"
#include "ui_signalingform.h"

#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QSqlQuery>
#include <QSqlRecord>

SignalingForm::SignalingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignalingForm)
{
    ui->setupUi(this);
    ui->dateEditDep->setDate(QDate::currentDate());
    ui->timeEditDep->setTime(QTime::currentTime());
    ui->dateEditArrival->setDate(QDate::currentDate());
    ui->timeEditArrival->setTime(QTime::currentTime());
    ui->dateEditReturn->setDate(QDate::currentDate());
    ui->timeEditReturn->setTime(QTime::currentTime());

    createModel();

    m_model->insertRow(m_model->rowCount(QModelIndex()));
    m_mapper->toLast();
    ui->lineEditDepType->setText("сигнализация");

}

SignalingForm::~SignalingForm()
{
    delete ui;
}

void SignalingForm::addSignalingDeparture()
{
    m_mapper->submit();
    QString deptypeID = "SELECT * FROM DeparturesType WHERE (DepType = '%1')";
    QSqlQuery query;
    query.exec(deptypeID.arg(ui->lineEditDepType->text()));
    QSqlRecord rec = query.record();
    int nameCol = rec.indexOf("DepTypeID");
    query.next();
    int row = m_model->rowCount(QModelIndex()) - 1;
    m_model->setData(m_model->index(row, 1), query.value(nameCol).toInt());
    m_model->submitAll();
    emit modelChanged();
    this->close();
}

void SignalingForm::createModel()
{
    m_model = new QSqlRelationalTableModel(this);
    m_model->setTable("Signaling");
    m_model->setRelation(1, QSqlRelation("DeparturesType", "DepTypeID", "DepType"));
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->select();

    m_mapper = new QDataWidgetMapper();
    m_mapper->setModel(m_model);
    m_mapper->addMapping(ui->lineEditDepType, 1);
    m_mapper->addMapping(ui->lineEditAddress, 2);
    m_mapper->addMapping(ui->dateEditDep, 3);
    m_mapper->addMapping(ui->timeEditDep, 4);
    m_mapper->addMapping(ui->dateEditArrival, 5);
    m_mapper->addMapping(ui->timeEditArrival, 6);
    m_mapper->addMapping(ui->dateEditReturn, 7);
    m_mapper->addMapping(ui->timeEditReturn, 8);
    m_mapper->addMapping(ui->textEditDescripton, 9);
    m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}
