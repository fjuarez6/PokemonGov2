#include "Pokemon.h"
ostream& operator<<(ostream& out, const Pokemon& p)
{
	if (p.type2 != "NULL")
	{
		out << p.name << ": " << p.type1 << " " << p.type2 << endl;
	}
	else
	{
		out << p.name << ": " << p.type1 << endl;
	}

	return out;
}

Pokemon::Pokemon()
{}

Pokemon::Pokemon(const string& newName, const string& newType1, const string& newType2)
{
	name = newName;
	type1 = newType1;
	type2 = newType2;
}

string Pokemon::getName() const
{
	return name;
}

string Pokemon::getType1() const
{
	return type1;
}

string Pokemon::getType2() const
{
	return type2;
}

bool Pokemon::operator==(const Pokemon& p)
{
	return (name == p.name && type1 == p.type1 && type2 == p.type2);
}

Pokemon Pokemon::operator=(const Pokemon& p)
{
	if (*this == p)
		cout << "Cannot Copy item to itself.";
	else
	{
		name = p.name;
		type1 = p.type1;
		type2 = p.type2;
	}
	return *this;
}

Pokemon::~Pokemon()
{}