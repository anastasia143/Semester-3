#pragma once
#include <QObject>
#include <fstream>
#include <string.h>
#include <QString>
#include <iostream>
#include "computers/linux.h"
#include "computers/mac.h"
#include "computers/windows.h"

/**
 * @brief Class for logic network part
 */
class Network : public QObject
{
	Q_OBJECT

public:
	explicit Network(QWidget *parent = 0);
	~Network();
	void updateSettingsForNewVirus(int randNumber);


public slots:
	void runVirus();
	void setWindowsChance(int);
	void setLinuxChance(int);
	void setMacChance(int);
	int nextStep();

signals:
	void computerIsInfected(int);
	void giveInstigator(QString);
	void currentComputer(int);
	void currentResult(bool);
	void endOftry();

private:
	Computer *network[16]; // All computers in network
	char **networkConnection; // Adjacency matrix for connections between computers
	bool *infectedOnThisStep; // Passed and infected computers on this try
	QList<int> needForCheck; // List of computer numbers that can be infected on this try

	void fillNetworkConnectionMatrix();
	void startInfection(int number);
	int windowsChance;
	int linuxChance;
	int macChance;
};
