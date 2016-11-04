#ifndef MYFUNCTIONS_H
#define MYFUNCTIONS_H

#include <string>

using namespace std;

string outfitColor();
string eyeColor();
string hairColor();
string skinColor();
string gender();

class profile
{
  private:
    string user;
    string pass;
    string outColor;
    string eyeColor;
    string hairColor;
    string skinColor;
    string gender;

  public:
    profile(string, string, string, string, string, string, string);
    string getHair() const;
    string getSkin() const;
    string getEye() const;
    string getOutfit() const;
    string getGender() const;
    void setPassword();
    void setHair();
    void setSkin();
    void setEye();
    void setOutfit();
    void setGender();
};

class pokemon
{
  private:
    string type;
    string name;
    double cp;
    double hp;

  public:
    string getType()const;
    string getName()const;
    double getCp()const;
    double getHp()const;
    void setType();
    void setName();
    void setCp();
    void setHp();
};

#endif // MYFUNCTIONS_H
