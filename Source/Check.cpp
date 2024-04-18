#include "Check.h"
#include "Menu.h"
#include "Setting.h"

using namespace std;

bool checkCol(char** board, int row, int col, int px, int py, int start, int end, int y) {
    for (int i = start; i <= end; i++) {    // Loop for to check the elements between two entered cells
        if (board[i][y] != ' ') {
            return false;
        }
    }
    return true;
}

bool checkRow(char** board, int row, int px, int py, int col, int start, int end, int x) {
    for (int i = start; i <= end; i++) {// Loop for to check the elements between two entered cells
        if (board[x][i] != ' ') {
            return false;
        }
    }
    return true;
}

void deleteLineRow(char** board, int row, int col, int px, int py, int start, int end, int x) {
    for (int i = start; i < end; i++) {
        board[x][i] = ' ';
    }
}

void deleteLineCol(char** board, int row, int col, int px, int py, int start, int end, int y) {
    for (int i = start; i < end; i++) {
        board[i][y] = ' ';
    }
}

void deleteI(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2) {
    if (x1 == x2) {
        int Min = min(y1, y2);
        int Max = max(y1, y2);
        if (checkRow(board, row, col, px, py, Min + 1, Max, x1)) {
            deleteLineRow(board, row, col, px, py, Min + 1, Max, x1);
        }
    }
    if (y1 == y2) {
        int Min = min(x1, x2);
        int Max = max(x1, x2);
        if (checkCol(board, row, col, px, py, Min + 1, Max, y1)) {
            deleteLineRow(board, row, col, px, py, Min + 1, Max, y1);
        }
    }
}

void deleteCell(char& a, char& b) { // function to delete entered cell
    // Assigning the empty value to the elements present in the input.
    a = ' ';
    b = ' ';
}

void DeleteElementFocus(char** a, int row, int col, char focus) {
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (a[i][j] == focus) {
                a[i][j] = ' ';
            }
        }
    }
}

bool checkI(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2) {
    if (x1 == x2 && y1 == y2) {     // In case of two identical points, they are removed.
        return false;
    }

    if (x1 == x2) {     // (the x-coordinates of the two points are equal).
        int Min = min(y1, y2);
        int Max = max(y1, y2);
        return checkRow(board, row, col, px, py, Min + 1, Max - 1, x1); // Checking the empty space between two corresponding points.
    }

    if (y1 == y2) {     // (the y-coordinates of the two points are equal).
        int Min = min(x1, x2);
        int Max = max(x1, x2);
        return checkCol(board, row, col, px, py, Min + 1, Max - 1, y1); // Checking the empty space between two corresponding points.
    }
    // If the conditions above are not met, then return false.
    return false;
}

bool checkL(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2) {
    if (x1 == x2 ||  y1 == y2) {    // If the two points are in a straight line, then eliminate them.
        return false;
    }
    int minx = min(x1, x2);     // find min of pos1x, pos2x
    int maxx = max(x1, x2);     // find max of pos1x, pos2x
    int miny = min(y1, y2);     // find min of pos1y, pos2y
    int maxy = max(y1, y2);     // find max of pos1y, pos2y
    if ((y1 < y2 && x1 < x2) || (y1 > y2 && x1 > x2)) {//The first type is when the points are top-left and bottom-right.
        // Checking the condition corresponding to two perpendicular line segments with the angle formed by the two line segments pointing towards the bottom left.
        // The following are the conditions to be checked.
        if (checkI(board, row, col, px, py, maxx + 1, miny, minx, miny) && checkI(board, row, col, px, py, maxx, miny - 1, maxx, maxy) && board[minx + 1][miny] == ' ' && board[maxx][maxy - 1] == ' ') {
            return true;
        }
        // Checking the condition corresponding to two perpendicular line segments with the angle formed by the two line segments pointing towards the top right.
        // The following are the conditions to be checked.
        if (checkI(board, row, col, px, py, minx, maxy + 1, minx, miny) && checkI(board, row, col, px, py, minx - 1, maxy, maxx, maxy) && board[minx][miny + 1] == ' ' && board[maxx - 1][maxy] == ' ') {
            return true;
        }
    }
    if ((y1 > y2 && x1 < x2) || (y1 < y2 && x1 > x2))   //The second type is when the points are top-right and bottom-left.
    {
        //Checking the condition corresponding to two perpendicular line segments with the angle formed by the two line segments pointing towards the top left.
        // The following are the conditions to be checked.
        if (checkI(board, row, col, px, py, minx - 1, miny, maxx, miny) && checkI(board, row, col, px, py, minx, miny - 1, minx, maxy) && board[maxx - 1][miny] == ' ' && board[minx][maxy - 1] == ' ') {
            return true;
        }
        //Checking the condition corresponding to two perpendicular line segments with the angle formed by the two line segments pointing towards the bottom left.
        // The following are the conditions to be checked.
        if (checkI(board, row, col, px, py, maxx, maxy + 1, maxx, miny) && checkI(board, row, col, px, py, maxx + 1, maxy, minx, maxy) && board[maxx][miny + 1] == ' ' && board[minx + 1][maxy] == ' ') {
            return true;
        }
    }
    // If the conditions above are not met, then return false.
    return false;
}

