#pragma once

class Cheltuiala
{
private:
    int ziua;
    int suma;
    char* type;
public:
    Cheltuiala();
    Cheltuiala(int ziua, int suma, char* type);
    ~Cheltuiala();
    void set_ziua(int ziua);
    int get_ziua();
    void set_suma(int suma);
    int get_suma();
    void set_type(char *e);
    char* get_type();
    void operator_equal(Cheltuiala &ch_destination, const Cheltuiala ch_origin);
    //Cheltuiala& operator=(const Cheltuiala& ch);


};