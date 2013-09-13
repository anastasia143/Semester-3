#include "computer.h"

Computer::Computer()
{
	operationSystem = 2; // Linux
	isInfected = false;
}

bool Computer::tryToInfect()
{
	int randNumber = rand() % 100 + 1;
	isInfected = randNumber <= infectionRisk;
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

int Computer::getInfectionRisk()
{
	return infectionRisk;
}

void Computer::setInfectionRisk(int number)
{
	infectionRisk = number;
}
