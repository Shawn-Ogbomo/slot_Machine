//Shawn Ogbomo
#include <cstdlib>										// permits use of srand function
#include <ctime>										// permits use of the time function
#include<iostream>
#include <string>
#include<Windows.h>
int randRange(int low, int high)
{
	return rand() % (high - low + 1) + low;

}
std::string choice(void)
{
	std::string selection;
	int flag = 0;
	while (!flag)
	{
		std::cin >> selection;

		if (selection == "y" || selection == "Y" || selection == "n" || selection == "N")
		{
			flag = 1;


		}
		else
		{
			std::cout << "Please enter a valiid character Y or Y or N or n: ";
		}
	}

	return selection;
}

int coins_Processor(void)
{
	int coins = 0;
	bool choice = false;
	std::cout << "Please instert coins must less than or equal to 20: ";
	while (!choice)
	{
		std::cin >> coins;

		if (coins < 1 || coins > 20)
		{
			std::cout << "No more than 20 coins please... ";

		}
		else if (coins >= 1 || coins <= 20)
		{
			
			choice = true;
			
		}
	}
	return coins;

}										

void add_Coins(int*coins)
{
	int coin = 0;
	int flag = 0;

	while (!flag)
	{

		coin = coins_Processor();  
		*coins += coin;
		if (*coins > 20)
		{
			std::cout << "\nYour coins are over 20...";
			*coins -= coin;

		}
		else if (*coins <=20 )
		{
			std::cout << "\nGood...";
			std::cout << "\n Coins stocked: " << coin;
			std::cout << "\n Keep playing";
			flag = 1;

		}
	}

}


int main(void)
{
	srand(time(NULL));
	const int num_Of_Slots = 3;
	int slot[num_Of_Slots] = { 0 };
	int flag = 0;
	int turn = 0;
	int attempts = 0;
	int tokens = coins_Processor();
	int earnings = 0;
	std::cout << "Good! game will now start:";
	while (!flag)
	{
		std::cout << "\nturn: " << ++turn << '\n';
		Sleep(1000);
		attempts++;
		tokens --;
		tokens --;
		
		for (int i = 0; i < num_Of_Slots; i++)
		{
			
			slot[i] = randRange(0, 7);
			std::cout << slot[i] << " ";
			Sleep(1000);
			
		}

		if (slot[0] == slot[1] && slot[1] == slot[2] && tokens >= 0)
		{
			std::cout << "You win...\n";
			Sleep(1000);
			std::cout << "number of attempts: " << attempts;
			Sleep(1000);
			std::cout << "\nTokens remaining: " << tokens;
			Sleep(1000);
			earnings++;
			std::cout << "\nearnings: " << earnings;

			std::cout << "\nTry again? ";
			std::string opt = choice();
			opt == "y" || opt == "Y" ? flag = 0 : flag = 1;
			std::cout << '\n';
		}
		else
		{
			std::cout << "\nTry again? ";
			std::string opt = choice();
			opt == "y" || opt == "Y" ? flag = 0 : flag = 1;								
			if (tokens <= 1 )													
			{																	
				
				std::cout << "\nCoins remaining: " << tokens << " A minimum of two coins are required.";
				std::cout << "\n Do you want to add more coins? ";
				opt = choice();
				if (opt == "y" || opt == "Y")
				{

					add_Coins(&tokens); 						
					turn = 0;
					flag = 0;
				}
				else
				{
					flag = 1;
				}
			}			
			std::cout << "\n Coins remaining: " << tokens;
			std::cout << '\n';
		}

	}
	std::cout << "\nHere's your change: " << tokens;
	Sleep(1000);
	std::cout << "\nHere's your Earnings: " <<  earnings;
	Sleep(1000);
	tokens += earnings;
	std::cout << "\nTotal: " << tokens;
	std::cout << "\nThanks for playing!";

	return 0;
}