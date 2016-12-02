/*
* Author:                 Brandon Mork, Ryan Keller, Alexander Lee
* Assignment Title:       plotter.h
* Assignment Description: The header file for the plotter class
* Due Date:               12/2/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/30/2016
*/

/*
  ************************************************
                  Plotter
  ************************************************
  - coordScreen: COORD
  - hConsoleOutput: HANDLE
  - dummy: char
  - pChar: char
  - pInk: int
  ************************************************
  + Plotter():
  + clear(): void
  + move(int, int): void
  + plot(int, int, char): void
  + setColor(ink): void
  ************************************************
*/

#ifndef PLOTTER_H_
#define PLOTTER_H_

#include <windows.h>
#include <mmsystem.h>
#include <conio.h>
#include <ctime>
#include "profile.h"
#include <iostream>

using namespace std;

const char SQUARE = 219;
const char LEFT   = 221;
const char RIGHT  = 222;
const char TOP    = 223;
const char BOTTOM = 220;
const char BLANK  = ' ';
const char GRASS  = 177;
const char WATER   = 178;


enum ink
{
    black   = 0x00, darkblue = 0x01, darkgreen  = 0x02, darkcyan  = 0x03,
    darkred = 0x04, purple   = 0x05, darkyellow = 0x06, lightgrey = 0x07,
    grey    = 0x08, blue     = 0x09, green      = 0x0A, cyan      = 0x0B,
    red     = 0x0C, magenta  = 0x0D, yellow     = 0x0E, white     = 0x0F
};

struct Point
{
	int x;         //  x coordinate for the point
	int y;         //  y coordinate for the point
	char character;
	ink color;

  Point ();
	Point(int, int, char, ink);
	char getCharacter() const;
	ink getColor() const;

	void display(ostream& out);

};
class Plotter
{
    protected:
       COORD  coordScreen;
       HANDLE hConsoleOutput;
       char   dummy;
       void cls( HANDLE hConsole );
       char pChar;
       int pInk;
    public:

      /*
        Precondition:
          Default constructor has been called
        Postcondiditon:
          A new constructor is created with x = 0,y = 0,green,square
        Return:
          none
        Description:
          Default constructor for a Plotter
      */
       Plotter();

      /*
        Precondition:
          the functions has been called
          Plotter exists
        Postcondiditon:
          the plotters are removed from the screen
        Return:
          void
        Description:
          clears the screen from all plotters
      */
       void clear();

      /*
        Precondition:
          two ints are passed through parameters
          Plotter exists
        Postcondiditon:
          plotter is moved to coordinates entered and cursor is moved
        Return:
          void
        Description:
          moves the plotter to the coordinates passed through the parameters
          and move the cursor.
      */
       void move(int, int);

      /*
        Precondition:
          two ints and a char are passed through parameters
          Plotter exists
        Postcondiditon:
          plotter is moved to coordinates entered and cursor is moved
          the shape of the pixel is determined
        Return:
          void
        Description:
          moves the plotter to the coordinates passed through the parameters
          and move the cursor and decides the shape of the plot
      */
       void plot(int, int, char);

      /*
        Precondition:
          the function i called and an ink is colored through parameters
        Postcondiditon:
          the ink color is set
        Return:
          void
        Description:
          sets the color of the plotter
      */
       void setColor(ink);
};

/*
  Precondition:
    function is called with ostream&,int&,int&,and profile& passed through
    parameters
  Postcondiditon:
    Map is displayed,Colors the player,Allows the player to move,Displays
    the menus and calculates random pokemon encounters
  Return:
    void
  Description:
    The map is created with pre-determined roads,lakes,and pokestops. The color
    of the character is decided based off of the profile. Displays the menus to
    catch the pokemon, display the pokemon, and clear the pokemon. Allows for
    the movement of the user with restricted movement based on boundaries.

*/
void mapDisplay(ostream&, int&, int&, profile&);

/*
  Precondition:
    two ints are passed through parameters and the function is called
  Postcondiditon:
    a colored pokeball is plotted at the coordinates
  Return:
    void
  Description:
    plots a colored pokeball on the screen with the given coordinates
*/
void pokeballArt(int, int);

/*
  Precondition:
    two ints are passed through parameters and the function is called
  Postcondiditon:
    a black pokeball is plotted over the colored pokeball
  Return:
    void
  Description:
    plots over the pokeball in black with the given coordinates

*/
void clearPoke(int, int);

#endif /*PLOTTER_H_*/
