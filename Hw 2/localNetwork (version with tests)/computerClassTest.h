#pragma once

#include <QtCore/QObject>
#include <QtTest/QTest>
#include "mainWindow.h"
#include "computer.h"

class ComputerClassTest : public QObject
{
	Q_OBJECT

public:

private:
	Computer* computer;

private slots:

	void osTest_1()
	{
		computer = new Windows;
		QCOMPARE(computer->getOS(), 1);
	}

	void osTest_2()
	{
		computer = new Mac;
		QCOMPARE(computer->getOS(), 3);
	}

	void interfectionRiskTest()
	{
		computer = new Linux;
		QCOMPARE(computer->getInfectionRisk(), 50);
		computer->setInfectionRisk(17);
		QCOMPARE(computer->getInfectionRisk(), 17);
	}

	void infectionPresenceTest_1()
	{
		computer = new Linux;
		QVERIFY(!computer->getIsInfected());
		computer->setInfectionRisk(100);
		computer->tryToInfect();
		QVERIFY(computer->getIsInfected());
	}

	void infectionPresenceTest_2()
	{
		computer = new Linux;
		QVERIFY(!computer->getIsInfected());
		computer->setInfectionRisk(0);
		computer->tryToInfect();
		QVERIFY(!computer->getIsInfected());
	}

	void cleanup()
	{
		delete computer;
	}

};
