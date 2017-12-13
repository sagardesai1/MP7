
#include "Character.h"
#ifndef Knight_h
#define Knight_h

class KnightCharacter : public Character
{
public:
	KnightCharacter();
	int getHealth();
	int Attack();
	int Defense();
	int Damage(int a, int d);
	void setHealth(int h);
	void setAttack(int a);
	void setDefense(int d);
protected:
	int health;
	int attack;
	int defense;
};

KnightCharacter::KnightCharacter()
{
	health = 20;
	attack = 6;
	defense = 4;
}


void KnightCharacter::setHealth(int h)
{
	health = h;
}

void KnightCharacter::setAttack(int a)
{
	attack = a;
}

void KnightCharacter::setDefense(int d)
{
	defense = d;
}

int KnightCharacter::getHealth()
{
	return health;
}

int KnightCharacter::Attack()
{
	//cout << "Knight Attack: ";
	int temp = rand() % attack + 1;
	return temp;
}

int KnightCharacter::Defense()
{
	//cout << "Knight's Defense: ";
	int temp = rand() % defense + 1;
	return temp;
}

int KnightCharacter::Damage(int a, int d)
{
	//cout << "Damage: ";
	int damage = abs(a - d);
	health = health - damage;
	return damage;
}

#endif /* Knight_h */
