#include "trainingform.h"
#include "ui_trainingform.h"

TrainingForm::TrainingForm(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TrainingForm)
{
    ui->setupUi(this);
}

TrainingForm::~TrainingForm()
{
    delete ui;
}
