#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LabTest2.h"

class LabTest2 : public QMainWindow
{
    Q_OBJECT

public:
    LabTest2(QWidget *parent = Q_NULLPTR);

private:
    Ui::LabTest2Class ui;
};
