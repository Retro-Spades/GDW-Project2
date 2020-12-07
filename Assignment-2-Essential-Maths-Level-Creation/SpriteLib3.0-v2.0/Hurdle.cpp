#include "Hurdle.h"
#include "ECS.h"
#include <iostream>
#include <chrono>
#include <thread>
#include "PhysicsPlayground.h"
int heightVar2;
using namespace std;
using namespace std::chrono_literals;

void HurdleThing::OnTrigger()
{
	Trigger::OnTrigger();

	if (!triggered)
	{
		if (heightVar2 == 0)
		{
			for (int i = 0; i < m_targetEntities.size(); i++)
			{
				PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
			}
			triggered = true;
		}
	}
}

void HurdleThing::OnEnter()
{
	Trigger::OnEnter();

	if (!triggered)
	{
		
		if (heightVar2 == 0)
		{
			for (int i = 0; i < m_targetEntities.size(); i++)
			{
				PhysicsBody::m_bodiesToDelete.push_back(m_targetEntities[i]);
			}

			triggered = true;
			std::this_thread::sleep_for(std::chrono::seconds(1));
			system("cls");
			string Menu[3] = {





						  " ___________      .__  __   \n"
	" \\_   _____/__  __|__|/  |_\n"
	  "  |    __)_\\  \\/  /  \\   __\\\n"
	  "  |        \\>    <|  ||  |     \n"
	  " /_______  /__/\\_ \\__||__|\n"
	 "         \\/      \\/ \n"
				,
				""



				, "" };
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

void HurdleThing::OnExit()
{
	Trigger::OnExit();
}
