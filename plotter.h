#ifndef PLOTTER_H_
#define PLOTTER_H_
#include <windows.h>
#include <mmsystem.h>
#include <conio.h>

const char SQUARE = 219;
const char LEFT   = 221;
const char RIGHT  = 222;
const char TOP    = 223;
const char BOTTOM = 220;
const char BLANK  = ' ';
const char GRASS  = 177;
const char PATH   = 178;


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
       Plotter();
       void clear();
       void move(int, int);
       void plot(int, int, char);
       void setColor(ink);
};

void mapDisplay(ostream&, int&, int&);

#endif /*PLOTTER_H_*/
