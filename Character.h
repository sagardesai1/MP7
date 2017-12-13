
#ifndef Character_h
#define Character_h
#include <iostream>
#include <string>
#include <cmath>
#include <time.h>

using namespace std;

class Character
{
public:
	virtual int Attack() = 0;
	virtual int Defense() = 0;
	virtual int Damage(int a, int d) = 0;
	string getName();
	void setname(string n);
protected:
	string name;
	int health;
	int attack;
	int defense;
};

string Character::getName()
{
	return name;
}

void Character::setname(string n)
{
	name = n;
}


#endif /* Character_h */