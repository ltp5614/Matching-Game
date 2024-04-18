#include "Menu.h"
#include "Setting.h"
#include "Check.h"
#include "Board.h"

using namespace std;

//Declaration for leaderboard list
PlayerInfo leaderboard[Max_Players];
int numPlayers = 0;		//Size of leaderboard list
PlayerInfo newPlayer;	//Variable to store player's information

//Play theme song
void playSound() {
	//Playing theme song concurrently with other function when in the main menu
	//Theme song will be replayed when it's finished
	PlaySound(L"Music/MarioThemeSong.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

//Play sound effect
void playSoundEffect() {
	//Playing sound effect concurrently with other function when in the level list
	PlaySound(L"Music/SoundEffect.wav", NULL, SND_FILENAME | SND_ASYNC);
}

//Play sound to congratulate player
void playSoundWinner() {
	//Play song for winner cocurrently while showing congratulation session
	//Song will be replayed when it's finished
	PlaySound(L"Music/WinnerSong.wav", NULL, SND_FILENAME | SND_LOOP | SND_ASYNC);
}

//Choose level to play
void showLevels() {
	//Turn off music
	PlaySound(NULL, 0, 0);

	//Array string to contain 3 levels' name
	const string level[Level_List] = { "Easy", "Normal", "Hard"};
	int ptrLevel = 0; //Cursor to select the option

	//Clear the console
	system("cls");

	//Show the table to select the level
	while (true) {
		textColor(YELLOW);

		goToXY(73, 15);
		cout << "Select Difficulty" << endl;

		//Loop for showing the level list
		for (int i = 0; i < Level_List; i++) {
			//If that option is being selected, it will change color to green
			if (ptrLevel == i) {
				textColor(GREEN);
				goToXY(75, 17 + i);
				cout << char(175) << " " << level[i] << " " << char(174);
			}
			
			//If not, it will have its color is yellow
			else {
				textColor(YELLOW);
				goToXY(75, 17 + i);
				cout << "[+] " << level[i];
			}
		}

		textColor(YELLOW);
		goToXY(64, 21);
		cout << "Press Esc to return to the main menu";

		//Setting keyboard button
		while (true) {
			if (_kbhit()) { //If a key is pressed
				char button = _getch(); //Store that key

				//If you press any key in this level session, it will play sound effect
				playSoundEffect();

				//Key up
				if (button == Key_Up || button == 'w' || button == 'W') {
					if (ptrLevel > 0) {
						--ptrLevel;
					}

					else {
						ptrLevel = Level_List - 1;
					}

					break;
				}

				//Key down
				else if (button == Key_Down || button == 's' || button == 'S') {
					if (ptrLevel < Level_List - 1) {
						++ptrLevel;
					}

					else {
						ptrLevel = 0;
					}

					break;
				}

				//Key Esc
				else if (button == Key_Esc) {
					playSound();
					return;
				}

				else if (button == Key_Enter) {
					system("cls");
					
					//Save player's level and name
					inputPlayerInfo(ptrLevel + 1);
					
					switch (ptrLevel) {
						case 0: {
							easyLevel(newPlayer.score);
							
							writeLeaderboard();

							break;
						}

						case 1: {
							normalLevel(newPlayer.score);

							writeLeaderboard();
							break;
						}

						case 2: {
							hardLevel(newPlayer.score);

							writeLeaderboard();
							break;
						}

						default: {
							cout << "Error";
						}
					}
				}

				break;
			}
		}
	}
}

void replay(int ptrLevel) {
	//Array string to contain 2 option
	const string next[Continue_List] = { "Yes", "No" };
	int ptrContinue = 0;

	system("cls");
	
	textColor(YELLOW);
	goToXY(70, 20);
	cout << "Do you want to continue ?";
	
	//Show option to choose
	while (true) {
		for (int i = 0; i < Continue_List; i++) {
			//If that option is being selected, option will change to green
			if (ptrContinue == i) {
				textColor(GREEN);
				goToXY(78, 22 + i);
				cout << char(175) << ' ' << next[i] << ' ' << char(174);
			}

			//If not, option is red
			else {
				textColor(BRIGHT_RED);
				goToXY(78, 22 + i);
				cout << "[+] " << next[i];
			}
		}

		while (true) {
			if (_kbhit()) { //If any key is pressed
				char buttonContinue = _getch(); //Store that key

				//Key up
				if (buttonContinue == Key_Up || buttonContinue == 'w' || buttonContinue == 'W') {
					if (ptrContinue > 0) {
						--ptrContinue;
					}

					else {
						ptrContinue = Continue_List - 1;
					}

					break;
				}

				//Key down
				else if (buttonContinue == Key_Down || buttonContinue == 's' || buttonContinue == 'S') {
					if (ptrContinue < Continue_List - 1) {
						++ptrContinue;
					}

					else {
						ptrContinue = 0;
					}

					break;
				}

				else if (buttonContinue == Key_Enter) {
					switch (ptrContinue) {

					//Player continue playing
					case 0: {

						//Reset player score
						newPlayer.score = 0;

						switch (ptrLevel) {
						case 0: {
							easyLevel(newPlayer.score);
							break;
						}

						case 1: {
							normalLevel(newPlayer.score);
							break;
						}

						case 2: {
							hardLevel(newPlayer.score);
							break;
						}

						default: {
							cout << "Error";
						}
						}
					}

					//Exit
					case 1: {
						system("cls");
						return;
					}

					default: {
						cout << "Error";
					}
					}
				}
			}
		}
	}
}

//List of top 10 players
void showLeaderboard() {
	system("cls");

	textColor(YELLOW);
	goToXY(47, 3);
	cout << "-------------------------------------------------------------------------" << endl;
	goToXY(47, 4);
	cout << "                                LEADERBOARD                              " << endl;
	goToXY(47, 5);
	cout << "-------------------------------------------------------------------------" << endl;
	goToXY(47, 6);
	cout << "         NAME                     LEVEL                    SCORE" << endl;

	readLeaderboard();

	textColor(MAROON);
	printLeaderboard();

	textColor(WHITE);
	goToXY(67, 25);
	cout << "Press Esc to return to the main menu";

	while (true) {
		if (_kbhit()) {
			char button = _getch();

			//Key Esc
			if (button == Key_Esc) {
				return;
			}
		}
	}
}

//Get data in leaderboard.txt
void readLeaderboard() {
	ifstream readFile("Text/leaderboard.txt");

	if (!readFile) {
		cout << "Cannot open leaderboard file" << endl;

		return;
	}

	//Set number players is 0
	numPlayers = 0;
	string temp;

	//While file is not read to the end and number players is not max
	while ((getline(readFile, temp)) &&
		   (numPlayers < Max_Players)) {

		//Skip empty line
		if (temp.empty()) {
			continue;
		}

		size_t pos = temp.find('|');

		//Skip malformed line
		if (pos == string::npos) {
			continue;
		}

		//Get the name from string temp
		leaderboard[numPlayers].name = temp.substr(0, pos);
		temp.erase(0, pos + 1); //Delete name in string temp

		pos = temp.find('|');

		//Skip malformed line
		if (pos == string::npos) {
			continue;
		}

		//Get player's score in string temp
		leaderboard[numPlayers].score = stoi(temp.substr(0, pos));
		temp.erase(0, pos + 1); //Delete score in string temp

		//Get the level
		leaderboard[numPlayers].level = stoi(temp);

		//Increase number players in the leaderboard list
		numPlayers++;
	}

	readFile.close();
}


//Sort all players' score in descending ordrer
void sortLeaderboard() {
	for (int i = numPlayers - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (leaderboard[j].score < leaderboard[j + 1].score) {
				PlayerInfo temp = leaderboard[j];
				leaderboard[j] = leaderboard[j + 1];
				leaderboard[j + 1] = temp;
			}
		}
	}
}

//Login
//Get the player's information
void inputPlayerInfo(int selectedLevel) {
	goToXY(70, 21);
	cout << "Please enter the name under 20 characters";
	goToXY(70, 20);
	cout << "Enter your name: ";
	getline(cin, newPlayer.name);

	//The name must not be empty or longer than 20 characters
	while (newPlayer.name.length() > 20 || newPlayer.name == "") {
		system("cls");
		goToXY(70, 22);
		cout << "Invalid length";
		goToXY(70, 21);
		cout << "Please enter the name under 20 characters";
		goToXY(70, 20);
		cout << "Enter your name: ";
		getline(cin, newPlayer.name);
	}

	//Store the level that player has chose
	newPlayer.level = selectedLevel;
	
	//Reset player's score
	newPlayer.score = 0;
}

//Print list of 10 highest score player
void printLeaderboard() {
	for (int i = 0; i < numPlayers; i++) {
		if (i >= 10) {
			break;
		}

		goToXY(56, 8 + i);
		cout << leaderboard[i].name;
		goToXY(83, 8 + i);
		cout << leaderboard[i].level;
		goToXY(108, 8 + i);
		cout << leaderboard[i].score;
	}
}

//Adding new player or update the old player's score
void updateLeaderboard(PlayerInfo& newPlayerInfo) {
	//Check new player's name is similar to any player's name in the leaderboard;
	bool foundName = false;

	for (int i = 0; i < numPlayers; i++) {
		if ((leaderboard[i].name == newPlayerInfo.name) &&
			(leaderboard[i].level == newPlayerInfo.level)) {
			foundName = true;

			if (newPlayer.score > leaderboard[i].score) {
				leaderboard[i].score = newPlayerInfo.score;
			}
			
			break;
		}
	}

	if (!foundName && numPlayers < Max_Players) {
		leaderboard[numPlayers++] = newPlayerInfo;
	}

	sortLeaderboard();
}

//Rewrite the file leaderboard.txt
void writeLeaderboard() {
	readLeaderboard();

	updateLeaderboard(newPlayer);

	ofstream writeFile("Text/leaderboard.txt");
	if (!writeFile) {
		cout << "Cannot open file leaderboard.txt for writing" << endl;
		return;
	}

	for (int i = 0; i < numPlayers; ++i) {
		writeFile << leaderboard[i].name << "|" << leaderboard[i].score << "|" << leaderboard[i].level;

		if (i < numPlayers - 1) {
			writeFile << endl;
		}
	}

	writeFile.close();
}

//Tutorial
void showTutorial() {
	system("cls");

	textColor(YELLOW);
	goToXY(47, 3);
	cout << "-------------------------------------------------------------------------";
	goToXY(47, 4);
	cout << "                                TUTORIAL                                 ";
	goToXY(47, 5);
	cout << "-------------------------------------------------------------------------";
	
	textColor(WHITE);
	goToXY(50, 6);
	cout << char(175) << " Using buttons W, A, S, D or Arrow key to move.";
	goToXY(50, 7);
	cout << char(175) << " Press Enter to select the box need to delete.";
	goToXY(50, 8);
	cout << char(175) << " Press U for move suggestion.";
	goToXY(50, 9);
	cout << char(175) << " Press I and type the character you want to delete.";  
	goToXY(50, 10);
	cout << "  It will delete all cells with the character you have entered.";
	goToXY(50, 11);
	cout << char(175) << " Press Esc to return to menu.";


	while (true) {
		if (_kbhit()) {
			char button = _getch();

			if (button == Key_Esc) {
				return;
			}
		}
	}
}

//Introduce project
void showIntroduction() {
	system("cls");

	textColor(YELLOW);
	goToXY(48, 3);
	cout << "--------------------------------------------------------------------------";
	goToXY(48, 4);
	cout << "                                   ABOUT                                 ";
	goToXY(48, 5);
	cout << "--------------------------------------------------------------------------";

	textColor(WHITE);
	goToXY(50, 6);
	cout << "This is a game project for the Advanced Programming Technique and Practice";
	goToXY(49, 7);
	cout << "course. This project is carried out by two freshmen students from the";
	goToXY(49, 8);
	cout << "University of Science. This project is a matching game, a game to connect";
	goToXY(49, 9);
	cout << "2 identical squares and connect all pairs of squares to win.";
	goToXY(49, 11);
	cout << "Press Esc to return the main menu";
	

	while (true) {
		if (_kbhit()) {
			char button = _getch();

			if (button == Key_Esc) {
				return;
			}
		}
	}
}

//Show winner session
void winner() {
	system("cls");

	playSoundWinner();

	textColor(MAROON);
	goToXY(58, 17);
	cout << " __   __                          _          _   _   _";

	textColor(GREEN);
	goToXY(58, 18);
	cout << " \\ \\ / / ___   _   _   __      _ (_) ____   | | | | | |";

	textColor(NAVY_BLUE);
	goToXY(58, 19);
	cout << "  \\ V / / _ \\ | | | |  \\ \\ /\\ / /| ||  _ \\  | | | | | |";

	textColor(PURPLE);
	goToXY(58, 20);
	cout << "   | | | (_) || |_| |   \\ V  V / | || | | | |_| |_| |_|";

	textColor(TEAL);
	goToXY(58, 21);
	cout << "   |_|  \\___/  \\___/     \\_/\\_/  |_||_| |_| (_) (_) (_)";

	textColor(WHITE);
	goToXY(71, 25);
	system("pause");

	PlaySound(NULL, 0, 0);
}


//Show easy level
void easyLevel(int &score) {
	//Initialize the game board
    char** gameBoard = genBoard();
	char*** undoBoard = CreateUndoBoard();
    char move = '0';

    // Size of the game board
    int rows = 8;
    int cols = 8;

    // Player's position
    int playerX = 1;
    int playerY = 1;

    // Positions of points on the board
    int x1 = -1;
    int y1 = -1;
    int x2 = -1;
    int y2 = -1;

    // Display the game board on the console
    MakeBoard(gameBoard, rows, cols, playerX, playerY, x1, y1, x2, y2, score);

	MoveBoardForEasy(undoBoard, gameBoard, rows, cols, playerX, playerY, x1, y1, x2, y2, move, score);

    // Free memory after finishing the game
    deallocate(gameBoard, rows, cols);
    deallocateUndo(undoBoard, rows, cols);

	replay(0);
}


//Show normal level
void normalLevel(int &score){
	// Initialize the game board
    char** gameBoard = genBoard();
    char*** undoBoard = CreateUndoBoard();
    char move = '0';

    // Size of the game board
    int rows = 8;
    int cols = 8;

    // Player's position
    int playerX = 1;
    int playerY = 1;

    // Positions of points on the board
    int x1 = -1;
    int y1 = -1;
    int x2 = -1;
    int y2 = -1;

    // Display the game board on the console
    MakeBoard(gameBoard, rows, cols, playerX, playerY, x1, y1, x2, y2, score);

	MoveBoardForNormal(undoBoard, gameBoard, rows, cols, playerX, playerY, x1, y1, x2, y2, move, score);

    // Free memory after finishing the game
    deallocate(gameBoard, rows, cols);
    deallocateUndo(undoBoard, rows, cols);

	replay(1);
}

//Show hard level
void hardLevel(int &score) {
	// Initialize the game board
	char** gameBoard = genBoard();
	char*** undoBoard = CreateUndoBoard();
	char move = '0';

	// Size of the game board
	int rows = 8;
	int cols = 8;

	// Player's position
	int playerX = 1;
	int playerY = 1;

	// Positions of points on the board
	int x1 = -1;
	int y1 = -1;
	int x2 = -1;
	int y2 = -1;

	// Display the game board on the console
	MakeBoard(gameBoard, rows, cols, playerX, playerY, x1, y1, x2, y2, score);

	MoveBoardForHard(undoBoard, gameBoard, rows, cols, playerX, playerY, x1, y1, x2, y2, move, score);

	// Free memory after finishing the game
	deallocate(gameBoard, rows, cols);
	deallocateUndo(undoBoard, rows, cols);

	replay(2);
}

//Show the menu - Start the game
void showMenu() {
	//Array string to contain 5 option in the main menu
	const string menu[Menu_List] = { "Play", "Leaderboard", "Help", "About", "Exit" };
	int ptrMenu = 0; //Pointer to select option
	int flag = 1; //Check if the game is playing or not

	//Play theme song
	playSound();

	system("cls");

	//Draw the START box
	for (int i = 70; i < 90; i++) {
		goToXY(i, 18);
		cout << "-";
		goToXY(i, 22);
		cout << "-";
	}

	for (int i = 19; i < 22; i++) {
		goToXY(70, i);
		cout << "|                  |";
	}

	goToXY(78, 20);
	cout << "START";

	goToXY(57, 25);
	cout << "Please open in full screen for the best experience.";
	goToXY(67, 27);
	system("pause");

	while (true) {
		//Clear console
		system("cls");

		//Title
		textColor(NAVY_BLUE);
		goToXY(50, 10);
		cout << " ______   _____   _    _              ______   _     _   _     _";
		goToXY(50, 11);
		cout << "(_____ \\ (_   _) | |  / )     /\\     /  ____) | |   | | | |   | |";
		goToXY(50, 12);
		cout << " _____) )  | |   | | / /     /  \\   |  /      | |__ | | | |   | |";
		
		textColor(YELLOW);
		goToXY(50, 13);
		cout << "|  ____/   | |   | |< <     / /\\ \\  | |       |  __)| | | |   | |";
		goToXY(50, 14);
		cout << "| |       _| |_  | | \\ \\   / /--\\ \\ |  \\____  | |   | | | |___| |";
		goToXY(50, 15);
		cout << "|_|      (_____) |_|  \\_) /_/    \\_\\ \\______) |_|   |_|  \\_____/";


		//Print menu on console
		for (int i = 0; i < Menu_List; i++) {
			//If option is being selected, change to green
			if (ptrMenu == i) {
				textColor(GREEN);
				goToXY(72, 20 + i);
				cout << "\t" << char(175) << " " << menu[i] << " " << char(174);
			}

			//If not, option is white
			else {
				textColor(WHITE);
				goToXY(72, 20 + i);
				cout << "\t[+] " << menu[i];
			}
		}

		//Setting keyboard button
		while (true) {
			if (_kbhit()) {
				char button = _getch();

				//Key up
				if (button == Key_Up || button == 'w' || button == 'W') {
					if (ptrMenu > 0) {
						--ptrMenu;
					}

					else {
						ptrMenu = Menu_List - 1;
					}

					break;
				}

				//Key down
				else if (button == Key_Down || button == 's' || button == 'S') {
					if (ptrMenu < Menu_List - 1) {
						++ptrMenu;
					}

					else {
						ptrMenu = 0;
					}

					break;
				}

				//Key Enter
				else if (button == Key_Enter) {
					switch (ptrMenu) {
					case 0: {
						showLevels();
						break;
					}

					case 1: {
						showLeaderboard();
						break;
					}

					case 2: {
						showTutorial();
						break;
					}

					case 3: {
						showIntroduction();
						break;
					}

					case 4: {
						flag = -1;
						PlaySound(NULL, 0, 0);
						
						break;
					}

					default: {
						cout << "Error" << endl;
					}
					}

					break;
				}
			}

			if (flag == -1) {
				break;
			}
		}

		if (flag == -1) {
			break;
		}
	}

	//Exit game
	if (flag == -1) {
		system("cls");

		textColor(YELLOW);
		goToXY(40, 15);
		cout << "  _____ _                 _           __                    _             _             ";
		goToXY(40, 16);
		cout << " |_   _| |__   __ _ _ __ | | _____   / _| ___  _ __   _ __ | | __ _ _   _(_)_ __   __ _ ";
		goToXY(40, 17);
		cout << "   | | | '_ \\ / _` | '_ \\| |/ / __| | |_ / _ \\| '__| | '_ \\| |/ _` | | | | | '_ \\ / _` |";
		goToXY(40, 18);
		cout << "   | | | | | | (_| | | | |   <\\__ \\ |  _| (_) | |    | |_) | | (_| | |_| | | | | | (_| |";
		goToXY(40, 19);
		cout << "   |_| |_| |_|\\__,_|_| |_|_|\\_\\___/ |_|  \\___/|_|    | .__/|_|\\__,_|\\__, |_|_| |_|\\__, |";
		goToXY(40, 20);
		cout << "                                                     |_|            |___/         |___/ ";
	}
}
