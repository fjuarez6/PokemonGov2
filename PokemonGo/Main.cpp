#include "PokemonList.h"
#include "InputHandler.h"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	PokemonList pokemonList;

	readPokemonData(pokemonList);

	cout << " *** Generation 1 Pokemon ***\n\n";
	cout << pokemonList;
	cout << "\nTotal number of pokemon: " << pokemonList.getTotalNoPokemon() << endl;
	cout << "\n *************************************************\n";

	char answer = 'n';
	cout << "\nWould you like to search for a specific pokemon? (y/n) ";
	cin >> answer;

	while (answer == 'y')
	{
		char selection = '4';
		cout << "\nPlease, make a selection:\n"
			<< " \n    1. Name"
			<< "\n    2. Single type (i.e. Water, Fire, etc.)"
			<< "\n    3. Double type (i.e. Bug Flying, Normal Fairy, etc.)";
		cout << "\n\nYour selection: ";
		cin >> selection;

		string name, type1, type2;
		switch (selection)
		{
		case '1':
			cout << "\nPlease enter the pokemon name: ";
			cin >> name;
			cout << endl;
			pokemonList.printPokemon(name);
			break;
		case '2':
			cout << "\nPlease enter the pokemon type: ";
			cin >> type1;
			cout << endl;
			pokemonList.printPokemonTypes(type1);
			break;
		case '3':
			cout << "\nPlease enter the pokemon (double) type: ";
			cin >> type1 >> type2;
			cout << endl;
			pokemonList.printPokemonTypes(type1, type2);
			break;
		default:
			cout << "\nThere are only 3 selections." << endl;
			break;
		}

		cout << "\nWould you like to search again? (y/n) ";
		cin >> answer;
	}

	cout << endl;
	system("Pause");
	return 0;
}