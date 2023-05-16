
#include "Tenisi.h"
#include <random>
Tenisi::Tenisi()
{
    this->marime = 0;
    this->pret = 0;
    this->random_id = 0;
}

Tenisi::Tenisi(int marime, int pret, int id)
{
    this->marime = marime;
    this->pret = pret;
    this->random_id = id;
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

void Tenisi::set_id(int id)
{
    this->random_id = id;
}

int Tenisi::get_id()
{
    return this->random_id;
}