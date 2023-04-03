#pragma once
#include "NumarComplex.h"

class Repo
{
private:
    NumarComplex numere[100];
    int noNumbers;
public:
    Repo();
    ~Repo();
    void add_number(NumarComplex &n);
//    int get_size();
//    NumarComplex get_nr_from_pos(int pos);
    void afisare();
};