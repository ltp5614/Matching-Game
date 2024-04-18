#pragma once

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <mmsystem.h>
#include <iomanip>
#include <string>
#include <fstream>

//LIST
#define Menu_List	5		//Maximum number of options for main menu
#define Level_List	3		//Maximum number of options for level
#define Continue_List 2		//Maximum number of options for replaying


//BASIC KEY
#define Key_Up		72
#define Key_Down	80
#define Key_Left	75
#define Key_Right	77
#define Key_Enter	13
#define Key_Esc		27

//COLOR
#define BLACK         0
#define NAVY_BLUE     1
#define GREEN         2
#define TEAL          3
#define MAROON        4
#define PURPLE        5
#define OLIVE         6
#define GRAY          7
#define DARK_GRAY     8
#define BRIGHT_GREEN  9
#define AQUA          10
#define LIGHT_GREEN   11
#define BRIGHT_RED    12
#define PINK          13
#define YELLOW        14
#define WHITE         15


//LEADERBOARD TEXT FILE
#define Max_Players		100		//Max player can be save in the list of leaderboard

using namespace std;

//PLAYER'S INFORMATION
struct PlayerInfo {
	string name;
	int level;
	int score;
};


//MAIN FUNCTION IN MENU
void showMenu();			//Display game starting

void playSound();			//Play theme song
void playSoundEffect();		//Play sound effect when selecting level
void playSoundWinner();		//Play song when player wins

void showLevels();			//Display list of level 
void showLeaderboard();		//Display leaderboard
void showTutorial();		//Display gameplay tutorial
void showIntroduction();	//Display game introduction
void winner();				//Announcement of player's victory
void replay(int ptrLevel);	//Continue playing the same level or exit the level


//LEADERBOARD - LOGIN
void readLeaderboard();									//Read and print the leaderboard
void sortLeaderboard();									//Sort leaderboard in descending order
void updateLeaderboard(PlayerInfo& newPlayerInfo);		//Update new player or new score in array
void printLeaderboard();								//Print leaderboard on console
void inputPlayerInfo(int selectedLevel);				//Input new player's information
void writeLeaderboard();								//Update leaderboard.txt


//LEVELS
void easyLevel(int &score);		//Easy level
void normalLevel(int &score);	//Normal level
void hardLevel(int &score);		//Hard level