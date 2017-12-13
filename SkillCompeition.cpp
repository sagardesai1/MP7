#include <iostream>
#include <string>
#include <cmath>
#include <time.h>
#include "Character.h"
#include "Knight.h"
#include "Wizard.h"

using namespace std;

int wizardWins = 0;
int knightWins = 0;
double wallet = 500.00;
double moneyMade = 0.00;
double moneyLost = 0.00;
bool pickedWinner = false;
bool pickedRounds = false;
bool predictKnightWin = false;
bool predictWizardWin = false;
int predictRounds;
int roundsTotal;
double betWinnerAmount;
double betRoundAmount;


bool fightClub() {
	srand(time(NULL));
	bool gameWinner;
	KnightCharacter Knight;
	WizardCharacter Wizard;
	int counter = 1;
	int randomChoice = rand() % 10 + 1;

	// Knight attacks first if a number greater than 5 is generator
	if (randomChoice > 5)
	{
		while ((Knight.getHealth() > 0) && (Wizard.getHealth() > 0))
		{
			cout << "===========" << endl;

			cout << "Round: " << counter << endl;
			cout << "------------" << endl;
			int a;
			int d;
			a = Knight.Attack();
			cout << a << endl;
			d = Wizard.Defense();
			cout << "Wizard's Defense: " << d << endl;
			cout << "Damage Taken By Wizard: " << Wizard.Damage(a, d) << endl;
			cout << "Knight's Health: " << Knight.getHealth() << endl;
			cout << "Wizard's Health: " << Wizard.getHealth() << endl;
			cout << endl;
			cout << endl;

			if (Knight.getHealth() <= 0 || Wizard.getHealth() <= 0) {
				break;
			}

			a = 0;
			d = 0;
			a = Wizard.Attack();
			cout << a << endl;
			d = Knight.Defense();
			cout << "Knight's Defense: " << d << endl;
			cout << "Damage Taken By Knight: " << Knight.Damage(a, d) << endl;
			cout << "Knight's Health: " << Knight.getHealth() << endl;
			cout << "Wizard's Health: " << Wizard.getHealth() << endl;
			cout << endl;
			counter++;
		}
	}

	// Otherwise Wizard Attack's first
	else
	{
		while ((Knight.getHealth() > 0) && (Wizard.getHealth() > 0))
		{

			cout << "Round: " << counter << endl;
			cout << "------------" << endl;
			int a;
			int d;
			a = Wizard.Attack();
			cout << "Wizard's Attack: " << a << endl;
			d = Knight.Defense();
			cout << "Knight's Defense: " << d << endl;
			cout << "Damage Taken By Knight: " << Knight.Damage(a, d) << endl;
			cout << "Knight's Health: " << Knight.getHealth() << endl;
			cout << "Wizard's Health: " << Wizard.getHealth() << endl;
			cout << endl;

			if (Knight.getHealth() <= 0 || Wizard.getHealth() <= 0) {
				break;
			}
			a = 0;
			d = 0;
			a = Knight.Attack();
			cout << "Knight's Attack: " << a << endl;
			d = Wizard.Defense();
			cout << "Wizard's Defense: " << d << endl;
			cout << "Damage Taken By Wizard: " << Wizard.Damage(a, d) << endl;
			cout << "Knight's Health: " << Knight.getHealth() << endl;
			cout << "Wizard's Health: " << Wizard.getHealth() << endl;
			cout << endl;
			counter++;
		}
	}

	roundsTotal = counter;
	if (Knight.getHealth() <= 0)
	{
		//cout << "Wizard has won" << endl;
		wizardWins++;
		gameWinner = false;
	}
	else if (Wizard.getHealth() <= 0)
	{
		//cout << "Knight has won" << endl;
		knightWins++;
		gameWinner = true;
	}


	cout << "Wizard's wins: " << wizardWins << endl;
	cout << "Knight's wins: " << knightWins << endl;

	system("pause");
	return gameWinner;
}

void displayWallet() {
	system("cls");
	cout << " ------------------------" << endl;
	cout << "|\t WALLET \t |" << endl;
	cout << " ------------------------" << endl;
	cout << "You have $" << wallet << " in your wallet" << endl;
	system("pause");
}

