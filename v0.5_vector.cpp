#include "header.h"

int main()
{
    srand(time(NULL));
    ofstream outFile, outFile1, outFile2;
    ifstream inFile;
    int Number_of_files=5, sk=1000;
    string filename, filename1="vargsiukai.txt", filename2="kietiakai.txt", eilute, vardas, pavarde;
    vector <mokinys> Stud, vargseliai;
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
            outFile .width(15);
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
            Stud.push_back(mokinys());
            inFile >> Stud[q].vardas;
            inFile >> Stud[q].pavarde;
            inFile >> Stud[q].galutinis;
        }
        end = clock();
        double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu skaitymo laikas: " <<time_taken <<" sec.\n";


        //Studentu galutiniu rezultatu rikiavimas pagal galutini bala
        sort(Stud.begin(), Stud.end(), comparePagalGalutini);

        //mokiniu padalinimas i dvi grupes, vargsiuku atskyrimas nuo kietiaku

        start = clock();
        vargseliai = skirstykStudentus(Stud);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu padalijimas i dvi grupes laikas: " <<time_taken <<" sec.\n";

        //vargsiuku rasymas i faila
            outFile2.open(filename1.c_str());
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


        //kietiaku rasymas i faila
            outFile1.open(filename2.c_str());
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