bool checkU(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2) {
    int minx = min(x1, x2);     // find min of pos1x, pos2x
    int maxx = max(x1, x2);     // find max of pos1x, pos2x
    int miny = min(y1, y2);     // find min of pos1y, pos2y
    int maxy = max(y1, y2);     // find max of pos1y, pos2y

    // With this CheckU function, we have divided it into 5 cases to address the issue.

    // In this first case, the elements lie in the same row or column outside the four edges of the board.
    if ((x1 == 1 && x2 == 1) ||
        (y1 == 1 && y2 == 1) ||
        (x1 == row && x2 == row) ||
        (y1 == col && y2 == col)) {
        return true;
    }

    // The second case addresses the situation when two points lie in the same row.
    if (x1 == x2) {

        // The first loop is to iterate through the empty values with the U shape towards the left side of the two points.
        for (int i = minx - 1; i >= 0; i--) {
            if (checkI(board, row, col, px, py, i, miny, minx, miny) && checkL(board, row, col, px, py, i, miny, maxx, maxy) && board[i][miny] == ' ') {
                return true;
            }
        }
        // The first loop is to iterate through the empty values with the U shape towards the right side of the two points.
        for (int i = maxx + 1; i <= row + 1; i++) {
            if (checkI(board, row, col, px, py, i, miny, minx, miny) && checkL(board, row, col, px, py, i, miny, maxx, maxy) && board[i][miny] == ' ') {
                return true;
            }
        }
    }
    // In this third case, the elements lie in the same row or row outside the four edges of the board.

    else if (y1 == y2) {

        // The first loop is to iterate through the empty values with the U shape towards the top of the two points.
        for (int i = miny - 1; i >= 0; i--) {
            if (checkI(board, row, col, px, py, minx, i, minx, miny) && checkL(board, row, col, px, py, minx, i, maxx, maxy) && board[minx][i] == ' ') {
                return true;
            }
        }
        // The first loop is to iterate through the empty values with the U shape towards the bottom of the two points.
        for (int i = miny + 1; i <= row + 1; i++) {
            if (checkI(board, row, col, px, py, minx, i, minx, miny) && checkL(board, row, col, px, py, minx, i, maxx, maxy) && board[minx][i] == ' ') {
                return true;
            }
        }
    }

    // Moving on to the fourth case, where the two locations of the two pointers are on the top-left and bottom-right
    if ((x1 > x2 && y1 > y2) || (x1 < x2 && y1 < y2)) {

        // With the first loop, we rotate the U shape 180 degrees clockwise.
        for (int i = minx - 1; i >= 0; i--) {
            if (checkI(board, row, col, px, py, i, miny, minx, miny) && 
                checkL(board, row, col, px, py, i, miny, maxx, maxy) && 
                board[i][miny] == ' ') {

                return true;
            }
        }

        // With the second loop, we rotate the U shape 90 degrees clockwise.
        for (int i = miny - 1; i >= 0; i--) {
            if (checkI(board, row, col, px, py, minx, i, minx, miny) && 
                checkL(board, row, col, px, py, minx, i, maxx, maxy) && 
                board[minx][i] == ' ') {

                return true;
            }
        }

        // With the third loop, we rotate the U shape 270 degrees clockwise.
        for (int i = miny + 1; i <= row + 1; i++) {
            if (checkI(board, row, col, px, py, minx, i, minx, miny) && 
                checkL(board, row, col, px, py, minx, i, maxx, maxy) && 
                board[minx][i] == ' ') {

                return true;
            }
        }

        // With the fourth loop, we rotate the U shape
        for (int i = maxx + 1; i <= row + 1; i++) {
            if (checkI(board, row, col, px, py, i, miny, minx, miny) && 
                checkL(board, row, col, px, py, i, miny, maxx, maxy) && 
                board[i][miny] == ' ') {

                return true;
            }
        }
    }

    // In the fifth case, the two locations are at the top-right and bottom-left positions.
    if ((x1 < x2 && y1 > y2) || (x1 > x2 && y1 < y2)) {

        // With the first loop, we rotate the U shape
        for (int i = maxx + 1; i <= col + 1; i++) {
            if (checkI(board, row, col, px, py, i, miny, maxx, miny) && checkL(board, row, col, px, py, i, miny, minx, maxy) && board[i][miny] == ' ') {
                return true;
            }
        }

        // With the second loop, we rotate the U shape 90 degrees clockwise.
        for (int i = miny - 1; i >= 0; i--) {
            if (checkI(board, row, col, px, py, maxx, i, maxx, miny) && checkL(board, row, col, px, py, maxx, i, minx, maxy) && board[maxx][i] == ' ') {
                return true;
            }
        }

        // With the third loop, we rotate the U shape 180 degrees clockwise.
        for (int i = minx - 1; i >= 0; i--) {
            if (checkI(board, row, col, px, py, i, miny, maxx, miny) && checkL(board, row, col, px, py, i, miny, minx, maxy) && board[i][miny] == ' ') {
                return true;
            }
        }

        // With the fourth loop, we rotate the U shape 270 degrees clockwise.
        for (int i = maxy + 1; i <= col + 1; i++) {
            if (checkI(board, row, col, px, py, minx, i, minx, maxy) && checkL(board, row, col, px, py, minx, i, maxx, miny) && board[minx][i] == ' ') {
                return true;
            }
        }
    }

    // If the conditions above are not met, then return false.

    return false;
}

