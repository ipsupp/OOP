#include "Cheltuiala.h"
#include <cstring>
using namespace std;

Cheltuiala::Cheltuiala()
{
    this->suma = 0;
    this->ziua = 0;
    this->type = nullptr;
}

Cheltuiala::Cheltuiala(int ziua, int suma, char* type)
{
    this->ziua = ziua;
    this->suma = suma;
    this->type = type;
}
Cheltuiala::~Cheltuiala()
{
 //   delete[] this->type; strica codul impreuna cu redefinirea operatorului '=' nu stiu de ce :)
}

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

void Cheltuiala::set_type(char *e)
{
    delete[] this->type;
    this->type = new char[strlen(e) + 1];
    strcpy(this->type, e);
}

char* Cheltuiala::get_type()
{
    return this->type; // cand apelez: char* type = c.get_type(); cout<<type;
}

void Cheltuiala::operator_equal(Cheltuiala &ch_destination, const Cheltuiala ch_origin)
{
    ch_destination.ziua = ch_origin.ziua;
    ch_destination.suma = ch_origin.suma;
    strcpy(ch_destination.type,ch_origin.type);

}

//
//Cheltuiala& Cheltuiala::operator=(const Cheltuiala& ch)
//{
//    if (this != &ch)
//    {
//        this->ziua = ch.ziua;
//        this->suma = ch.suma;
//        delete[] this->type;
//        this->type = new char[strlen(ch.type) + 1];
//        strcpy(this->type, ch.type);
//        return *this;
//    }
//}