void betWinner() {
	system("cls");
	int choice;
	cout << "You have $" << wallet << " in your wallet" << endl;

	cout << "Who do you think will win?" << endl;
	cout << "1. Knight" << endl << "2. Wizard" << endl;
	cin >> choice;
	while (choice > 2 || choice < 0) {
		cout << "Wrong choice try again" << endl;
		cin >> choice;
	}
	if (choice == 1) {
		predictKnightWin = true;
		pickedWinner = true;
	}
	else if (choice == 2) {
		predictWizardWin = true;
		pickedWinner = true;
	}

	cout << "How much would you like to bet?: ";
	cin >> betWinnerAmount;
	cout << endl;
	while (betWinnerAmount > wallet || betWinnerAmount < 0) {
		cout << "You can't bet more than you have or bet a negative number. Try Again: ";
		cin >> betWinnerAmount;
	}
}

void betRounds() {
	system("cls");
	cout << "You have $" << wallet << " in your wallet" << endl;
	cout << "How many rounds will the fight take?: ";
	cin >> predictRounds;
	while (predictRounds < 0) {
		cout << "pick a positive number: " << endl;
		cin >> predictRounds;
	}

	cout << "How much would you like to bet?: ";
	cin >> betRoundAmount;
	while (betRoundAmount > wallet || betRoundAmount < 0) {
		cout << "You can't bet more than you have or bet a negative number. Try Again: ";
		cin >> betRoundAmount;
	}
	pickedRounds = true;
}

void calculations(bool didKnightWin) {
	system("cls");
	cout << "Summary" << endl;
	cout << "=======" << endl;
	if (pickedWinner) {
		if (didKnightWin && predictKnightWin) {
			wallet = wallet + betWinnerAmount;
			moneyMade += betWinnerAmount;
			cout << "You made $" << betWinnerAmount << " !" << endl;
		}
		else {
			wallet = wallet - betWinnerAmount;
			moneyLost += betWinnerAmount;
			cout << "You lost $" << betWinnerAmount << endl;
		}
	}

	if (pickedRounds) {
		if (predictRounds == roundsTotal) {
			wallet = wallet + (2 * betRoundAmount);
			moneyMade += (2 * betRoundAmount);
			cout << "You made $" << 2 * betRoundAmount << endl;
		}
		else {
			wallet = wallet - betRoundAmount;
			moneyLost += (2 * betRoundAmount);
			cout << "You lost $" << betRoundAmount << endl;
		}
	}

	cout << endl << "You have $" << wallet << " in your wallet" << endl;
	system("pause");
}

void summary() {
	system("cls");
	cout << "Thanks For Playing!" << endl;
	cout << endl << "Here is your summary" << endl;
	cout << "                    " << endl;
	cout << "Wallet: $" << wallet << endl;
	cout << "Money Made: $" << moneyMade << endl;
	cout << "Money Lost: $" << moneyLost << endl;
	cout << "Net Earnings: $" << moneyMade - moneyLost << endl;
	if ((moneyMade - moneyLost) > 0) {
		cout << "Congrats! You made money!" << endl;
	}
	else if ((moneyMade - moneyLost) == 0) {
		cout << "At least you didn't lost money." << endl;
	}
	else {
		cout << "You're pretty bad at gambling." << endl;
	}
}

void menu() {
	system("cls");
	int menuChoice;
	cout << "Welcome To Fight Club" << endl;
	cout << "=====================" << endl;
	cout << "1. Check Wallet" << endl;
	cout << "2. Bet who is going to win" << endl;
	cout << "3. Bet how many rounds it will take" << endl;
	cout << "4. FIGHT!" << endl;
	cout << "5. Quit" << endl;
	cin >> menuChoice;

	while (menuChoice < 1 || menuChoice > 5) {
		cout << "Pick an option from 1 - 5" << endl;
		cin >> menuChoice;
	}

	if (menuChoice == 1) {
		displayWallet();
		menu();
	}
	else if (menuChoice == 2) {
		betWinner();
		menu();
	}
	else if (menuChoice == 3) {
		betRounds();
		menu();
	}
	else if (menuChoice == 4) {
		bool knightWin = fightClub();
		calculations(knightWin);
		menu();
	}
	else if (menuChoice == 5) {
		summary();
	}
}


int main()
{
	menu();
	system("pause");
	return 0;
}