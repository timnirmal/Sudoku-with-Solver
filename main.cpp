#include <iostream>
#include <time.h>
#include <windows.h>
#include <vector>
#include <algorithm>

#include "Generator.h"
#include "Solver.h"
#include "Solver3.h"

using namespace std;

vector <string> Loader;
int inpNum;
bool finish = false;

//Load Animations (Loader)
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

//Text Animations
void textLoader(string txt){
    vector<char> LoaderTXT(txt.begin(), txt.end());
    for (const char &c: LoaderTXT) {
        //Switch Based on Effects Settings
        if (effectEnable == true) {
            cout << "G";
            Sleep(30);
            printf("\b ");
            Sleep(40);
        }
        std::cout << c;
    }
}

//When User Select Start From Main Menu
void puzzleGen(){
    cout<<"1. Generate Puzzle\n"<<endl;
    cout<<"2.. Solve Puzzle using Recursive Algorithm"<<endl;
    cout<<"3.. Solve Puzzle using Non-Recursive Algorithm"<<endl;
    cout<<"4.. Solve Puzzle using User Inputs"<<endl;

    cout<<"\nEnter number : "<<endl;
    cin>>inpNum;

    //////Generating Sudoku Board
    if (inpNum == 1){
        system("cls");

        //Hardness Level need to be enterd before game
        cout<<"\nEnter Level (2-4) : "<<endl;
        cin>>Level;

        //Fill Sudoku Board
        cout<<"Sudoku Board Building \t: ";
        Load();
        Fill();
        cout<<endl;
        //Print_Board_Solved_file();

        cout<<"Making Empty Slots \t: ";
        removeKDigits();
        Load();
        cout<<endl;
        //Print_Board_file();

        cout<<"Puzzle build Successful...\n\n";

        cout<<"Sudoku Puzzle Preview...\n\n";
        printBoard();   //Print Board
        cout<<endl;

        //Loading "It's Time to Play the Game..." with animations
        textLoader("It's Time to Play the Game...\n\n");
        system("pause");
        system("cls");

        //Text Files can be used to stop the connectino between generator and solver.
        //But it is not used in here.
        //Generate.close();
        //Generate_Solverd.close();
    }
    ////Solve Puzzle using Recursive Algorithm
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
    ////Solve Puzzle using Non-Recursive Algorithm
    else if (inpNum == 3){
        Copy_SudokuBoard_for3();
        solveSudoku_Easy();
        system("pause");
    }
    ////Solve Puzzle using User Inputs
    else if (inpNum == 4){
        Copy_SudokuBoard_for3();
        solveSudoku_UserInput();
    }

}

// Driver code
int main() {
    srand(time(0)); //seed for rand
    cout<< "* * * * *  Sudoku Game * * * * *\n\n";

    while (true){
        if (finish){    //Check termination conditions
            return 0;
        }

        ////Main menu
        cout<<"1. Start"<<endl;
        cout<<"2. How to Play"<<endl;
        cout<<"3. Settings"<<endl;
        cout<<"4. Exit"<<endl;

        cout<<"\nEnter number : "<<endl;
        cin>>inpNum;

        //Start
        if (inpNum==1) {
            puzzleGen();

        }
        //How to Play
        else if(inpNum==2) {
            cout<<"There are 2 section in this game. One is Puzzle Generation\n"
                  "Other one is Puzzle solving \n\n For Puzzle solving there are thee options.\n\n";
            cout<<"\t2. Solve Puzzle using Recursive Algorithm\n\t"
            "3.. Solve Puzzle using Non-Recursive Algorithmn\n\t"
            "4.. Solve Puzzle using User Inputs";

            cout << "*** 2 MODE - Solve Puzzle using Recursive Algorithm ***\n" << endl;
            cout << "\tUse y/Y to yes\n";
            cout << "\tUse n/N to no\n";
            cout << "\tUse e/E to Neglect Errors and Get final answer\n";

            cout << "\n\n*** 3 MODE - Solve Puzzle using Non-Recursive Algorithm ***\n" << endl;
            cout << "  A simple algorithm is used to compare with Answer of the Puzzle\n";

            cout << "\n\n*** 3 MODE - Solve Puzzle using User Input ***\n" << endl;
            cout << "  A simple algorithm is used to compare user inputs with Answer of the Puzzle\n";
        }
        //Settings
        else if (inpNum==3){
            cout << "Settings" << endl;
            cout<< "\n\nCurrent Settings : \n\tEffects : "<<effectEnable;
            cout <<  "\n\tLevel : "<<Level<<endl;

            char inp;

            cout<< "\n\nChange Effect (y/n) : ";
            cin>>inp;
            if(inp=='y' || inp=='Y'){
                effectEnable = !effectEnable;
            }else{
                effectEnable = effectEnable;
            }

            cout<<"Changed Effects : "<<effectEnable<<endl<<endl;

            cout<< "\n\nChange Level (y/n) : ";
            cin>>inp;
            if(inp=='y' || inp=='Y'){
                cout<<"\nEnter Level : ";
                cin>>Level;
            }else{
                Level = Level;
            }

            cout<<"Changed Level : "<<Level<<endl<<endl;

            system("pause");
            system("cls");
        }
        //Exit
        else if(inpNum==4) {
            cout<<"Exit"<<endl;
            finish = true;
        }
        //Default
        else{
            cout<<"Wrong input try again";

        }
    }
}

