#include "Cheltuiala.h"
#include <string.h>
using namespace std;

Cheltuiala::Cheltuiala()
{
    this->suma = 0;
    this->ziua = 0;
}

Cheltuiala::Cheltuiala(int ziua, int suma, char type[])
{
    this->ziua = ziua;
    this->suma = suma;
    strcpy(this->type, type);
}
Cheltuiala::~Cheltuiala() {}

void Cheltuiala::set_ziua(int ziua)
{
    this->ziua = ziua;
}

int Cheltuiala::get_ziua()
{
    return this->ziua;
}

void Cheltuiala::set_suma(int suma)
{
    this->suma = suma;
}

int Cheltuiala::get_suma()
{
    return this->suma;
}

void Cheltuiala::set_type(char e[])
{
    strcpy(this->type, e);
}

char* Cheltuiala::get_type()
{
    return this->type; // cand apelez: char* type = c.get_type(); cout<<type;
}