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
  - profSkinColor: string
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
  + getSkin() const: string
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
  + setSkin(ostream&, istream&): void
  + setEye(ostream&, istream&): void
  + setOutfit(ostream&, istream&): void
  + setGender(ostream&, istream&): void
  + writeProfInfo(ostream&): void
  + Pokestop(): void
  + readPokemon(istream&, int&): void
  + writePokemon(ostream&, int): void
  ************************************************
*/

#ifndef PROFILE_H
#define PROFILE_H

#include <string>
#include <iostream>
#include "Pokemon.h"
#include "plotter.h"
#include <ctime>

using namespace std;

string outfitColor(ostream&, istream&);
string eyeColor(ostream&, istream&);
string hairColor(ostream&, istream&);
string skinColor(ostream&, istream&);
string gender(ostream&, istream&);

struct backpack
{
    int pokeball;
    int potion;

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
    string profSkinColor;     //  avatar race/ethnicity
    string profGender;        //  avatar gender
    int XP;                   //  profile XP
    int numPokemon;           //  total pokemon owned by user
    backpack myBack;          //  backpack of pokeballs and potions
    Pokemon myPokemon[250];   //  array of pokemon the user owns


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
    profile(string, string, string, string, string, string, string, int, int, int, backpack);

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
              a profile object exists with a designated race/ethnicity color
      Postcondition:
              The string stored as the skin color of the profile avatar is
              returned
              The skin color remains unchanged
      Return:
              string
      Description:
              This function grabs and returns the string stored as the skin
              color of the avatar for the profile
    */
    string getSkin() const;

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
              a profile object exists with a designated outfit color
              An ink color that corresponds with the avatars outfit color
              exists
      Postcondition:
              The ink color that corresponds to the outfit color of the avatar
              is returned
              The outfit color remains unchanged
      Return:
              ink
      Description:
              This function grabs the string stored as the outfit color, finds
              the ink variable that corresponds to the same color as the
              avatar outfit, and returns that ink
    */
    ink getMapDot() const;

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
              The string stored as the skin color of the profile avatar is
              changed
      Return:
              void
      Description:
              This function calls the function that displays a menu for the
              user to go through the process to determine a new skin color for
              their profile avatar
    */
    void setSkin(ostream&, istream&);

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
    void readPokemon(istream&, int&);

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
    void writePokemon(ostream&, int);

    void avatarDisplay(int, int);

};



#endif // PROFILE_H
