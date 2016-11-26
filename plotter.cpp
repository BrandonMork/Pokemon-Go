using namespace std;
#include <iostream>
#include "plotter.h"
#include <ctime>
#include <iostream>
#include "profile.h"

Point::Point()
{
  x = 0.0;
  y = 0.0;
  character = SQUARE;
  color = green;
}

Point::Point(int a, int b, char c, ink d)
{
  x = a;
  y = b;
  character = c;
  color = d;
}

char Point::getCharacter() const
{
  return character;
}

ink Point::getColor() const
{
  return color;
}

void Point::display(ostream& out)
{
	out << "(" << x << "," << y << ")";
}

Plotter::Plotter()
{
       coordScreen.X = 0;
       coordScreen.Y = 0;

       hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
       SetConsoleTextAttribute(hConsoleOutput, white);

}

void Plotter::move(int x, int y)
{
       coordScreen.X = x;
       coordScreen.Y = y;
       //SetConsoleTextAttribute(hConsoleOutput, c);
       SetConsoleCursorPosition( hConsoleOutput, coordScreen );
}

void Plotter::plot(int x, int y, char c)
{

       coordScreen.X = x;     //x coordinate of point
       coordScreen.Y = y;     //y coordinate of point
       //SetConsoleTextAttribute(hConsoleOutput, c);
       SetConsoleCursorPosition( hConsoleOutput, coordScreen );

       cout  << c;            //  character to be displayed

       cout.flush();
}

void Plotter::setColor(ink c)
{
   SetConsoleTextAttribute(hConsoleOutput, c);
}


void Plotter::clear()
{
  cls( hConsoleOutput );
}


void Plotter::cls( HANDLE hConsole )
{
  COORD coordScreen = { 0, 0 };    // here's where we'll home the cursor

  DWORD cCharsWritten;
  CONSOLE_SCREEN_BUFFER_INFO csbi; // to get buffer info
  DWORD dwConSize;                 // number of character cells in the current buffer

  // get the number of character cells in the current buffer
  GetConsoleScreenBufferInfo( hConsole, &csbi );
  dwConSize = csbi.dwSize.X * csbi.dwSize.Y;

  // fill the entire screen with blanks
  FillConsoleOutputCharacter( hConsole, (TCHAR) ' ', dwConSize, coordScreen, &cCharsWritten );

  // get the current text attribute
  GetConsoleScreenBufferInfo( hConsole, &csbi );

  // now set the buffer's attributes accordingly
  FillConsoleOutputAttribute( hConsole, csbi.wAttributes, dwConSize, coordScreen, &cCharsWritten );

  // put the cursor at (0, 0)
  SetConsoleCursorPosition( hConsole, coordScreen );

  return;
}

void mapDisplay(ostream& out, int& x, int& y)
{
  srand(time(0));
  Plotter map1;
  ink color;
  int currX = x;
  int currY = y;
  int prevX = currX;
  int prevY = currY;
  char key;
  char character;
  Point map2[261][61];

  out << "Once Gameplay Has Started, Press 'b' at Anytime to Exit...";

  Sleep(1500);

  out << "\n\nPress 'c' to continue...";

  while (key != 'c')
  {
    if (kbhit())
      key = getch();
  }

  for (int x = 0; x <= 260; x++)
  {
    for (y = 0; y <= 60; y++)
    {
      color = green;
      character = GRASS;
      if ((x > 18 && x < 28) || (x > 86 && x < 96) || (x > 156 && x < 166))
      {
        color = darkyellow;
        character = SQUARE;
      }
      if ((y > 18 && y < 22) || ((y > 40 && y < 44) && x < 157))
      {
        color = darkyellow;
        character = SQUARE;
      }
      if (x > 180 && x < 220 && y > 30 && y < 55)
      {
        color = blue;
        character = WATER;
      }


      //  If you want to add in specific block colors and objects
      //  do it here

      map2[x][y] = Point(x, y, character, color);
      map1.setColor(map2[x][y].getColor());
      map1.plot(x, y, map2[x][y].getCharacter());
    }
  }

    while(key != 'b')
    {
      if (kbhit)      // in conio
      {
        key = getch();
        switch (key)
        {
          case 'd':
              if (currX < 260)
                currX++;
              break;
          case 'a':
              if (currX > 0)
                  currX--;
              break;
          case 'w':
              if (currY > 0)
                  currY--;
              break;
          case 's':
              if (currY < 60)
                currY++;
        }

        Sleep(100);
        map1.setColor(map2[prevX][prevY].getColor());
        map1.plot(prevX, prevY, map2[prevX][prevY].getCharacter());
        map1.setColor(green);
        map1.plot(currX, currY, SQUARE);


        prevX = currX;
        prevY = currY;
        x = currX;
        y = currY;
      }
      //if (rand() % 20 == 5)
    }

  map1.setColor(white);
  map1.clear();

}
