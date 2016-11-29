/*
* Author:                 Brandon Mork, Ryan Keller, Alexander Lee
* Assignment Title:       profile.cpp
* Assignment Description: The implementation file for the profile class
* Due Date:               11/29/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/28/2016
*/

#include "profile.h"
#include "plotter.h"

using namespace std;

Plotter l;

string outfitColor(ostream& out, istream& in)
{
  char select;
  string color;
  int count = 0;

  do
  {
    if (count > 0)
    {
      l.clear();
      out << "Invalid choice...Please try again\n\n";
    }
    out << "Please choose your outfit color: "
         << "\n1. Red\n2. Yellow\n3. Blue\n";
    select = getch();

    switch (select)
    {
      case '1':
        color = "Red";
        break;
      case '2':
        color = "Yellow";
        break;
      case '3':
        color = "Blue";
    }
    count++;

  }while(select != '1' && select != '2' && select != '3');


  return color;
}

string eyeColor(ostream& out, istream& in)
{
  char select;
  string color;
  int count = 0;

  do
  {
    if (count > 0)
    {
      l.clear();
      out << "Invalid choice...Please try again\n\n";
    }
    out << "Please choose your eye color: "
         << "\n1. Green\n2. Brown\n3. Blue\n";
    select = getch();

    switch (select)
    {
      case '1':
        color = "Green";
        break;
      case '2':
        color = "Brown";
        break;
      case '3':
        color = "Blue";
    }
    count++;

  }while(select != '1' && select != '2' && select != '3');


  return color;
}

string hairColor(ostream& out, istream& in)
{
  char select;
  string color;
  int count = 0;

  do
  {
    if (count > 0)
    {
      l.clear();
      out << "Invalid choice...Please try again\n\n";
    }
    out << "Please choose your hair color: "
         << "\n1. Brown\n2. Blonde\n3. Black\n";
    select = getch();

    switch (select)
    {
      case '1':
        color = "Brown";
        break;
      case '2':
        color = "Blonde";
        break;
      case '3':
        color = "Black";
    }
    count++;

  }while(select != '1' && select != '2' && select != '3');



  return color;
}

string skinColor(ostream& out, istream& in)
{
  char select;
  int count = 0;
  string color;
  do
  {
    if (count > 0)
    {
      l.clear();
      out << "Invalid choice...Please try again\n\n";
    }

    out << "Please choose your skin color: "
       << "\n1. White\n2. Brown\n3. Black\n";
    select = getch();

    switch (select)
    {
      case '1':
        color = "White";
        break;
      case '2':
        color = "Brown";
        break;
      case '3':
        color = "Black";
    }
    count++;

  }while(select != '1' && select != '2' && select != '3');


  return color;
}

