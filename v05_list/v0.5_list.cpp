#include "list_header.h"

int main()
{
    srand(time(NULL));
    ofstream outFile, outFile1, outFile2;
    ifstream inFile;
    int Number_of_files=5, sk=1000;
    string filename, eilute, vardas, pavarde, filename1 = "kietiakai.txt", filename2 = "vargsiukai.txt";
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
        //sort(Stud.begin(), Stud.end());
        //mokiniu padalinimas i dvi grupes, vargsiuku atskyrimas nuo kietiaku

        start = clock();
        vargseliai = skirstykStudentusTrinant(Stud);
        end = clock();
        time_taken = double(end - start) / double(CLOCKS_PER_SEC);
        cout << sk <<" irasu padalijimas i dvi grupes laikas: " <<time_taken <<" sec.\n";

            outFile2.open(filename2.c_str());

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

            outFile1.open(filename1.c_str());

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
        vargseliai.clear();
        sk*=10;
        outFile2.close();
        outFile1.close();
        inFile.close();
        cout <<"\n";
        }
  return 0;
};
