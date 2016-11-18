#include "Pokemon.h"
#include <cstdlib>
#include <time.h>

using namespace std;

Pokemon::Pokemon()
{
  name = "Pikachu";
  type = "Electric";
  cp = 50;
  hp = 50;
  move1 = "Tackle";
  move2 = "Thunderbolt";
}

void Pokemon::setName(string n)
{
  name = n;
}

string Pokemon::getName() const
{
  return name;
}

void Pokemon::setType(string t)
{
  type = t;
}

string Pokemon::getType() const
{
  return type;
}

void Pokemon::setCP(int c)
{
  cp = c;
}

int Pokemon::getCP() const
{
  return cp;
}

void Pokemon::setHP(int h)
{
  hp = h;
}

int Pokemon::getHP() const
{
  return hp;
}

void Pokemon::setMove1(string m)
{
  move1 = m;
}

string Pokemon::getMove1() const
{
  return move1;
}

void Pokemon::setMove2(string m)
{
  move2 = m;
}

string Pokemon::getMove2() const
{
  return move2;
}

int Pokemon::randCP()
{
  srand(time(0));
  return rand() % 1001 + 10;
}

int Pokemon::randHP()
{
  srand(time(0));
  return rand() % 101 + 50;
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
  if(num == 4)
    return "Headbutt";
}

void Pokemon::randPokemon()
{
  srand(time(0));
  int num = rand() % 4 + 1;
  if(num == 1)
  {
    name = "Pikachu";
    type = "Electric";
    cp = randCP();
    hp = randHP();
    move1 = randMove1();
    move2 = "Thunderbolt";
  }
  if(num == 2)
  {
    name = "Bulbasaur";
    type = "Grass";
    cp = randCP();
    hp = randHP();
    move1 = randMove1();
    move2 = "Razor Leaf";
  }
  if(num == 3)
  {
    name = "Charmander";
    type = "Fire";
    cp = randCP();
    hp = randHP();
    move1 = randMove1();
    move2 = "Flamethrower";
  }
  if(num == 4)
  {
    name = "Squirtle";
    type = "Water";
    cp = randCP();
    hp = randHP();
    move1 = randMove1();
    move2 = "Water Gun";
  }
}
