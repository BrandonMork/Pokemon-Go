/*
* Author:                 Brandon Mork, Ryan Keller, Alexander Lee
* Assignment Title:       profile.h
* Assignment Description: The header file for the profile class
* Due Date:               11/29/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/28/2016
*/

/*
  ************************************************
                    Profile
  ************************************************
  - user: string
  - pass: string
  - profOutColor: string
  - profEyeColor: string
  - profHairColor: string
  - profGender: string
  - XP: int
  - numPokemon: int
  - myBack: backpack
  - myPokemon: Pokemon
  - currentX: int
  - currentY: int
  ************************************************
  + profile():
  + getHair() const: string
  + getEye() const: string
  + getOutfit() const: string
  + getGender() const: string
  + getUser() const: string
  + getMapDot() const: ink
  + getPokeball() const: int
  + getPotion() const: int
  + getNumPokemon() const: int
  + setNumPokemon(int): void
  + setPokeball(int): void
  + setPotion(int): void
  + setPotion(int): void
  + setPassword(ostream&, istream&): void
  + setHair(ostream&, istream&): void
  + setEye(ostream&, istream&): void
  + setOutfit(ostream&, istream&): void
  + setGender(ostream&, istream&): void
  + writeProfInfo(ostream&): void
  + Pokestop(): void
  + readPokemon(istream&, int&): void
  + writePokemon(ostream&, int): void
  + avatarDisplay(int, int): void
  + subtrPokeball(): void
  + addPokemon(string, string, int, int, string, string, int): void
  + sortPokemon(ostream&): void
  + poketable(ostream&): void
  ************************************************
*/

#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <iostream>
#include "Pokemon.h"
#include <ctime>

using namespace std;

/*
  Precondition:
          an input stream exists
          an output stream exists
  Postcondition:
          A string, whose message is determined by the user, is returned
  Return:
          string
  Description:
          This function displays a menu for the user to choose the outfit
          color of their avatar in gameplay and reads in their choice
*/
string outfitColor(ostream&, istream&);

/*
  Precondition:
          an input stream exists
          an output stream exists
  Postcondition:
          A string, whose message is determined by the user, is returned
  Return:
          string
  Description:
          This function displays a menu for the user to choose the eye color
          of their avatar in gameplay and reads in their choice
*/
string eyeColor(ostream&, istream&);

/*
  Precondition:
          an input stream exists
          an output stream exists
  Postcondition:
          A string, whose message is determined by the user, is returned
  Return:
          string
  Description:
          This function displays a menu for the user to choose the hair color
          of their avatar in gameplay and reads in their choice
*/
string hairColor(ostream&, istream&);

/*
  Precondition:
          an input stream exists
          an output stream exists
  Postcondition:
          A string, whose message is determined by the user, is returned
  Return:
          string
  Description:
          This function displays a menu for the user to choose the gender
          of their avatar in gameplay and reads in their choice
*/
string gender(ostream&, istream&);

struct backpack
{
    int pokeball;             //  number of pokeballs in the backpack
    int potion;               //  number of potions in the backpack

    backpack(int = 0, int = 0);
};

class profile
{
  private:

    string user;              //  Username of the profile
    string pass;              //  profile password
    string profOutColor;      //  avatar outfit color
    string profEyeColor;      //  avatar eyecolor
    string profHairColor;     //  avatar hair color
    string profGender;        //  avatar gender
    int numPokemon;           //  total pokemon owned by user
    backpack myBack;          //  backpack of pokeballs and potions
    Pokemon myPokemon[25];    //  array of pokemon the user owns


  public:

    int currentX;             //  current X position on map
    int currentY;             //  current Y position on map
    /*
      Precondition:
              none
      Postcondition:
              a profile object is created with the arguments/values passed
              to it
      Return:
              none
      Description:
              This function creates a profile object from the arguments passed
              to it
    */
    profile(string, string, string, string, string, string, int,
            int, backpack);

    /*
      Precondition:
              a profile object exists with a designated hair color
      Postcondition:
              The string stored as the hair color of the profile avatar is
              returned
              The hair color remains unchanged
      Return:
              string
      Description:
              This function grabs and returns the string stored as the hair
              color of the avatar for the profile
    */
    string getHair() const;

