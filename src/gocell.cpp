#include "gocell.h"
#include "ui_gocell.h"
#include <QRegularExpressionValidator>
#include <QRegularExpression>


GoCell::GoCell(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::GoCell)
{
    ui->setupUi(this);
    //Validating the regular expression
    QRegularExpression regCell{"[A-Z][1-9][0-9]{0,2}"};

    //Validating the regular expression
    ui->lineEdit->setValidator(new QRegularExpressionValidator(regCell));
}

GoCell::~GoCell()
{
    delete ui;
}
QString GoCell::cell() const
{
    return ui->lineEdit->text();
}