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
#include "plotter.h"
#include <string>             //  string c_str()
#include <stdlib.h>           //  system
#include "pokemonMenus.h"     //  gameMenuLoop

using namespace std;

int main()
{
  //  Data Abstraction
  Plotter a;
  int count3 = 1;
  char usrChoice;
  int XP = 0;
  int potion = 0;
  int pokeball = 0;
  int xCoor = 130;
  int yCoor = 30;
  int pokemonCount = 0;
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


  if (usrChoice == '1' || usrChoice == '2')
  {
    //  Creation of New User
    if (usrChoice == '2')
    {
      newUserCreation(cout, cin);
    }

    //  Input
    //  Sign in to Account
    do
    {
      a.clear();

      if (count3 > 1)
      {
        in.close();
        cout << "Invalid Username or Password, try again...\n";
      }


      cout << "Sign in. If you do not know your username or password, type in"
           << " 'exit' for username to exit the game.\nUsername: ";
      cin >> username;

      if (username != "exit")
      {
        cout << "Password: ";
        cin >> password;

        userFile = username + ".txt";

        in.open(userFile.c_str());

        in >> username >> tempPassword;
      }

      count3++;

    }while((!in.is_open() || password != tempPassword) && username != "exit");

    if (username != "exit")
    {


      in >> hColor >> sColor >> eColor >> oColor >> gende >> xCoor >> yCoor >> XP >> pokeball >> potion;

      backpack myPack(pokeball, potion);

      profile profile(username, password, hColor, sColor, eColor, oColor, gende, xCoor, yCoor, XP, myPack);

      profile.readPokemon(in, pokemonCount);

      //  Update
      //  Game Menu
      gameMenuLoop(cout, cin, profile);

      out.open(userFile.c_str());
      //  Draw
      profile.writeProfInfo(out);
    }
  }
  system("cls");

  cout << "\nThank You For Playing!! Come Back and Catch 'Em All!!\n\n";

  return 0;

}
