#pragma once
#include <stdlib.h>

/**
 * @brief Class for representation computers with different OS.
 */
class Computer
{
public:
	Computer();
	bool tryToInfect(int probabilityToBeInfected);
	int getOS();
	void setOS(int number);
	bool getIsInfected();

private:
	bool isInfected;
	int operationSystem; // 1 - Windows; 2 - Linux; 3 - Mac OS
};
