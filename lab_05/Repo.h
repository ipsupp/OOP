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
    void afisare_lista();
    bool cadran_check(NumarComplex &n);
    void afisare_numar(NumarComplex &n);
    void cadran_lista();
    int cmm_numar();
    void afisare_cmm_numar();
    void secventa(int &i, int &j);
    void afisare_secv(int i, int j);
    bool is_equal(NumarComplex n, NumarComplex m);
};