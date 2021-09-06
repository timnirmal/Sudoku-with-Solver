#include <iostream>
#include <time.h>

#define N 9

using namespace std;

int sudokuBoard[N][N] = {0};

/*
int sudokuBoard[N][N] = {5, 8, 5, 9, 6, 8, 5, 9, 6,
                         7, 9, 3, 8, 5, 6, 4, 6, 6,
                         3, 9, 8, 2, 6, 6, 9, 2, 2,
                         7, 5, 2, 4, 4, 4, 4, 9, 9,
                         3, 4, 4, 8, 9, 9, 6, 3, 9,
                         3, 2, 4, 7, 2, 5, 5, 1, 6,
                         8, 8, 9, 6, 1, 6, 9, 8, 8,
                         6, 7, 3, 4, 8, 9, 2, 9, 6,
                         1, 3, 7, 3, 8, 6, 6, 6, 5};
*/

void printBoard() {
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout<< sudokuBoard [i][j] << " ";
        }
        cout<<endl;
    }
}

bool rowCheck(int r , int val) {
    bool flag=0;
    //cout<<"val "<<val<<endl;
    for (int col=0; col<N; col++){
        //cout<<sudokuBoard[r][col];
        if (sudokuBoard[r][col] != val){
            flag = false;
        }else{
            return true;
        }
    }
    return flag;
}

bool colCheck(int c , int val){
    bool flag=0;
    //cout<<"val "<<val<<endl;
    for (int row=0; row<N; row++){
       // cout<<sudokuBoard[row][c];
        if (sudokuBoard[row][c] != val){
            flag = false;
        }else{
            return true;
        }
    }
    return flag;
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
    bool flag =0;

    plusRow = helpBoxCheck(r);
    plusCol = helpBoxCheck(c);

    for (int r=plusRow; r<plusRow+3; r++){
        for (int c=plusCol; c<plusCol+3; c++){
            if (sudokuBoard[r][c] != val){
                flag = false;
            }else{
                return true;
            }
            //cout<< sudokuBoard [r][c] << " ";
        }
        //cout<<endl;
    }
    return false;
}

int randNum() {
    return (rand() % 9) + 1;
}

bool canEnter(int r, int c, int tempVal){
    //cout<<"\tRow Check = "<<rowCheck(r,tempVal)<<endl;
    if (!rowCheck(r,tempVal) && !colCheck(c,tempVal) && !boxCheck(r,c,tempVal)){
        return true;
    } else{
        return false;
    }
}

void numGen(int r, int c) {

    int tempVal = 0;
    tempVal = randNum();
    //cout<<"Value is = "<<tempVal<<" in "<<"( "<<r<<","<<c<<" )"<<endl;
    if (canEnter(r, c, tempVal)) {
        sudokuBoard[r][c] = tempVal;
        cout<<endl<<"val = "<<tempVal<<endl;
        printBoard();
    } else {
        numGen(r, c);
    }



    //cout<<"Value is = "<<tempVal<<" in "<<"( "<<r<<","<<c<<" )"<<endl;

    /*if (rowCheck(r,tempVal)){
        cout<<"\trowCheck passed"<<endl;
        if (colCheck(c,tempVal)){
            cout<<"\tcolCheck passed"<<endl;
            if (r,c,tempVal){
                cout<<"\tbox    Check passed"<<endl;
                return tempVal;
            } else {
                return numGen(r, c);
            }
        }
        else {
            return numGen(r, c);
        }
    }
    else{
        return numGen(r,c);
    }*/
}

int main() {
    srand(time(0));
    //std::cout << "Hello, World!" << std::endl;
    //printBoard();
    //cout<<boxCheck(2,5,0);

    //sudokuBoard[2][2] = 5;
    //cout<< sudokuBoard[2][2]<<endl<<endl;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            numGen(r, c);
        }
    }

    for (int (i) = 0; (i) <N ; ++(i)) {
        //for (int j = 0; j < N; ++j) {
         //   cout<<sudokuBoard[i][0];
            //cout<<rowCheck(i,j)<<endl;
        //}
    }
    cout<<endl;
    //printBoard();

    cout<<endl<<"colCheck"<<colCheck(0,9)<<endl;
    cout<<endl<<"rowCheck"<<rowCheck(0,9)<<endl;
    cout<<endl<<"bocCheck"<<boxCheck(0,0,9)<<endl;
    //cout<<endl<< sudokuBoard[2][2]<<endl;
    return 0;
}

//Generate Puzzle with random numbers
//Randomly remove numbers from 2 - 4 from each column and row

//Solving Algorithm
//Solve using Rules
//Rows, columns, boxes

//Check if filled correctly, if print and solve again
//If not show wrong value and show start over or solve from previous step


