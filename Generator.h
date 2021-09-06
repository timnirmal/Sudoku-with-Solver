//
// Created by timni on 9/6/2021.
//

#ifndef UNTITLED11_GENERATOR_H
#define UNTITLED11_GENERATOR_H

#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include <fstream>

#define N 9 //width and height of Puzzle

using namespace std;

int Level = 4;  //Default Level

int sudokuBoard[9][9] = {0};
int sudokuBoard_solved[N][N] = {0};

// Print Board
void printBoard() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (sudokuBoard[i][j] != 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            } else {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            cout << sudokuBoard[i][j] << ", ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        cout << endl;
    }
}

////Write to Files (Did't used in project)
ofstream Generate("Generate.txt", ios::trunc);
ofstream Generate_Solverd("Generate-Solved.txt", ios::trunc);

void Print_Board_Solved_file() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Generate_Solverd << sudokuBoard[i][j] << " ";
        }
        Generate_Solverd << endl;
    }
}

void Print_Board_file() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            Generate << sudokuBoard[i][j] << " ";
        }
        Generate << endl;
    }
}

////Check if cell is valid to enter value.
// check in the row for existence
bool rowCheck(int r, int num) {
    for (int col = 0; col < N; col++)
        if (sudokuBoard[r][col] == num)
            return false;
    return true;
}

// check in the row for existence
bool colCheck(int c, int num) {
    for (int row = 0; row < N; row++)
        if (sudokuBoard[row][c] == num)
            return false;
    return true;
}

// Returns false if given 3 x 3 block contains num.
bool boxCheck(int rowStart, int colStart, int num) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            if (sudokuBoard[rowStart + r][colStart + c] == num) {
                return false;
            }
        }
    }
    return true;
}

// Check if safe to put in cell
bool canEnter(int row, int col, int num) {
    return (rowCheck(row, num) && colCheck(col, num) && boxCheck(row - row % 3, col - col % 3, num));
}

// Random generator
int randNum() {
    return (rand() % 9) + 1;
}





// Fill a 3 x 3 matrix.
void fill_3x3(int row, int col) {
    int num;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                num = randNum();
            } while (!boxCheck(row, col, num));
            sudokuBoard[row + i][col + j] = num;
        }
    }
}

void fill_Diag() {
    for (int i = 0; i < N; i = i + 3)
        fill_3x3(i, i);
}
bool fill_Rest(int i, int j) {
    if (j >= N && i < N - 1) {
        i = i + 1;
        j = 0;
    }
    if (i >= N && j >= N) {
        return true;
    }
    if (i < 3) {
        if (j < 3)
            j = 3;
    }
    else if (i < N - 3) {
        if (j == (int) (i / 3) * 3)
            j = j + 3;
    }
    else {
        if (j == N - 3) {
            i = i + 1;
            j = 0;
            if (i >= N) {
                return true;
            }
        }
    }

    for (int num = 1; num <= N; num++) {
        if (canEnter(i, j, num)) {
            sudokuBoard[i][j] = num;
            if (fill_Rest(i, j + 1)){
                return true;
            }
            sudokuBoard[i][j] = 0;
        }
    }
    return false;
}

void Fill() {
    //First fill 3 x 3 diagonal matrices
    fill_Diag();
    //Next fill Rest of the matrix
    fill_Rest(0, 3);

    //Make Copy of Solved Board
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            int temp = sudokuBoard[i][j];
            sudokuBoard_solved[i][j] = temp;
        }
    }
}


//Remove Number of Cells

int arr[9] = {0};
vector<int> list;

int temp() {
    int tempNum = randNum() - 1;
    if (std::count(list.begin(), list.end(), tempNum)) {
        temp();
    } else {
        return tempNum;
    }
}

int genEmptyCellLocation(int r, int c) {
    int tempNum = randNum() - 1;

    if (arr[tempNum] < Level) {
        if (list.size() == Level) {
            list.clear();
        }
        if (std::count(list.begin(), list.end(), tempNum)) {
            //Duplicate found
            tempNum = temp();
        } else {
            //No Duplicate
        }
        list.push_back(tempNum);

        //Proceed
        arr[tempNum] += 1;
        return tempNum;
    } else {
        genEmptyCellLocation(r, c);
    }
}

void removeKDigits() {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < Level; ++j) {
            sudokuBoard[i][genEmptyCellLocation(i, j)] = 0;
        }
    }
}

#endif //UNTITLED11_GENERATOR_H