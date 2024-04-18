#pragma once

#include <iostream>
#include <Windows.h>

//CHECK ROW AND COLUMN FOR MATCHING
bool checkCol(char** board, int row, int col, int px, int py, int start, int end, int y);
bool checkRow(char** board, int row, int px, int py, int col, int start, int end, int x);
bool CheckEmptyCol(char** a, int row, int col, int posy);
bool CheckEmptyRow(char** a, int row, int col, int posx);

//CHECK MATCHING
bool checkI(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2);	//Check I matching
bool checkL(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2);	//Check L matching
bool checkU(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2);	//Check U matching
bool checkZ(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2);	//Check Z matching


//CHECK RESULT
bool checkWin(char** board, int row, int col);	//Check whether player has won or not


//DELETE
void deleteLineRow(char** board, int row, int col, int px, int py, int start, int end, int x);
void deleteLineCol(char** board, int row, int col, int px, int py, int start, int end, int y);
void deleteCell(char& a, char& b);
void DeleteElementFocus(char** a, int row, int col, char focus); //Delete all characters identical to a specific character stored in variable "focus"
void deleteI(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2);
void deallocate(char**& board, int row, int col);

//Using for Normal Level and Hard Level
void DelEmptyRowDown(char** a, int row, int col, int posx);		//Delete empty row and move down
void DelEmptyRowUp(char** a, int row, int col, int posx);		//Delete empty row and move up
void DelEmptyColLeft(char** a, int row, int col, int posy);		//Delete empty column and move left
void DelEmptyColRight(char** a, int row, int col, int posy);	//Delete empty column and move right


//SLIDING CELLS TO THE CENTER
void SortEmptyRow(char** a, int row, int col);	//Move row up and down to the center
void SortEmptyCol(char** a, int row, int col);	//Move column left and right to the center
