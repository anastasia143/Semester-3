#include "mainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("Local Network");
	infectedOnThisStep = new bool[16];

	network = new Computer[16];
	network[4].setOS(1);
	network[13].setOS(1);
	network[15].setOS(1);
	network[3].setOS(3);
	network[5].setOS(3);
	network[6].setOS(3);
	network[11].setOS(3);

	networkConnection = new char*[16];
	for(int i = 0; i < 16; i++)
		networkConnection[i] = new char[16];
	fillNetworkConnectionMatrix();

	connect(ui->startButton, SIGNAL(clicked()), this, SLOT(runVirus()));
	connect(this, SIGNAL(computerIsInfected(int)), SLOT(killComputer(int)));
}

void MainWindow::runVirus()
{
	int randNumber = rand() % 15 + 1;
	ui->instigator->setText("Computer " + QString::number(randNumber));

	for(int i = 0; i < 16; i++)
		infectedOnThisStep[i] = false;
	startInfection(randNumber);
}

void MainWindow::startInfection(int number)
{
	int chance = 0;
	switch(network[number].getOS())
	{
	case 1:
		chance = ui->spinBox_windows->value();
		break;
	case 2:
		chance = ui->spinBox_linux->value();
		break;
	case 3:
		chance = ui->spinBox_mac->value();
		break;
	}

	if ((network[number].getIsInfected()|| network[number].tryToInfect(chance))
														&& (!infectedOnThisStep[number]))
	{
		emit computerIsInfected(number);
		infectedOnThisStep[number] = true;
		for(int i = 1; i < 16; i++)
			if (((int)networkConnection[number][i] == 49))
					startInfection(i);
	}
}

void MainWindow::fillNetworkConnectionMatrix()
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

void MainWindow::killComputer(int number)
{
	switch(number)
	{
	case 1:
		ui->computer_1->setEnabled(false);
		break;
	case 2:
		ui->computer_2->setEnabled(false);
		break;
	case 3:
		ui->computer_3->setEnabled(false);
		break;
	case 4:
		ui->computer_4->setEnabled(false);
		break;
	case 5:
		ui->computer_5->setEnabled(false);
		break;
	case 6:
		ui->computer_6->setEnabled(false);
		break;
	case 7:
		ui->computer_7->setEnabled(false);
		break;
	case 8:
		ui->computer_8->setEnabled(false);
		break;
	case 9:
		ui->computer_9->setEnabled(false);
		break;
	case 10:
		ui->computer_10->setEnabled(false);
		break;
	case 11:
		ui->computer_11->setEnabled(false);
		break;
	case 12:
		ui->computer_12->setEnabled(false);
		break;
	case 13:
		ui->computer_13->setEnabled(false);
		break;
	case 14:
		ui->computer_14->setEnabled(false);
		break;
	case 15:
		ui->computer_15->setEnabled(false);
		break;
	}
}

MainWindow::~MainWindow()
{
	delete network;
	delete networkConnection;
	delete infectedOnThisStep;
	delete ui;
}
