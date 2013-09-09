/**
 * @author Semenova A.
 * This program implements local network.
 * User have 15 computers and 3 OS. User can set vulnerability of every OS and run different viruses to a random computer.
 **/

#include "mainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	w.show();
	return a.exec();
}
