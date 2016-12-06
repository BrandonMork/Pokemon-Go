#include <iostream>
#include <fstream>
#include <iomanip>
#include "prog25Functions.h"

using namespace std;

int main()
{
  Transactions transactions [100];      //an array of 100 transactions
  Categories categories [50];           //an array of 50 categories
  ifstream trans;                       //declare input file stream for transaction file
  ifstream cat;                         //declare input file stream for category file
  ifstream bal;                         //declare input file stream for balance file
  trans.open("transactions.dat");       //connect file stream to ifstream
  cat.open("categories.txt");           //connect file stream to ifstream
  bal.open("balance.dat");              //connect file stream to ifstream
  double balance = 0.0;                 //balance of the account
  int transID = 0;                      //transaction ID of the transaction
  int index = 0;                        //index of the transaction array
  string deposit;                       //deposit or withdrawal
  double amount = 0.0;                  //amount being taken in or out
  int category = 0;                     //the category of the transaction
  string descr;                         //description of the transaction
  string word;                          //first word of the description
  bool warning = false;                 //when the balance falls below 0

  //check to make sure the files open
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

    //get descriptions from file
    cat.ignore(500,'\n');
    while((cat >> category >> word) && (getline(cat, descr)))
    {
      word += descr;
      categories[category - 1].Category = category;
      categories[category - 1].description = word;
    }

    //sort the transaction list
    sortTrans(transactions, index);

    //display the table categories
    cout << left << setw(5) << "ID" << setw(30) << "Category" << setw(5) << "T"
         << right << setw(10) << "Amount" << setw(10) << "Balance" << endl << endl;

    for(int i = 0; i < index; i ++)
    {

      //display a warning if the transaction is missing
      if(transactions[i].getTransID() - transactions[i - 1].getTransID() > 1)
        cout << "\nMISSING TRANSACTION\n\n";

      //calculate the balance
      balance += transactions[i].calcBalance();

      //display the transactions and corresponding descriptions
      cout << left << setw(5) << transactions[i].getTransID() << setw(30)
           << categories[transactions[i].getCatID() - 1].description << setw(5)
           << transactions[i].getDeposit() << right <<setw(10)
           << transactions[i].getAmount() << setw(10)
           << balance << endl;

      //check if balance falls below 0
      if(balance < 0)
        warning = true;
    }

    //display a warning at the end if balance fell below 0
    if(warning)
      cout << "\n***** WARNING: Negative Balance *****\n\n";

  }

  //display an error
  else
    cout << "Incorrect files" << endl;

  return 0;
}

