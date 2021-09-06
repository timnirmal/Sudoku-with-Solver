#include <iostream>

#define N 9

using namespace std;

int sudokuBoard[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
};

void printBoard() {
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout<< sudokuBoard [i][j] << " ";
        }
        cout<<endl;
    }
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    printBoard();
    return 0;
}

//Generate Puzzle with random numbers
//Randomly remove numbers from 2 - 4 from each column and row

//Solving Algorithm
//Solve using Rules
//Rows, columns, boxes

//Check if filled correctly, if print and solve again
//If not show wrong value and show start over or solve from previous step


