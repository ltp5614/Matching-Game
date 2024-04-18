#include "Setting.h"

//Set text color using the specified number
void textColor(int number) {
	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE); //Get the handle to console output
	SetConsoleTextAttribute(color, number);			//Set text attribute to the specified number
}

//Move cursor to the specified position (x, y)
void goToXY(int x, int y) {
	HANDLE hConsoleOutput; //Declare a handle to the console output
	COORD Cursor_and_Pos = { x - 1, y - 1 }; //Create a COORD structure with the specified position (x, y)
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE); //Get the handle to the console output
	SetConsoleCursorPosition(hConsoleOutput, Cursor_and_Pos); //Set the cursor position to the specified coordinate
}