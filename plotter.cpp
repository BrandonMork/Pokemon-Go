/*
* Author:                 Brandon Mork, Ryan Keller, Alexander Lee
* Assignment Title:       plotter.cpp
* Assignment Description: The implementation file for the plotter class
* Due Date:               11/29/2016
* Date Created:           11/7/2016
* Date Last Modified:     11/28/2016
*/

using namespace std;

#include "plotter.h"

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

void avatarDisplay(int x, int y, profile a)
{
  Plotter avatar;
  ink color;
  Point man[40][20];

  for (int i = 0; i < 20; i ++)
  {
    for (int j = 0; j < 40; j++)
    {
      switch(i)
      {
        case 0:
            if (j > 15 && j < 25)
              man[j][i].color = a.getMapDot();
            else
              man[j][i].color = black;
            break;
        case 1:
            if (j > 15 && j < 25)
              man[j][i].color = a.getMapDot();
            else
              man[j][i].color = black;
            break;*/
        case 2:
            if (j > 15 && j < 30)
              man[j][i].color = a.getMapDot();
            else
              man[j][i].color = black;
            break;
        case 3:
            if (j > 15 && j < 20)
              man[j][i].color = darkyellow;
            else if (j > 19 && j < 24)
              man[j][i].color = lightgrey;
            else if (a.getGender() == "Female")
            {
              if (j < 16 && j > 13)
              man[j][i].color = darkyellow;
            }
            else
              man[j][i].color = black;
            break;
        case 4:
            if (j == 23 || (j > 18 && j < 22))
              man[j][i].color = lightgrey;
            else if (j == 22)
              man[j][i].color = blue;
            else if (j > 15 && j < 19)
              man[j][i].color = darkyellow;
            else if (a.getGender() == "Female")
            {
              if (j < 16 && j > 13)
              man[j][i].color = darkyellow;
            }
            else
              man[j][i].color = black;
            break;

        case 5:
            if (j < 24 && j > 15)
              man[j][i].color = lightgrey;
            else if (a.getGender() == "Female")
            {
              if (j < 16 && j > 13)
              man[j][i].color = darkyellow;
            }
            else
              man[j][i].color = black;
            break;
        case 6:
            if (j < 24 && j > 15)
              man[j][i].color = lightgrey;
            else if (a.getGender() == "Female")
            {
              if (j < 16 && j > 13)
              man[j][i].color = darkyellow;
            }
            else
              man[j][i].color = black;
            break;
        case 7:
            if (j < 30 && j > 9)
            {
              man[j][i].color = red;
              if (j == 12 || j == 27 || j ==13 || j == 26)
                man[j][i].color = cyan;
              else if (j > 16 && j < 23)
                man[j][i].color = lightgrey;
            }
            else
              man[j][i].color = black;
            break;
        case 8:
            if (j < 30 && j > 9)
            {
              man[j][i].color = a.getMapDot();
              if (j == 12 || j == 27 || j ==13 || j == 26)
                man[j][i].color = cyan;
            }

            else
              man[j][i].color = black;
            break;
        case 9:
            if (j < 30 && j > 9)
            {
              man[j][i].color = a.getMapDot();
              if (j == 13 || j == 26)
                man[j][i].color = cyan;
            }

            else
              man[j][i].color = black;
            break;
        case 10:
            if (j < 30 && j > 9)
            {
              man[j][i].color = a.getMapDot();
              if (j == 13 || j == 26)
                man[j][i].color = cyan;
            }

            else
              man[j][i].color = black;
            break;
        case 11:
            if (j < 30 && j > 9)
            {
              man[j][i].color = a.getMapDot();
              if (j == 13 || j == 26)
                man[j][i].color = black;
            }

            else
              man[j][i].color = black;
            break;
        case 12:
            if (j < 30 && j > 9)
            {
              man[j][i].color = lightgrey;
              if (j < 26 && j > 13)
                man[j][i].color = a.getMapDot();
              if (j == 13 || j == 26)
                man[j][i].color = black;
            }

            else
              man[j][i].color = black;
            break;
        case 13:
            if (j < 26 && j > 13)
              man[j][i].color = a.getMapDot();
            else
              man[j][i].color = black;
            break;
        case 14:
            if (j < 26 && j > 13)
              man[j][i].color = a.getMapDot();
            else
              man[j][i].color = black;
            break;
        case 15:
            if (j < 26 && j > 13)
              man[j][i].color = a.getMapDot();
            else
              man[j][i].color = black;
            break;
        case 16:
            if (j < 26 && j > 13)
              man[j][i].color = a.getMapDot();
            else
              man[j][i].color = black;
            break;
        case 17:
            if (j < 26 && j > 13)
              man[j][i].color = a.getMapDot();
            else
              man[j][i].color = black;
            break;
        case 18:
            if (j < 26 && j > 13)
              man[j][i].color = a.getMapDot();
            else
              man[j][i].color = black;
            break;
        case 19:
            if (j < 28 && j > 11)
              man[j][i].color = white;
            else
              man[j][i].color = black;
            break;
      }
        if (i == 5 && (j == 24 || j == 20))
          avatar.plot(j, i, TOP);
        else if (i == 6 && j > 20 && j < 24)
          avatar.plot(j, i, BOTTOM);
        else if (i == 7 && (j == 10 || j == 29))
          avatar.plot(j, i, BOTTOM);
        else if (i == 13)
          avatar.plot(j, i, BOTTOM);
        else if (i > 14 && i < 20 && j == 20)
          avatar.plot(j, i, RIGHT);
        else
        {
          avatar.setColor(man[j][i].getColor());
          avatar.plot(j, i, SQUARE);
        }
    }
  }
  return 0;
}
void mapDisplay(ostream& out, int& x, int& y, string a)
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

  if (a == "Red")
    color = red;
  else if (a == "Blue")
    color = blue;
  else if (a == "Yellow")
    color = yellow;

  while(key != 'b')
  {
    if (kbhit)      // in conio
    {
      key = getch();
      switch (key)
      {
        case 'd':
            if (currX < 260 && !( x == 180 && (y > 30 && y < 55)))
              currX++;
            break;
        case 'a':
            if (currX > 0 && !( x == 220 && (y > 30 && y < 55)))
                currX--;
            break;
        case 'w':
            if (currY > 0 && !( y == 55 && (x > 180 && x < 220)))
                currY--;
            break;
        case 's':
            if (currY < 60 && !( y == 30 && (x > 180 && x < 220)))
              currY++;
      }

      Sleep(100);
      map1.setColor(map2[prevX][prevY].getColor());
      map1.plot(prevX, prevY, map2[prevX][prevY].getCharacter());
      map1.setColor(color);
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
