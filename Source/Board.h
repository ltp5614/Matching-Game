#pragma once

#include <iostream>
#include <cstdlib>
#include <Windows.h>
#include <time.h>
#include <ctime>
#include <cstdlib>
#include <conio.h>


//DISPLAY BOARD
void MakeColor(char c);	//Set color for a specified character
void MakeBoard(char** a, int m, int n, int px, int py, int x1, int y1, int x2, int y2, int& score); //Draw the board
char** genBoard(); //Generate values for each cell in the board


//UNDO BOARD
char*** CreateUndoBoard();	
void GenUndoBoard(char*** a, char** board, int row, int col, int index);
void GenUndoBoardToMainBoard(char*** a, char** board, int row, int col, int index);
void deallocateUndo(char***& Undo, int row, int col);


//MOVEMENT FOR EACH LEVEL
void MoveBoardForEasy(char*** undo, char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2, char move, int &score);
void MoveBoardForNormal(char*** undo, char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2, char move, int &score);
void MoveBoardForHard(char*** undo, char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2, char move, int &score);