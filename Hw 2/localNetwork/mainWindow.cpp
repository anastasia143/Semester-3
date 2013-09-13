#include "mainWindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(new Ui::MainWindow)
{
	ui->setupUi(this);
	setWindowTitle("Local Network");
	network = new Network;
	ui->stepButton->setEnabled(false);

	connect(network, SIGNAL(computerIsInfected(int)), this, SLOT(killComputer(int)));
	connect(network, SIGNAL(giveInstigator(QString)), this, SLOT(setInstigator(QString)));
	connect(network, SIGNAL(currentComputer(int)), this, SLOT(setCurrentComputer(int)));
	connect(network, SIGNAL(currentResult(bool)), this, SLOT(setCurrentResult(bool)));
	connect(network, SIGNAL(endOftry()), this, SLOT(onEndOfTry()));
	connect(ui->spinBox_linux, SIGNAL(valueChanged(int)), network, SLOT(setLinuxChance(int)));
	connect(ui->spinBox_mac, SIGNAL(valueChanged(int)), network, SLOT(setMacChance(int)));
	connect(ui->spinBox_windows, SIGNAL(valueChanged(int)), network, SLOT(setWindowsChance(int)));
	connect(ui->stepButton, SIGNAL(clicked()), network, SLOT(nextStep()));
	connect(ui->startButton, SIGNAL(clicked()), network, SLOT(runVirus()));
}

void MainWindow::setInstigator(QString instigator)
{
	ui->instigator->setText("Computer " + instigator);
	ui->startButton->setEnabled(false);
	ui->stepButton->setEnabled(true);
}

void MainWindow::setCurrentComputer(int number)
{
	ui->currentComputer->setText(QString::number(number));
}

void MainWindow::setCurrentResult(bool result)
{
	if(result)
		ui->currentResult->setText("Success!");
	else
		ui->currentResult->setText("Fail!");
}

void MainWindow::onEndOfTry()
{
	ui->startButton->setEnabled(true);
	ui->stepButton->setEnabled(false);
	ui->instigator->setText("End of try");
	ui->currentComputer->setText("");
	ui->currentResult->setText("");
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
	delete ui;
}
