#pragma once

class Cheltuiala
{
private:
    int ziua;
    int suma;
    char type[101];
    //can folosesc tipul, trebuie sa il copiez in alta variabila char array
public:
    Cheltuiala();
    Cheltuiala(int ziua, int suma, char type[]);
    ~Cheltuiala();
    void set_ziua(int ziua);
    int get_ziua();
    void set_suma(int suma);
    int get_suma();
    void set_type(char e[]);
    char* get_type();

};