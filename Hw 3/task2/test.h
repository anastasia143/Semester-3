#pragma once
#include <QtCore/QObject>
#include <QtTest/QTest>
#include <stdlib.h>
#include "zeroArrayElementsCounter.h"

class Test : public QObject
{
	Q_OBJECT
public:
	explicit Test(QObject *parent = 0) : QObject(parent) {}

private:
	int* oneDimensionalArray;
	int** twoDimensionalArray;
	int line;
	int column;

private slots:
	void initTestCase()
	{
		line = 10;
		column = 10;

		oneDimensionalArray = new int[line];
		twoDimensionalArray = new int*[line];
		for(int i = 0; i < line; i++)
			twoDimensionalArray[i] = new int[column];
	}

	void oneArrayTest_1()
	{
		for(int i = 0; i < line; i++)
			oneDimensionalArray[i] = 0;

		QCOMPARE(countZeroElements(oneDimensionalArray, line), line);
	}

	void twoArrayTest_1()
	{
		for(int i = 0; i < line; i++)
			for(int k = 0; k < column; k++)
				twoDimensionalArray[i][k] = 0;

		QCOMPARE(countZeroElements(twoDimensionalArray, line, column), line * column);
	}

	void oneArrayTest_2()
	{
		for(int i = 0; i < line; i++)
			oneDimensionalArray[i] = rand() % 100 + 1;
		oneDimensionalArray[6] = 0;
		oneDimensionalArray[9] = 0;
		oneDimensionalArray[5] = 0;
		oneDimensionalArray[1] = 0;

		QCOMPARE(countZeroElements(oneDimensionalArray, line), 4);
	}

	void twoArrayTest_2()
	{
		for(int i = 0; i < line; i++)
			for(int k = 0; k < column; k++)
				twoDimensionalArray[i][k] = rand() % 100 + 1;
		twoDimensionalArray[4][8] = 0;
		twoDimensionalArray[4][9] = 0;
		twoDimensionalArray[1][2] = 0;
		twoDimensionalArray[7][3] = 0;
		twoDimensionalArray[3][8] = 0;

		QCOMPARE(countZeroElements(twoDimensionalArray, line, column), 5);
	}

	void cleanupTestCase()
	{
		delete[] oneDimensionalArray;
		for(int i = 0; i < line; i++)
			delete[] twoDimensionalArray[i];
		delete[] twoDimensionalArray;
	}
};
