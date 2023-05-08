
#pragma once
class Tenisi {
private:
    int marime;
    int pret;
    int random_id;
public:
    Tenisi();
    Tenisi(int marime, int pret, int id);
    ~Tenisi();
    void set_marime(int marime);
    int get_marime();
    void set_pret(int pret);
    int get_pret();
    void set_id(int id);
    int get_id();

};