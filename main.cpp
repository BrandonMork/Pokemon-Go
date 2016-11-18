//this is a test

#include <iostream>           //  cin >> cout << endl
#include <fstream>            //  open close
#include <iomanip>
#include "profile.h"
#include <string>             //  string c_str()
#include <stdlib.h>
#include "plotter.h"

using namespace std;

int main()
{
  //  Data Abstraction
  int count1 = 0;
  int count2 = 1;
  int count3 = 1;
  int count4;
  int count5;
  int count6;
  int usrChoice;
  int editChoice;
  int avChoice = 0;
  string userFile;
  string password;        //  stores password for account
  string tempPassword;    //  stores password to test validation of password
  string username;        //  stores username
  string hColor;          //  stores hair color
  string eColor;          //  stores eye color
  string oColor;          //  stores outfit color
  string sColor;          //  stores skin color
  string gende;           //  stores gender
  //
  string message;
  ifstream in;
  ofstream out;



  cout << "Welcome to Pokemon GO!!";

  //  Login screen
  do
  {
    count1++;

    if (count1 > 1)
      cout << "Invalid Selection, Please select again...";

    cout << "\n\n1. Existing User\n2. New User\n3. Exit Game\n";
    cin >> usrChoice;
  }while (usrChoice < 1 && usrChoice > 3);

  if (usrChoice == 1 || usrChoice == 2)
  {
    //  Creation of New User
    if (usrChoice == 2)
    {
      system("cls");
      cout << "Please Enter a Username: ";
      cin >> username;

      userFile = username + ".txt";

      out.open(userFile.c_str());

      //  Password Creation
      do
      {
        if (count2 > 1)
          cout << "\nPasswords do not match...try again...\n";

        cout << "Please Enter a Password: ";
        cin >> password;
        cout << "Please Reenter Password: ";
        cin >> tempPassword;
      }while (password != tempPassword);

      //  Choosing and Writing Avatar and info to User File
      out << username << endl << password << endl;

      cout.flush();
      out << hairColor(cout, cin) << endl;
      system("cls");
      out << skinColor(cout, cin) << endl;
      system("cls");
      out << eyeColor(cout, cin) << endl;
      system("cls");
      out << outfitColor(cout, cin) << endl;
      system("cls");
      out << gender(cout, cin);
    }

    //  Sign in to Account
    do
    {
      system("cls");

      if (count3 > 1)
      {
        in.close();
        cout << "Invalid Username or Password, try again...\n";
      }


      cout << "Sign in.\nUsername: ";
      cin >> username;
      cout << "Password: ";
      cin >> password;

      userFile = username + ".txt";

      in.open(userFile.c_str());

      in >> username >> tempPassword;

      count3++;

    }while(!in.is_open() || password != tempPassword);

    out.open(userFile.c_str());

    in >> hColor >> sColor >> eColor >> oColor >> gende;

    profile profile(username, password, hColor, sColor, eColor, oColor, gende);

    //  Game Menu
    do
    {
      system("cls");

      count4 = 1;

      do
      {
        cout << "Welcome " << username << "!\n\n" << "What would you like to do?";

        if (count4 > 1)
          cout << "\n\nInvalid choice, please try again...";

        cout << "\n1. Play\n2. Edit Profile\n3. Exit\n";
        cin >> usrChoice;
      }while (usrChoice < 1 && usrChoice > 3);


      //  Choice for Gameplay
      if (usrChoice == 1)
      {
        mapDisplay();
      }

      //  Choice for editing profile
      if (usrChoice == 2)
      {
        do
        {
          count5 = 1;

          //  Menu for attributes to edit
          do
          {
            system("cls");

            if (count5 > 1)
              cout << "Invalid choice, please try again...\n";

            cout << "What would you like to change?"
                 << "\n1. Password\n2. Avatar\n3. Back\n";
            cin >> editChoice;

          }while (editChoice < 1 && editChoice > 3);

          if (editChoice != 3)
          {
            switch (editChoice)
            {
              //  Edit Password
              case 1:
                profile.setPassword();

              //  Edit Avatar
              case 2:
                do
                {
                  count6 = 1;

                  //  Menu for Avatar Attribute to Edit
                  do
                  {
                    system("cls");

                    if (count6 > 1)
                      cout << "Invalid choice, please try again...\n";

                    cout << "What would you like to change?"
                         << "\n1. Hair Color\n2. Outfit Color\n3. Eye Color\n4. Skin"
                         << "Color\n5. Gender\n6. Back\n";
                    cin >> avChoice;

                    count6++;
                  }while (avChoice < 1 && avChoice > 6);


                  if (avChoice != 6)
                  {
                    switch (avChoice)
                    {
                      case 1:
                        profile.setHair(cout, cin);
                        break;

                      case 2:
                        profile.setOutfit(cout, cin);
                        break;

                      case 3:
                        profile.setEye(cout, cin);
                        break;

                      case 4:
                        profile.setSkin(cout, cin);
                        break;

                      case 5:
                        profile.setGender(cout, cin);
                    }
                  }
                }while (avChoice != 6);
            }
          }
        }while (editChoice != 3);
      }
    }while (usrChoice != 3);

    profile.writeProfInfo(out);
  }
  system("cls");



  cout << "\nThank You For Playing!! Come Back and Catch 'Em All!!\n\n";

  return 0;





}
