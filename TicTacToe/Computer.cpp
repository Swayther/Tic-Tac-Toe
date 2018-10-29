#include "Computer.h"
#include <iostream>
#include <string>

using namespace std;


Computer::Computer()
{
	 gameCheck = false;
	 winCount = 0; 
	 setRow();
	 setColumn();
}


Computer::~Computer()
{
}
//setters
void Computer::setRow()
{
	row = rand() % 3;	//does the same for the column
}

void Computer::setColumn()
{
	column = rand() % 3;	//does the same for the column
}

void Computer::setGameCheck(int gc)
{
	gameCheck = gc;
}

//getters
int Computer::getRow()
{
	return row;
}

int Computer::getColumn()
{
	return column;
}

int Computer::getGameCheck()
{
	return gameCheck;
}
