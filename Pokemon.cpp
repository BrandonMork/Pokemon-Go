/*
* Author:                 Brandon Mork, Ryan Keller, Alexander Lee
* Assignment Title:       Pokemon.cpp
* Assignment Description: The implementation file for the pokemon header
* Due Date:               11/29/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/28/2016
*/

#include "Pokemon.h"

using namespace std;

Pokemon allPokemon[10] = {
              Pokemon("Pikachu", "Electric", "Thunderbolt"),
              Pokemon("Bulbasaur", "Grass", "Razor Leaf"),
              Pokemon("Charmander", "Fire", "Flamethrower"),
              Pokemon("Squirtle", "Water", "Water Gun"),
              Pokemon("Pidgey", "Flying", "Wing Attack"),
              Pokemon("Rattata", "Normal", "Bite"),
              Pokemon("Caterpie", "Bug", "String Shot"),
              Pokemon("Geodude", "Rock", "Rock Throw"),
              Pokemon("Gengar", "Ghost", "Shadow Ball"),
              Pokemon("Alakazam", "Psychic", "Psychic"),
              };


Pokemon::Pokemon()
{
  name = "Pikachu";
  type = "Electric";
  cp = 10;
  hp = 10;
  move1 = "Tackle";
  move2 = "Thunderbolt";
}


Pokemon::Pokemon(string n, string t, string m2)
{
  name = n;
  type = t;
  cp = randCP();
  hp = randHP();
  move1 = randMove1();
  move2 = m2;
}

string Pokemon::getName() const
{
  return name;
}

string Pokemon::getType() const
{
  return type;
}

int Pokemon::getCP() const
{
  return cp;
}

int Pokemon::getHP() const
{
  return hp;
}

string Pokemon::getMove1() const
{
  return move1;
}

string Pokemon::getMove2() const
{
  return move2;
}

int Pokemon::randCP()
{
  srand(time(0));
  return rand() % 991 + 10;
}

int Pokemon::randHP()
{
  srand(time(0));
  return rand() % 91 + 10;
}

string Pokemon::randMove1()
{
  srand(time(0));
  int num = rand() % 4 + 1;
  if(num == 1)
    return "Tackle";
  if(num == 2)
    return "Scratch";
  if(num == 3)
    return "Quick Attack";
  else
    return "Headbutt";
}

void Pokemon::randPokemon()
{
  srand(time(0));
  int num = rand() % 10;

  name = allPokemon[num].getName();
  type = allPokemon[num].getType();
  cp = allPokemon[num].getCP();
  hp = allPokemon[num].getHP();
  move1 = allPokemon[num].getMove1();
  move2 = allPokemon[num].getMove2();

}

void Pokemon::writePokeInfo(ostream& out)
{
  out << name << " " << type << " " << cp << " "
      << hp << " " << move1 << " " << move2 << endl;
}

Pokemon::Pokemon(string a, string b, int c, int d, string e, string f)
{
  name = a;
  type = b;
  cp = c;
  hp = d;
  move1 = e;
  move2 = f;
}



