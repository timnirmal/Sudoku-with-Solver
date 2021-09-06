#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>
#include "Generator.h"
#include "Solver.h"
#include "Solver3.h"

//#define N 9
//#define K 20
//#define Level 2

bool finish = false;

using namespace std;

vector <string> Loader;


int inpNum;
//int inpChar;

void Load(){
    Loader.clear();
    for (int i = 0; i < 10; ++i) {
        Loader.push_back("=");
    }
    Loader.push_back(">|");
    for (int i = 0; i < Loader.size(); ++i) {
        Sleep(40);
        cout << Loader[i];
    }
    Loader.clear();
}

void textLoader(string txt){
    vector<char> LoaderTXT(txt.begin(), txt.end());

    for (const char &c: LoaderTXT) {
        cout<<"G";
        Sleep(30);
        printf("\b ");
        Sleep(40);
        std::cout << c;
    }
}

void puzzleGen(){

    cout<<"1. Generate Puzzle\n"<<endl;
    cout<<"2.. Solve Puzzle using Recursive Algorithm"<<endl;
    cout<<"3.. Solve Puzzle using Non-Recursive Algorithm"<<endl;
    cout<<"4.. Solve Puzzle using User Inputs"<<endl;

    cout<<"\nEnter number : "<<endl;
    cin>>inpNum;

    if (inpNum == 1){
        system("cls");
        //Fill Sudoku Board
        cout<<"Sudoku Board Building \t: ";
        Load();
        Fill();
        cout<<endl;
        Print_Board_Solved_file();

        cout<<"Making Empty Slots \t: ";
        removeKDigits();
        Load();
        cout<<endl;
        Print_Board_file();

        cout<<"Puzzle build Successful...\n\n";

        cout<<"Sudoku Puzzle Preview...\n\n";
        printBoard();
        cout<<endl;

        //cout<<"It's Time to Play the Game...\n\n";
        textLoader("It's Time to Play the Game...\n\n");
        system("pause");
        system("cls");

        Generate.close();
        Generate_Solverd.close();

    }
    else if (inpNum == 2){
        //Since sudokuSolver[][] is made with dumy data. Lets copy Generated array to that.
        //Make copy of Board to Used when Resetting.
        Copy_SudokuBoard();
        if (solveSudoku() == true){
            printSolver();
        }
        else {
            cout << "No solution exists";
        }
        system("pause");
    }
    else if (inpNum == 3){
        Copy_SudokuBoard_for3();
        solveSudoku_Easy();
        system("pause");
    }
    else if (inpNum == 4){
        Copy_SudokuBoard_for3();
        solveSudoku_UserInput();
    }

}

// Driver code
int main() {
    srand(time(0));
    cout<< "* * * * *  Sudoku Game * * * * *\n\n";

    while (true){
        if (finish){
            return 0;
        }
        cout<<"1. Start"<<endl;
        cout<<"2. How to Play"<<endl;
        cout<<"3. Settings"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"\nEnter number : "<<endl;
        cin>>inpNum;

        if (inpNum==1) {
            puzzleGen();

        }else if(inpNum==2) {

            cout << "In 2. Solve Puzzle using Recursive Algorithm MODE" << endl;
            cout << "\tUse y/Y to yes\n";
            cout << "\tUse n/N to no\n";
            cout << "\tUse e/E to Neglect Errors and Get final answer\n";
        }
        else if (inpNum==3){
            cout << "Settings" << endl;
        }
        else if(inpNum==4) {
            cout<<"Exit"<<endl;
            finish = true;
        }else{
            cout<<"Wrong input try again";

        }

    }







}

