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
    //constructors
    Pokemon();
    Pokemon(string n, string t, string m2);
    /*
      Precondition:
          4 string and 2 int values  exist
      PostCondition:
          a pokemon object is created from the arguments
          the arguments remain unchanged
      Return:
          none
      Description:
          This is the constructor used to create a pokemon object when all of
          the attributes are known
    */
    Pokemon(string, string, int, int, string, string);

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
