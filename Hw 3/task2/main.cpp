/**
*@author Semenova Anastasia
*@version 1.0
*/

#include <iostream>
#include "test.h"

int main()
{
	Test test;
	QTest::qExec(&test);
	return 0;
}
