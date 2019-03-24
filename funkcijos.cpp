#include "funkcijos.h"
#include <windows.h>
#include <iostream>

using namespace std;

funkcijos::funkcijos()
{
}

void funkcijos::refreshXY(int X, int Y)
{
	HANDLE hOut;
	COORD Position;

	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	Position.X = X;
	Position.Y = Y;
	SetConsoleCursorPosition(hOut, Position);
}

void funkcijos::screenCL(int eilutes)
{
	for (int i=0; i<eilutes; i++)
	{
		refreshXY(0, i);
		cout << "                                                            "; //60 symbols;
	}
	refreshXY(0, 0);
}