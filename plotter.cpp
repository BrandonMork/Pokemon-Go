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

void pokeballArt(int x, int y)
{
  Plotter pokeball;
  char character;
  Point pok[14][7];
  ink color;

  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 14; j++)
    {
      switch(i)
      {
        case 0:
          if (j == 6 || j == 7)
            pok[j][i].color = grey;
          else
            pok[j][i].color = black;
          break;
        case 1:
          if (j == 3 || j == 10)
            pok[j][i].color = grey;
          else if (j == 5 || j == 4)
            pok[j][i].color = red;
          else if (j == 8 || j == 9)
            pok[j][i].color = white;
          else
            pok[j][i].color = black;
          break;
        case 2:
          if (j == 1 || j == 12)
            pok[j][i].color = grey;
          else if (j > 1 && j < 6)
            pok[j][i].color = red;
          else if (j > 7 && j < 12)
            pok[j][i].color = white;
          else
            pok[j][i].color = black;
          break;
        case 3:
          if (j == 0 || j == 13)
            pok[j][i].color = grey;
          else if (j > 4 && j < 9)
            pok[j][i].color = black;
          else if (j > 8 && j < 13)
            pok[j][i].color = white;
          else
            pok[j][i].color = red;
          break;
        case 4:
          if (j == 1 || j == 12)
            pok[j][i].color = grey;
          else if (j > 1 && j < 6)
            pok[j][i].color = red;
          else if (j > 7 && j < 12)
            pok[j][i].color = white;
          else
            pok[j][i].color = black;
          break;
        case 5:
          if (j == 3 || j == 10)
            pok[j][i].color = grey;
          else if (j == 5 || j == 4)
            pok[j][i].color = red;
          else if (j == 8 || j == 9)
            pok[j][i].color = white;
          else
            pok[j][i].color = black;
          break;
        case 6:
          if (j == 6 || j == 7)
            pok[j][i].color = grey;
          else
            pok[j][i].color = black;
      }
      if (i == 0)
        character = BOTTOM;
      else if (i == 6)
        character = TOP;
      else
        character = SQUARE;
      pokeball.setColor(pok[j][i].getColor());
      pokeball.plot((j + x), (i + y), character);

    }
  }
}

void clearPoke(int x, int y)
{
  Plotter p;
  p.setColor(black);
  for (int i = 0; i < 7; i++)
  {
    for (int j = 0; j < 14; j++)
      p.plot((j + x), (i + y), SQUARE);
  }
}


void mapDisplay(ostream& out, int& x, int& y, profile& a)
{
  srand(time(0));
  Pokemon spawnPoke;
  Plotter map1;
  ink color;
  bool poke;
  bool caught;
  int catchChance;
  int count;
  int currX = x;
  int currY = y;
  int prevX = currX;
  int prevY = currY;
  char key;
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
      map2[x][y].color = green;
      map2[x][y].character = GRASS;
      if ((x > 18 && x < 28) || (x > 86 && x < 96) || (x > 156 && x < 166))
      {
        map2[x][y].color = darkyellow;
        map2[x][y].character = SQUARE;
      }
      if ((y > 18 && y < 22) || ((y > 40 && y < 44) && x < 157))
      {
        map2[x][y].color = darkyellow;
        map2[x][y].character = SQUARE;
      }
      if (x > 180 && x < 220 && y > 30 && y < 55)
      {
        map2[x][y].color = blue;
        map2[x][y].character = WATER;
      }

      //  If you want to add in specific block colors and objects
      //  do it here
      if(((x > 29 && x < 34) || (x > 150 && x < 155) || (x > 235 && x < 240))
         && ((y > 15 && y < 18) || (y > 44 && y < 47)))
      {
        map2[x][y].color = purple;
        map2[x][y].character = SQUARE;
      }


    }
  }
  do
  {
    poke = false;
    for (int i = 0; i < 261; i++)
    {
      for (int j = 0; j < 61; j++)
      {
        map1.setColor(map2[i][j].getColor());
        map1.plot(i, j, map2[i][j].getCharacter());
      }
    }

    color = yellow;
    if (a.getOutfit() == "Red")
      color = red;
    else if (a.getOutfit() == "Blue")
      color = blue;


    while(key != 'b' && poke == false)
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

        if(map2[prevX][prevY].getColor() == purple)
          a.Pokestop();

        prevX = currX;
        prevY = currY;
        x = currX;
        y = currY;
      }
      if (key != 'b')
      {
        if (rand() % 20 == 5)
        {
          map1.clear();
          poke = true;
          caught = false;
          spawnPoke.randPokemon();
          spawnPoke.displayPokemon(115, 20);


          a.avatarDisplay(20, 20);
          count = 0;

          map1.move(0, 0);
          map1.setColor(white);

          if (a.getNumPokemon() == 25)
          {
            out << "Too many Pokemon caught....Please delete some and come "
                << "out again\n\n Running Away.....";
            Sleep(4000);
          }
          else if (a.getPokeball() == 0)
          {
            out << "You have no pokeballs in your backpack...Please visit a "
                << "pokestop to get more out again\n\n Running Away.....";
            Sleep(4000);
          }
          else
          {
            out << "A wild " << spawnPoke.getName() << " has appeared!!\n\n"
                << "What would you like to do?\n1. "
                << "Throw a Pokeball\n2. Throw a Razz Berry\n3. Run Away\n";
          catchChance = 3;
            do
            {
              do
              {
                key = getch();
              }while(key != '1' && key != '2' && key != '3');

              if (key == '1')
              {
                a.subtrPokeball();

                if(a.getPokeball() == 0)
                {
                  map1.move(60, 3);
                  map1.setColor(white);
                  out << "No More Pokeballs....Please Visit a Pokestop for More";
                }
                else
                {
                  pokeballArt(65, 20);
                  Sleep(1000);
                  clearPoke(65, 20);
                  pokeballArt(80, 10);
                  Sleep(1000);
                  clearPoke(80, 10);
                  pokeballArt(95, 20);
                  Sleep(1000);
                  clearPoke(95, 20);

                  if(rand() % catchChance == 1)
                  {
                    clearPokemon(115, 20);
                    pokeballArt(120, 35);
                    caught = true;
                    map1.move(60, 3);
                    map1.setColor(white);
                    out << "You Caught it!!!";
                    a.addPokemon(spawnPoke.getName(), spawnPoke.getType(),
                                 spawnPoke.getCP(), spawnPoke.getHP(),
                                 spawnPoke.getMove1(), spawnPoke.getMove2());
                    Sleep(5000);
                  }
                  else
                  {
                    pokeballArt(95, 35);
                    Sleep(1000);
                    clearPoke(95, 35);
                  }
                }
              }
              else if (key == '2')
              {
                if (a.getPotion() == 0)
                {
                  map1.move(0, 25);
                  map1.setColor(white);
                  out << "No More Potions....Please Visit a Pokestop for More\n\n"
                      << "Throw a Pokeball or Run Away";
                }
                else
                {
                  catchChance = 2;
                  a.subtrPotion();
                  map1.move(0, 20);
                  map1.setColor(white);
                  out << "Razz Berry Thrown!";
                }
              }
            }while ((key == '1' || key == '2')&& caught == false);
          }

        }
      }
    }

  }while(poke == true);

  map1.setColor(white);
  map1.clear();

}
