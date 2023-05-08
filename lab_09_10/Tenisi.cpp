

#include "Tenisi.h"

Tenisi::Tenisi()
{
    this->marime = 0;
    this->pret = 0;
}

Tenisi::Tenisi(int marime, int pret)
{
    this->marime = marime;
    this->pret = pret;
}

Tenisi::~Tenisi() {}

void Tenisi::set_marime(int marime)
{
    this->marime = marime;
}

int Tenisi::get_marime()
{
    return this->marime;
}

void Tenisi::set_pret(int pret)
{
    this->pret = pret;
}

int Tenisi::get_pret()
{
    return this->pret;
}