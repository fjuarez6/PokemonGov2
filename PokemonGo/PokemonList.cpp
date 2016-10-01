#include "PokemonList.h"
#include "Pokemon.h"


ostream& operator<<(ostream& out, const PokemonList& list)
{
	int num = 1;

	for (int i = 0; i < list.getTotalNoPokemon(); ++i)
	{
		if (i < 9)
			out << num << "       " << list.ptr[i];
		else if (i >= 10 && i < 99)
			out << num << "      " << list.ptr[i];
		else if (i >= 100)
			out << num << "     " << list.ptr[i];

		++num;
	}

	return out;
}

PokemonList::PokemonList()
{
	listCapacity = 200;
	ptr = new Pokemon[listCapacity];
	totalPokemon = 0;
}

void PokemonList::addPokemon(const string& newName, const string& newType1, const string& newType2)
{
	if (totalPokemon > listCapacity)
	{
		cerr << "Trying to excide capacity." << endl;
	}
	else
	{
		ptr[totalPokemon] = Pokemon(newName, newType1, newType2);
		++totalPokemon;
	}
}

int PokemonList::getTotalNoPokemon() const
{
	return totalPokemon;
}

int PokemonList::getCapacity() const
{
	return listCapacity;
}

void PokemonList::printPokemon(const string& name)
{
	//if (totalPokemon == 0)
	//{
	//	cerr << "There are no pokemons in the list.";
	//}
	//else
	//{
	//	int i = 0;
	//	bool found = false;

	//	while (i < totalPokemon && !found)
	//	{
	//		if (ptr[i].getName() == name)
	//		{
	//			cout << ptr[i];
	//			found = true;
	//		}
	//		else
	//		{
	//			++i;
	//		}
	//	}

	//	if (i > totalPokemon)
	//	{
	//		cout << name << " is not in the list." << endl;
	//	}
	//}

	int index = 0;

	if (search(name, index))
		cout << ptr[index];
	else
		cout << name << " is not in the list." << endl;
}

void PokemonList::printPokemonTypes(const string& type) const
{
	if (totalPokemon == 0)
	{
		cerr << "There are no pokemons in the list.";
	}
	else
	{
		int i = 0;
		bool found = false;

		while (i < totalPokemon)
		{
			if (ptr[i].getType1() == type || ptr[i].getType2() == type)
			{
				cout << ptr[i];
				found = true;
			}

			++i;
		}

		if (!found)
		{
			cout << "No Pokemon is of type " << type << "." << endl;
		}
	}
}

void PokemonList::printPokemonTypes(const string& type1, const string& type2)
{
	if (totalPokemon == 0)
	{
		cerr << "There are no pokemons in the list.";
	}
	else
	{
		int i = 0;
		bool found = false;

		while (i < totalPokemon)
		{
			if (ptr[i].getType1() == type1 && ptr[i].getType2() == type2)
			{
				cout << ptr[i];
				found = true;
			}
			
			++i;
		}

		if (!found)
		{
			cout << "No Pokemon is of type " << type1 << " " << type2 << "." << endl;
		}
	}
}

bool PokemonList::search(const string& name, int &index)
{
	bool ex;

	do
	{
		ex = false;

		for (int i = 0; i < totalPokemon -1 ; ++i)
		{
			if (ptr[i].getName() > ptr[i + 1].getName())
			{
				Pokemon *temp = new Pokemon(ptr[i].getName(), ptr[i].getType1(), ptr[i].getType2());
				ptr[i] = ptr[i + 1];
				ptr[i + 1] = *temp;
				ex = true;
			}
		}
	} while (ex);

	int first = 1;
	int last = totalPokemon;

	return binarySearch(name, index, first, last);
}

bool PokemonList::binarySearch(const string& name, int &index, int first, int last) const
{
	bool found = false;

	if (first > last)
	{
		index = -1;
		return found;
	}
	else
	{
		int mid = (first + last) / 2;

		if (name == ptr[mid - 1].getName())
		{
			index = mid - 1;
			found = true;
			return found;
		}
		else if (name < ptr[mid - 1].getName())
			return binarySearch(name, index, first, mid - 1);
		else
			return binarySearch(name, index, mid + 1, last);
	}
}

void PokemonList::clearList()
{
	delete[] ptr;
	ptr = nullptr;
	totalPokemon = 0;
}

PokemonList::~PokemonList()
{
	clearList();
}