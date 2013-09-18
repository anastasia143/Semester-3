#pragma once

#include <QtTest/QTest>
#include "robotTask.h"

class Test : public QObject
{
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0) : QObject(parent) {}

private:
	QList<int> robots;
	char* file;
	RobotTask* task;

private slots:
	void init()
	{
		robots.clear();
		file = new char[100];
		for(int i = 0; i < 100; i++)
			file[i] = '\n';
	}

	void logicTestOne()
	{
		file = "graph1.txt";
		robots << 0 << 1 << 2;
		task = new RobotTask(file, 5, robots);
		QCOMPARE(task->possibilityOfDestruction(), true);
	}

	void logicTestTwo()
	{
		file = "graph2.txt";
		robots << 1 << 3;
		task = new RobotTask(file, 5, robots);
		QCOMPARE(task->possibilityOfDestruction(), true);
	}

	void logicTestThree()
	{
		file = "graph3.txt";
		robots << 1;
		task = new RobotTask(file, 6, robots);
		QCOMPARE(task->possibilityOfDestruction(), false);
	}

	void logicTestFour()
	{
		file = "graph4.txt";
		robots << 1 << 2 << 3 << 5;
		task = new RobotTask(file, 6, robots);
		QCOMPARE(task->possibilityOfDestruction(), true);
	}

	void logicTestFive()
	{
		file = "graph5.txt";
		robots << 1 << 2 << 5;
		task = new RobotTask(file, 6, robots);
		QCOMPARE(task->possibilityOfDestruction(), false);
	}

	void cleanup()
	{
		delete[] file;
		delete task;
	}
};
