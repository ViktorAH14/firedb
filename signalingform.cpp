#include "signalingform.h"
#include "ui_signalingform.h"
#include "tableiomapper.h"

SignalingForm::SignalingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignalingForm)
{
    ui->setupUi(this);
}

SignalingForm::~SignalingForm()
{
    delete ui;
}

void SignalingForm::setMapper(TableIOMapper *mapper)
{
    this->mapper = mapper;
}
