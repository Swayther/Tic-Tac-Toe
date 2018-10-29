#pragma once
class Computer
{
private:

	int winCount;
	bool gameCheck;
	int row;		//used for user's input for x
	int column;		//used for the user's input for y

public:
	Computer();
	~Computer();

	//setters
	void setRow();
	void setColumn();
	void setGameCheck(int gc);

	//getters
	int getRow();
	int getColumn();
	int getGameCheck();
};

