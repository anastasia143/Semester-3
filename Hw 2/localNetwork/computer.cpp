#include "computer.h"

Computer::Computer()
{
	operationSystem = 2; // Linux
	isInfected = false;
}

bool Computer::tryToInfect(int probabilityToBeInfected)
{
	int randNumber = rand() % 101 + 1;
	isInfected = (randNumber <= probabilityToBeInfected);
	return isInfected;
}

int Computer::getOS()
{
	return operationSystem;
}

void Computer::setOS(int number)
{
	operationSystem = number;
}

bool Computer::getIsInfected()
{
	return isInfected;
}
