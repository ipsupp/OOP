#include "Repo.h"
#include <iostream>
using namespace std;
Repo::Repo()
{
    this->nr_ch = 0;
}

Repo::~Repo() {}

void Repo::add_cheltuieli(const Cheltuiala &c)
{
    this->cheltuieli[this->nr_ch] = c;
    this->nr_ch++;
}

int Repo::get_size()
{
    return this->nr_ch;
}

Cheltuiala* Repo::get_all()
{
    return cheltuieli;
}

void Repo::afisare_cheltuiala(Cheltuiala c)
{
    cout<<"Ziua: "<<c.get_ziua()<<" ; "<<"Suma: "<<c.get_suma()<<" ; "<<"Tipul: "<<c.get_type()<<endl;
}