    /*
      Precondition:
              a profile object exists with a designated eye color
      Postcondition:
              The string stored as the eye color of the profile avatar is
              returned
              The eye color remains unchanged
      Return:
              string
      Description:
              This function grabs and returns the string stored as the eye
              color of the avatar for the profile
    */
    string getEye() const;

    /*
      Precondition:
              a profile object exists with a designated outfit color
      Postcondition:
              The string stored as the outfit color of the profile avatar is
              returned
              The hair color remains unchanged
      Return:
              string
      Description:
              This function grabs and returns the string stored as the outfit
              color of the avatar for the profile
    */
    string getOutfit() const;

    /*
      Precondition:
              a profile object exists with a designated gender
      Postcondition:
              The string stored as the gender of the profile avatar is
              returned
              The gender remains unchanged
      Return:
              string
      Description:
              This function grabs and returns the string stored as the gender
              of the avatar for the profile
    */
    string getGender() const;

    /*
      Precondition:
              a profile object exists with a designated username
      Postcondition:
              The string stored as the username of the profile avatar is
              returned
              The username remains unchanged
      Return:
              string
      Description:
              This function grabs and returns the string stored as the
              username of the avatar for the profile
    */
    string getUser() const;

    /*
      Precondition:
              a profile object exists with a designated number of pokeballs
              in their backpack
      Postcondition:
              The int stored as the number of pokeballs in the profile is
              returned
              The number of pokeballs remains unchanged
      Return:
              int
      Description:
              This function grabs and returns the int stored as the value of
              pokeball in myBack.
    */
    int getPokeball() const;

    /*
      Precondition:
              a profile object exists with a designated number of potions
              in their backpack
      Postcondition:
              The int stored as the number of potions in the profile is
              returned
              The number of potions remains unchanged
      Return:
              int
      Description:
              This function grabs and returns the int stored as the value of
              potions in myBack.
    */
    int getPotion() const;

    /*
      Precondition:
              a profile object exists with a designated number of pokemon
      Postcondition:
              The int stored as the number of pokemon in the profile is
              returned
              The number of pokemon remains unchanged
      Return:
              int
      Description:
              This function grabs and returns the int stored as the value of
              numPokemon in the profile
    */
    int getNumPokemon() const;

    /*
      Precondition:
              a profile object exists
              an int value exists
      Postcondition:
              numPokemon is changed to the value of the int passed to the
              function
              the int value passed to the function is unchanged
      Return:
              void
      Description:
              This function changes the value of the number of pokemon in the
              profile object
    */
    void setNumPokemon(int);

    /*
      Precondition:
              a profile object exists
              an int value exists
      Postcondition:
              pokeball is changed in myBack to the value of the int passed to
              the function
              the int value passed to the function is unchanged
      Return:
              void
      Description:
              This function changes the value of the number of pokeballs in
              myBack in the profile object
    */
    void setPokeball(int);

    /*
      Precondition:
              a profile object exists
              an int value exists
      Postcondition:
              potion is changed in myBack to the value of the int passed to
              the function
              the int value passed to the function is unchanged
      Return:
              void
      Description:
              This function changes the value of the number of potions in
              myBack in the profile object
    */
    void setPotion(int);

    /*
      Precondition:
              a profile object exists with a designated password
      Postcondition:
              The string stored as the password of the profile avatar is
              changed
      Return:
              void
      Description:
              This function displays a menu for the user to go through the
              process to create/write a new password for their profile
    */
    void setPassword(ostream&, istream&);

    /*
      Precondition:
              a profile object exists
      Postcondition:
              The string stored as the hair color of the profile avatar is
              changed
      Return:
              void
      Description:
              This function calls the function that displays a menu for the
              user to go through the process to determine a new hair color for
              their profile avatar
    */
    void setHair(ostream&, istream&);

    /*
      Precondition:
              a profile object exists
      Postcondition:
              The string stored as the eye color of the profile avatar is
              changed
      Return:
              void
      Description:
              This function calls the function that displays a menu for the
              user to go through the process to determine a new eye color for
              their profile avatar
    */
    void setEye(ostream&, istream&);

