#include "PokemonList.h"

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void createPokemonList(ifstream& infile, PokemonList& pokemonList)
{
	string  name, type1, type2;

	while (!infile.eof())
	{
		infile >> name >> type1 >> type2;

		pokemonList.addPokemon(name, type1, type2);
	}
}

void readPokemonData(PokemonList& pokemonList)
{
	ifstream infile;

	infile.open("pokemon_database.txt");

	if (!infile)
	{
		cerr << "Input file does not exist." << endl;
		exit(1);
	}

	createPokemonList(infile, pokemonList);

	infile.close();
}
