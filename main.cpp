#include <iostream>

#define N 9

using namespace std;

int sudokuBoard[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 0, 2, 0, 0, 3, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 4, 0, 0, 5, 0, 0, 6, 0},
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

bool rowCheck(int r , int val) {
    for (int col=0; col<N; col++){
        if (sudokuBoard[r][col] == val){
            return true;
        }
    }
    return false;
}

bool colCheck(int c , int val){
    for (int row=0; row<N; row++){
        if (sudokuBoard[row][c] == val){
            return true;
        }
    }
    return false;
}

int helpBoxCheck(int val) {
    if (val<3){
        return 0;
    }else if (3<=val && val<6){
        return 3;
    }else if(6<=val && val<9){
        return 6;
    }
}

bool boxCheck(int r, int c, int val) {
    int plusRow = 0;
    int plusCol = 0;

    plusRow = helpBoxCheck(r);
    plusCol = helpBoxCheck(c);

    for (int r=plusRow; r<plusRow+3; r++){
        for (int c=plusCol; c<plusCol+3; c++){
            if (sudokuBoard[r][c] == val){
                return true;
            }
            cout<< sudokuBoard [r][c] << " ";
        }
        cout<<endl;
    }
    return false;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    //printBoard();
    boxCheck(2,5,0);
    return 0;
}

//Generate Puzzle with random numbers
//Randomly remove numbers from 2 - 4 from each column and row

//Solving Algorithm
//Solve using Rules
//Rows, columns, boxes

//Check if filled correctly, if print and solve again
//If not show wrong value and show start over or solve from previous step


