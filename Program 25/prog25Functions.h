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
    string Description;
    string Deposit;

  public:
    Transactions();
    Transactions(int,int,double,string,string);
    int getTransID() const;
    int getCatID() const;
    string getDeposit() const;
    //string getDescription() const;
    double getAmount() const;
    void setAmount(double);
    void setTransID(int);
    void setCatID(int);
    void setDeposit(string);
    //void setDescription(string);
    double calcBalance();

};

void sortTrans(Transactions [], int);


#endif // PROG25FUNCTIONS_H
