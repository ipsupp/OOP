
#pragma once
class Tenisi {
private:
    int marime;
    int pret;

public:
    Tenisi();
    Tenisi(int marime, int pret);
    ~Tenisi();
    void set_marime(int marime);
    int get_marime();
    void set_pret(int pret);
    int get_pret();

};

