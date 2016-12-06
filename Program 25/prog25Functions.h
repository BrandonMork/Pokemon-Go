
/*
*************************************************
                  Transactions
*************************************************
 - TransID: int
 - CatID: int
 - Amount: double
 - Deposit: string
*************************************************
 + Transactions()
 + Transactions(int,int,double,string);
 + getTransID() const: int
 + int getCatID() const: int
 + string getDeposit() const: string
 + double getAmount() const: double
 + void setAmount(double): void
 + void setTransID(int): void
 + void setCatID(int): void
 + void setDeposit(string): void
 + double calcBalance(): double
*************************************************
*/

#ifndef PROG25FUNCTIONS_H
#define PROG25FUNCTIONS_H

#include <string>

using namespace std;

struct Categories
{
  int Category;
  string description;

  Categories();
  Categories(int,string);
};

class Transactions
{
  private:
    int TransID;
    int CatID;
    double Amount;
    string Deposit;

  public:
    Transactions();
    Transactions(int,int,double,string);
    int getTransID() const;
    int getCatID() const;
    string getDeposit() const;
    double getAmount() const;
    void setAmount(double);
    void setTransID(int);
    void setCatID(int);
    void setDeposit(string);
    double calcBalance();

};

void sortTrans(Transactions [], int);


#endif // PROG25FUNCTIONS_H
