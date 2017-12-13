
#include "Character.h"
#ifndef Wizard_h
#define Wizard_h

class WizardCharacter : public Character
{
public:
	WizardCharacter();
	int getHealth();
	int Attack();
	int Defense();
	int Damage(int a, int d);
protected:
	int health;
	int attack;
	int denfense;
	int magicSpell;
};

WizardCharacter::WizardCharacter()
{
	health = 18;
	attack = 3;
	denfense = 5;
	magicSpell = 10;
}

int WizardCharacter::getHealth()
{
	return health;
}

int WizardCharacter::Attack()
{
	int temp = rand() % 100 + 1;
	int temp2 = 0;

	//cout << "Wizard Attack";
	if (temp > 20)
	{
		//cout << " with Normal Attack: ";
		temp2 = rand() % attack + 1;
		return temp2;
	}
	else if (temp < 20)
	{
		//cout << " with Magic Attack: ";
		temp2 = rand() % magicSpell + 1;
		return temp2;
	}

	return temp2;
}

int WizardCharacter::Defense()
{
	//cout << "Wizard's Defense: ";
	int temp = rand() % denfense + 1;
	return temp;
}

int WizardCharacter::Damage(int a, int d)
{
	//cout << "Damage: ";
	int damage = abs(a - d);
	health = health - damage;
	return damage;
}


#endif /* Wizard_h */
