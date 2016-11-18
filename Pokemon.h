using namespace std;

#ifndef POKEMON_H
#define POKEMON_H
#include <string>

class Pokemon
{
  private:
    string name;
    string type;
    int cp;
    int hp;
    string move1;
    string move2;
  public:
    //constructor
    Pokemon();

    void setName(string n);
    string getName() const;

    void setType(string t);
    string getType() const;

    void setCP(int c);
    int getCP() const;

    void setHP(int h);
    int getHP() const;

    void setMove1(string m);
    string getMove1() const;

    void setMove2(string m);
    string getMove2() const;

    int randCP();
    int randHP();
    string randMove1();
    void randPokemon();



};
#endif // POKEMON_H
