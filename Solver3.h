//
// Created by timni on 9/6/2021.
//

//Example Data  (Later replaced by Genertated Data)
int sudokuSolver3[N][N] = {
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

int Copy_sudokuSolver3[N][N] = {0};
int Copy_sudokuBoard3[N][N] = {0};

//Read from generator files and Copy to SolverBoard and Keep copy of it to reset.
void Copy_SudokuBoard_for3(){
    for (int i =0; i<N ; i++){
        for (int j = 0; j < N; j++) {
            int temp = sudokuBoard[i][j];
            sudokuSolver3[i][j] = temp;
            Copy_sudokuBoard3[i][j] = temp;
        }
    }
    for (int i =0; i<N ; i++){
        for (int j = 0; j < N; j++) {
            int temp = sudokuBoard_solved[i][j];
            Copy_sudokuSolver3[i][j] = temp;
        }
    }
}

//////////print the sudoku sudokuSolver3 after solve with Colors
void printSolver3(int r, int c, bool clear){

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
                cout << sudokuSolver3[row][col] << " ";
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }else {
                if(Copy_sudokuBoard3[row][col] != 0){
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 9);
                    cout << sudokuSolver3[row][col] << " ";
                }
                else{
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
                    cout << sudokuSolver3[row][col] << " ";
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

////Use For 3 Mode which is fill by Algorithm
void solveSudoku_Easy(){
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cout<<Copy_sudokuSolver3[row][col]<<" ";
        }
        cout<<endl;
    }

    //Go from number 1 - 9
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            int temp = sudokuSolver3[row][col];
            if ( temp == 0){
                //cout<<sudokuSolver3[row][col]<<" "<<endl;
                for (int num = 1; num <= 9; num++){
                    //Check if cell can be filled with the num
                    int temp2 = Copy_sudokuSolver3[row][col];
                    if (Copy_sudokuSolver3[row][col] == num){
                        sudokuSolver3[row][col] = num;
                        printSolver3(row,col,true);
                    }
                }
            }

        }
    }
}

////Use for 4th mode which is Fill by user inputs
//Get User Inputs
void getinput(int row, int col){
    bool flag4=0;
    while(true){
        if (flag4==true){
            return;
        }
        cout<<"Enter Number ( "<<row<<","<<col<<" ): ";
        int num;
        cin>>num;
        //Check if cell can be filled with the num
        int temp2 = Copy_sudokuSolver3[row][col];
        if (Copy_sudokuSolver3[row][col] == num){
            sudokuSolver3[row][col] = num;
            printSolver3(row,col,true);
            flag4 = 1;
            break;
        }
    }
}

//User Inputs solving Code
void solveSudoku_UserInput(){
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cout<<Copy_sudokuSolver3[row][col]<<" ";
        }
        cout<<endl;
    }

    //Go from number 1 - 9
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            int temp = sudokuSolver3[row][col];
            if ( temp == 0){
                getinput(row,col);
            }

        }
    }
}
