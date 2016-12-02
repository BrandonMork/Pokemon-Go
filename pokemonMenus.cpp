/*
* Author:                 Brandon Mork, Ryan Keller, Alexander Lee
* Assignment Title:       pokemonMenus.cpp
* Assignment Description: The implementation file for the pokemon menus header
* Due Date:               11/29/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/28/2016
*/

#include "pokemonMenus.h"
#include "plotter.h"

using namespace std;
Plotter p;
char introMenu(ostream& out, istream& in)
{
  char choice;
  int count = 0;
  do
   {
     count++;

     if (count > 1)
     {
       p.clear();
       out << "Invalid Selection, Please select again...";
     }

     out << "\n\n1. Existing User\n2. New User\n3. Exit Game\n";
     choice = getch();
   }while (choice != '1' && choice != '2' && choice != '3');

  return choice;
}

void newUserCreation(ostream& out, istream& in)
{
  string username;
  string password;
  string userFile;
  string tempPassword;
  ofstream out2;
  int count = 0;

  p.clear();
  out << "Please Enter a Username: ";
  in >> username;

  userFile = username + ".txt";

  out2.open(userFile.c_str());

  //  Password Creation
  do
  {
    if (count > 1)
      out << "\nPasswords do not match...try again...\n";

    out << "Please Enter a Password: ";
    in >> password;
    out << "Please Reenter Password: ";
    in >> tempPassword;
    count++;
  }while (password != tempPassword);

  //  Choosing and Writing Avatar and info to User File
  out2 << username << endl << password << endl;

  p.clear();
  out2 << hairColor(out, in) << endl;
  p.clear();
  out2 << eyeColor(out, in) << endl;
  p.clear();
  out2 << outfitColor(out, in) << endl;
  p.clear();
  out2 << gender(out, in);
}

void gameMenuLoop(ostream& out, istream& in, profile& a)
{
  char choice;
  do
    {
      p.clear();

      choice = gameMainMenu(out, in, a);

      //  Choice for Gameplay
      if (choice == '1')
      {
        mapDisplay(out, a.currentX, a.currentY, a);
      }

      //  Choice for editing profile
      if (choice == '2')
      {
        editProfileMenu(out, in, a);
      }
    }while (choice != '3');
}

char gameMainMenu(ostream& out, istream& in, profile& a)
{
  int count = 0;
  char choice;
  do
  {
    p.clear();
    out << "Welcome " << a.getUser() << "!\n\n"
        << "What would you like to do?";

    if (count > 1)
      out << "\n\nInvalid choice, please try again...";

    out << "\n1. Play\n2. Edit Profile\n3. Exit Game\n";
    choice = getch();

    count++;

  }while (choice != '1' && choice != '2' && choice != '3');

  return choice;
}


void editProfileMenu(ostream& out, istream& in, profile& a)
{
  char choice;
  char avChoice;
  do
  {
    int count = 1;

    //  Menu for attributes to edit
    do
    {
      p.clear();

      if (count > 1)
        out << "Invalid choice, please try again...\n";

      out << "What would you like to change?"
           << "\n1. Password\n2. Avatar\n3. Sort Pokemon\n4. Manage Pokemon"
           << "\n5. Back\n";
      choice = getch();
      count++;

    }while (choice != '1' && choice != '2' && choice != '3' && choice != '4'
            && choice != '5');

    if (choice != '5')
    {
      switch (choice)
      {
        //  Edit Password
        case '1':
          a.setPassword(out, in);
          break;

        //  Edit Avatar
        case '2':
          do
          {
            int count2 = 1;

            //  Menu for Avatar Attribute to Edit
            do
            {
              p.clear();
              a.avatarDisplay(20, 5);
              p.move(0,0);
              p.setColor(white);
              if (count2 > 1)
                out << "Invalid choice, please try again...\n";

              cout << "What would you like to change?"
                   << "\n1. Hair Color\n2. Outfit Color\n3. Eye Color\n"
                   << "4. Gender\n5. Back\n";
              avChoice = getch();

              count2++;
            }while (avChoice != '1' && avChoice != '2' && avChoice != '3' &&
                    avChoice != '4' && avChoice != '5');

            p.clear();
            if (avChoice != '6')
            {
              switch (avChoice)
              {
                case '1':
                  a.setHair(out, in);
                  break;

                case '2':
                  a.setOutfit(out, in);
                  break;

                case '3':
                  a.setEye(out, in);
                  break;

                case '4':
                  a.setGender(out, in);
              }
            }
          }while (avChoice != '5');
          break;

        case '3':
          a.sortPokemon(out);
          break;

        case '4':
          a.managePokemon(out, in);
      }
    }
  }while (choice != '5');
}

