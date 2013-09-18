#include "robotTask.h"

RobotTask::RobotTask(char* graphFileName, int vertexCount, QList<int> robots)
{
	matrixSize = vertexCount;
	graphMatrix = new int*[vertexCount];
	for(int i = 0; i < vertexCount; i++)
		graphMatrix[i] = new int[vertexCount];
	fillGraphMatrix(graphFileName);

	robotCount = robots.length();
	robotPlacement = robots;
}

RobotTask::~RobotTask()
{
	for(int i = 0; i < matrixSize; i++)
		delete[] graphMatrix[i];
	delete[] graphMatrix;
}

bool RobotTask::possibilityOfDestruction()
{
	if(robotCount == 1)
		return false;

	bypassGraphOne(0, 2);

	int adjacentVertex = 0;
	for(int i = 0; i < matrixSize; i++)
	{
		if(graphMatrix[0][i] == 1)
		{
			adjacentVertex = i;
			break;
		}
	}
	bypassGraphTwo(adjacentVertex, 2);

	if(!pathTwo.isEmpty())
	{
		for(int i = 0; i < pathTwo.length(); i++)
			if(pathOne.contains(pathTwo.at(i)))
				return true;
	}

	int robotCountOnPathOne = 0;
	int robotCountOnPathTwo = 0;

	for(int i = 0; i < robotCount; i++)
	{
		if(pathOne.contains(robotPlacement.at(i)))
			robotCountOnPathOne++;
		if(pathTwo.contains(robotPlacement.at(i)))
			robotCountOnPathTwo++;
	}

	if((robotCountOnPathOne == 1) || (robotCountOnPathTwo == 1))
		return false;

	return true;
}

void RobotTask::bypassGraphOne(int vertex, int parity)
{
	if(parity % 2 == 0)
		pathOne.append(vertex);
	parity++;
	for(int i = 0; i < matrixSize; i++)
		if((graphMatrix[vertex][i] == 1) && (!pathOne.contains(i)))
			bypassGraphOne(i, parity);
}

void RobotTask::bypassGraphTwo(int vertex, int parity)
{
	if(parity % 2 == 0)
		pathTwo.append(vertex);
	parity++;
	for(int i = 0; i < matrixSize; i++)
		if((graphMatrix[vertex][i] == 1) && (!pathTwo.contains(i)))
			bypassGraphTwo(i, parity);
}

void RobotTask::fillGraphMatrix(char* graphFileName)
{
	std::ifstream file;
	char str[100];
	file.open(graphFileName);

	for(int i = 0; i < matrixSize; i++)
		str[i] = NULL;
	for(int i = 0; i < matrixSize; i++)
	{
		file >> str;
		for(int k = 0; k < matrixSize; k++)
			graphMatrix[i][k] = (int)str[k] - (int)'0';

		for(int c = 0; c < matrixSize; c++)
			str[c] = NULL;
	}
	file.close();
}
