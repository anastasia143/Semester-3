#pragma once
#include <fstream>
#include <iostream>
#include <QList>
#include "QString"

/**
 * @brief RobotTask class
 * This class helps to find out possibility of robot destruction.
 */
class RobotTask
{
public:
	RobotTask(char* graphFileName, int vertexCount, QList<int> robots);
	~RobotTask();

	//  Main function
	bool possibilityOfDestruction();

private:
	void fillGraphMatrix(char* graphFileName);

	// These functions compose two possible path for robots.
	void bypassGraphOne(int vertex, int parity);
	void bypassGraphTwo(int vertex, int parity);

	int** graphMatrix;
	int matrixSize;
	int robotCount;

	// Verties with robots.
	QList<int> robotPlacement;
	// In this lists we are collecting pathes.
	QList<int> pathOne;
	QList<int> pathTwo;
};
