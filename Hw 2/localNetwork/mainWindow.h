#pragma once
#include <QMainWindow>
#include "computers/linux.h"
#include "computers/mac.h"
#include "computers/windows.h"
#include "network.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
	Q_OBJECT
	
public:
	explicit MainWindow(QWidget *parent = 0);
	~MainWindow();

public slots:
	void killComputer(int);
	void setInstigator(QString);
	void setCurrentComputer(int);
	void setCurrentResult(bool);
	void onEndOfTry();
	
private:
	Ui::MainWindow *ui;
	Network *network;
};
