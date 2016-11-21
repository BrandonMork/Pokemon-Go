#include <iostream>
#include <string>
#include "profile.h"
#include <stdlib.h>

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
  out << "Please choose your outfit color: "
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

profile::profile(string a, string b, string c, string d, string e, string f, string g, int x = 130, int y = 30)
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
  out.clear();
  out << user << endl << pass << endl << profHairColor << endl << profSkinColor
      << endl << profEyeColor << endl << profOutColor << endl << profGender
      << endl << currentX << endl << currentY;


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
