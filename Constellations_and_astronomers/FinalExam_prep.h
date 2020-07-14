#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_FinalExam_prep.h"

class FinalExam_prep : public QMainWindow
{
    Q_OBJECT

public:
    FinalExam_prep(QWidget *parent = Q_NULLPTR);

private:
    Ui::FinalExam_prepClass ui;
};