bool checkZ(char** board, int row, int col, int px, int py, int x1, int y1, int x2, int y2) {
    int minx = min(x1, x2);     // find min of pos1x, pos2x
    int maxx = max(x1, x2);     // find max of pos1x, pos2x
    int miny = min(y1, y2);     // find min of pos1y, pos2y
    int maxy = max(y1, y2);     // find max of pos1y, pos2y

    //Similarly to the functions above, the condition to check the CheckZ function must also address the two scenarios where the coordinates of the points are respectively top-left and bottom-right, and top-right and bottom-left.
    // Moving on to the first case, where the two locations of the two pointers are on the top-left and bottom-right
    if ((x1 > x2 && y1 > y2) || (x1 < x2 && y1 < y2)) {

        //In the first case, we checked the letter Z towards the bottom side relative to the coordinate with the smallest x and y, and let it run from minx + 1 to less than maxx.
        for (int i = minx + 1; i < maxx; i++) {
            if (checkI(board, row, col, px, py, i, miny, minx, miny) && checkL(board, row, col, px, py, i, miny, maxx, maxy) && board[i][miny] == ' ' && board[minx + 1][miny] == ' ') {
                return true;
            }
        }
        //In the second case, we checked the letter Z towards the right side relative to the coordinate with the smallest x and y, and let it run from miny + 1 to less than maxy.

        for (int i = miny + 1; i < maxy; i++) {
            if (checkI(board, row, col, px, py, minx, i, minx, miny) && checkL(board, row, col, px, py, minx, i, maxx, maxy) && board[minx][i] == ' ' && board[minx][miny + 1] == ' ') {
                return true;
            }
        }
    }

    // Moving on to the first case, where the two locations of the two pointers are on the top-right and bottom-left.
    if ((x1 < x2 && y1 > y2) || (x1 > x2 && y1 < y2)) {

        // In the first case, we checked the letter Z towards the top side relative to the coordinate with the largest x and smallest y, and let it run from maxx - 1 to greater than minx.
        for (int i = maxx - 1; i > minx; i--) {
            if (checkI(board, row, col, px, py, i, miny, maxx, miny) && checkL(board, row, col, px, py, i, miny, minx, maxy) && board[i][miny] == ' ' && board[maxx - 1][miny] == ' ') {
                return true;
            }
        }

        // In the second case, we checked the letter Z towards the right side relative to the coordinate with the largest x and smallest y, and let it run from miny + 1 to less than maxy.
        for (int i = miny + 1; i < maxy; i++) {
            if (checkI(board, row, col, px, py, maxx, i, maxx, miny) && checkL(board, row, col, px, py, maxx, i, minx, maxy) && board[maxx][i] == ' ' && board[maxx][miny + 1] == ' ') {
                return true;
            }
        }
    }

    // If the conditions above are not met, then return false.
    return false;
}

//USING FOR NORMAL LEVEL AND HARD LEVEL

// This function is used to check whether the row is empty or not.
bool CheckEmptyRow(char** a, int row, int col, int posx) {
    // Loop for check the row is empty or not.
    for (int i = 1; i <= col; i++) {
        if (a[posx][i] != ' ') {
            return false;
        }
    }
    return true;
}

// This function is used to check whether the col is empty or not.
bool CheckEmptyCol(char** a, int row, int col, int posy) {
    // Loop for check the row is empty or not.
    for (int i = 1; i <= row; i++) {
        if (a[i][posy] != ' ') {
            return false;
        }
    }
    return true;
}

