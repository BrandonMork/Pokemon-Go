/*
* Author:                 Brandon Mork, Ryan Keller, Alexander Lee
* Assignment Title:       pokemonMenus.h
* Assignment Description: The header file for main menu customization
* Due Date:               12/2/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/30/2016
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
        char
  Description:
        Display the first main menu with the user able to leave the game,
        log in, or create a new user by hitting a key and returning it
*/
char introMenu(ostream&, istream&);

/*
  Precondition:
        an input stream has been declared
        an output stream has been declared
  Postcondiditon:
        "username".txt is created
        avatar with attributes is created
  Return:
        void
  Description:
        Display each avatar attribute to the user and have them decide which
        attribute they would like to have.Also creates the username and
        password for the profile and creates the user file.

*/
void newUserCreation(ostream&, istream&);

/*
  Precondition:
        an input stream has been declared
        an output stream has been declared
        profile is passed through parameters
  Postcondiditon:
        Map is created or profile menu is called or game closes
        profile attributes are changed as necessary by the processes called
  Return:
        void
  Description:
        Depending on the user's choice, either the map is created,
        the edit profile menu is displayed, or the game closes
*/
void gameMenuLoop(ostream&, istream&, profile&);

/*
  Precondition:
        an input stream has been declared
        an output stream has been declared
        profile is passed through parameters
  Postcondiditon:
        a char is returned
        profile attributes are changed as necessary by the processes called
  Return:
        char
  Description:
        Display a menu after the user creates their account to play, edit
        profile or exit game and return the character of selection
*/
char gameMainMenu(ostream&, istream&, profile&);

/*
  Precondition:
        an input stream has been declared
        an output stream has been declared
        a profile object has been passed through parameters
  Postcondiditon:
        Display menu for the user to decide what they would like to change in
        their profile.
        profile attributes are changed as necessary by the processes called
  Return:
        void
  Description:
        Allows the user to edit their profile,passwords, or delete pokemon.
        The option to sort pokemon is selected in this menu as well.
*/
void editProfileMenu(ostream&, istream&, profile&);


#endif // POKEMONMENUS_H
