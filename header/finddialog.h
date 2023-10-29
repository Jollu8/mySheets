#pragma once

#include <QDialog>

namespace Ui {
    class FindDialog;
}

class FindDialog : public QDialog
{
Q_OBJECT

public:
    explicit FindDialog(QWidget *parent = nullptr);
    QString textfield() const;
    ~FindDialog();

private:
    Ui::FindDialog *ui;
};

