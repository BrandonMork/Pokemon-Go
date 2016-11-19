/*
  Authors:                Ryan Keller, Brandon Mork, Alex Lee
  Assignment Title:       Pokemon Go
  Assignment Description: This is a program that contains the game code for
                          Pokemon Go
  Due Date:               12/3/16
  Date Created:           11/7/16
  Date Last Modified:     11/18/16
*/

/*
  Data Abstraction:

  Input:

  Process:

  Output:

  Assumptions:

*/

#include <iostream>           //  cin >> cout <<
#include <fstream>            //  open close
#include "profile.h"          //  profile writeProfInfo
#include <string>             //  string c_str()
#include <stdlib.h>           //  system
#include "pokemonMenus.h"     //  gameMenuLoop

using namespace std;

int main()
{
  //  Data Abstraction
  int count3 = 1;
  int usrChoice;
  int xCoor = 0;
  int yCoor = 0;
  string userFile;
  string password;        //  stores password for account
  string tempPassword;    //  stores password to test validation of password
  string username;        //  stores username
  string hColor;          //  stores hair color
  string eColor;          //  stores eye color
  string oColor;          //  stores outfit color
  string sColor;          //  stores skin color
  string gende;           //  stores gender
  ifstream in;
  ofstream out;



  cout << "Welcome to Pokemon GO!!";

  //  Login screen

  usrChoice = introMenu(cout, cin);


  if (usrChoice == 1 || usrChoice == 2)
  {
    //  Creation of New User
    if (usrChoice == 2)
    {
      newUserCreation(cout, cin);
    }

    //  Input
    //  Sign in to Account
    do
    {
      system("cls");

      if (count3 > 1)
      {
        in.close();
        cout << "Invalid Username or Password, try again...\n";
      }


      cout << "Sign in. If you do not know\nUsername: ";
      cin >> username;
      cout << "Password: ";
      cin >> password;

      userFile = username + ".txt";

      in.open(userFile.c_str());

      in >> username >> tempPassword;

      count3++;

    }while(!in.is_open() || password != tempPassword);

    out.open(userFile.c_str());

    in >> hColor >> sColor >> eColor >> oColor >> gende >> xCoor >> yCoor;

    profile profile(username, password, hColor, sColor, eColor, oColor, gende, xCoor, yCoor);

    //  Update
    //  Game Menu
    gameMenuLoop(cout, cin, profile);

    //  Draw
    profile.writeProfInfo(out);

  }
  system("cls");

  cout << "\nThank You For Playing!! Come Back and Catch 'Em All!!\n\n";

  return 0;

}
