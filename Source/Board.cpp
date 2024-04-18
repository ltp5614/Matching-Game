	#include "Board.h"
	#include "Setting.h"
	#include "Menu.h"
	#include "Check.h"

	using namespace std;

	//This function is used to assign fixed colors to letters from A to I.
	void MakeColor(char c) {
		switch (c) {
			// with each letter corresponding to 1 color A - I
			case 'A': {
				textColor(NAVY_BLUE);
				break;
			}
			case 'B': {
				textColor(YELLOW);
				break;
			}
			case 'C': {
				textColor(TEAL);
				break;
			}
			case 'D': {
				textColor(MAROON);
				break;
			}
			case 'E': {
				textColor(PURPLE);
				break;
			}
			case 'F': {
				textColor(BRIGHT_GREEN);
				break;
			}
			case 'G': {
				textColor(DARK_GRAY);
				break;
			}
			case 'H': {
				textColor(OLIVE);
				break;
			}
			case 'I': {
				textColor(WHITE);
				break;
			}
			default:
				break;
		}
	}

	// This function draws the board to the console.
	void MakeBoard(char** a, int m, int n, int px, int py, int x1, int y1, int x2, int y2, int &score){ 
		system("cls");	// first clear the console to draw the next move

		// The first loop is to draw the top frame border
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				textColor(LIGHT_GREEN);
				cout << "___________";
			}

			else {
				cout << "____________";
			}
		}
		cout << "\n";
		// This loop is used to draw the top border.
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				textColor(LIGHT_GREEN);
				cout << "|               ";
			}
			else if (j == 8) {
				cout << "            |";
			}
			else {
				cout << "           ";
			}
		}
		cout << "\n";
		// This outer loop is used to draw the cells containing letters used for playing the game.
		for (int i = 1; i <= m; i++)
		{
			textColor(LIGHT_GREEN);
			cout << "| ";
			// This loop is used to draw the first row of the letter frame
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] != ' ')
				{
					cout << "  ";
					MakeColor(a[i][j]);
					cout << " ------- ";
				}
				if (a[i][j] == ' ') {
					cout << "           ";
				}
			}
			textColor(LIGHT_GREEN);
			cout << "    |\n" << "| ";
			// This loop is used to draw the second row of the letter frame
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] != ' ')
				{
					if ((i == x1 && j == y1) || (i == x2 && j == y2))
					{
						cout << "  ";
						MakeColor(a[i][j]);
						cout << "|";
						textColor(0x30);
						cout << "       ";
						MakeColor(a[i][j]);
						cout << "|";
					}
					else if (i == px && j == py) {
						cout << "  ";
						MakeColor(a[i][j]);
						cout << "|";
						textColor(0x70);
						cout << "       ";
						MakeColor(a[i][j]);
						cout << "|";
					}
					else
					{
						textColor(0x07);
						cout << "  ";
						MakeColor(a[i][j]);
						cout << "|       |";
					}
				}
				else
				{
					if (i == px && j == py) {
						cout << "   ";
						textColor(0x70);
						cout << "        ";
					}
					else {
						textColor(0x07);
						cout << "           ";
					}
				}
			}
			textColor(LIGHT_GREEN);
			cout << "    |\n" << "| ";
			// This loop is used to draw the third row of the letter frame
			for (int j = 1; j <= n; j++)
			{

				if (a[i][j] != ' ')
				{
					if ((i == x1 && j == y1) || (i == x2 && j == y2))
					{
						cout << "  ";
						MakeColor(a[i][j]);
						cout << "|";
						textColor(0x30);
						cout << "   " << a[i][j] << "   ";
						MakeColor(a[i][j]);
						cout << "|";
					}
					else if (i == px && j == py) {
						cout << "  ";
						MakeColor(a[i][j]);
						cout << "|";
						textColor(0x70);
						cout << "   " << a[i][j] << "   ";
						MakeColor(a[i][j]);
						cout << "|";
					}
					else
					{
						textColor(0x07);
						cout << "  ";
						MakeColor(a[i][j]);
						cout << "|   " << a[i][j] << "   |";
					}
				}
				else
				{
					if (i == px && j == py) {
						cout << "   ";
						textColor(0x70);
						cout << "        ";
					}
					else {
						textColor(0x07);
						cout << "           ";
					}
				}
			}
			textColor(LIGHT_GREEN);
			cout << "    |\n" << "| ";
			// This loop is used to draw the fourth row of the letter frame
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] != ' ')
				{
					if ((i == x1 && j == y1) || (i == x2 && j == y2))
					{
						cout << "  ";
						MakeColor(a[i][j]);
						cout << "|";
						textColor(0x30);
						cout << "       ";
						MakeColor(a[i][j]);
						cout << "|";
					}
					else if (i == px && j == py) {
						cout << "  ";
						MakeColor(a[i][j]);
						cout << "|";
						textColor(0x70);
						cout << "       ";
						MakeColor(a[i][j]);
						cout << "|";
					}
					else
					{
						textColor(0x07);
						cout << "  ";
						MakeColor(a[i][j]);
						cout << "|       |";
					}
				}
				else
				{
					if (i == px && j == py) {
						cout << "   ";
						textColor(0x70);
						cout << "        ";
					}
					else {
						textColor(0x07);
						cout << "           ";
					}
				}
			}
			textColor(LIGHT_GREEN);
			cout << "    |\n" << "| ";
			// This loop is used to draw the fifth  row of the letter frame
			for (int j = 1; j <= n; j++)
			{
				if (a[i][j] != ' ')
				{
					cout << "  ";
					MakeColor(a[i][j]);
					cout << " ------- ";
				}
				if (a[i][j] == ' ') {
					cout << "           ";
				}
			}
			textColor(LIGHT_GREEN);
			cout << "    |\n";
			textColor(0x07);
		}
		// This loop is used to draw the padding for the border frame.
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				textColor(LIGHT_GREEN);
				cout << "|               ";
			}
			else if (j == 8) {
				cout << "            |";
			}
			else {
				cout << "           ";
			}
		}
		cout << "\n";
		// This loop is used to draw the last row of the border frame
		for (int j = 1; j <= n; j++) {
			if (j == 1) {
				textColor(LIGHT_GREEN);
				cout << "|__________";
			}
			else if (j == 8) {
				cout << "___________|";
			}
			else {
				cout << "____________";
			}
		}
		cout << "\n";

		// This part is used to draw the function cells and the shape cells."

		goToXY(102, 1);
		cout << "-----------------------------------------------";

		goToXY(102, 10);
		cout << "-----------------------------------------------";

		for (int i = 2; i < 10; i++) {
			goToXY(102, i);
			cout << "|                                             |";
		}

		goToXY(122, 3);
		cout << "SCORE: " << score;

		goToXY(104, 5);
		cout << char(175) << " Using W, S, A, D, or arrow key to move";
		goToXY(104, 6);
		cout << char(175) << " Using U for Move Suggestion";
		goToXY(104, 7);
		cout << char (175) << " Using I for Delete Specific Character";
		goToXY(104, 8);
		cout << char (175) << " Using R for Undo Movement";
		goToXY(104, 9);
		cout << char (175) << " Press Esc to exit";

		goToXY(100, 12);
		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";
		goToXY(100, 13);
		cout << "x      _  _     ___   __  __   _   _    ___      x";
		goToXY(100, 14);
		cout << "x     | || |   / __| |  \\/  | | | | |  / __|     x";
		goToXY(100, 15);
		cout << "x     | __ |  | (__  | |\\/| | | |_| |  \\__ \\     x";
		goToXY(100, 16);
		cout << "x     |_||_|   \\___| |_|__|_|  \\___/   |___/     x";
		goToXY(100, 17);
		cout << "x      _|\"\"\"\"\"\"|_|\"\"\"\"\"\"|_|\"\"\"\"\"\"|_|\"\"\"\"\"\"|      x";
		goToXY(100, 18);
		cout << "x     \"`--0-0-'\"`--0-0-'\"`--0-0-'\"`--0-0-'       x";
		goToXY(100, 19);
		cout << "x       __   _                                   x";
		goToXY(100, 20);
		cout << "x     _(  )_( )_                     \\_/         x";
		goToXY(100, 21);
		cout << "x    (_   _    _)          T~      --(_)--       x";
		goToXY(100, 22);
		cout << "x      (_) (__)            |         /\"\\         x";
		goToXY(100, 23);
		cout << "x                 T~~     |'| T~~                x";
		goToXY(100, 24);
		cout << "x             T~~ |    T~ WWWW|                  x";
		goToXY(100, 25);
		cout << "x             |  /\"\\   |  |  |/\\T~~              x";
		goToXY(100, 26);
		cout << "x            /\"\\ WWWW  /\"\\ |' |WW|               x";
		goToXY(100, 27);
		cout << "x           WWWW/\\| /   \\|'/\\|/\"\\                x";
		goToXY(100, 28);
		cout << "x           |   /__\\/]WWW[\\/__\\WWWW              x";
		goToXY(100, 29);
		cout << "x           |\"  WWWW'|I_I|'WWWW'  |              x";
		goToXY(100, 30);
		cout << "x           |   |' |/  -  \\|' |'  |              x";
		goToXY(100, 31);
		cout << "x           |'  |  |LI=H=LI|' |   |              x";
		goToXY(100, 32);
		cout << "x           |   |' | |[_]| |  |'  |              x";
		goToXY(100, 33);
		cout << "x           |   |  |_|###|_|  |   |              x";
		goToXY(100, 34);
		cout << "x           '---'--'-/___\\-'--'---'              x";
		goToXY(100, 35);
		cout << "x                   /     \\                      x";
		goToXY(100, 36);
		cout << "xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx";

	}

	///Function to generate values for cells of the board
	char** genBoard() {
		srand(time(0));     //  reset random
		char** a;   // create pointer a
		a = new char* [10];  //  create size row of a is 9

		// loop for create each row have 9 col
		for (int t = 0; t < 10; t++) {
			a[t] = new char[10]; // create col for each row
		}	

		// 2 loop for assign value " " to a
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				a[i][j] = ' ';
			}
		}
			
		//  create array rd have 9 cell, and each cell have num with each letter was created before
		int rd[9] = { 8, 8, 8, 8, 8, 6, 6, 6, 6 };
		int random;
		random = rand() % 9;    // create random num 

		for (int i = 1; i <= 8; i++) {
			for (int j = 1; j <= 8; j++) {
				while (rd[random] == 0) {
					random = rand() % 9;
				}
					
				a[i][j] = 'A' + random;	// convert from numbers to letters
				rd[random]--;			// check quantity of that letter with the num
				random = rand() % 9;
			}
		}
		
		return a;
	}

	// The function used to create a triple pointer to store the moves.
	char***  CreateUndoBoard() {
		char*** a = new char** [32]; 
		for (int i = 0; i < 32; i++) {
			a[i] = new char* [10];

			for (int j = 0; j < 10; j++) {
				a[i][j] = new char[10];

				for (int k = 0; k < 10; k++) {
					a[i][j][k] = ' ';
				}
			}
		}

		return a;
	}

	// The function used to store the moves
	void GenUndoBoard(char*** a, char** board, int row, int col, int index) {
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				a[index][i][j] = board[i][j];
			}
		}
	}

	// The function used to reverse the value back into the game board.
	void GenUndoBoardToMainBoard(char*** a, char** board, int row, int col, int index) {
		for (int i = 1; i <= row; i++) {
			for (int j = 1; j <= col; j++) {
				board[i][j] = a[index][i][j];
				a[index][i][j] = ' ';
			}
		}
	}

	// The function used to delete the memory storage of the save function.
	void deallocateUndo(char***& Undo, int row, int col) {
		for (int i = 0; i < 32; i++) {
			for (int j = 0; j <= col + 1; j++) {
				delete[] Undo[i][j];
			}
		}
		delete[] Undo;
	}

	// This function is used to provide a hint for the next move.
	// This function will run from the beginning of the array and iterate through to the end to find two elements that meet the condition and display them. When any button on the keyboard is pressed, the game can continue.
	void moveSuggestion(char** a, int row, int col, int px, int py, int x1, int y1, int x2, int y2, int &score) {
		// The first two loops are used to iterate through the elements in the array.
		for (int i = 1; i < 9; i++) {
			for (int j = 1; j < 9; j++) {
				// This loop is used to iterate through the elements in the same row before.
				for (int k = j + 1; k < 9; k++) {
					// Check the condition, if satisfied, then display those two points.
					if (a[i][j] == a[i][k] && a[i][j] != ' ') {
						if (checkI(a, row, col, px, py, i, j, i, k) ||
							checkZ(a, row, col, px, py, i, j, i, k) ||
							checkL(a, row, col, px, py, i, j, i, k) ||
							checkU(a, row, col, px, py, i, j, i, k)) {

							x1 = i; y1 = j; x2 = i; y2 = k;
							MakeBoard(a, row, col, px, py, x1, y1, x2, y2, score);
							char button = _getch();
							return;
						}
					}
				}
				// These are two loops running downward to check the point below the current point to see if it satisfies the condition
				if (i < 9) {
					for (int m = i + 1; m < 9; m++) {
						for (int n = 1; n < 9; n++) {
							// Check the condition, if satisfied, then display those two points.
							if (a[i][j] == a[m][n] && a[i][j] != ' ') {
								if (checkI(a, row, col, px, py, i, j, m, n) ||
									checkZ(a, row, col, px, py, i, j, m, n) ||
									checkL(a, row, col, px, py, i, j, m, n) ||
									checkU(a, row, col, px, py, i, j, m, n)) {

									x1 = i; y1 = j; x2 = m; y2 = n;
									MakeBoard(a, row, col, px, py, x1, y1, x2, y2,score);
									char button = _getch();
									return;
								}
							}
						}
					}
				}
			}
		}
	}

	void MoveBoardForEasy(char*** undo, char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2, char move, int &score) {
		char*** movementBoard = CreateUndoBoard();	// create undo board
		int redoIndex = 0; // The current undo address.
		int lastUndoIndex = -1; // The last undo address.
		char focus;	// Usedfor the letter erase function.
		bool selectFirstPos = true;	// To check the selected two points.

		do {
			// To check if the board is empty, indicating a victory.
			if (checkWin(board, row, col)) {
				winner();

				return;
			}

			MakeBoard(board, row, col, px, py, x1, y1, x2, y2, score);
			move = _getch();

			// To move up, down, left, or right

			switch (move) {
				case 'A':
				case 'a':
				case Key_Left: {
					if (py > 1) {
						py--;
					}

					break;
				}

				case 'D':
				case 'd':
				case Key_Right: {
					if (py < row) {
						py++;
					}

					break;
				}

				case 'S':
				case 's':
				case Key_Down: {
					if (px < col) {
						px++;
					}

					break;
				}

				case 'W':
				case 'w':
				case Key_Up: {
					if (px > 1) {
						px--;
					}

					break;
				}
				// Press the Enter key to select a point
				case '\r':
				case 32: {
					if (selectFirstPos) {
						x1 = px;
						y1 = py;
						selectFirstPos = false;
					}
					else {
						x2 = px;
						y2 = py;
						selectFirstPos = true;

						// Check if the two selected letters are the same.

						if (board[x1][y1] != board[x2][y2]) {
							x1 = -1;
							x2 = -1;
							y1 = -1;
							y2 = -1;
						}

						// Check if the coordinates of the two points are the same.

						if (x1 == x2 && y1 == y2) {
							x1 = -1;
							x2 = -1;
							y1 = -1;
							y2 = -1;
						}
						
						// Check if the two points can be connected.

						else if (board[x1][y1] == board[x2][y2]) {
							if (checkI(board, row, col, px, py, x1, y1, x2, y2) ||
								checkL(board, row, col, px, py, x1, y1, x2, y2) ||
								checkU(board, row, col, px, py, x1, y1, x2, y2) ||
								checkZ(board, row, col, px, py, x1, y1, x2, y2)) {
								
								score += 10; // If true, add 10 points.

								// Save the board before deleting the two matching elements.
								GenUndoBoard(movementBoard, board, row, col, redoIndex);
								lastUndoIndex = redoIndex;
								redoIndex++;
								deleteCell(board[x1][y1], board[x2][y2]);

								MakeBoard(board, row, col, px, py, x1, y1, x2, y2, score);

								x1 = -1;
								y1 = -1;
								x2 = -1;
								y2 = -1;
							}

							else {
								x1 = -1;
								y1 = -1;
								x2 = -1;
								y2 = -1;
							}

						}
					}

					break;
				}

				// Suggest function.
				case 'u':
				case 'U': {
					moveSuggestion(board, row, col, px, py, x1, y1, x2, y2, score);
					score -= 10;
					break;
				}

				// Alphabetical deletion function.
				case 'i':
				case 'I': {
					do {
						system("cls");

						cout << "Enter the letter you want to delete from A to I: ";
						cin >> focus;
					}

					while ((focus < 'A' || focus > 'I') && (focus < 'a' || focus > 'i'));

					if (focus >= 'a' && focus <= 'i') {
						focus -= 32;
					}
					GenUndoBoard(movementBoard, board, row, col, redoIndex);
					lastUndoIndex = redoIndex;
					redoIndex++;
					score -= 20;
					DeleteElementFocus(board, row, col, focus);

					break;
				}

				// Undo function.
				case 'r':
				case 'R': {
					if (lastUndoIndex >= 0) {
						score -= 10;
						system("cls");
						GenUndoBoardToMainBoard(movementBoard, board, row, col, lastUndoIndex);
						redoIndex = lastUndoIndex;
						lastUndoIndex--;
					}
					

					break;
				}

				default: {
					break;
				}
			}
		} 

		// Press the 'Esc' key to exit.
		while (move != Key_Esc);
	}


	void MoveBoardForNormal(char*** undo, char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2, char move, int &score) {
		char*** movementBoard = CreateUndoBoard();	// create undo board
		int redoIndex = 0; 	// The current undo address.
		int lastUndoIndex = -1; // The last undo address.
		char focus;		// Usedfor the letter erase function.
		bool selectFirstPos = true;	// To check the selected two points.

		do {
			// To check if the board is empty, indicating a victory.
			if (checkWin(board, row, col)) {
				winner();

				return;
			}

			MakeBoard(board, row, col, px, py, x1, y1, x2, y2, score);
			move = _getch();
			
			// To move up, down, left, or right

			switch (move) {
				case 'A':
				case 'a':
				case Key_Left: {
					if (py > 1) {
						py--;
					}
					break;
				}

				case 'D':
				case 'd':
				case Key_Right: {
					if (py < row) {
						py++;
					}
					break;
				}

				case 'S':
				case 's':
				case Key_Down: {
					if (px < col) {
						px++;
					}
					break;
				}

				case 'W':
				case 'w':
				case Key_Up: {
					if (px > 1) {
						px--;
					}
					break;
				}

				// Press the Enter key to select a point
				case '\r':
				case 32: {
					if (selectFirstPos) {
						x1 = px;
						y1 = py;
						selectFirstPos = false;
					}

					else {
						x2 = px;
						y2 = py;
						selectFirstPos = true;

						// Check if the two selected letters are the same.


						if (board[x1][y1] != board[x2][y2]) {
							x1 = -1;
							x2 = -1;
							y1 = -1;
							y2 = -1;
						}

						// Check if the coordinates of the two points are the same.

						if (x1 == x2 && y1 == y2) {
							x1 = -1;
							x2 = -1;
							y1 = -1;
							y2 = -1;
						}

						// Check if the two points can be connected.

						else if (board[x1][y1] == board[x2][y2]) {
							if (checkI(board, row, col, px, py, x1, y1, x2, y2) ||
								checkL(board, row, col, px, py, x1, y1, x2, y2) ||
								checkU(board, row, col, px, py, x1, y1, x2, y2) ||
								checkZ(board, row, col, px, py, x1, y1, x2, y2)) {

								score += 15;	// If true, add 15points.

								// Save the board before deleting the two matching elements.
								GenUndoBoard(movementBoard, board, row, col, redoIndex);
								lastUndoIndex = redoIndex;
								redoIndex++;

								deleteCell(board[x1][y1], board[x2][y2]);
								DelEmptyColRight(board, row, col, y1);
								DelEmptyColLeft(board, row, col, y1);
								DelEmptyColLeft(board, row, col, y2);
								DelEmptyColRight(board, row, col, y2);
								DelEmptyRowUp(board, row, col, x1);
								DelEmptyRowDown(board, row, col, x1);
								DelEmptyRowUp(board, row, col, x2);
								DelEmptyRowDown(board, row, col, x2);
								MakeBoard(board, row, col, px, py, x1, y1, x2, y2, score);

								

								x1 = -1;
								y1 = -1;
								x2 = -1;
								y2 = -1;
							}
							else {
								x1 = -1;
								y1 = -1;
								x2 = -1;
								y2 = -1;
							}
						}
					}

					break;
				}

				// Suggest function.
				case 'u':
				case 'U': {
					moveSuggestion(board, row, col, px, py, x1, y1, x2, y2, score);
					score -= 15;

					break;
				}

				// Alphabetical deletion function.
				case 'i':
				case 'I': {
					do {
						system("cls");
						cout << "Enter the letter you want to delete from A to I: ";
						cin >> focus;
					}

					while ((focus < 'A' || focus > 'I') && (focus < 'a' || focus > 'i'));

					if (focus >= 'a' && focus <= 'i') {
						focus -= 32;
					}
					score -= 30;
					GenUndoBoard(movementBoard, board, row, col, redoIndex);
					lastUndoIndex = redoIndex;
					redoIndex++;
					DeleteElementFocus(board, row, col, focus);
					DelEmptyColRight(board, row, col, y1);
					DelEmptyColLeft(board, row, col, y1);
					DelEmptyColLeft(board, row, col, y2);
					DelEmptyColRight(board, row, col, y2);
					DelEmptyRowUp(board, row, col, x1);
					DelEmptyRowDown(board, row, col, x1);
					DelEmptyRowUp(board, row, col, x2);

					break;
				}

				// Undo function.
				case 'r':
				case 'R': {
					if (lastUndoIndex >= 0) {
						score -= 15;
						system("cls");
						GenUndoBoardToMainBoard(movementBoard, board, row, col, lastUndoIndex);
						redoIndex = lastUndoIndex;
						lastUndoIndex--;
					}
					

					break;
				}

				default: {
					break;
				}
			}
		}

		// Press the 'Esc' key to exit.
		while (move != Key_Esc);
	}

	void MoveBoardForHard(char*** undo, char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2, char move, int &score) {
		char*** movementBoard = CreateUndoBoard();	// create undo board
		int redoIndex = 0; // The current undo address.
		int lastUndoIndex = -1; // The last undo address.
		char focus;		// Usedfor the letter erase function.
		bool selectFirstPos = true;	// To check the selected two points.

		do {
			// To check if the board is empty, indicating a victory.
			if (checkWin(board, row, col)) {
				winner();

				return;
			}

			MakeBoard(board, row, col, px, py, x1, y1, x2, y2, score);
			move = _getch();

			// To move up, down, left, or right

			switch (move) {
			case 'A':
			case 'a':
			case Key_Left: {
				if (py > 1) {
					py--;
				}

				break;
			}

			case 'D':
			case 'd':
			case Key_Right: {
				if (py < row) {
					py++;
				}

				break;
			}

			case 'S':
			case 's':
			case Key_Down: {
				if (px < col) {
					px++;
				}

				break;
			}

			case 'W':
			case 'w':
			case Key_Up: {
				if (px > 1) {
					px--;
				}

				break;
			}

			// Press the Enter key to select a point
			case '\r':
			case 32: {
				if (selectFirstPos && board[px][py] != ' ') {
					x1 = px;
					y1 = py;
					selectFirstPos = false;
				}

				else {
					x2 = px;
					y2 = py;
					selectFirstPos = true;

					// Check if the two selected letters are the same.
					if (board[x1][y1] != board[x2][y2]) {
						x1 = -1;
						x2 = -1;
						y1 = -1;
						y2 = -1;
					}

					// Check if the coordinates of the two points are the same.
					if (x1 == x2 && y1 == y2) {
						x1 = -1;
						x2 = -1;
						y1 = -1;
						y2 = -1;
					}

					// Check if the two points can be connected.
					else if (board[x1][y1] == board[x2][y2]) {
						if (checkI(board, row, col, px, py, x1, y1, x2, y2) ||
							checkL(board, row, col, px, py, x1, y1, x2, y2) ||
							checkU(board, row, col, px, py, x1, y1, x2, y2) ||
							checkZ(board, row, col, px, py, x1, y1, x2, y2)) {

							score +=20;	// If true, add 20 points

							// Save the board before deleting the two matching elements.
							GenUndoBoard(movementBoard, board, row, col, redoIndex);
							lastUndoIndex = redoIndex;
							redoIndex++;

							deleteCell(board[x1][y1], board[x2][y2]);
							SortEmptyCol(board, row, col);
							SortEmptyRow(board, row, col);
							SortEmptyCol(board, row, col);
							SortEmptyRow(board, row, col);
							SortEmptyCol(board, row, col);
							SortEmptyRow(board, row, col);
							MakeBoard(board, row, col, px, py, x1, y1, x2, y2, score);

							
							x1 = -1;
							y1 = -1;
							x2 = -1;
							y2 = -1;
						}
						else {
								x1 = -1;
								y1 = -1;
								x2 = -1;
								y2 = -1;
							}

					}
				}

				break;
			}

			// Suggest function.
			case 'u':
			case 'U': {
				moveSuggestion(board, row, col, px, py, x1, y1, x2, y2, score);
				score -= 20;
				break;
			}

			// Alphabetical deletion function.
			case 'i':
			case 'I': {
				do {
					system("cls");
					cout << "Enter the letter you want to delete from A to I: ";
					cin >> focus;
				}

				while ((focus < 'A' || focus > 'I') && (focus < 'a' || focus > 'i'));

				if (focus >= 'a' && focus <= 'i') {
					focus -= 32;
				}
				
				score -= 40;
				GenUndoBoard(movementBoard, board, row, col, redoIndex);
				lastUndoIndex = redoIndex;
				redoIndex++;
				DeleteElementFocus(board, row, col, focus);
				SortEmptyCol(board, row, col);
				SortEmptyRow(board, row, col);
				SortEmptyCol(board, row, col);
				SortEmptyRow(board, row, col);
				SortEmptyCol(board, row, col);
				SortEmptyRow(board, row, col);
				break;
			}

			// Undo function.
			case 'r':
			case 'R': {
				if (lastUndoIndex >= 0) {
					score -= 20;
					system("cls");
					GenUndoBoardToMainBoard(movementBoard, board, row, col, lastUndoIndex);
					redoIndex = lastUndoIndex;
					lastUndoIndex--;
				}
				
				break;
			}

			default: {
				break;
			}
			}
		}
		// Press the 'Esc' key to exit.
		while (move != Key_Esc);
	}
