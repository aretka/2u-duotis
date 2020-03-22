#include "deque_header.h"

string IntToStr(int n)
{
    std::stringstream result;
    result << n;
    return result.str();
}

deque<mokinys> skirstykStudentus(deque<mokinys>& studentai)
{
 deque<mokinys> kieti, minksti;
 for (int i = 0; i != studentai.size(); i++)
 {
     if (studentai[i].galutinis < 5)
     minksti.push_back(studentai[i]);
     else
     kieti.push_back(studentai[i]);
 }

 studentai = kieti; // vektoriui 'studentai' priskiriame kietus
 return minksti; // grąžina vektorių iš studentų gavusių skolą
}

void GalBalas(deque<mokinys>& studentai)
{
    int suma;
    for(int i=0; i<studentai.size(); i++)
    {
        suma = 0;
        for(int t=0; t<studentai[i].C.size(); t++)
        {
            suma+=studentai[i].C[t];
        }
        if(studentai[i].C.size() == 0)
        {
            studentai[i].galutinis = 0.6*studentai[i].egzaminas;
        }
        else{
            studentai[i].galutinis = (0.4*suma/studentai[i].C.size())+(0.6*studentai[i].egzaminas);
        }
    }
}

bool comparePagalVarda(const mokinys& x, const mokinys& y)
{
    return x.vardas < y.vardas;
}

bool comparePagalPavarde(const mokinys& x, const mokinys& y)
{
    return x.pavarde < y.pavarde;
}
bool comparePagalGalutini(const mokinys& x, const mokinys& y)
{
    return x.galutinis < y.galutinis;
}
