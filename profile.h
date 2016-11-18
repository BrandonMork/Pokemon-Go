


#ifndef PROFILE_H
#define PROFILE_H

#include <string>

using namespace std;

string outfitColor(ostream&, istream&);
string eyeColor(ostream&, istream&);
string hairColor(ostream&, istream&);
string skinColor(ostream&, istream&);
string gender(ostream&, istream&);

class profile
{
private:

  string user;
  string pass;
  string profOutColor;
  string profEyeColor;
  string profHairColor;
  string profSkinColor;
  string profGender;


public:

  int currentX;
  int currentY;
  profile(string, string, string, string, string, string, string, int, int);
  string getHair() const;
  string getSkin() const;
  string getEye() const;
  string getOutfit() const;
  string getGender() const;
  string getUser() const;
  void setPassword(ostream&, istream&);
  void setHair(ostream&, istream&);
  void setSkin(ostream&, istream&);
  void setEye(ostream&, istream&);
  void setOutfit(ostream&, istream&);
  void setGender(ostream&, istream&);
  void writeProfInfo(ostream&);

};

#endif // PROFILE_H
