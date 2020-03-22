#include "list_header.h"

string IntToStr(int n)
{
    std::stringstream result;
    result << n;
    return result.str();
}

list<mokinys> skirstykStudentus(list<mokinys>& studentai)
{
 list<mokinys> kieti, minksti;
 list<mokinys>::iterator it;
 mokinys duomenys;
 it = studentai.begin();
 while ( it != studentai.end())
 {
     duomenys.vardas = it->vardas;
     duomenys.pavarde = it->pavarde;
     duomenys.galutinis = it->galutinis;
     if (it->galutinis < 5)
     minksti.push_back(duomenys);
     else
     kieti.push_back(duomenys);

     it++;
 }

 studentai = kieti; // vektoriui 'studentai' priskiriame kietus
 return minksti; // grąžina vektorių iš studentų gavusių skolą
}


