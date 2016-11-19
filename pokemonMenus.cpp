#include <fstream>
#include <iostream>
#include "profile.h"
#include <stdlib.h>
#include "plotter.h"
#include "pokemonMenus.h"
#include <conio.h>

using namespace std;
Plotter a;
int introMenu(ostream& out, istream& in)
{
  int choice;
  int count = 0;
  do
   {
     count++;

     if (count > 1)
       out << "Invalid Selection, Please select again...";

     out << "\n\n1. Existing User\n2. New User\n3. Exit Game\n";
     in >> choice;
   }while (choice < 1 && choice > 3);

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

  system("cls");
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

  a.clear();
  out2 << hairColor(out, in) << endl;
  system("cls");
  out2 << skinColor(out, in) << endl;
  system("cls");
  out2 << eyeColor(out, in) << endl;
  system("cls");
  out2 << outfitColor(out, in) << endl;
  system("cls");
  out2 << gender(out, in);
}

void gameMenuLoop(ostream& out, istream& in, profile& a)
{
  int count;
  int choice;
  do
    {
      system("cls");

      count = 1;

      choice = gameMainMenu(out, in, a);

      //  Choice for Gameplay
      if (choice == 1)
      {
        mapDisplay(out, a.currentX, a.currentY);
      }

      //  Choice for editing profile
      if (choice == 2)
      {
        editProfileMenu(out, in, a);
      }
    }while (choice != 3);
}

int gameMainMenu(ostream& out, istream& in, profile& a)
{
  int count = 0;
  int choice;
  do
  {
    out << "Welcome " << a.getUser() << "!\n\n" << "What would you like to do?";

    if (count > 1)
      out << "\n\nInvalid choice, please try again...";

    out << "\n1. Play\n2. Edit Profile\n3. Exit Game\n";
    in >> choice;

    count++;

  }while (choice < 1 && choice > 3);

  return choice;
}


void editProfileMenu(ostream& out, istream& in, profile& a)
{
  int choice;
  int avChoice;
  do
  {
    int count = 1;

    //  Menu for attributes to edit
    do
    {
      system("cls");

      if (count > 1)
        out << "Invalid choice, please try again...\n";

      out << "What would you like to change?"
           << "\n1. Password\n2. Avatar\n3. Back\n";
      in >> choice;
      count++;

    }while (choice < 1 && choice > 3);

    if (choice != 3)
    {
      switch (choice)
      {
        //  Edit Password
        case 1:
          a.setPassword(out, in);
          break;

        //  Edit Avatar
        case 2:
          do
          {
            int count2 = 1;

            //  Menu for Avatar Attribute to Edit
            do
            {
              system("cls");

              if (count2 > 1)
                out << "Invalid choice, please try again...\n";

              out << "What would you like to change?"
                   << "\n1. Hair Color\n2. Outfit Color\n3. Eye Color\n4. Skin"
                   << "Color\n5. Gender\n6. Back\n";
              in >> avChoice;

              count2++;
            }while (avChoice < 1 && avChoice > 6);


            if (avChoice != 6)
            {
              switch (avChoice)
              {
                case 1:
                  a.setHair(out, in);
                  break;

                case 2:
                  a.setOutfit(out, in);
                  break;

                case 3:
                  a.setEye(out, in);
                  break;

                case 4:
                  a.setSkin(out, in);
                  break;

                case 5:
                  a.setGender(out, in);
              }
            }
          }while (avChoice != 6);
      }
    }
  }while (choice != 3);
}
