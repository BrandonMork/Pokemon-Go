#include <iostream>
#include <fstream>
#include <iomanip>
#include "prog25Functions.h"

using namespace std;

int main()
{
  Transactions transactions [100];
  Categories categories [50];
  ifstream trans;
  ifstream cat;
  ifstream bal;
  trans.open("transactions.dat");
  cat.open("categories.txt");
  bal.open("balance.dat");
  double balance = 0.0;
  int transID = 0;
  int index = 0;
  string deposit;
  double amount = 0.0;
  int category = 0;
  string descr;
  string word;
  bool warning = false;

  if(trans.is_open() && cat.is_open() && bal.is_open())
  {
    //get balance from file
    bal.ignore(500,'$');
    bal >> balance;

    //get transactions from file
    trans.ignore(500, '\n');
    while(trans >> transID >> deposit >> amount >> category)
    {
      transactions[index].setTransID(transID);
      transactions[index].setDeposit(deposit);
      transactions[index].setAmount(amount);
      transactions[index].setCatID(category);
      index ++;
    }

    cat.ignore(500,'\n');
    while((cat >> category >> word) && (getline(cat, descr)))
    {
      word += descr;
      categories[category - 1].Category = category;
      categories[category - 1].description = word;
    }

    sortTrans(transactions, index);


    cout << left << setw(5) << "ID" << setw(30) << "Category" << setw(5) << "T"
         << right << setw(10) << "Amount" << setw(10) << "Balance" << endl << endl;

    for(int i = 0; i < index; i ++)
    {
      if(transactions[i].getTransID() - transactions[i - 1].getTransID() > 1)
        cout << "\nMISSING TRANSACTION\n\n";
      balance += transactions[i].calcBalance();
      cout << left << setw(5) << transactions[i].getTransID() << setw(30)
           << categories[transactions[i].getCatID() - 1].description << setw(5)
           << transactions[i].getDeposit() << right <<setw(10)
           << transactions[i].getAmount() << setw(10)
           << balance << endl;
      if(balance < 0)
        warning = true;
    }
    if(warning)
      cout << "\n***** WARNING: Negative Balance *****\n\n";

  }
  else
    cout << "Incorrect files" << endl;

  return 0;
}

