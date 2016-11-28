#ifndef POKEMONMENUS_H
#define POKEMONMENUS_H


char introMenu(ostream&, istream&);

void newUserCreation(ostream&, istream&);

void gameMenuLoop(ostream&, istream&, profile&);

char gameMainMenu(ostream&, istream&, profile&);

void editProfileMenu(ostream&, istream&, profile&);


#endif // POKEMONMENUS_H
