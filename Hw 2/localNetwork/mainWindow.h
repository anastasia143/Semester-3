#pragma once
#include <QMainWindow>
#include "computer.h"
#include <iostream>
#include <fstream>
#include <string.h>

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
	void runVirus();
	void killComputer(int);

signals:
	void computerIsInfected(int);
	
private:
	Ui::MainWindow *ui;
	Computer *network; // All computers with network
	char **networkConnection; // Adjacency matrix for connections between computers
	bool *infectedOnThisStep; // Passed and infected computers on this step of work

	void fillNetworkConnectionMatrix();
	void startInfection(int number);
};
