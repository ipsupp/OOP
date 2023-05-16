#include "RepoFile.h"
#include "Repo.h"
#include <fstream>
using namespace std;
RepoFile::RepoFile(string fisier) : fisier(fisier) {
    incarcaFisier();
}

void RepoFile::adauga(int marime, int pret, int id)  {
    Repo::add(marime, pret, id);
    salveazaFisier();
}

void RepoFile::sterge(int marime,int pret, int id)  {
   Repo::delete_(marime, pret, id);
    salveazaFisier();
}

void RepoFile::actualizeaza(int id, int new_marime, int new_pret)
{
    Repo::update(id, new_marime, new_pret);
    salveazaFisier();
}