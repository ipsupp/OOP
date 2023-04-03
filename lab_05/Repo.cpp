#include "Repo.h"
#include <iostream>
using namespace std;
Repo::Repo()
{
    this->noNumbers = 0;
}

Repo::~Repo()
{}

void Repo::add_number(NumarComplex &n)
{
    this->numere[this->noNumbers++] = n;
}
//
//int Repo::get_size()
//{
//    return this->noNumbers;
//}
//
//NumarComplex Repo::get_nr_from_pos(int pos)
//{
//    return this->numere[pos];
//}

void Repo::afisare()
{
    for (int i=0;i<this->noNumbers;i++)
        if (numere[i].get_pc()>0)
             cout<<numere[i].get_pr()<<"+"<<numere[i].get_pc()<<"i"<<endl;
        else
            cout<<numere[i].get_pr()<<numere[i].get_pc()<<"i"<<endl;
}