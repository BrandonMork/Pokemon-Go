/*
* Author:                 Brandon Mork, Ryan Keller, Alexander Lee
* Assignment Title:       pokemonMenus.h
* Assignment Description: The header file for main menu customization
* Due Date:               11/29/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/28/2016
*/

#ifndef POKEMONMENUS_H
#define POKEMONMENUS_H

#include <fstream>
#include "profile.h"

/*
  Precondition:
        an input stream has been declared
        an output stream has been declared
  Postcondiditon:
        a char is returned

  Return:

  Description:
*/
char introMenu(ostream&, istream&);

void newUserCreation(ostream&, istream&);

void gameMenuLoop(ostream&, istream&, profile&);

char gameMainMenu(ostream&, istream&, profile&);

void editProfileMenu(ostream&, istream&, profile&);


#endif // POKEMONMENUS_H
