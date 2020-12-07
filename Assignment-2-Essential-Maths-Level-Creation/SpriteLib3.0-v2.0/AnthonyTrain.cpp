#include "AnthonyTrain.h"
#include "ECS.h"
#include "Game.h"
#include <cstdlib>
#include <chrono>
#include <thread>
#include <windows.h>
#include <cstdlib>
#include "Game.h"
#include<windows.h>
#include <iostream>
#include "PhysicsPlayground.h"
	int heightVar, displayscore;
using namespace std;
using namespace std::chrono_literals;

void AnthonyTrain::OnTrigger()
{
	Trigger::OnTrigger();

	if (!triggered)
	{
		if (heightVar < 2)
		{
			for (int i = 0; i < m_targetEntities.size(); i++)
			{
				PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
			}

			triggered = true;
			std::cout << "You hit a wall";
		}
	}
}

void AnthonyTrain::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		if (heightVar < 2)
		{
			for (int i = 0; i < m_targetEntities.size(); i++)
			{
				PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
			}

			triggered = true;

			std::this_thread::sleep_for(std::chrono::seconds(1));
			system("cls");
			string Menu[3] = { "Play Again" , "Exit", ""};
			int pointer = 0;
			bool bMainMenu = true;
			while (bMainMenu)
			{
				system("cls");

				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
				cout << "YOU DIED \n";
				cout << "Your Score was " << displayscore << "!\n";
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


						}
						case 1:
						{
							//thank you for playing
							system("cls");
							std::cout << " you selected Exit\n Good Bye!";
							Sleep(1000);
							bMainMenu = false;
							exit(0);
						}
						default:
						{
							cout << "Invalid Input! ";
						}
						}
					}
				}
			}
		}
	}
}

void AnthonyTrain::OnExit()
{
	Trigger::OnExit();
}