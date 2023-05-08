#include <cmath>
#include "Repo.h"
#include <iostream>
using namespace std;
Repo::Repo() {
    nr_tenisi = 0;
}

Repo::~Repo() {}

Tenisi* Repo::get_all()
{
    return tenisi;
}

int Repo::get_nr_tenisi()
{
    return nr_tenisi;
}

void Repo::add(int marime, int pret)
{
    tenisi[nr_tenisi].set_marime(marime);
    tenisi[nr_tenisi].set_pret(pret);
    nr_tenisi++;
}

void Repo::delete_(int marime, int pret)
{
    for (int i=0;i<nr_tenisi;i++)
        if (tenisi[i].get_marime() == marime and tenisi[i].get_pret() == pret)
        {
            for (int j=i; j<nr_tenisi ;j++)
                swap(tenisi[j],tenisi[j+1]);
            nr_tenisi--;
        }
}

void Repo::update(int marime, int pret, int new_marime, int new_pret)
{
    int ok = 0;
    for (int i = 0;i < nr_tenisi; i++)
        if (tenisi[i].get_marime() == marime and tenisi[i].get_pret() == pret)
        {
            tenisi[i].set_marime(new_marime);
            tenisi[i].set_pret(new_pret);
            ok = 1;
        }
    if (ok == 0)
        cout<<"Nu exista tenisii!"<<endl;
}


void Repo::list()
{
    for (int i = 0 ;i<nr_tenisi;i++)
        cout<<"ID: "<<tenisi[i].get_id()<<" | Size: "<<tenisi[i].get_marime()<<" | Price: "<<tenisi[i].get_pret()<<endl;

}