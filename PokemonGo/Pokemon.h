/*
Juarez, Freddy
CS A200
August 31, 2016

Class Pokemon
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <iostream>
using namespace std;

class Pokemon
{
	friend ostream& operator<<(ostream& out, const Pokemon& p);

public:
	Pokemon();
	Pokemon(const string& newName, const string& newType1, const string& newType2);

	string getName() const;
	string getType1() const;
	string getType2() const;

	bool operator==(const Pokemon& p);
	Pokemon operator=(const Pokemon& p);

	~Pokemon();

private:
	string name;
	string type1;
	string type2;
};

#endif // !POKEMON_H
