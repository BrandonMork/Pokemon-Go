#include "prog25Functions.h"

Categories::Categories()
{
  Category = 0;
  description = "N/A";
}

Categories::Categories(int c,string d)
{
  Category =c ;
  description = d;
}

Transactions::Transactions()
{
  TransID = 1;
  CatID = 1;
  Description = "Pay Check";
  Deposit = "D";
  Amount = 0.0;
}

Transactions::Transactions(int t,int i,double a,string des, string dep)
{
  TransID = t;
  CatID = i;
  Description = des;
  Deposit = dep;
  Amount = a;
}

int Transactions::getCatID() const
{
  return CatID;
}

string Transactions::getDeposit() const
{
  return Deposit;
}

int Transactions::getTransID() const
{
  return TransID;
}

double Transactions::getAmount() const
{
  return Amount;
}

void Transactions::setAmount(double a)
{
  Amount = a;
}

void Transactions::setTransID(int t)
{
  TransID = t;
}

void Transactions::setCatID(int i)
{
  CatID = i;
}

void Transactions::setDeposit(string b)
{
  Deposit = b;
}

double Transactions::calcBalance()
{
  double num = Amount;

  if(Deposit == "W")
    num *= -1.0;
  return num;
}

void sortTrans(Transactions trans[], int index)
{
  bool swap;
  Transactions temp;
  do
  {
    swap = false;

    for(int i = 0;i < index -1;i ++)
    {
      if(trans[i].getTransID() > trans[i +1].getTransID())
      {
        temp = trans[i];
        trans[i] = trans[i + 1];
        trans[i + 1] = temp;
        swap = true;
      }
    }
  }while(swap);
}


