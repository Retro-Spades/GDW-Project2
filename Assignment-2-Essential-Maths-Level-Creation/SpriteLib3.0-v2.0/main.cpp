#include "Game.h"
#include<windows.h>
#include <iostream>
using namespace std;

#undef main
int main()
{
    //Create the Game
    
    Game theGame;






    //Initialize the game
    theGame.InitGame();

    
        system("cls");
        string Menu[3] = {     
         " __________.__                \n"                 
         " \\______   \\  | _____  ___.__.\n"
         "  |     ___/  | \\__  \\<   |  |\n"
         "  |    |   |  |__/ __ \\___   |\n"
         "  |____|   |____(____  / ____|\n"
         "                     \\/\\/\n"              
            , 
   "  _________                __                .__ \n"
   "  \\_   ___ \\  ____   _____/  |________  ____ |  |   ______\n"
   "  /    \\  \\/ /  _ \\ /    \\   __\\_  __ \\/  _ \\|  |  /  ___/\n"
   "  \\     \\___(  <_> )   |  \\  |  |  | \\(  <_> )  |__\\___ \\\n"
   "   \\______  /\\____/|___|  /__|  |__|   \\____/|____/____  >\n"
   "          \\/            \\/                             \\/\n"  ,      
    " ___________      .__  __   \n"
    " \\_   _____/__  __|__|/  |_\n"
      "  |    __)_\\  \\/  /  \\   __\\\n"
      "  |        \\>    <|  ||  |     \n"
      " /_______  /__/\\_ \\__||__|\n"
     "         \\/      \\/ \n" 
        };
        int pointer = 0;
        bool bMainMenu = true;

        while (bMainMenu = true)
        {
            system("cls");

            SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
            cout << "  _____________ _____________  __      __  _____ _____.___.   _____________ _____________________________________________  _________\n";
            cout << " /   _____/    |   \\______   \\/  \\    /  \\/  _  \\\\__  |   |  /   _____/    |   \\______   \\_   _____/\\_   _____/\\______   \\/   _____/\n";
            cout << " \\_____  \\|    |   /|    |  _/\\   \\/\\/   /  /_\\  \\/   |   |  \\_____  \\|    |   /|       _/|   __)    |    __)_  |       _/\\_____  \\\n";
            cout << " /        \\    |  / |    |   \\ \\        /    |    \\____   |  /        \\    |  / |    |   \\|     \\    |        \\ |    |   \\/        \\\n";
            cout << "/_______  /______/  |______  /  \\__/\\  /\\____|__  / ______| /_______  /______/  |____|_  /\\___  /   /_______  / |____|_  /_______  /\n";
            cout << "        \\/                 \\/        \\/         \\/\\/                \\/                 \\/     \\/            \\/         \\/        \\/\n";
            cout << "Main Menu\n\n";

            for (int i = 0; i < 3; ++i)
            {
                if (i == pointer)
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
                    cout << Menu[i] << endl;
                }
                else
                {
                    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
                    cout << Menu[i] << endl;
                }
            }

            while (bMainMenu)
            {
                if (GetAsyncKeyState(VK_UP) & 1)
                {
                    pointer = pointer - 1;
                    if (pointer == -1)
                    {
                        pointer = 2;
                    }
                    break;
                }
                else if (GetAsyncKeyState(VK_DOWN) & 1)
                {
                    pointer += 1;
                    if (pointer == 3)
                    {
                        pointer = 0;
                    }
                    break;
                }
                else if (GetAsyncKeyState(VK_RETURN) & 1)
                {
                    switch (pointer)
                    {
                    case 0:
                    {
                        //play game
                        system("cls");

                        Sleep(1000);
                        cout << "Playing" << endl;
                        return theGame.Run();
                    }
                    case 1:
                    {
                        //Controls
                        system("cls");
                        std::cout << "You Selected Controls\n";
                        Sleep(1000);
                        cout << "How to play: " << endl << "Click -A- to move left" << endl << "Click -D- to move right" << endl << "Click -Space Bar- to Jump" << endl << "To Play the game click 1\nTo Exit press 2" << endl;
                        int Gobax;
                        cin >> Gobax;
                        if (Gobax == 1)
                        {
                            pointer = 0;
                            break;
                        }
                        else if (Gobax == 2)
                        {
                            pointer = 2;
                           
                        }
                       
                    }
                    case 2:
                    {
                        //thank you for playing
                        system("cls");
                        std::cout << " you selected Exit\n Good Bye!";
                        Sleep(1000);
                        bMainMenu = false;
                        return EXIT_SUCCESS;
                    }
                    default:
                    {
                        cout << "Invalid Input! ";
                    }
                    }
                }
            }
            Sleep(150);
        }
    
    return 0;


}