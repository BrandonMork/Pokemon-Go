/*
* Author:                 Brandon Mork, Ryan Keller, Alex Lee
* Assignment Title:       Pokemon.h
* Assignment Description: The header file for the pokemon class
* Due Date:               11/29/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/28/2016
*/

/*
  ************************************************
                      Pokemon
  ************************************************
  - name: string
  - type: string
  - cp: int
  - hp: int
  - move1: string
  - move2: string
  ************************************************
  + Pokemon():
  + Pokemon(string,string,string):
  + Pokemon(string,string,int,int,string,string):
  + getName() const: string
  + getType() const: string
  + getCP() const: int
  + getHP() const: int
  + getMove1(): string
  + getMove2(): string
  + randCP(): int
  + randHP(): int
  + randMove1(): string
  + randPokemon(): void
  + writePokeInfo(ostream&): void
  + displayPokemon(int, int): void
  + clearPokeData(): void
  ************************************************
*/

#ifndef POKEMON_H
#define POKEMON_H

#include <string>
#include <cstdlib>
#include <time.h>
#include <fstream>

using namespace std;

class Pokemon
{
  private:


    int cp;
    int hp;
    string move1;
    string move2;

  public:
    //constructors
    string name;
    string type;
    Pokemon();
    Pokemon(string, string, string);

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

     /*
      Precondition:
          a Pokemon object exists with a designated name
      PostCondition:
          name of the Pokemon object is returned
      Return:
          string
      Description:
          this function returns the string stored as name
    */
    string getName() const;

    /*
      Precondition:
          a Pokemon object exists with a designated type
      PostCondition:
          type of the Pokemon object is returned
      Return:
          string
      Description:
          this function returns the string stored as type
    */
    string getType() const;

    /*
      Precondition:
          a Pokemon object exists with a designated cp
      PostCondition:
          cp of the Pokemon object is returned
      Return:
          int
      Description:
          this function returns the int stored as cp
    */
    int getCP() const;

    /*
      Precondition:
          a Pokemon object exists with a designated hp
      PostCondition:
          hp of the Pokemon object is returned
      Return:
          int
      Description:
          this function returns the string stored as hp
    */
    int getHP() const;

    /*
      Precondition:
          a Pokemon object exists with a designated first move
      PostCondition:
          the first move of the Pokemon object is returned
      Return:
          string
      Description:
          this function returns the string stored as move1
    */
    string getMove1() const;

    /*
      Precondition:
          a Pokemon object exists with a designated second move
      PostCondition:
          the second move of the Pokemon object is returned
      Return:
          string
      Description:
          this function returns the string stored as move2
    */
    string getMove2() const;

    /*
      Precondition:
          a Pokemon object exists with a designated cp
      PostCondition:
          cp value is randomized from 10 to 1000 and returned
      Return:
          int
      Description:
          this function randomizes the cp of a Pokemon object  from 10 to 1000
    */
    int randCP();

    /*
      Precondition:
          a Pokemon object exists with a designated hp
      PostCondition:
          hp value is randomized from 10 to 100 and returned
      Return:
          int
      Description:
          this function randomizes the hp of a Pokemon object  from 10 to 100
    */
    int randHP();

    /*
      Precondition:
          a Pokemon object exists with a designated move1
      PostCondition:
          first move is randomized from the list of possible first moves
           and is returned
      Return:
          int
      Description:
          this function randomizes the first move of a Pokemon object either
          "Tackle", "Scratch", "Quick Attack", or "Headbutt" and returns it
    */
    string randMove1();

    /*
      Precondition:
          a Pokemon object exists
      PostCondition:
          name, type, cp, hp, move1, move2 are all changed
      Return:
          void
      Description:
          a random Pokemon object is chosen from the array of possible
          names, types and second move
          It is given a random cp, hp, and first move.

    */
    void randPokemon();

    /*
      Precondition:
          a Pokemon object exists
      PostCondition:
          name, type, cp, hp, move1, move2 are all written to an output file
            stream
          output stream is changed
      Return:
          void
      Description:
          This function writes the name, type, cp, hp, move1, and move2 to an
            output file
    */
    void writePokeInfo(ostream&);

    /*
      Precondition:
        The function is called with an x and y coordinate and a pokemon exists
      Postcondiditon:
        The pokemon selected is displayed on the screen
      Return:
        void
      Description:
        Plots the pokemon on the screen with the given x and y coordinates
        from the user. The function decideds which pokemon to plot.
    */
    void displayPokemon(int, int);

    /*
      Precondition:
        The function is called and a pokemon exists
      Postcondiditon:
        The pokemon and it's attributes is deleted
      Return:
        void
      Description:
        Removes the pokemon and all of its attributes
    */
    void clearPokeData();


};

/*
  Precondition:
    The function is called with an x and y coordinate
  Postcondiditon:
    The squirtle pokemon is plotted to the screen based on the x and y coords
  Return:
    void
  Description:
    The color of each pixel is decided as it runs through the dimensions of the
    pokemon and is plotted with the specified color.
*/
void displaySquirtle(int, int);

/*
  Precondition:
    The function is called with an x and y coordinate
  Postcondiditon:
    The pikachu pokemon is plotted to the screen based on the x and y coords
  Return:
    void
  Description:
    The color of each pixel is decided as it runs through the dimensions of the
    pokemon and is plotted with the specified color.
*/
void displayPikachu(int, int);

/*
  Precondition:
    The function is called with an x and y coordinate
  Postcondiditon:
    The charmander pokemon is plotted to the screen based on the x and y coords
  Return:
    void
  Description:
    The color of each pixel is decided as it runs through the dimensions of the
    pokemon and is plotted with the specified color.
*/
void displayCharmander(int, int);

/*
  Precondition:
    The function is called with an x and y coordinate
  Postcondiditon:
    The kakuna pokemon is plotted to the screen based on the x and y coords
  Return:
    void
  Description:
    The color of each pixel is decided as it runs through the dimensions of the
    pokemon and is plotted with the specified color.
*/
void displayKakuna(int, int);

/*
  Precondition:
    The function is called with an x and y coordinate
  Postcondiditon:
    The haunter pokemon is plotted to the screen based on the x and y coords
  Return:
    void
  Description:
    The color of each pixel is decided as it runs through the dimensions of the
    pokemon and is plotted with the specified color.
*/
void displayHaunter(int, int);

/*
  Precondition:
    the function is called with an x and y coordinate
  Postcondiditon:
    Black sqaures are plotted over the specified location
  Return:
    void
  Description:
    The pokemon will be plotted over with this function so that it looks like
    it vanished
*/
void clearPokemon(int, int);

#endif // POKEMON_H


