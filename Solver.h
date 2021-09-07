/********************************************************************************
 * Name             : Nirmal L.Y.T.
 * Index No         : 19/ENG/072
 * Registration No  : EN93921
*********************************************************************************/


#ifndef UNTITLED11_SOLVER_H
#define UNTITLED11_SOLVER_H

#include "Generator.h"

bool wrongNumber = false;
bool reset = false;
bool neglectError = false;


int icol = 0;       //initial Condition
int irow = 0;
//vector <int> correctionList;

//Example Data (Later replaced by Generated Data)
int sudokuSolver[N][N] = {
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

int Copy_sudokuSolver[N][N] = {0};

//Read from generator files and Copy to SolverBoard and Keep copy of it to reset.
void Copy_SudokuBoard(){
    for (int i =0; i<N ; i++){
        for (int j = 0; j < N; j++) {
            int temp = sudokuBoard[i][j];
            sudokuSolver[i][j] = temp;
            Copy_sudokuSolver[i][j] = temp;
            //We can access Solved file in 2 and 3 solving methods to check the answer.
        }
    }
}

//Print Sudoku Board
void printSolver(){
    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            if(col == 0 || col == 3 || col == 6 || col == 9){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                cout << " | ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            if(Copy_sudokuSolver[row][col] != 0){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                cout << sudokuSolver[row][col] << " ";
            }
            else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                cout << sudokuSolver[row][col] << " ";
            }
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        if(row == 2 || row == 5){
            cout << endl;
            for(int i = 0; i<N; i++){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                cout << "---";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
        }
        cout << endl;
    }
    cout<<endl;
}

//////////print the sudoku sudokuSolver after solve with Colors
void printSolver(int r, int c, bool clear){

    for (int row = 0; row < N; row++){
        for (int col = 0; col < N; col++){
            // | lines
            if(col == 0 || col == 3 || col == 6){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                cout << " | ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }

            // Numbers
            if (row ==r && col ==c){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
                cout << sudokuSolver[row][col] << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }else {
                if(Copy_sudokuSolver[row][col] != 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                    cout << sudokuSolver[row][col] << " ";
                }
                else{
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << sudokuSolver[row][col] << " ";
                }
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
        }
        if(row == 2 || row == 5){
            cout << endl;
            for(int i = 0; i<N; i++){
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
                cout << "---";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
        }
        cout << endl;
    }
    cout<<endl;
    Sleep(100);
    if (clear)
        system("cls");
}

bool rowCheck_Solver(int r, int num){ //check whether num is present in r or not
    for (int col = 0; col < N; col++)
        if (sudokuSolver[r][col] == num)
            return false;
    return true;
}

bool colCheck_Solver(int c, int num){ //check whether num is present in col or not
    for (int row = 0; row < N; row++)
        if (sudokuSolver[row][c] == num)
            return false;
    return true;
}

//check whether num is present in 3x3 box or not
bool boxCheck_Solver(int rowStart, int colStart, int num){
    for (int r = 0; r < 3; r++){
        for (int c = 0; c < 3; c++){
            if (sudokuSolver[r + rowStart][c + colStart] == num){
                return false;
            }
        }
    }
    return true;
}

bool canEnter_Solver(int row, int col, int num){
    //when item not found in col, row and current 3x3 box
    return rowCheck_Solver(row, num) && colCheck_Solver(col, num) && boxCheck_Solver(row - row % 3 ,col - col%3, num);
}

//get empty location and update row and column
bool checkEmpty(int &row, int &col){
    for (row = 0; row < N; row++){
        for (col = 0; col < N; col++){
            if (sudokuSolver[row][col] == 0)
                return true;
        }
    }
    return false;
}

void ResetBoard() {
    cout<<"Resetting Board....\n\n\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int temp = Copy_sudokuSolver[i][j];
            sudokuSolver[i][j] = temp;
        }
    }

    printSolver();
    cout<<"\n\nReset Done\n\n\n";
    Sleep(1000);
    system("cls");
}

bool solveSudoku(){
    int row, col;

    //If all places are filled return true
    if (!checkEmpty(row, col))
        return true;

    //Go from number 1 - 9
    for (int num = 1; num <= 9; num++){
        //Check if cell can be filled with the num
        if (canEnter_Solver(row, col, num)){
            sudokuSolver[row][col] = num;
            if(effectEnable==true){
                printSolver(row,col, true);
            }

            //Mark the initial position, so it can detect go to previous have made Error
            if (irow == 0 && icol ==0){
                irow = row;
                icol = col;
            }

            //Recursive function to go to other empty
            if (solveSudoku()) {
                wrongNumber = false;
                return true;
            }

            ////If Error Occurs
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            cout << "Error...";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

            //Mark that on the Board
            cout<<endl<<endl;

            if (!neglectError) {
                char inp;

                printSolver(row, col, false);
                cout<<endl;
                cout<<"Select choice...\n\n";
                cout << "\tPress Y if you want to start over (y/Y) : \n";
                cout << "\tPress E if you want to Neglect Errors and Finish Solving (e/E) : \n";
                cout << "\tPress N to Go to Previous Step (n/N) : \n\n";
                cout<<"Enter Your Choice : ";
                cin >> inp;

                system("cls");

                if (inp == 'y' || inp == 'Y') {
                    ResetBoard();
                    //solveSudoku();
                } else if (inp == 'e' || inp == 'E') {
                    neglectError = true;
                } else {
                    if (row == irow && col == icol) {
                        cout << "You have reach the Beginning.. Do you want to Start from begin (y/Y): ";
                        cin >> inp;
                        if (inp == 'y' || inp == 'Y') {
                            ResetBoard();
                        }
                    }
                    return false;
                }
            }

            //Turn to 0 when conditions are not satisfied.
            wrongNumber = true;
            sudokuSolver[row][col] = 0;
        }
    }
    return false;
}

//Read From File - not completed
/*
void ReadFile(){
    string array[81];
    int count = 0;

    ifstream file("C:\\Users\\timni\\CLionProjects\\untitled3\\Generated.txt");

    if (!file)
        cout << "File not Found";

    count = 0;
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            sudokuSolver[i][j] = stoi(array[count]);
            count++;
        }
    }

    //Create copy of array
    int maze_copy[N][N];
    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            int temp = sudokuSolver[i][j];
            maze_copy[i][j] = temp;
        }
    }

    for (int j = 0; j < N; j++) {
        for (int i = 0; i < N; i++) {
            cout<<sudokuSolver;
        }
    }
}*/

#endif //UNTITLED11_SOLVER_H
