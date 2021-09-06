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

#define N 9
#define K 20
#define Level 2

using namespace std;

int mat[9][9] = {0};

void fillDiagonal();
bool unUsedInBox(int rowStart, int colStart, int num);
void fillBox(int row, int col);
int randomGenerator();
bool CheckIfSafe(int i, int j, int num);
bool unUsedInRow(int i, int num);
bool unUsedInCol(int j, int num);
bool fillRemaining(int i, int j);
// Fill the diagonal 3 number of 3 x 3 matrices

//void removeKDigits();
void printSudoku();

void fillValues() {
    // Fill the diagonal of 3 x 3 matrices
    fillDiagonal();

    // Fill remaining blocks
    fillRemaining(0, 3);

    // Remove Randomly K digits to make game
    //removeKDigits();
}

void fillDiagonal() {
    for (int i = 0; i < N; i = i + 3)
        // for diagonal box, start coordinates->i==j
        fillBox(i, i);
}

// Returns false if given 3 x 3 block contains num.
bool unUsedInBox(int rowStart, int colStart, int num) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            //cout<< rowStart + i << " " <<colStart +j << " num = "<<num<<endl;
            if (mat[rowStart + i][colStart + j] == num) {
                //cout<<"\t"<< false<<endl;
                return false;
            }
        }
    }//cout<<"\t"<< true<<endl;
    return true;
}

// Fill a 3 x 3 matrix.
void fillBox(int row, int col) {
    int num;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            do {
                num = randomGenerator();
            } while (!unUsedInBox(row, col, num));

            mat[row + i][col + j] = num;
        }
    }
}

// Random generator
int randomGenerator() {
    return (rand() % 9) + 1;
}

// Check if safe to put in cell
bool CheckIfSafe(int i, int j, int num) {
    return (unUsedInRow(i, num) &&
            unUsedInCol(j, num) &&
            unUsedInBox(i - i % 3, j - j % 3, num));
}

// check in the row for existence
bool unUsedInRow(int i, int num) {
    for (int j = 0; j < N; j++)
        if (mat[i][j] == num)
            return false;
    return true;
}

// check in the row for existence
bool unUsedInCol(int j, int num) {
    for (int i = 0; i < N; i++)
        if (mat[i][j] == num)
            return false;
    return true;
}

// A recursive function to fill remaining
// matrix
bool fillRemaining(int i, int j) {
    // System.out.println(i+" "+j);
    if (j >= N && i < N - 1) {
        i = i + 1;
        j = 0;
    }
    if (i >= N && j >= N)
        return true;

    if (i < 3) {
        if (j < 3)
            j = 3;
    } else if (i < N - 3) {
        if (j == (int) (i / 3) * 3)
            j = j + 3;
    } else {
        if (j == N - 3) {
            i = i + 1;
            j = 0;
            if (i >= N)
                return true;
        }
    }

    for (int num = 1; num <= N; num++) {
        if (CheckIfSafe(i, j, num)) {
            mat[i][j] = num;
            if (fillRemaining(i, j + 1))
                return true;

            mat[i][j] = 0;
        }
    }
    return false;
}

// Remove the K no. of digits to
// complete game

int arr[9] = {0};
vector <int> list;

int temp(){
    int tempNum = randomGenerator() -1;
    if (std::count(list.begin(), list.end(), tempNum)) {
        //cout<<"  Duplicate found";
        temp();
    }
    else {
        return tempNum;
    }
}

int gen(int r, int c){
    int tempNum = randomGenerator() -1;

    if (arr[tempNum]<Level){
        if(list.size()==Level){
            list.clear();
        }

        if (std::count(list.begin(), list.end(), tempNum)) {
            //cout<<"  Duplicate found";
            tempNum = temp();
        }
        else {
            //cout<<" Not found ";
        }
        list.push_back(tempNum);


        //Proceed
        arr[tempNum]+=1;
        //cout<<"\t"<<arr[tempNum]<<" "<<tempNum<<endl;
        cout<<"\t";
        for (int i = 0; i < N; ++i) {
            cout<<arr[i]<<" ";
        }
        cout<<" "<<tempNum<<"\t";
        for(int i = 0; i < list.size(); i++)
            std::cout << list[i] << ' ';
        cout<<endl;
        return tempNum;
    }
    else{
        gen(r,c);
    }
}

void removeKDigits() {
    int count = K;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j <Level ; ++j) {
            cout<<i<<" "<<j;
            mat[i][gen(i,j)] = 0;
        }
        cout<<endl;
    }
}

// Print sudoku
void printSudoku() {
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            if (mat[i][j] != 0) {
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
            }else{
                SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            }
            cout<< mat [i][j] << " ";
            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        }
        cout<<endl;
    }
}



#endif //UNTITLED11_GENERATOR_H
