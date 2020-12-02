#include "Game.h"
#include <String>
#include "window.h"
using namespace std;

#undef main
string mainMenu();

int main()
{
	//Create the Game
	Game theGame;

	//Initialize the game
	theGame.InitGame();

   


        string menuNum = mainMenu();

        if (menuNum == "1") { //start 
            //choose map 
            cout << "Playing" << endl;
           
        }
        else if (menuNum == "2") { //rules 
            //rules 
            int goBac;
            cout << "How to play: " << endl << "Click -A- to moce left" << endl << "Click -D- to move right" << endl << "Click -Space Bar- to Jump" << endl << "Click -S- to charge through walls" << endl << "To go back to main menu click 1" << endl;
            cin >> goBac;
            if (goBac == 1)
            {
                cout << endl;
               mainMenu();
            }
           
        }
        else if (menuNum == "3") { //quit 
            return EXIT_SUCCESS;
        }
        else {
        }

    

  

	//Runs the game until it returns :)
	return theGame.Run();
}

string mainMenu()
{
    string menuOp; //menu option 
    bool loopMenu = false;

    while (!loopMenu)
    {
        cout << "\n\n\nSubway Surfers" << endl;
        cout << "Input a number to begin: " << endl;
        cout << "1. Start" << endl
            << "2. How To play" << endl
            << "3. Quit" << endl;
        cin >> menuOp;

        if (menuOp == "1" || menuOp == "2" || menuOp == "3") {
            loopMenu = true;
        }
        else {
        }

        system("CLS"); //clear console 
    }
    return menuOp;
}