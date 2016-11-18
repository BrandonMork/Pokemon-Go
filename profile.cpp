#include <iostream>
#include <string>
#include "profile.h"

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

profile::profile(string a, string b, string c, string d, string e, string f, string g)
{
  user = a;
  pass = b;
  profHairColor = c;
  profSkinColor = d;
  profEyeColor = e;
  profGender = g;
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

void profile::setPassword()
{

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
  out << user << endl << pass << endl << profHairColor << endl << profSkinColor
      << endl << profEyeColor << endl << profOutColor << endl << profGender
      << endl;


}
