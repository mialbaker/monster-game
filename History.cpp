#include <iostream>
#include <string>
#include <random>
#include <utility>
#include <cstdlib>
#include <cctype>
using namespace std;

#include "History.h"




History::History(int nRows, int nCols)
{
	m_nRows = nRows;
	m_nCols = nCols;
	
	//initializes history grid to a grid of 0 (ints)
	for (int i = 1; i <= nRows; i++) 
	{
		for (int j = 1; j <= nCols; j++)
		{
			grid[i][j] = 0; 
		}
	}
}

bool History::record(int r, int c)
{
	// if r is greater than nRows or r is less than 1
	// if c is greater than nCols or c is less than 1
	if ((r > m_nRows) || (r < 1) || (c > m_nCols) || (c < 1)) //make sure the bounds are right
	{
		return false;
	}
	else
	{

		//record where the poison vial was dropped and add 1 
		//to number of poisoned vials already dropped on that grid point
		grid[r][c] += 1;
		return true; 
	}
}

void History::display() const
{
	//clear arena screen
	clearScreen();

	//fill history grid
	for (int r = 1; r <= m_nRows; r++)
	{
		for (int c = 1; c <= m_nCols; c++)
		{
			//if there is no record of blood vials dropped represent grid point as '.'
			if (grid[r][c] == 0)
			{
				cout << '.';
			}
			//if there is a record of blood vials dropped
			else
			{
				//represent grid point as a character from A-Z 
				//by adding 64 to change it to a character (ASCII)
				cout << char(grid[r][c] + 64);
			}
		}
		cout << endl;
	}
	cout << endl;
}