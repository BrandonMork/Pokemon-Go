#include <iostream>
#include <string>
#include "profile.h"
#include <cstdlib>
#include <ctime>

using namespace std;

string outfitColor(ostream& out, istream& in)
{
  int select;
  string color;
  out << "Please choose your outfit color: "
       << "\n1. Red\n2. Yellow\n3. Blue\n";
  in >> select;

  switch (select)
  {
    case 1:
      color = "Red";
      break;
    case 2:
      color = "Yellow";
      break;
    case 3:
      color = "Blue";
  }

  return color;
}

string eyeColor(ostream& out, istream& in)
{
  int select;
  string color;
  out << "Please choose your eye color: "
       << "\n1. Green\n2. Brown\n3. Blue\n";
  in >> select;

  switch (select)
  {
    case 1:
      color = "Green";
      break;
    case 2:
      color = "Brown";
      break;
    case 3:
      color = "Blue";
  }

  return color;
}

string hairColor(ostream& out, istream& in)
{
  int select;
  string color;
  out << "Please choose your hair color: "
       << "\n1. Brown\n2. Blonde\n3. Black\n";
  in >> select;

  switch (select)
  {
    case 1:
      color = "Brown";
      break;
    case 2:
      color = "Blonde";
      break;
    case 3:
      color = "Black";
  }

  return color;
}

string skinColor(ostream& out, istream& in)
{
  int select;
  string color;
  out << "Please choose your skin color: "
       << "\n1. White\n2. Brown\n3. Black\n";
  in >> select;

  switch (select)
  {
    case 1:
      color = "White";
      break;
    case 2:
      color = "Brown";
      break;
    case 3:
      color = "Black";
  }

  return color;
}

string gender(ostream& out, istream& in)
{
  int select;
  string gend;
  out << "Please choose your gender: "
       << "\n1. Male\n2. Female\n";
  in >> select;

  switch (select)
  {
    case 1:
      gend = "Male";
      break;
    case 2:
      gend = "Female";

  }

  return gend;
}

profile::profile(string a, string b, string c, string d, string e, string f, string g, int x, int y, int xp, backpack mypack)
{
  user = a;
  pass = b;
  profHairColor = c;
  profSkinColor = d;
  profEyeColor = e;
  profOutColor = f;
  profGender = g;
  currentX = x;
  currentY = y;
  XP = xp;
  myBack = mypack;
}
void profile::setHair(ostream& out, istream& in)
{
  profHairColor = hairColor(out, in);
}

void profile::setEye(ostream& out, istream& in)
{
  profEyeColor = eyeColor(out, in);
}

void profile::setSkin(ostream& out, istream& in)
{
  profSkinColor = skinColor(out, in);
}

void profile::setGender(ostream& out, istream& in)
{
  profGender = gender(out, in);
}

void profile::setOutfit(ostream& out, istream& in)
{
  profOutColor = outfitColor(out, in);
}

void profile::setPassword(ostream& out, istream& in)
{
  string oldPass;
  string newPass;
  string testNewPass;
  int count = 1;

  do
  {
    system("cls");
    if (count > 1)
      out << "Password incorrect, please try again...\n\n";

    out << "Please enter old password. If you cant remember, type in 'back':";
    in >> oldPass;

    count++;

  }while(oldPass != pass && oldPass != "back");

  if (oldPass == pass)
  {
    system("cls");
    count = 1;
    do
    {
      if (count > 1)
        out << "\nPasswords do not match...try again...\n";

      out << "Please Enter a Password: ";
      in >> newPass;
      out << "Please Reenter Password: ";
      in >> testNewPass;
      count++;
    }while (newPass != testNewPass);

    pass = newPass;
  }

}

string profile::getUser() const
{
  return user;
}
string profile::getHair() const
{
  return profHairColor;
}
string profile::getSkin() const
{
  return profSkinColor;
}
string profile::getEye() const
{
  return profEyeColor;
}
string profile::getOutfit() const
{
  return profOutColor;
}
string profile::getGender() const
{
  return profGender;
}

void profile::writeProfInfo(ostream& out)
{
  int i = 1;
  out.clear();
  out << user << endl << pass << endl << profHairColor << endl << profSkinColor
      << endl << profEyeColor << endl << profOutColor << endl << profGender
      << endl << currentX << endl << currentY << endl << XP << endl
      << myBack.pokeball << endl << myBack.potion << endl;

  writePokemon(out, i);
}

backpack::backpack(int a, int b)
{
  pokeball = a;
  potion = b;
}

int profile::getPokeball() const
{
  return myBack.pokeball;
}

int profile::getPotion() const
{
  return myBack.potion;
}

void profile::setPokeball(int x)
{
  myBack.pokeball = x;
}

void profile::setPotion(int x)
{
 myBack.potion = x;
}

void profile::Pokestop()
{
  time_t now = time(0);
  static time_t last = 0;

  if(now - last <= 0)
  {
    srand(time(NULL));
    myBack.pokeball += rand() % 4;
    myBack.potion += rand() % 4;
    last = now;
  }

}

void profile::readPokemon(istream& in)
{
  string name,
         type,
         move1,
         move2;
  int CP,
      HP,
      i = 0;

  while(in >> name >> type >> CP >> HP >> move1 >> move2)
  {
    myPokemon[i] = Pokemon(name, type, CP, HP, move1, move2);
    i++;
  }
}

void profile::writePokemon(ostream& out, int i)
{
  for(int j = 0; j < i; j++)
  {
    out << myPokemon[j].getName() << " " << myPokemon[j].getType() << " "
        << myPokemon[j].getCP() << " " << myPokemon[j].getHP() << " "
        << myPokemon[j].getMove1() << " " << myPokemon[j].getMove2() << "\n";
  }
}
