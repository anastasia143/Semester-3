#pragma once
#include <stdlib.h>

/**
 * @brief Class for representation computers with different OS.
 */
class Computer
{
public:
	Computer();
	bool tryToInfect();
	int getOS();
	bool getIsInfected();
	int getInfectionRisk();
	void setInfectionRisk(int number);
	void setOS(int number);

protected:
	bool isInfected;
	int operationSystem; // 1 - Windows; 2 - Linux; 3 - Mac OS
	int infectionRisk;
};
