#ifndef PROFILE_H
#define PROFILE_H
#include <string>
#include "Pokemon.h"
#include "plotter.h"

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
    string getSkin() const;
    string getEye() const;
    string getOutfit() const;
    string getGender() const;
    string getUser() const;
    ink getMapDot() const;
    int getPokeball() const;
    int getPotion() const;
    int getNumPokemon() const;
    void setNumPokemon(int);
    void setPokeball(int);
    void setPotion(int);
    void setPassword(ostream&, istream&);
    void setHair(ostream&, istream&);
    void setSkin(ostream&, istream&);
    void setEye(ostream&, istream&);
    void setOutfit(ostream&, istream&);
    void setGender(ostream&, istream&);
    void writeProfInfo(ostream&);
    void Pokestop();
    void readPokemon(istream&, int&);
    void writePokemon(ostream&, int);

};



#endif // PROFILE_H
