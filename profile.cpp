/*
* Author:                 Brandon Mork, Ryan Keller, Alexander Lee
* Assignment Title:       profile.cpp
* Assignment Description: The implementation file for the profile class
* Due Date:               12/2/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/30/2016
*/

#include "profile.h"
#include "plotter.h"
#include <iomanip>

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

profile::profile(string a, string b, string c, string e, string f,
                 string g, int x, int y, backpack mypack)
{
  user = a;
  pass = b;
  profHairColor = c;
  profEyeColor = e;
  profOutColor = f;
  profGender = g;
  currentX = x;
  currentY = y;
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
  out << user << endl << pass << endl << profHairColor << endl
      << profEyeColor << endl << profOutColor << endl << profGender << endl
      << currentX << endl << currentY << endl << myBack.pokeball << endl
      << myBack.potion << endl;

  writePokemon(out);
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

void profile::subtrPokeball()
{
  if (myBack.pokeball > 0)
    myBack.pokeball -= 1;
}

void profile::subtrPotion()
{
  if (myBack.potion > 0)
    myBack.potion -= 1;
}

void profile::addPokemon(string a, string b, int c, int d, string e, string f)
{
  myPokemon[numPokemon] = Pokemon(a, b, c, d, e, f);
  numPokemon++;
}

void profile::managePokemon(ostream& out, istream& in)
{
  int select;
  int count;
  do
  {
    count = 0;
    do
    {
      l.clear();
      out << setw(4) << " " << left << setw(12) << "NAME" << setw(10)
          << "TYPE" << setw(6) << "CP" << setw(6) << "HP" << setw(15)
          << "MOVE 1" << setw(15) << "MOVE 2" << endl;

      for(int j = 0; j < numPokemon; j++)
      {
        out << (j + 1) << ". ";
        if (j < 9)
          out << " ";
        myPokemon[j].writePokeInfo(out);
      }
      if(count > 0)
        out << "Invalid number....Please Enter Another";

      out << "\n\nType in the number of the pokemon you would like to send "
          << "to the Professor and press 'ENTER'.\n\nIf you want to exit, "
          << "enter '99'";
      in >> select;

      count++;

    }while(select < 0 || (select > numPokemon && select != 99));

    if (select != 99)
    {
      for (; select < numPokemon; select++)
        myPokemon[select - 1] = myPokemon[select];

      numPokemon--;
    }

  }while(select != 99);
}

void profile::Pokestop()
{
  unsigned int now = int(time(0));
  static int last = now - 30;

  if(now - last >= 30)
  {
    srand(time(NULL));
    myBack.pokeball += (rand() % 4) + 1;
    myBack.potion += (rand() % 4) + 1;
    last = now;
  }

}

void profile::readPokemon(istream& in)
{
  numPokemon = 0;
  string name,
         type,
         move1,
         move2;
  int CP,
      HP;

  while(in >> name >> type >> CP >> HP >> move1 >> move2)
  {
    myPokemon[numPokemon] = Pokemon(name, type, CP, HP, move1, move2);
    numPokemon++;
  }
}

void profile::writePokemon(ostream& out)
{
  for(int j = 0; j < numPokemon; j++)
  {
    myPokemon[j].writePokeInfo(out);
  }
}

void profile::poketable(ostream& out)
{
  out << left << setw(12) << "NAME" << setw(10) << "TYPE" << setw(6) << "CP"
      << setw(6) << "HP" << setw(15) << "MOVE 1" << setw(15) << "MOVE 2"
      << endl;

  writePokemon(out);
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

void profile::sortPokemon(ostream& out)
{
  char choice;
  int count;
  int pokeCounter;
  Pokemon temp;
  bool swap;

  do
  {
    l.clear();
    pokeCounter = 0;
    count = 0;
    do
    {

      if (count > 0)
      {
        l.clear();
        out << "Invalid choice...Please try again\n\n";
      }
      out << "What would you like to sort by?\n1. Name\n2. CP\n3. HP\n"
          << "4. Go Back\n";

      poketable(out);

      choice = getch();
      count++;

    }while(choice != '1' && choice != '2' && choice != '3' && choice != '4');

    switch (choice)
    {
      case '1':
        do
        {
          swap = false;
          for (int i = 0; i < (numPokemon - 1); i++)
          {

            if (myPokemon[i].getName()[0] > myPokemon[i + 1].getName()[0])
            {
              temp = myPokemon[i + 1];
              myPokemon[i + 1] = myPokemon[i];
              myPokemon[i] = temp;
              swap = true;
            }
            else if (myPokemon[i].getName()[0]
                     == myPokemon[i + 1].getName()[0])
            {
              if (myPokemon[i].getCP() > myPokemon[i + 1].getCP())
              {
                temp = myPokemon[i + 1];
                myPokemon[i + 1] = myPokemon[i] ;
                myPokemon[i] = temp;
                swap = true;
              }
              else if (myPokemon[i].getCP() == myPokemon[i + 1].getCP())
              {
                if (myPokemon[i].getHP() > myPokemon[i + 1].getHP())
                {
                  temp = myPokemon[i + 1];
                  myPokemon[i + 1] = myPokemon[i] ;
                  myPokemon[i] = temp;
                  swap = true;
                }
              }
            }
          }
        }while(swap == true);
        break;

      case '2':
        do
        {
          swap = false;
          for(int i = 0; i < (numPokemon - 1); i++)
          {
            if (myPokemon[i].getCP() > myPokemon[i + 1].getCP())
            {
              temp = myPokemon[i + 1];
              myPokemon[i + 1] = myPokemon[i];
              myPokemon[i] = temp;
              swap = true;
            }
            else if(myPokemon[i].getCP() == myPokemon[i + 1].getCP())
            {
              if (myPokemon[i].getName()[0] > myPokemon[i + 1].getName()[0])
              {
                temp = myPokemon[i + 1];
                myPokemon[i + 1] = myPokemon[i];
                myPokemon[i] = temp;
                swap = true;
              }
              else if (myPokemon[i].getName()[0]
                       == myPokemon[i + 1].getName()[0])
              {
                if (myPokemon[i].getHP() > myPokemon[i + 1].getHP())
                {
                  temp = myPokemon[i + 1];
                  myPokemon[i + 1] = myPokemon[i];
                  myPokemon[i] = temp;
                  swap = true;
                }
              }
            }
          }
        }while (swap == true);
        break;

      case '3':
        do
        {
          swap = false;
          for(int i = 0; i < (numPokemon - 1); i++)
          {
            if (myPokemon[i].getHP() > myPokemon[i + 1].getHP())
            {
              temp = myPokemon[i + 1];
              myPokemon[i + 1] = myPokemon[i];
              myPokemon[i] = temp;
              swap = true;
            }
            else if(myPokemon[i].getHP() == myPokemon[i + 1].getHP())
            {
              if (myPokemon[i].getName()[0] > myPokemon[i + 1].getName()[0])
              {
                temp = myPokemon[i + 1];
                myPokemon[i + 1] = myPokemon[i];
                myPokemon[i] = temp;
                swap = true;
              }
              else if (myPokemon[i].getName()[0]
                       == myPokemon[i + 1].getName()[0])
              {
                if (myPokemon[i].getCP() > myPokemon[i + 1].getCP())
                {
                  temp = myPokemon[i + 1];
                  myPokemon[i + 1] = myPokemon[i];
                  myPokemon[i] = temp;
                  swap = true;
                }
              }
            }
          }
        }while (swap == true);
    }
  }while (choice != '4');

}
