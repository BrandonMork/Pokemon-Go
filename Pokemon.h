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

    Pokemon();
    Pokemon(string n, string t, string m2);

    string getName() const;
    string getType() const;
    int getCP() const;
    int getHP() const;
    string getMove1() const;
    string getMove2() const;
    int randCP();
    int randHP();
    string randMove1();
    void randPokemon();
    void writePokeInfo(ostream&);

};
#endif // POKEMON_H

