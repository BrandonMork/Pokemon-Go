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
  Input:

  Update:

  Draw:
*/

#include <iostream>           //  cin >> cout <<
#include <fstream>            //  open close
#include "profile.h"          //  profile writeProfInfo
#include "plotter.h"          //  plotter clear
#include <string>             //  string c_str()
#include <stdlib.h>           //  system
#include "pokemonMenus.h"     //  gameMenuLoop

using namespace std;

int main()
{
  //  Data Abstraction
  Plotter a;              //  the map plotter
  int count = 1;         //  count to make sure user signs in
  char usrChoice;         //  the choice the user enters
  int potion = 0;         //  number of potions
  int pokeball = 0;       //  number of pokeballs
  int xCoor = 130;        //  the default x coordinate
  int yCoor = 30;         //  the default y coordinate
  string userFile;        //  name of the file for the user
  string password;        //  stores password for account
  string tempPassword;    //  stores password to test validation of password
  string username;        //  stores username
  string hColor;          //  stores hair color
  string eColor;          //  stores eye color
  string oColor;          //  stores outfit color
  string gende;           //  stores gender
  ifstream in;            //  input file stream object
  ofstream out;           //  output file stream object



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

      if (count > 1)
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
      count++;

    }while((!in.is_open() || password != tempPassword) && username != "exit");

    if (username != "exit")
    {


      in >> hColor >> eColor >> oColor >> gende >> xCoor >> yCoor
         >> pokeball >> potion;

      backpack myPack(pokeball, potion);

      profile profile(username, password, hColor, eColor, oColor,
                      gende, xCoor, yCoor, myPack);

      profile.readPokemon(in);

      //  Update
      //  Game Menu
      gameMenuLoop(cout, cin, profile);

      out.open(userFile.c_str());
      //  Draw
      profile.writeProfInfo(out);
    }
  }
  a.clear();

  cout << "\nThank You For Playing!! Come Back and Catch 'Em All!!\n\n";

  return 0;

}
