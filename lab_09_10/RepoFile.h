
#pragma once

#include "Tenisi.h"
#include "Repo.h"
#include <fstream>
using namespace std;

class RepoFile : public Repo {
private:
    string fisier;

    void incarcaFisier() {
        ifstream fin(fisier);
        int marime;
        int pret;
        int random_id;
        while (fin >> marime >> pret >> random_id) {
            Tenisi tenisi_perche(marime, pret, random_id);

        }
        fin.close();
    }

    void salveazaFisier() {
        std::ofstream fout(fisier);
        for (auto& tenisi_pereche : tenisi) {
            fout << tenisi_pereche.get_marime() << " " << tenisi_pereche.get_pret() << " " << tenisi_pereche.get_id() << "\n";
        }
        fout.close();
    }

public:
    RepoFile(string fisier);

    void adauga(int marime, int pret, int id);

    void sterge(int marime,int pret, int id);

    void actualizeaza(int id, int new_marime, int new_pret);
};

