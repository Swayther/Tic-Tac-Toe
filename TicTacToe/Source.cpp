//Creates two player tictactoe
//Programer name: Michael Kleinman
//date: 03/10/2016

#include <iostream>
#include <string>		//library need for strings
#include <stdlib.h>     //used for the random number generator
#include "Computer.h"
using namespace std;
//gloabal variables

const int NUM_ROWS = 3;			//max num of size the grid can be
const int NUM_COLUMNS = 3;		//
char tictactoe_game[NUM_ROWS][NUM_COLUMNS];			

bool winCheckH(char pc, int row, int column);		//Checks the horizontal win state
bool winCheckV(char pc, int row, int column);		//checks for the vertical win state
bool winCheckD(char pc);							//checks the diagonal win state

void spaceCheckP(char pc, int row, int column);		//checks if the user's move is a allowed to be made
void spaceCheckC(char pc, int row, int column);		//checks if the computer's move is allowed to be made


void pvp();		//player vs player
void pvc();		//player vs computer



int main()
{

	int choice = 0;			//variable used for the user's menu choice


	do {
		//user UI
		cout << "============MENU=========== " << endl;
		cout << "1 - play against a another player " << endl;
		cout << "2 - play against computer" << endl;
		cout << "Or press -1 to exit" << endl;
		cout << "\nPlease chose a menu option : " << endl;
		cin >> choice;//reads in the user's choice

		switch (choice)
		{
		case 1: 

			pvp();

			break;
		case 2:

			pvc();

			break;

		case -1:

			cout << "Thanks for playing" << endl;

			exit;

			break;

		default:
			cout << "\nMenu choice was no valid, please enter a valid menu choice" << endl;
		}

	}while (choice != -1);		//runs the loop, until menu choice is -1
	//variable list

	exit;
	
	return 0;
}

//////////////////////////////////////////////

bool winCheckH( char pc, int row, int column )	//after every turn if the user has won yet in a row
{
	int winCount = 0;
	bool winCheck = false;
	//char x;

	for (int column = 0; column<NUM_COLUMNS; column++)
	{
		if (tictactoe_game[row][column] == pc)
		{
			// the character at this location
			// in the grid matches our players
			// character
			// add one to our win counter

			winCount++;
		}
	}

	if (winCount == NUM_COLUMNS)
	{
		winCheck = true;
		cout << "\n\t you win!!!! \n" << endl;
		
		//resets the board
		for (int row = 0; row<NUM_ROWS; row++)
		{
			for (int column = 0; column<NUM_COLUMNS; column++)
			{
				tictactoe_game[row][column] = 'A';

			}
		}
		return true;	//exits the check if the user passes the check for horizon 
	}
	else
		return false;

}

///////////////////////////////////////////

bool winCheckV(char pc, int row, int column)			//checks if the user wins via 3 in a column
{

	int winCount = 0;
	bool winCheck = false;

	for (int row = 0; row<NUM_COLUMNS; row++)
	{
		if (tictactoe_game[row][column] == pc)
		{
			// the character at this location
			// in the grid matches our players
			// character
			// add one to our win counter

			winCount++;
		}
	}

	if (winCount == NUM_COLUMNS)
	{
		winCheck = true;
		cout << "\n\t you win!!!! \n" << endl;
	
		//resets the board
		for (int row = 0; row<NUM_ROWS; row++)
		{
			for (int column = 0; column<NUM_COLUMNS; column++)
			{
				tictactoe_game[row][column] = 'A';
			}
		}
		return true;	//exits the check if the user passes the check for horizon 
	}
	else
	{
		return false;
	}

}



////////////////////////////////

bool winCheckD(char pc)
{
	if (tictactoe_game[1][1] == pc && tictactoe_game[0][0] == pc && tictactoe_game[2][2]== pc)
	{
		cout << "\n\t you win!!!! \n" << endl;

		//resets the board
		for (int row = 0; row<NUM_ROWS; row++)
		{
			for (int column = 0; column<NUM_COLUMNS; column++)
			{
				tictactoe_game[row][column] = 'A';
			}
		}
		return true;	//exits the check if the user passes the check for horizon 
	}

	else
	if (tictactoe_game[1][1] == pc &&  tictactoe_game[2][0]== pc  &&  tictactoe_game[0][2] == pc)
	{
		cout << "\n\t you win!!!! \n" << endl;

		//resets the board
		for (int row = 0; row<NUM_ROWS; row++)
		{
			for (int column = 0; column<NUM_COLUMNS; column++)
			{
				tictactoe_game[row][column] = 'A';
			}
		}
		return true;	//exits the check if the user passes the check for horizon 
	}

	else return false;
}

void spaceCheckC(char pc, int row, int column)
{
	while (tictactoe_game[row][column] != 'A')
	{
		row = rand() % 3;		//random num between 1-2
		column = rand() % 3;	//random num between 1-2
	}

	tictactoe_game[row][column] = pc;
}


