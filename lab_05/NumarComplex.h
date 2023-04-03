#pragma once

class NumarComplex
{
private:
    float parte_reala;
    float parte_complexa;

public:
    int get_pr();
    int get_pc();
    void set_pr(float x);
    void set_pc(float x);
    NumarComplex();
    NumarComplex(float x, float y);
    NumarComplex(const NumarComplex &m);
    ~NumarComplex(); // deconstructor
    void adunare(const NumarComplex n, const NumarComplex m);
    void scadere(const NumarComplex n, const NumarComplex m);
    void inmultire(const NumarComplex n, const NumarComplex m);
    int modul(const NumarComplex n);
};