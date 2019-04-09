#include "unuccountingfireform.h"
#include "ui_unuccountingfireform.h"

#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QSqlQuery>
#include <QSqlRecord>

UnuccountingFireForm::UnuccountingFireForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::UnuccountingFireForm)
{
    ui->setupUi(this);

    ui->dateEditDeparture->setDate(QDate::currentDate());
    ui->timeEditDeparture->setTime(QTime::currentTime());

    createModel();
    m_model->insertRow(m_model->rowCount(QModelIndex()));
    m_mapper->toLast();
    ui->lineEditDepType->setText("неучётный пожар");
}

UnuccountingFireForm::~UnuccountingFireForm()
{
    delete ui;
}

void UnuccountingFireForm::addUnuccountingFireDeparture()
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

    QString unaccountedFireID = "SELECT * FROM TypeUnuccountingFire WHERE (TypeUnuccountingFire = '%1')";
    QSqlQuery queryUnaccountedFire;
    queryUnaccountedFire.exec(unaccountedFireID.arg(ui->cBoxTypeUnuccountingFire->currentText()));
    QSqlRecord recUnaccountedFire = queryUnaccountedFire.record();
    int nameColUnaccountedFire = recUnaccountedFire.indexOf("TypeUnuccountingFireID");
    queryUnaccountedFire.next();
    int rowUnaccountedFire = m_model->rowCount(QModelIndex()) - 1;
    m_model->setData(m_model->index(rowUnaccountedFire, 2), queryUnaccountedFire.value(nameColUnaccountedFire).toInt());

    m_model->submitAll();
    emit modelChanged();
    this->close();
}

void UnuccountingFireForm::createModel()
{
    m_model = new QSqlRelationalTableModel(this);
    m_model->setTable("UnuccountingFire");
    m_model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    m_model->setRelation(1, QSqlRelation("DeparturesType", "DepTypeID", "DepType"));
    m_model->setRelation(2, QSqlRelation("TypeUnuccountingFire", "TypeUnuccountingFireID", "TypeUnuccountingFire"));
    m_model->select();

    m_mapper = new QDataWidgetMapper(this);
    m_mapper->setModel(m_model);
    ui->cBoxTypeUnuccountingFire->setModel(m_model->relationModel(2));
    ui->cBoxTypeUnuccountingFire->setModelColumn(1);
    m_mapper->addMapping(ui->lineEditDepType, 1);
    m_mapper->addMapping(ui->cBoxTypeUnuccountingFire, 2);
    m_mapper->addMapping(ui->lineEditAddress, 3);
    m_mapper->addMapping(ui->lineEditReported, 4);
    m_mapper->addMapping(ui->dateEditDeparture, 5);
    m_mapper->addMapping(ui->timeEditDeparture, 6);
    m_mapper->addMapping(ui->dateEditArrival, 7);
    m_mapper->addMapping(ui->timeEditArrival, 8);
    m_mapper->addMapping(ui->dateEditFirstBarrel, 9);
    m_mapper->addMapping(ui->timeEditFirstBarrel, 10);
    m_mapper->addMapping(ui->dateEditLocalization, 11);
    m_mapper->addMapping(ui->timeEditLocalization, 12);
    m_mapper->addMapping(ui->dateEditMitigation, 13);
    m_mapper->addMapping(ui->timeEditMitigation, 14);
    m_mapper->addMapping(ui->dateEditReturn, 15);
    m_mapper->addMapping(ui->timeEditReturn, 16);
    m_mapper->addMapping(ui->pTextEditdescription, 17);
    m_mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
}

void UnuccountingFireForm::resizeLineEditAddress()
{
    QString text = ui->lineEditAddress->text();
    QFont font("", 0);
    QFontMetrics fm(font);
    int pixelsWide = fm.width(text);
    int pixelsHigh = fm.height();
    ui->lineEditAddress->setFixedSize(pixelsWide, pixelsHigh);
    this->adjustSize();
}
