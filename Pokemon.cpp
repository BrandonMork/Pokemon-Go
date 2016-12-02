/*
* Author:                 Ryan Keller, Brandon Mork, Alex Lee
* Assignment Title:       Pokemon.cpp
* Assignment Description: The implementation file for the pokemon header
* Due Date:               12/2/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/30/2016
*/

#include "Pokemon.h"
#include "plotter.h"
#include <iomanip>

using namespace std;

Pokemon allPokemon[10] = {
              Pokemon("Pikachu", "Electric", "Thunderbolt"),
              Pokemon("Charmander", "Fire", "Flamethrower"),
              Pokemon("Squirtle", "Water", "Water_Gun"),
              Pokemon("Haunter", "Ghost", "Shadow_Ball"),
              Pokemon("Kakuna", "Bug", "Struggle"),
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
    return "Quick_Attack";
  else
    return "Headbutt";
}

void Pokemon::randPokemon()
{
  srand(time(0));
  int num = rand() % 5;

  name = allPokemon[num].getName();
  type = allPokemon[num].getType();
  cp = allPokemon[num].getCP();
  hp = allPokemon[num].getHP();
  move1 = allPokemon[num].getMove1();
  move2 = allPokemon[num].getMove2();

}

void Pokemon::writePokeInfo(ostream& out)
{
  out << left << setw(12) << name << setw(10) << type << setw(6) << cp
      << setw(6) << hp << setw(15) << move1 << setw(15) << move2 << endl;
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

void Pokemon::displayPokemon( int x, int y)
{
  if (name == "Squirtle")
    displaySquirtle(x, y);
  else if (name == "Pikachu")
    displayPikachu(x, y);
  else if (name == "Kakuna")
    displayKakuna(x, y);
  else if (name == "Charmander")
    displayCharmander(x, y);
  else if (name == "Haunter")
    displayHaunter(x, y);

}

void Pokemon::clearPokeData()
{
  name.clear();
  type.clear();
  move1.clear();
  move2.clear();
  //hp.clear();
  //cp.clear();
}

void clearPokemon(int x, int y)
{
  Plotter p;
  p.setColor(black);
  for (int i = 0; i < 30; i++)
  {
    for (int j = 0; j < 30; j++)
      p.plot((j + x), (i + y), SQUARE);
  }
}

void displayPikachu(int x, int y)
{
  Plotter a;
  Point Pikachu [19][19];
  for(int i = 0;i < 19;i ++)
  {
    for(int j = 0;j < 19; j++)
    {
      switch(i)
      {
        case 0:
          Pikachu[j][i].color = black;
          break;
        case 1:
          if(j == 16)
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 2:
          if((j > 14 && j < 18) || j == 5)
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 3:
          if((j > 13 && j < 18) || (j > 3 && j < 6))
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 4:
          if((j > 13 && j < 17) || (j > 3 && j < 6) || (j > 10 && j < 13))
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 5:
          if((j > 12 && j < 16) || (j > 2 && j < 7) || (j > 8 && j < 12))
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 6:
          if((j > 1 && j < 11) || (j > 12 && j < 15))
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 7:
          if((j > 1 && j < 10) || (j > 13 && j < 16))
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 8:
          if((j > 1 && j < 11) || j == 15)
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 9:
          if((j > 0 && j < 5) || (j > 6 && j < 12) || (j > 12 && j < 15))
            Pikachu[j][i].color = yellow;
          else if(j == 5)
            Pikachu[j][i].color = white;
          else
            Pikachu[j][i].color = black;
          break;
        case 10:
          if((j > 1 && j < 5) || (j > 8 && j < 12) || (j > 12 && j < 15))
            Pikachu[j][i].color = yellow;
          else if(j > 6 && j < 9)
            Pikachu[j][i].color = red;
          else
            Pikachu[j][i].color = black;
          break;
        case 11:
          if((j > 2 && j < 7) || (j > 7 && j < 13))
            Pikachu[j][i].color = yellow;
          else if(j == 7)
            Pikachu[j][i].color = red;
          else
            Pikachu[j][i].color = black;
          break;
        case 12:
          if((j > 1 && j < 13))
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 13:
          if((j > 3 && j < 9) || (j > 9 && j < 13))
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 14:
          if((j > 3 && j < 8) || (j > 8 && j < 13))
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 15:
          if((j > 4 && j < 9) || (j > 9 && j < 13) || j == 3)
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 16:
          if((j > 6 && j < 12))
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 17:
          if(j == 10)
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
        case 18:
          if(j > 8 && j < 12)
            Pikachu[j][i].color = yellow;
          else
            Pikachu[j][i].color = black;
          break;
      }
      a.setColor(Pikachu[j][i].getColor());
      a.plot(j + x, i + y, SQUARE);
    }
  }
}


void displayKakuna(int x, int y)
{
  Plotter a;
  Point Kakuna[17][17];

  for(int i = 0; i < 17; i++)
  {
    for(int j = 0; j < 17; j++)
    {
      switch(i)
      {
        case 0:
          Kakuna[j][i].color = black;
          break;
        case 1:
          if(j > 6 && j < 11)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 2:
          if(j > 4 && j <13)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 3:
          if(j > 4 && j <14)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 4:
          if((j > 5 && j <15) || j == 4)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 5:
          if((j > 5 && j <15) || j == 4)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 6:
          if((j > 5 && j <9) || j == 4 || (j > 11 && j < 14))
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 7:
          if((j > 4 && j <8) || (j > 10 && j < 13))
            Kakuna[j][i].color = yellow;
          else if(j == 9)
            Kakuna[j][i].color = white;
          else
            Kakuna[j][i].color = black;
          break;
        case 8:
          if((j > 6 && j <11) || j == 13)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 9:
          if((j > 10 && j <14) || j == 6)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 10:
          if(j > 6 && j <14)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 11:
          if(j > 6 && j <13)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 12:
          if(j > 7 && j <13)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 13:
          if(j > 7 && j <12)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 14:
          if(j > 8 && j <12)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 15:
          if(j > 8 && j <11)
            Kakuna[j][i].color = yellow;
          else
            Kakuna[j][i].color = black;
          break;
        case 16:
          Kakuna[j][i].color = black;
      }
      a.setColor(Kakuna[j][i].getColor());
      a.plot((j + x), (i + y), SQUARE);
    }
  }
}

void displayCharmander(int x, int y)
{
  Plotter a;
  Point Charmander[21][16];

  for(int i = 0; i < 16; i++)
  {
    for(int j = 0; j < 21; j++)
    {
      switch(i)
      {
        case 0:
          if((j > 4 && j < 9) || j == 18)
            Charmander[j][i].color = red;
          else
            Charmander[j][i].color = black;
          break;

        case 1:
          if((j > 3 && j < 10) || (j > 17 && j < 20))
            Charmander[j][i].color = red;
          else
            Charmander[j][i].color = black;
          break;

        case 2:
          if((j > 3 && j < 10) || (j > 17 && j < 20))
            Charmander[j][i].color = red;
          else
            Charmander[j][i].color = black;
          break;

        case 3:
          if((j > 2 && j < 11) || j == 19 || (j > 16 && j < 21))
            Charmander[j][i].color = red;
          else
            Charmander[j][i].color = black;
          break;

        case 4:
          if((j > 1 && j < 6) || (j > 7 && j < 11) ||
             (j > 16 && j < 19) || j == 20)
            Charmander[j][i].color = red;
          else if(j == 19)
            Charmander[j][i].color = yellow;
          else if(j == 6)
            Charmander[j][i].color = white;
          else
            Charmander[j][i].color = black;
          break;

        case 5:
          if((j > 1 && j < 6) || (j > 7 && j < 12) || j == 17 || j == 20)
            Charmander[j][i].color = red;
          else if(j > 17 && j < 20)
            Charmander[j][i].color = yellow;
          else
            Charmander[j][i].color = black;
          break;

        case 6:
          if(j > 1 && j < 12)
            Charmander[j][i].color = red;
          else if(j == 18)
            Charmander[j][i].color = yellow;
          else
            Charmander[j][i].color = black;
          break;

        case 7:
          if((j > 2 && j < 13) || j == 18)
            Charmander[j][i].color = red;
          else
            Charmander[j][i].color = black;
          break;

        case 8:
          if((j > 4 && j < 14) || (j > 16 && j < 19))
            Charmander[j][i].color = red;
          else
            Charmander[j][i].color = black;
          break;

        case 9:
          if((j > 7 && j < 10) || (j > 10 && j < 14) || (j > 15 && j < 18))
            Charmander[j][i].color = red;
          else
            Charmander[j][i].color = black;
          break;

        case 10:
          if(j > 9 && j < 18)
            Charmander[j][i].color = red;
          else if(j > 6 && j < 9)
            Charmander[j][i].color = yellow;
          else
            Charmander[j][i].color = black;
          break;

        case 11:
          if(j > 11 && j < 17)
            Charmander[j][i].color = red;
          else if(j > 6 && j < 10)
            Charmander[j][i].color = yellow;
          else
            Charmander[j][i].color = black;
          break;

        case 12:
          if((j > 10 && j < 15) || j == 6)
            Charmander[j][i].color = red;
          else if(j > 7 && j < 11)
            Charmander[j][i].color = yellow;
          else
            Charmander[j][i].color = black;
          break;

        case 13:
          if(j > 10 && j < 14)
            Charmander[j][i].color = red;
          else if(j > 8 && j < 11)
            Charmander[j][i].color = yellow;
          else
            Charmander[j][i].color = black;
          break;

        case 14:
          if(j == 12)
            Charmander[j][i].color = red;
          else
            Charmander[j][i].color = black;
          break;

        case 15:
          if(j > 10 && j < 14)
            Charmander[j][i].color = red;
          else
            Charmander[j][i].color = black;
          break;
      }

      a.setColor(Charmander[j][i].getColor());
      a.plot(j + x, i + y, SQUARE);
    }
  }
}

void displayHaunter(int x, int y)
{
  Plotter a;
  Point Haunter [30][19];
  for(int i = 0;i < 19;i ++)
  {
    for(int j = 0;j < 30; j++)
    {
      switch(i)
      {
        case 0:
          Haunter[j][i].color = black;
          break;
        case 1:
          if(j > 7 && j < 13)
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 2:
          if((j > 5 && j < 16) || (j > 0 && j < 3) || (j > 18 && j < 21))
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 3:
          if((j > 4 && j < 14) || (j > 0 && j < 4) || (j > 16 && j < 21))
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 4:
          if((j > 3 && j < 12) || (j == 2) || (j > 13 && j < 20))
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 5:
          if(j > 1 && j < 19)
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 6:
          if((j > 2 && j < 18) || (j > 18 && j < 21))
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 7:
          if((j > 2 && j < 12) || (j > 20 && j < 23) || (j > 24 && j < 27))
            Haunter[j][i].color = purple;
          else if((j > 12 && j < 17))
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 8:
          if((j > 2 && j < 10) || (j > 21 && j < 27) ||
             (j > 12 && j < 21) || j == 1)
            Haunter[j][i].color = purple;
          else if(j == 12)
            Haunter[j][i].color = white;
          else
            Haunter[j][i].color = black;
          break;
        case 9:
          if((j > 2 && j < 9) || (j > 20 && j < 26) || (j > 12 && j < 18))
            Haunter[j][i].color = purple;
          else if(j < 13 && j > 10)
            Haunter[j][i].color = white;
          else
            Haunter[j][i].color = black;
          break;
        case 10:
          if((j > 3 && j < 8) || (j > 18 && j < 26) || (j > 12 && j < 16))
            Haunter[j][i].color = purple;
          else if((j < 13 && j > 10) || j == 9)
            Haunter[j][i].color = white;
          else
            Haunter[j][i].color = black;
          break;
        case 11:
          if((j > 3 && j < 8) || (j > 18 && j < 25) || (j > 11 && j < 18))
            Haunter[j][i].color = purple;
          else if(j < 12 && j > 8)
            Haunter[j][i].color = white;
          else
            Haunter[j][i].color = black;
          break;
        case 12:
          if((j > 3 && j < 13) || (j > 19 && j < 24) || (j > 14 && j < 19))
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 13:
          if((j > 5 && j < 10) || (j > 19 && j < 22))
            Haunter[j][i].color = purple;
          else if(j == 13)
            Haunter[j][i].color = red;
          else
            Haunter[j][i].color = black;
          break;
        case 14:
          if((j > 16 && j < 20))
            Haunter[j][i].color = purple;
          else if(j > 10 && j < 13)
            Haunter[j][i].color = red;
          else
            Haunter[j][i].color = black;
          break;
        case 15:
          if((j > 12 && j < 17) || j == 3 || j == 5)
            Haunter[j][i].color = purple;
          else if(j > 6 && j < 12)
            Haunter[j][i].color = red;
          else
            Haunter[j][i].color = black;
          break;
        case 16:
          if((j > 11 && j < 18) || j == 3 || (j > 4 && j < 7))
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 17:
          if((j > 13 && j < 18) || j == 5 || j == 12)
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
        case 18:
          if(j == 12 || j == 14 || j == 17)
            Haunter[j][i].color = purple;
          else
            Haunter[j][i].color = black;
          break;
      }
      a.setColor(Haunter[j][i].getColor());
      a.plot((j + x), (i + y), SQUARE);
    }
  }
}

void displaySquirtle(int x, int y)
{
  Plotter a;
  Point Squirtle[21][15];

  for(int i = 0; i < 15; i++)
  {
    for(int j = 0; j < 21; j++)
    {
      switch(i)
      {
        case 0:
          if((j > 3 && j < 8) || (j > 16 && j < 19))
            Squirtle[j][i].color = cyan;
          else
            Squirtle[j][i].color = black;
          break;

        case 1:
          if((j > 2 && j < 10) || (j > 15))
            Squirtle[j][i].color = cyan;
          else
            Squirtle[j][i].color = black;
          break;

        case 2:
          if((j > 2 && j < 10) || (j > 15 && j < 19) || j > 19)
            Squirtle[j][i].color = cyan;
          else if(j == 11)
            Squirtle[j][i].color = darkyellow;
          else
            Squirtle[j][i].color = black;
          break;

        case 3:
          if((j > 2 && j < 11) || (j > 14 && j < 18) || (j > 18))
            Squirtle[j][i].color = cyan;
          else if(j > 10 && j < 14)
            Squirtle[j][i].color = darkyellow;
          else
            Squirtle[j][i].color = black;
          break;

        case 4:
          if((j > 1 && j < 6) || (j > 7 && j < 11) ||
             (j > 15 && j < 18) || (j == 19))
            Squirtle[j][i].color = cyan;
          else if(j == 6 || j == 11)
            Squirtle[j][i].color = white;
          else if(j > 11 && j < 15)
            Squirtle[j][i].color = darkyellow;
          else
            Squirtle[j][i].color = black;
          break;

        case 5:
          if((j > 1 && j < 6) || (j > 7 && j < 11) || j == 16)
            Squirtle[j][i].color = cyan;
          else if(j == 11)
            Squirtle[j][i].color = white;
          else if(j > 11 && j < 15)
            Squirtle[j][i].color = darkyellow;
          else
            Squirtle[j][i].color = black;
          break;

        case 6:
          if((j > 3 && j < 11))
            Squirtle[j][i].color = cyan;
          else if(j == 12)
            Squirtle[j][i].color = white;
          else if(j > 12 && j < 16)
            Squirtle[j][i].color = darkyellow;
          else
            Squirtle[j][i].color = black;
          break;

        case 7:
          if((j > 4 && j < 9) || (j > 10 && j < 13))
            Squirtle[j][i].color = cyan;
          else if(j == 13)
            Squirtle[j][i].color = white;
          else if(j > 13 && j < 16)
            Squirtle[j][i].color = darkyellow;
          else
            Squirtle[j][i].color = black;
          break;

        case 8:
          if(j == 4 || (j > 8 && j < 13))
            Squirtle[j][i].color = cyan;
          else if(j == 13)
            Squirtle[j][i].color = white;
          else if(j > 13 && j < 16)
            Squirtle[j][i].color = darkyellow;
          else
            Squirtle[j][i].color = black;
          break;

        case 9:
          if(j > 5 && j < 8)
            Squirtle[j][i].color = yellow;
          else if(j > 8 && j < 12)
            Squirtle[j][i].color = cyan;
          else if(j == 13)
            Squirtle[j][i].color = white;
          else if(j > 13 && j < 16)
            Squirtle[j][i].color = darkyellow;
          else
            Squirtle[j][i].color = black;
          break;

        case 10:
          if(j > 6 && j < 9)
            Squirtle[j][i].color = yellow;
          else if(j == 13)
            Squirtle[j][i].color = white;
          else if(j > 13 && j < 16)
            Squirtle[j][i].color = darkyellow;
          else
            Squirtle[j][i].color = black;
          break;

        case 11:
          if(j > 7 && j < 13)
            Squirtle[j][i].color = yellow;
          else if(j == 14)
            Squirtle[j][i].color = white;
          else if(j == 6)
            Squirtle[j][i].color = cyan;
          else
            Squirtle[j][i].color = black;
          break;

        case 12:
          if(j > 9 && j < 12)
            Squirtle[j][i].color = yellow;
          else if(j == 14)
            Squirtle[j][i].color = white;
          else if(j == 12)
            Squirtle[j][i].color = cyan;
          else
            Squirtle[j][i].color = black;
          break;

        case 13:
          if(j > 10 && j < 13)
            Squirtle[j][i].color = cyan;
          else
            Squirtle[j][i].color = black;
          break;

        case 14:
          Squirtle[j][i].color = black;
          break;

        case 15:
          Squirtle[j][i].color = black;
          break;

      }
     a.setColor(Squirtle[j][i].getColor());
     a.plot((j + x), (i + y), SQUARE);
    }
  }
}


