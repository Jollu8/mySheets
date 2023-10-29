#pragma once


#include <QDialog>

namespace Ui {
    class GoCell;
}

class GoCell : public QDialog
{
Q_OBJECT

public:
    explicit GoCell(QWidget *parent = nullptr);
    [[nodiscard]] QString cell() const;

    ~GoCell() override;

private:
    Ui::GoCell *ui;

};

