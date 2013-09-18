#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>
#include "mainWindow.h"
#include "network.h"

class LogicTest : public QObject
{
	Q_OBJECT

public:

private:
	Network* network;

private slots:
	void init()
	{
		network = new Network;
	}

	void infectionAlgorithmTest()
	{
		int randNumber = 5;
		network->updateSettingsForNewVirus(randNumber);

		network->setMacChance(100);
		network->setLinuxChance(100);
		network->setWindowsChance(0);

		QCOMPARE(network->nextStep(), 5);
		QCOMPARE(network->nextStep(), 1);
		QCOMPARE(network->nextStep(), 6);
		QCOMPARE(network->nextStep(), 8);
		QCOMPARE(network->nextStep(), 7);
		QCOMPARE(network->nextStep(), 3);
		QCOMPARE(network->nextStep(), 10);
		QCOMPARE(network->nextStep(), 11);
		QCOMPARE(network->nextStep(), 2);
		QCOMPARE(network->nextStep(), 0); // Windows - 4
		QCOMPARE(network->nextStep(), 9);
		QCOMPARE(network->nextStep(), 0); // Windows - 15
	}

	void infectionAlgorithmTest_2()
	{
		int randNumber = 13;
		network->updateSettingsForNewVirus(randNumber);

		network->setMacChance(100);
		network->setLinuxChance(0);
		network->setWindowsChance(100);

		QCOMPARE(network->nextStep(), 13);
		QCOMPARE(network->nextStep(), 4);
		QCOMPARE(network->nextStep(), 0); // Linux - 12
		QCOMPARE(network->nextStep(), 0); // Linux - 14
		QCOMPARE(network->nextStep(), 3);
		QCOMPARE(network->nextStep(), 0); // Linux - 2
		QCOMPARE(network->nextStep(), 0); // Linux - 7
	}

	void cleanup()
	{
		delete network;
	}

};
