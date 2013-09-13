#include "network.h"

Network::Network(QWidget *parent)
{
	infectedOnThisStep = new bool[16];

	windowsChance = 100;
	macChance = 85;
	linuxChance = 50;

	network[0] = new Linux;
	network[1] = new Linux;
	network[2] = new Linux;
	network[3] = new Mac;
	network[4] = new Windows;
	network[5] = new Windows;
	network[6] = new Windows;
	network[7] = new Linux;
	network[8] = new Linux;
	network[9] = new Linux;
	network[10] = new Linux;
	network[11] = new Windows;
	network[12] = new Linux;
	network[13] = new Windows;
	network[14] = new Linux;
	network[15] = new Windows;

	networkConnection = new char*[16];
	for(int i = 0; i < 16; i++)
		networkConnection[i] = new char[16];
	fillNetworkConnectionMatrix();
}

void Network::runVirus()
{
	int randNumber = rand() % 15 + 1;
	emit giveInstigator(QString::number(randNumber));

	for(int i = 0; i < 16; i++)
		infectedOnThisStep[i] = false;

	needForCheck.clear();
	needForCheck.append(randNumber);

	nextStep();
}

void Network::nextStep()
{
	if(!needForCheck.isEmpty())
	{
		int number = needForCheck.first();
		emit currentComputer(number);

		int chance = 0;
		switch(network[number]->getOS())
		{
		case 1:
			chance = windowsChance;
			break;
		case 2:
			chance = linuxChance;
			break;
		case 3:
			chance = macChance;
			break;
		}
		network[number]->setInfectionRisk(chance);

		if ((network[number]->getIsInfected()|| network[number]->tryToInfect())
															&& (!infectedOnThisStep[number]))
		{
			emit computerIsInfected(number);
			emit currentResult(true);
			infectedOnThisStep[number] = true;
			for(int i = 1; i < 16; i++)
				if (((int)networkConnection[number][i] == 49) && (!needForCheck.contains(i)) && (!infectedOnThisStep[i]))
						needForCheck.append(i);
		}
		else
		{
			emit currentResult(false);
		}
		needForCheck.removeFirst();
	}
	else
	{
		emit endOftry();
	}
}

void Network::setLinuxChance(int chance)
{
	linuxChance = chance;
}

void Network::setMacChance(int chance)
{
	macChance = chance;
}

void Network::setWindowsChance(int chance)
{
	windowsChance = chance;
}

void Network::fillNetworkConnectionMatrix()
{
	std::ifstream file;
	char str[16];
	file.open("networkMatrix.txt");

	for(int i = 0; i < 16; i++)
		str[i] = NULL;
	for(int i = 1; i < 16; i++)
	{
		file >> str;
		for(int k = 1; k < 16; k++)
			networkConnection[i][k] = str[k - 1];
		for(int c = 0; c < 16; c++)
			str[c] = NULL;
	}
}

Network::~Network()
{
	for(int i = 0; i < 16; i++)
		delete[] networkConnection[i];
	delete[] networkConnection;
	delete[] infectedOnThisStep;
	for(int i = 0; i < 16; i++)
		delete network[i];
}
