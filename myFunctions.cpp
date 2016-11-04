#include <iostream>
#include <string>
#include "myFunctions.h"

using namespace std;

string outfitColor()
{
  int select;
  string color;
  cout << "Please choose your outfit color: "
       << "\n1. Red\n2. Yellow\n3. Blue\n";
  cin >> select;

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

string eyeColor()
{
  int select;
  string color;
  cout << "Please choose your eye color: "
       << "\n1. Green\n2. Brown\n3. Blue\n";
  cin >> select;

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

string hairColor()
{
  int select;
  string color;
  cout << "Please choose your hair color: "
       << "\n1. Brown\n2. Blonde\n3. Black\n";
  cin >> select;

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

string skinColor()
{
  int select;
  string color;
  cout << "Please choose your skin color: "
       << "\n1. White\n2. Brown\n3. Black\n";
  cin >> select;

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

string gender()
{
  int select;
  string gend;
  cout << "Please choose your outfit color: "
       << "\n1. Male\n2. Female\n";
  cin >> select;

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
  hairColor = c;
  skinColor = d;
  eyeColor = e;
  outColor = f;
  gender = g;
}
void profile::setHair()
{
  hairColor = "green";
}

void profile::setEye()
{
  eyeColor = "green";
}

void profile::setSkin()
{
  skinColor = "green";
}

void profile::setGender()
{
  gender = "green";
}

void profile::setOutfit()
{
  outColor = "green";
}

void profile::setPassword()
{

}

string profile::getHair() const
{
  return hairColor;
}
string profile::getSkin() const
{
  return skinColor;
}
string profile::getEye() const
{
  return eyeColor;
}
string profile::getOutfit() const
{
  return outColor;
}
string profile::getGender() const
{
  return gender;
}