// The function used in normal mode to collapse the row downwards if the row below is empty.
void DelEmptyRowDown(char** a, int row, int col, int posx) {

    // Without the beginning and end of the row
    if (posx == 0 || posx == row) {
        return;
    }
    else if (CheckEmptyRow(a, row, col, posx) && (posx <= row / 2)) {
        // The loop for sorting rows if the condition is met
        // Run from position posx to 2
        for (int i = posx; i >= 2; i--) {
            for (int j = 1; j <= col; j++) {
                a[i][j] = a[i - 1][j];
            }
        }
        // The loop for assigning empty values in the first row
        for (int j = 1; j <= col; j++) {
            a[1][j] = ' ';
        }
    }
}

// The function used in normal mode to collapse the row upwards if the row above is empty.
void DelEmptyRowUp(char** a, int row, int col, int posx) {
    // Without the beginning and end of the row
    if (posx == 0 || posx == row) {
        return;
    }

    else if (CheckEmptyRow(a, row, col, posx) && (posx >= row / 2)) {
        // The loop for sorting rows if the condition is met
        // Run from pos up to row - 1
        for (int i = posx; i <= row - 1; i++) {
            for (int j = 1; j <= col; j++) {
                a[i][j] = a[i + 1][j];
            }
        }
        // The loop for assigning empty values in the first row
        for (int j = 1; j <= col; j++) {
            a[row][j] = ' ';
        }
    }
}
// The function used in normal mode to collapse the rightmost column towards the middle column.
void DelEmptyColLeft(char** a, int row, int col, int posy) {
    // Without the beginning and end of the col
    if (posy == 0 || posy == col) {
        return;
    }
    else if (CheckEmptyCol(a, row, col, posy) && (posy <= col / 2)) {
        // The loop for sorting rows if the condition is met
        // Run from position posy to 2
        for (int j = posy; j >= 2; j--) {
            for (int i = 1; i <= row; i++) {
                a[i][j] = a[i][j - 1];
            }
        }
        // The loop for assigning empty values in the first row
        for (int i = 1; i <= row; i++) {
            a[i][1] = ' ';
        }
    }
}
// The function used in normal mode to collapse the rightmost column towards the middle column.
void DelEmptyColRight(char** a, int row, int col, int posy) {
    // Without the beginning and end of the col
    if (posy == 0 || posy == col) {
        return;
    }
    else if (CheckEmptyCol(a, row, col, posy) && (posy >= col / 2)) {
        // The loop for sorting rows if the condition is met
        // Run from pos up to col - 1
        for (int j = posy; j <= col - 1; j++) {
            for (int i = 1; i <= row; i++) {
                a[i][j] = a[i][j + 1];
            }
        }
        // The loop for assigning empty values in the first row
        for (int i = 1; i <= row; i++) {
            a[i][col] = ' ';
        }
    }
}

//USING FOR HARD LEVEL
// Auto-centering board

//Move row up and down to the center
// use for row
void SortEmptyRow(char** a, int row, int col) {
    // The loop runs to check for empty elements, then sorts the elements back to the center.
    // Run from 2 up to row / 2
    for (int i = 2; i <= row / 2; i++) {
        for (int j = 1; j <= col; j++) {
            if (a[i][j] == ' ') {
                a[i][j] = a[i - 1][j];
                a[i - 1][j] = ' ';
            }
        }
    }
    // The loop runs to check for empty elements, then sorts the elements back to the center.
    // Run from row / 2 up to row
    for (int i = (row / 2) + 1; i < row; i++) {
        for (int j = 1; j <= col; j++) {
            if (a[i][j] == ' ') {
                a[i][j] = a[i + 1][j];
                a[i + 1][j] = ' ';
            }
        }
    }
}

//Move column left and right to the center
// use for col
void SortEmptyCol(char** a, int row, int col) {
    // The loop runs to check for empty elements, then sorts the elements back to the center.
    // Run from 2 up to col / 2
    for (int i = 1; i <= row; i++) {
        for (int j = 2; j <= col / 2; j++) {
            if (a[i][j] == ' ') {
                a[i][j] = a[i][j - 1];
                a[i][j - 1] = ' ';
            }
        }
    }

    // The loop runs to check for empty elements, then sorts the elements back to the center.
    // Run from col / 2 up to col
    for (int i = 1; i <= row; i++) {
        for (int j = (col / 2) + 1; j < col; j++) {
            if (a[i][j] == ' ') {
                a[i][j] = a[i][j + 1];
                a[i][j + 1] = ' ';
            }
        }
    }
}

//Check Result
bool checkWin(char** board, int row, int col) {
    // 2 loops to check each element to see if it is empty
    // If there's any non-empty element, return false; otherwise, if all elements checked are empty, return true.
    for (int i = 1; i <= row; i++) {
        for (int j = 1; j <= col; j++) {
            if (board[i][j] != ' ') {
                return false;
            }
        }
    }
    return true;
}

// The function used to deallocate memory to avoid memory overflow
void deallocate(char**& board, int row, int col) {
    for (int i = 0; i <= row + 1; i++) {
        delete[] board[i];
    }
    delete[] board;
}


