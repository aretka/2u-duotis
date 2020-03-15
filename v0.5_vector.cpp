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
using std::deque;
using std::list;
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

string IntToStr(int n)
{
    std::stringstream result;
    result << n;
    return result.str();
}

void vidurkioSkaiciavimas(deque <mokinys> &Stud)
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


int main()
{
    srand(time(NULL));
    ofstream outFile, outFile1, outFile2;
    ifstream inFile;
    int Number_of_files=2, sk=1000, kiekND = 4, nd, suma, kelint;
    string filename, eilute, vardas, pavarde;
    deque <mokinys> Stud, vargseliai;

        for(int i=0; i<Number_of_files; i++)
        {
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
        sort(Stud.begin(), Stud.end());

        //mokiniu padalinimas i dvi grupes, vargsiuku atskyrimas nuo kietiaku

        start = clock();
        vargseliai = skirstykStudentus(Stud);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu padalijimas i dvi grupes laikas: " <<time_taken <<" sec.\n";



        filename="vargsiukai" + IntToStr(sk) +".txt";
            outFile2.open(filename.c_str());
        for(int t=0; t<vargseliai.size(); t++)
        {
            outFile2 .width(16);
            outFile2 << vargseliai[t].vardas;
            outFile2 .width(16);
            outFile2 << vargseliai[t].pavarde ;
            outFile2 .width(22);
            outFile2 << std::fixed<<std::setprecision(2)<< vargseliai[t].galutinis <<"\n";
            t++;
        }


        filename="kietiakai" + IntToStr(sk) +".txt";
            outFile1.open(filename.c_str());
        for(int t=0; t<Stud.size(); t++)
        {
            outFile1 .width(16);
            outFile1 << Stud[t].vardas;
            outFile1 .width(16);
            outFile1 << Stud[t].pavarde ;
            outFile1 .width(22);
            outFile1 << std::fixed<<std::setprecision(2)<< Stud[t].galutinis <<"\n";
        }

        Stud.clear();
        sk*=10;
        outFile2.close();
        outFile1.close();
        inFile.close();
        cout <<"\n";
        }
  return 0;
};
