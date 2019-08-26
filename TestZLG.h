#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_TestZLG.h"

class TestZLG : public QMainWindow
{
	Q_OBJECT

public:
	TestZLG(QWidget *parent = Q_NULLPTR);

private:
	Ui::TestZLGClass ui;
};