    /*
      Precondition:
              a profile object exists
      Postcondition:
              The string stored as the outfit color of the profile avatar is
              changed
      Return:
              void
      Description:
              This function calls the function that displays a menu for the
              user to go through the process to determine a new outfit color
              for their profile avatar
    */
    void setOutfit(ostream&, istream&);

    /*
      Precondition:
              a profile object exists
      Postcondition:
              The string stored as the gender of the profile avatar is
              changed
      Return:
              void
      Description:
              This function calls the function that displays a menu for the
              user to go through the process to determine a new gender for
              their profile avatar
    */
    void setGender(ostream&, istream&);

    /*
      Precondition:
              a profile object exists
      Postcondition:
              The value of pokeball in myBack decrements by 1
      Return:
              void
      Description:
              This function decreases the number of pokeballs in myBack by 1
    */
    void subtrPokeball();

    /*
      Precondition:
              a profile object exists
      Postcondition:
              The value of potion in myBack decrements by 1
      Return:
              void
      Description:
              This function decreases the number of potions in myBack by 1
    */
    void subtrPotion();

    /*
      Precondition:
              a profile object exists
              4 strings and 2 ints exist
      Postcondition:
              The value of teh strings and ints remains unchanged
              A pokemon object is created at the first available spot in the
              myPokemon array
      Return:
              void
      Description:
              This function adds a pokemon object to the array that contains a
              profile's caught pokemon
    */
    void addPokemon(string, string, int, int, string, string);

    /*
      Precondition:
              a profile object exists with all of the attributes having values
      Postcondition:
              All of the attributes of the profile object will be written in
              order to the output stream passed to the function
              The profile attributes remain unchanged
      Return:
              void
      Description:
              This function writes all of the values for the attributes of the
              profile object to the output stream passed to the function
    */
    void writeProfInfo(ostream&);

    void Pokestop();

    /*
      Precondition:
              a profile object exists with an empty pokemon array
              an input stream is declared
              an integer value exists
      Postcondition:
              All of the pokemon in the profile's data file will be
              read in and inserted into the array of pokemon in the profile
              object
      Return:
              void
      Description:
              This function reads in all of the information about the user's
              pokemon from their data file and creates pokemon objects in
              the array of pokemon in the user's profile
    */
    void readPokemon(istream&);

    /*
      Precondition:
              a profile object exists with pokemon objects in the array
              an output stream is declared
              an integer value exists
      Postcondition:
              All of the pokemon in the profile's pokemon array will be
              displayed to the output stream passed to the function
              The int value passed to the function is unchanged
              The pokemon remain unchanged
      Return:
              void
      Description:
              This function writes all information for the pokemon in the
              profile object to the output stream
    */
    void writePokemon(ostream&);

    /*
      Precondition:
              a profile object exists with avatar attributes assigned
      Postcondition:
              The avatar attributes remain unchanged
              The avatar visualization is displayed to stdout
      Return:
              void
      Description:
              This function displays the avatar visualization to the screen
              at a certain coordinate point
    */
    void avatarDisplay(int, int);

    /*
      Precondition:
              a profile object exists
      Postcondition:
              The pokemon objects in myPokemon are unchanged
              The pokemon objects are rearranged in the order that the user
              desires them to be displayed and written
      Return:
              void
      Description:
              This function rearranges the order of the caught pokemon objects
              in the array where they reside and also displays the list of all
              of the pokemon in the array
    */
    void sortPokemon(ostream&);

    /*
      Precondition:
              a profile object exists
      Postcondition:
              The pokemon objects in the array of myPokemon remain unchanged
              The pokemon objects in the myPokemon array are displayed in a
              table with headers
      Return:
              void
      Description:
              This function displays the pokemon objects in A pseudo table to
              the output stream
    */
    void poketable(ostream&);

    /*
      Precondition:
              a profile object exists
              an output stream exists
              an input stream exists
      Postcondition:
              Any number of the pokemon, if any, in myPokemon, may be written
              over and deleted
      Return:
              void
      Description:
              This function displays and numbers the pokemon in myPokemon in a
              pseudo table and then prompts the user to enter a number of a
              pokemon they want to delete or the kill number. If a pokemon
              number is entered, that pokemon object is written over. If the
              kill number is entered, the function ends
    */
    void managePokemon(ostream&, istream&);

};



#endif // PROFILE_H
