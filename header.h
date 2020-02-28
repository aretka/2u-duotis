#include <bits/stdc++.h>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>

struct mokinys{
std::string vardas, pavarde;
std::vector<int> C;
int n=0, egzaminas;
float vidurkis, galutinis;
};

void spausdinimas( std::vector<mokinys> Stud, int kiek, int vidarmed)
{
    std::ofstream fr ("kursiokai.txt");
    if(vidarmed == 1)
    {
            fr .width(15);
            fr << "Pavarde";
            fr .width(15);
            fr << "Vardas";
            fr .width(21);
            fr << "Galutinis(Med.)\n";
    }
    else{
            fr .width(15);
            fr << "Pavarde";
            fr .width(15);
            fr << "Vardas";
            fr .width(21);
            fr << "Galutinis(Vid.)\n";
    }
    for(int i=0; i<kiek; i++)
    {
        fr << std::setw(15);
        fr << Stud[i].vardas;
        fr << std::setw(15);
        fr << Stud[i].pavarde;
        fr << std::setw(20);
        fr <<std::fixed<<std::setprecision(2)<< Stud[i].galutinis << "\n";
    }
}

//rikiavimo funkcija
void rikiavimas(std::vector<mokinys> Stud, int kiek)
{
    for(int p=0; p<kiek; p++)
        std::sort(Stud[p].C.begin(), Stud[p].C.end());
}
