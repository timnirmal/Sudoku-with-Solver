#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "Generator.h"
#include "Solver.h"

//#define N 9
//#define K 20
//#define Level 2

using namespace std;

// Driver code
int main() {
    srand(time(0));
    fillValues();
    printSudoku();
    cout << endl << "remove K" << endl;
    removeKDigits();
    printSudoku();

    if (solveSudoku() == true){
        sudokuGrid();
    }
    else {
        cout << "No solution exists";
    }
}

