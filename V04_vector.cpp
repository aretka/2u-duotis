#include <bits/stdc++.h>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <sys/time.h>


using std::string;
using std::vector;
using std::ofstream;
using std::ifstream;
using std::sort;
using std::cout;
using std::cin;
using std::endl;


struct mokinys{
string vardas, pavarde;
vector<int> C;
int n=0, egzaminas;
float vidurkis, galutinis;

bool operator < (const mokinys& rhs) const {
        return galutinis < rhs.galutinis;
    }
};

void spausdinimas( vector<mokinys> Stud, int kiek, int vidarmed)
{
    ofstream fr ("kursiokai.txt");
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
        fr << std::fixed<<std::setprecision(2)<< Stud[i].galutinis << "\n";
    }
}

//rikiavimo studentu namu darbu rikiavimas
void rikiavimas(vector<mokinys> Stud, int kiek)
{
    for(int p=0; p<Stud.size(); p++)
        sort(Stud[p].C.begin(), Stud[p].C.end());
}



string IntToStr(int n)
{
    std::stringstream result;
    result << n;
    return result.str();
}

void vidurkioSkaiciavimas(vector <mokinys> &Stud)
{
    int suma;
    for(int r=0; r<Stud.size(); r++)
            {
              suma=0;
                for(int ii=0; ii<Stud[r].C.size(); ii++)
                {
                    suma+=Stud[r].C[ii];
                }
                if(suma == 0)
                {
                    Stud[r].galutinis = 0.6*Stud[r].egzaminas;
                }else{
                    cout << "";
                    Stud[r].vidurkis = 1.0*suma/Stud[r].C.size();
                    Stud[r].galutinis = (0.4*Stud[r].vidurkis)+(0.6*Stud[r].egzaminas);
                }
          }
}

void atskyrimas(vector <mokinys> Stud, int &kelint)
{
    for(int i=0; i<Stud.size(); i++)
    {
        if(Stud[i].galutinis >= 5)
        {
            kelint = i;
            break;
        }
        else if(i+1==Stud.size())
            kelint = i;
    }
}


int main()
{
    srand(time(NULL));
    ofstream outFile, outFile1, outFile2;
    ifstream inFile;
    int Number_of_files=5, sk=10000000, kiekND = 4, nd, suma, t=0, kelint;
    string filename, eilute, vardas, pavarde;
    vector <mokinys> Stud;


        filename="file_" + IntToStr(sk) +".txt";
        outFile.open(filename.c_str());
        for(int ii=0; ii < sk; ii++)
        {
            vardas = "Vardas" + IntToStr(ii+1);
            pavarde = "Pavarde" + IntToStr(ii+1);
            outFile .width(15);
            outFile << vardas;
            outFile .width(15);
            outFile << pavarde ;
            for(int p=0; p<kiekND; p++)
            {
                outFile .width(10);
                outFile << rand()%11;
            }
            outFile << "\n";
        }
        outFile.close();
        cout << "Failas uzdarytas\n";

        inFile.open(filename.c_str());
        // duomenu skaitymas
        clock_t start, end;
        start = clock();
        for(int q=0; q<sk; q++)
        {
            Stud.push_back(mokinys());
            inFile >> Stud[q].vardas;
            inFile >> Stud[q].pavarde;
            for(int w=0; w<kiekND-1; w++)
            {
                inFile >> nd;
                Stud[q].C.push_back(nd);
            }
            inFile >> Stud[q].egzaminas;
        }
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu skaitymo laikas: " <<time_taken <<" sec.\n";
        //Galutinio balo skaiciavimas skaiciavimas
        vidurkioSkaiciavimas(Stud);


        //Studentu galutiniu rezultatu rikiavimas
        start = clock();
        sort(Stud.begin(), Stud.end());
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu rusiavimo laikas didejimo tvarka su sort funkcija: " <<time_taken <<" sec.\n";
        //mokiniu padalinimas i dvi grupes
        t=0;

        //Vargsiuku atskyrimas nuo kietiaku
        start = clock();
        atskyrimas(Stud, kelint);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu padalijimas i dvi grupes laikas: " <<time_taken <<" sec.\n";


        start = clock();
        filename="vargsiukai" + IntToStr(sk) +".txt";
            outFile2.open(filename.c_str());
        while(Stud[t].galutinis < 5)
        {
            outFile2 .width(16);
            outFile2 << Stud[t].vardas;
            outFile2 .width(16);
            outFile2 << Stud[t].pavarde ;
            outFile2 .width(22);
            outFile2 << std::fixed<<std::setprecision(2)<< Stud[t].galutinis <<"\n";
            t++;
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu nelaimingu rasymas i faila laikas: " <<time_taken <<" sec.\n";

        start = clock();
        filename="kietiakai" + IntToStr(sk) +".txt";
            outFile1.open(filename.c_str());
        while(Stud[t].galutinis >= 5)
        {
            outFile1 .width(16);
            outFile1 << Stud[t].vardas;
            outFile1 .width(16);
            outFile1 << Stud[t].pavarde ;
            outFile1 .width(22);
            outFile1 << std::fixed<<std::setprecision(2)<< Stud[t].galutinis <<"\n";
            t++;
        }
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu kietiaku rasymas i faila laikas: " <<time_taken <<" sec.\n";


        outFile2.close();
        outFile1.close();
        inFile.close();


  return 0;
};
