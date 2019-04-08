#include "singleform.h"
#include "ui_singleform.h"

#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QSqlQuery>
#include <QSqlRecord>

SingleForm::SingleForm(const QString &depType, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SingleForm)
{
    ui->setupUi(this);
    ui->dateEditDep->setDate(QDate::currentDate());
    ui->timeEditDep->setTime(QTime::currentTime());

    createModel();
    m_model->insertRow(m_model->rowCount(QModelIndex()));
    m_mapper->toLast();
    m_depType = depType;

    ui->lineEditDepType->setText(m_depType);
    resizeLineEditDepType();

}

SingleForm::~SingleForm()
{
    delete ui;
}

void SingleForm::addSingleDeparture()
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

void SingleForm::resizeLineEditAddress()
{
    QString text = ui->lineEditAddress->text();
    QFont font("", 0);
    QFontMetrics fm(font);
    int pixelsWide = fm.width(text);
    int pixelsHigh = fm.height();
    ui->lineEditAddress->setFixedSize(pixelsWide, pixelsHigh);
    this->adjustSize();

}

void SingleForm::createModel()
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

void SingleForm::resizeLineEditDepType()
{
    QString text = ui->lineEditDepType->text();
    QFont font("", 0);
    QFontMetrics fm(font);
    int pixelsWide = fm.width(text);
    int pixelsHidh = fm.height();
    ui->lineEditDepType->setFixedSize(pixelsWide, pixelsHidh);
    this->adjustSize();
}
