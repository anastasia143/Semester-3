/**
 * @author Semenova A.
 * This program implements local network.
 * User have 15 computers and 3 OS. User can set vulnerability of every OS and run different viruses to a random computer.
 **/

#include "mainWindow.h"
#include "logicTest.h"
#include "computerClassTest.h"
#include <QtTest/QTest>

int main()
{
	LogicTest logicTest;
	QTest::qExec(&logicTest);

	ComputerClassTest computerTest;
	QTest::qExec(&computerTest);

	/*MainWindow w;
	w.show();*/
	return 0;
}
