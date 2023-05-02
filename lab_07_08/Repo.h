#include "Cheltuiala.h"

class Repo
{
private:
    Cheltuiala cheltuieli[100];
    int nr_ch;
public:
    Repo();
    ~Repo();
    void add_cheltuieli(const Cheltuiala &c);
    Cheltuiala* get_all();
    int get_size();
    void afisare_cheltuiala(Cheltuiala c);
};