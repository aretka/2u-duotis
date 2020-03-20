#include <bits/stdc++.h>
#include <vector>
#include <limits>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <sys/time.h>
#include <list>


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


};
bool operator <( const mokinys& a, const mokinys& b ){
    return a.galutinis < b.galutinis;
}
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


int main()
{
    srand(time(NULL));
    ofstream outFile, outFile1, outFile2;
    ifstream inFile;
    int Number_of_files=5, sk=1000, kiekND = 4, nd, suma, kelint;
    string filename, eilute, vardas, pavarde;
    list <mokinys> Stud, vargseliai;
    list <mokinys>::iterator it;
    mokinys duomenys;
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
            outFile .width(10);
            outFile << std::fixed<< std::setprecision(2) << 1.0*rand()/RAND_MAX*10;
            outFile << "\n";
        }
        outFile.close();

        inFile.open(filename.c_str());
        // duomenu skaitymas
        clock_t start, end;
        start = clock();
        for(int q=0; q<sk; q++)
        {
            inFile >> duomenys.vardas;
            inFile >> duomenys.pavarde;
            inFile >> duomenys.galutinis;
            Stud.push_back(duomenys);
        }
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu skaitymo laikas: " <<time_taken <<" sec.\n";
        sort(Stud.begin(), Stud.end())
        //mokiniu padalinimas i dvi grupes, vargsiuku atskyrimas nuo kietiaku

        start = clock();
        vargseliai = skirstykStudentus(Stud);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu padalijimas i dvi grupes laikas: " <<time_taken <<" sec.\n";

        filename="vargsiukai" + IntToStr(sk) +".txt";
            outFile2.open(filename.c_str());

            it = vargseliai.begin();
        while(it!=vargseliai.end())
        {
            outFile2 .width(16);
            outFile2 << it->vardas;
            outFile2 .width(16);
            outFile2 << it->pavarde ;
            outFile2 .width(22);
            outFile2 << std::fixed<<std::setprecision(2)<< it->galutinis <<"\n";
            it++;
        }

        filename="kietiakai" + IntToStr(sk) +".txt";
            outFile1.open(filename.c_str());

            it = Stud.begin();
        while(it!=Stud.end())
        {
            outFile1 .width(16);
            outFile1 << it->vardas;
            outFile1 .width(16);
            outFile1 << it->pavarde ;
            outFile1 .width(22);
            outFile1 << std::fixed<<std::setprecision(2)<< it->galutinis <<"\n";
            it++;
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