string gender(ostream& out, istream& in)
{
  char select;
  string gend;
  int count = 0;

  do
  {
    if (count > 0)
    {
      l.clear();
      out << "Invalid choice...Please try again\n\n";
    }
    out << "Please choose your gender: "
         << "\n1. Male\n2. Female\n";
    select = getch();

    switch (select)
    {
      case '1':
        gend = "Male";
        break;
      case '2':
        gend = "Female";
    }
    count++;

  }while(select != '1' && select != '2');

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

void profile::setNumPokemon(int i)
{
  numPokemon = i;
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

int profile::getNumPokemon() const
{
  return numPokemon;
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
  int i = getNumPokemon();
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

void profile::addPokemon(string a, string b, int c, int d, string e, string f, int i)
{
  /*string name = a,
         type = b,
         move1 = e,
         move2 = f;
  int CP = c,
      HP = d;*/

    myPokemon[i] = Pokemon(a, b, c, d, e, f);
    i++;

    setNumPokemon(i);
  //myPokemon[getNumPokemon()] = Pokemon(a, b, c, d, e, f);*/
  //cout << i;
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

void profile::readPokemon(istream& in, int& i)
{
  string name,
         type,
         move1,
         move2;
  int CP,
      HP;

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
    myPokemon[j].writePokeInfo(out);
  }
}

void profile::avatarDisplay(int x, int y)
{
  Plotter avatar;
  ink hair = darkyellow;
  ink eye = blue;
  ink color = yellow;
  char character;
  Point man[40][20];

  if (profOutColor == "Red")
      color = red;
  else if (profOutColor == "Blue")
      color = blue;
  if (profHairColor == "Black")
      hair = black;
  else if (profHairColor == "Blonde")
      hair = yellow;
  if (profEyeColor == "Green")
      eye = darkgreen;
  else if (profEyeColor == "Brown")
      eye = darkyellow;

  for (int i = 0; i < 20; i ++)
  {
    for (int j = 0; j < 40; j++)
    {
      switch(i)
      {
        case 0:
            if (j > 15 && j < 25)
              man[j][i].color = color;
            else
              man[j][i].color = black;
            break;
        case 1:
            if (j > 15 && j < 25)
              man[j][i].color = color;
            else
              man[j][i].color = black;
            break;
        case 2:
            if (j > 15 && j < 30)
              man[j][i].color = color;
            else
              man[j][i].color = black;
            break;
        case 3:
            if (j > 15 && j < 20)
              man[j][i].color = hair;
            else if (j > 19 && j < 24)
              man[j][i].color = lightgrey;
            else
              man[j][i].color = black;
            if (getGender() == "Female")
            {
              if (j < 16 && j > 13)
              man[j][i].color = hair;
            }
            break;
        case 4:
            if (j == 23 || (j > 18 && j < 22))
              man[j][i].color = lightgrey;
            else if (j == 22)
              man[j][i].color = eye;
            else if (j > 15 && j < 19)
              man[j][i].color = hair;
            else
              man[j][i].color = black;
            if (getGender() == "Female")
            {
              if (j < 16 && j > 13)
              man[j][i].color = hair;
            }
            break;

        case 5:
            if (j < 25 && j > 15)
              man[j][i].color = lightgrey;
            else
              man[j][i].color = black;
            if (getGender() == "Female")
            {
              if (j < 16 && j > 13)
              man[j][i].color = hair;
            }
            break;
        case 6:
            if (j < 24 && j > 15)
              man[j][i].color = lightgrey;

            else
              man[j][i].color = black;
            if (getGender() == "Female")
            {
              if (j < 16 && j > 11)
              man[j][i].color = hair;
            }
            break;
        case 7:
            if (j < 30 && j > 9)
            {
              man[j][i].color = color;
              if (j == 12 || j == 27 || j ==13 || j == 26)
                man[j][i].color = cyan;
              else if (j > 16 && j < 23)
                man[j][i].color = lightgrey;
            }
            else
              man[j][i].color = black;
            break;
        case 8:
            if (j < 30 && j > 9)
            {
              man[j][i].color = color;
              if (j == 12 || j == 27 || j ==13 || j == 26)
                man[j][i].color = cyan;
            }

            else
              man[j][i].color = black;
            break;
        case 9:
            if (j < 30 && j > 9)
            {
              man[j][i].color = color;
              if (j == 13 || j == 26)
                man[j][i].color = cyan;
            }

            else
              man[j][i].color = black;
            break;
        case 10:
            if (j < 30 && j > 9)
            {
              man[j][i].color = color;
              if (j == 13 || j == 26)
                man[j][i].color = cyan;
            }

            else
              man[j][i].color = black;
            break;
        case 11:
            if (j < 30 && j > 9)
            {
              man[j][i].color = color;
              if (j == 13 || j == 26)
                man[j][i].color = black;
            }

            else
              man[j][i].color = black;
            break;
        case 12:
            if (j < 30 && j > 9)
            {
              man[j][i].color = lightgrey;
              if (j < 26 && j > 13)
                man[j][i].color = color;
              if (j == 13 || j == 26)
                man[j][i].color = black;
            }

            else
              man[j][i].color = black;
            break;
        case 13:
            if (j < 26 && j > 13)
              man[j][i].color = color;
            else
              man[j][i].color = black;
            break;
        case 14:
            if (j < 26 && j > 13)
              man[j][i].color = color;
            else
              man[j][i].color = black;
            break;
        case 15:
            if (j < 26 && j > 13)
              man[j][i].color = color;
            else
              man[j][i].color = black;
            break;
        case 16:
            if (j < 26 && j > 13)
              man[j][i].color = color;
            else
              man[j][i].color = black;
            break;
        case 17:
            if (j < 26 && j > 13)
              man[j][i].color = color;
            else
              man[j][i].color = black;
            break;
        case 18:
            if (j < 26 && j > 13)
              man[j][i].color = color;
            else
              man[j][i].color = black;
            break;
        case 19:
            if (j < 28 && j > 11)
              man[j][i].color = white;
            else
              man[j][i].color = black;
            break;
      }
        if (i == 5 && (j == 24 || j == 20))
          character = TOP;
        else if (i == 6 && j > 20 && j < 24)
          character = BOTTOM;
        else if (i == 7 && (j == 10 || j == 29))
          character = BOTTOM;
        else if (i == 13)
          character = BOTTOM;
        else if (i > 14 && i < 20 && j == 20)
          character = RIGHT;
        else
          character = SQUARE;
        avatar.setColor(man[j][i].getColor());
        avatar.plot((j + x), (i + y), character);
    }
  }
}
