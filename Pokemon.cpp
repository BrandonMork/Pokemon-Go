#include "Pokemon.h"
#include <cstdlib>
#include <time.h>

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

Pokemon::Pokemon(string n, string t, int c, int h, string m1, string m2)
{
  name = n;
  type = t;
  cp = c;
  hp = h;
  move1 = m1;
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
  int num = rand() % 10 + 1;
  /*
  If you take away the "+ 1" from up there you can use "num" as the array
  cell assigner so you can make it simpler and clean......RK

  The changed code is commented below for implementation when everyone sees

  name = allPokemon[num].getName();
  type = allPokemon[num].getType();
  cp = allPokemon[num].getCP();
  hp = allPokemon[num].getHP();
  move1 = allPokemon[num].getMove1();
  move2 = allPokemon[num].getMove2();
  */
  if(num == 1)
  {
    name = allPokemon[0].getName();
    type = allPokemon[0].getType();
    cp = allPokemon[0].getCP();
    hp = allPokemon[0].getHP();
    move1 = allPokemon[0].getMove1();
    move2 = allPokemon[0].getMove2();
  }
  if(num == 2)
  {
    name = allPokemon[1].getName();
    type = allPokemon[1].getType();
    cp = allPokemon[1].getCP();
    hp = allPokemon[1].getHP();
    move1 = allPokemon[1].getMove1();
    move2 = allPokemon[1].getMove2();
  }
  if(num == 3)
  {
    name = allPokemon[2].getName();
    type = allPokemon[2].getType();
    cp = allPokemon[2].getCP();
    hp = allPokemon[2].getHP();
    move1 = allPokemon[2].getMove1();
    move2 = allPokemon[2].getMove2();
  }
  if(num == 4)
  {
    name = allPokemon[3].getName();
    type = allPokemon[3].getType();
    cp = allPokemon[3].getCP();
    hp = allPokemon[3].getHP();
    move1 = allPokemon[3].getMove1();
    move2 = allPokemon[3].getMove2();
  }
  if(num == 5)
  {
    name = allPokemon[4].getName();
    type = allPokemon[4].getType();
    cp = allPokemon[4].getCP();
    hp = allPokemon[4].getHP();
    move1 = allPokemon[4].getMove1();
    move2 = allPokemon[4].getMove2();
  }
  if(num == 6)
  {
    name = allPokemon[5].getName();
    type = allPokemon[5].getType();
    cp = allPokemon[5].getCP();
    hp = allPokemon[5].getHP();
    move1 = allPokemon[5].getMove1();
    move2 = allPokemon[5].getMove2();
  }
  if(num == 7)
  {
    name = allPokemon[6].getName();
    type = allPokemon[6].getType();
    cp = allPokemon[6].getCP();
    hp = allPokemon[6].getHP();
    move1 = allPokemon[6].getMove1();
    move2 = allPokemon[6].getMove2();
  }
  if(num == 8)
  {
    name = allPokemon[7].getName();
    type = allPokemon[7].getType();
    cp = allPokemon[7].getCP();
    hp = allPokemon[7].getHP();
    move1 = allPokemon[7].getMove1();
    move2 = allPokemon[7].getMove2();
  }
  if(num == 9)
  {
    name = allPokemon[8].getName();
    type = allPokemon[8].getType();
    cp = allPokemon[8].getCP();
    hp = allPokemon[8].getHP();
    move1 = allPokemon[8].getMove1();
    move2 = allPokemon[8].getMove2();
  }
  if(num == 10)
  {
    name = allPokemon[9].getName();
    type = allPokemon[9].getType();
    cp = allPokemon[9].getCP();
    hp = allPokemon[9].getHP();
    move1 = allPokemon[9].getMove1();
    move2 = allPokemon[9].getMove2();
  }
}

void Pokemon::writePokeInfo(ostream& out)
{
  /*out << name << " " << type << " " << cp << " "
      << hp << " " << move1 << " " << move2 << "\n";*/
}