void spaceCheckP(char pc, int row, int column)
{
	while (tictactoe_game[row][column] != 'A')
	{
		cout << "\nCo-oridnates already in use, please choose diffrent co-ordinates\n";
		cout << "Please enter the x co-ordinate : ";
		cin >> row;
		cout << "Please enter the y co-oridnate : ";
		cin >> column;
	}
	
	tictactoe_game[row][column] = pc;
}

void pvp()
{
	int winCount = 0;
	bool gameCheck = false;
	int row = 0;		//used for user's input for x
	int column = 0;		//used for the user's input for y


	cout << "\tTic Tac Toe Game" << endl;
	cout << "\t======PVP=======" << endl << endl;


	//setting up the grid with spaces
	for (int row = 0; row<NUM_ROWS; row++)
	{
		for (int column = 0; column<NUM_COLUMNS; column++)
		{
			tictactoe_game[row][column] = 'A';
		}
	}

	// prints the board 
	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int column = 0; column < NUM_COLUMNS; column++)
		{
			cout << "\t" << tictactoe_game[row][column];

		}
		cout << endl;
	}

	do
	{
		cout << "\nY's turn\nPlease enter your x value or enter -1 to exit to menu: ";
		cin >> row;
		if (row == -1)
		{
			break;
		}
		cout << "\nPlease enter yor y co-ordinate: ";
		cin >> column;

		cout << "\n" << endl;
		//used to check if the space on the board is free
		spaceCheckP('x', row, column);

		//checks after every move whether or not player x has won
		gameCheck = winCheckH('x', row, column);
		gameCheck = winCheckV('x', row, column);
		gameCheck = winCheckD('x');

		//prints the board again
		for (int row = 0; row < NUM_ROWS; row++)
		{
			for (int column = 0; column < NUM_COLUMNS; column++)
			{
				cout << "\t" << tictactoe_game[row][column];

			}
			cout << endl;
		}

		cout << "\nO's turn\nPlease enter your y value: ";
		cin >> row;

		cout << "\nPlease enter your x co-ordinate: ";
		cin >> column;

		cout << "\n" << endl;

		//checks if the space is free for player O
		spaceCheckP('O', row, column);

		//checks to see if player O has won 
		gameCheck = winCheckH('O', row, column);
		gameCheck = winCheckV('O', row, column);
		gameCheck = winCheckD('O');


		//prints the board again
		for (int row = 0; row < NUM_ROWS; row++)
		{
			for (int column = 0; column < NUM_COLUMNS; column++)
			{
				cout << "\t" << tictactoe_game[row][column];

			}
			cout << endl;
		}

	} while (row != -1 || column != -1);

	cout << "Thank you for playing. Goodbye" << endl;
	exit;

}

void pvc()
{
	Computer AI;		// AI is created 
	int row;
	int column;


	cout << "\tTic Tac Toe Game" << endl;
	cout << "\t======PVC=======" << endl << endl;

	//setting up the grid with spaces
	for (int row = 0; row<NUM_ROWS; row++)
	{
		for (int column = 0; column<NUM_COLUMNS; column++)
		{
			tictactoe_game[row][column] = 'A';
		}
	}

	// prints the board 
	for (int row = 0; row < NUM_ROWS; row++)
	{
		for (int column = 0; column < NUM_COLUMNS; column++)
		{
			cout << "\t" << tictactoe_game[row][column];

		}
		cout << endl;
	}
	do
	{
		cout << "\nX's turn\nPlease enter your y value or enter -1 to exit to menu: ";
		cin >> row;
		if (row == -1)
		{
			break;
		}
		cout << "\nPlease enter yor x co-ordinate: ";
		cin >> column;

		cout << "\n" << endl;
		//used to check if the space on the board is free
		spaceCheckP('x', row, column);

		//checks after every move whether or not player x has won
		AI.setGameCheck((winCheckH('x', row, column)));// = winCheckH('x', row, column);
		AI.setGameCheck((winCheckV('x', row, column)));
		AI.setGameCheck(winCheckD('x'));

		//prints the board again
		for (int row = 0; row < NUM_ROWS; row++)
		{
			for (int column = 0; column < NUM_COLUMNS; column++)
			{
				cout << "\t" << tictactoe_game[row][column];

			}
			cout << endl;
		}

		cout << "\nComputer's turn ";
		row = AI.getRow();		//random num between 1-2
		column = AI.getColumn(); 

		cout << "\n" << endl;

		//checks if the space is free for player O
		spaceCheckC('O', row, column);

		//checks to see if player O has won 
		AI.setGameCheck((winCheckH('O', row, column)));// = winCheckH('x', row, column);
		AI.setGameCheck((winCheckV('O', row, column)));
		AI.setGameCheck(winCheckD('O'));


		//prints the board again
		for (int row = 0; row < NUM_ROWS; row++)
		{
			for (int column = 0; column < NUM_COLUMNS; column++)
			{
				cout << "\t" << tictactoe_game[row][column];

			}
			cout << endl;
		}

	} while (row != -1 || column != -1);

	cout << "Thank you for playing. Goodbye" << endl;
	exit;

}
