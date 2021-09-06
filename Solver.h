//
// Created by timni on 9/6/2021.
//

#ifndef UNTITLED11_SOLVER_H
#define UNTITLED11_SOLVER_H

bool wrongNumber = false;
vector <int> correctionList;

int grid[N][N] = {
        3, 0, 0, 2, 1, 6, 0, 7, 0,
        7, 0, 0, 5, 0, 8, 0, 2, 6,
        2, 8, 6, 0, 0, 0, 0, 3, 5,
        0, 0, 3, 7, 0, 2, 8, 0, 9,
        6, 0, 0, 9, 5, 3, 0, 4, 0,
        5, 0, 0, 1, 8, 0, 3, 6, 0,
        9, 0, 2, 0, 0, 1, 6, 0, 7,
        4, 6, 1, 0, 2, 0, 5, 0, 0,
        0, 3, 7, 0, 9, 0, 2, 0, 4
};

bool isPresentInCol(int col, int num){ //check whether num is present in col or not
    for (int row = 0; row < N; row++)
        if (grid[row][col] == num)
            return false;
    return true;
}

bool rowCheck_Solver(int r, int num){ //check whether num is present in r or not
    for (int col = 0; col < N; col++)
        if (grid[r][col] == num)
            return false;
    return true;
}

bool isPresentInBox(int boxStartRow, int boxStartCol, int num){
//check whether num is present in 3x3 box or not
    for (int row = 0; row < 3; row++)
        for (int col = 0; col < 3; col++)
            if (grid[row+boxStartRow][col+boxStartCol] == num)
                return false;
    return true;
}

void sudokuGrid(){ //print the sudoku grid after solve
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            if(col == 3 || col == 6)
                cout << " | ";
            cout << grid[row][col] <<" ";
        }
        if(row == 2 || row == 5){
            cout << endl;
            for(int i = 0; i<N; i++)
                cout << "---";
        }
        cout << endl;
    }
}
void sudokuGrid(int r, int c){ //print the sudoku grid after solve
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            if(col == 3 || col == 6)
                cout << " | ";

            if (row ==r && col ==c){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << grid[row][col] << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }else {
                cout << grid[row][col] << " ";
            }
        }
        if(row == 2 || row == 5){
            cout << endl;
            for(int i = 0; i<N; i++)
                cout << "---";
        }
        cout << endl;
    }
    Sleep(100);
    system("cls");
}
bool findEmptyPlace(int &row, int &col){ //get empty location and update row and column
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0) //marked with 0 is empty
                return true;
    return false;
}

bool isValidPlace(int row, int col, int num){
    //when item not found in col, row and current 3x3 box
    return rowCheck_Solver(row, num) && isPresentInCol(col, num) && isPresentInBox(row - row % 3 ,
                                                                                  col - col%3, num);
}

bool solveSudoku(){
    int row, col;
    if (!findEmptyPlace(row, col))
        return true; //when all places are filled
    for (int num = 1; num <= 9; num++){ //valid numbers are 1 - 9
        if (isValidPlace(row, col, num)){ //check validation, if yes, put the number in the grid
            grid[row][col] = num;

            if (solveSudoku()) { //recursively go for other rooms in the grid
                wrongNumber = false;
                return true;
            }
            cout << "Error";

            cout<<endl;
            //sudokuGrid(row, col);
            cout<<endl;
            wrongNumber = true;
            grid[row][col] = 0; //turn to unassigned space when conditions are not satisfied
        }
    }
    return false;
}

#endif //UNTITLED11_SOLVER_H
