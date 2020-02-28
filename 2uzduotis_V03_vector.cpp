#include "header.h"

int main()
{
    bool a=false;
    std::string eilute, stri;
    std::stringstream ss;
     srand(time(NULL));
     double zmogus, namdarb, egz, arba, skait;
     int kiek=0, sk, nd, suma=0, ar, kiekrand, skaitymas, vidarmed;
     std::cout << "Jeigu norite kad duomenys nuskaitytumete is failo spauskite 1, o jeigu norite duomenis patys suvesti spauskite 2:"<<std::endl;
     std::cin >> skait;
     while (std::cin.fail() || skait>2 || skait<1 || (skait>1 && skait<2))
     {
         std::cin.clear();
         std::cin.ignore(1000,'\n');
         std::cout <<"Ivyko klaida, Jeigu norite kad duomenys nuskaitytumete is failo spauskite 1, o jeigu norite duomenis patys suvesti spauskite 2:"<<std::endl;
         std::cin >>zmogus;
     }
     skaitymas = (int)skait;
     std::vector <mokinys> Stud;
     if(skait==1)
     {
       //*****************************************************//
       //*****Skaiciavimas skaitant duomenis is failo*********//
       //*****************************************************//
         int ndkiek=0, duomenukiekis = 0, kelintas=0;
         std::ifstream fd ("studentai10000.txt.txt");

         std::stringstream buffer;
         if(fd)
         {
             buffer << fd.rdbuf();
             fd.close();
             buffer >> stri;
             buffer >> stri;
         while(true)
         {
             buffer >> stri;
             if(stri=="Egz.")
             {
                 break;
             }
             else
             ndkiek++;
         }
         while(!buffer.eof())
         {
             bool check=false;
             Stud.push_back(mokinys());

             buffer >> Stud[kiek].vardas >> Stud[kiek].pavarde;
                 for(int i=0; i<ndkiek; i++)
                 {
                     buffer >> nd;
                     if(buffer.eof())
                     {
                         Stud[kiek].egzaminas=nd;
                         check = true;
                         break;
                     }
                     Stud[kiek].n++;
                     Stud[kiek].C.push_back(nd);
                 }
                 if(check == true)
                 {
                     kiek++;
                     break;
                 }
                 buffer >> Stud[kiek].egzaminas;
                 kiek++;
         }
         }
         else{
            std::cout << "Failas tuscias arba neegzistuoja" <<std::endl;
            main();
         }
     }
     else{
       //*******************************************//
       //*****Skaiciavimas ivedant duomenis*********//
       //*******************************************//
          std::cout << "Iveskite mokiniu skaiciu: "<<std::endl;
          std::cin>>zmogus;

         while (std::cin.fail() || zmogus!=(int)zmogus || zmogus==0 || zmogus<0)
         {
             std::cin.clear();
             std::cin.ignore(1000,'\n');
             std::cout <<"Ivyko klaida, iveskite naturaluji skaiciu(didesni uz 0):"<<std::endl;
             std::cin >>zmogus;
         }
         kiek=(int)zmogus;
         for(int i=0; i<kiek; i++)
         {
             Stud.push_back(mokinys());
             sk=1;
             std::cout << "Iveskite mokinio varda: "<<std::endl;
             std::cin >> Stud[i].vardas;

             std::cout << "Iveskite mokinio pavarde: "<<std::endl;
             std::cin >> Stud[i].pavarde;

             std::cout << "Ar norite kad sugeneruotu random namu darbu rezultatus?(spauskite 1 jeigu taip arba 2 jeigu ne): "<<std::endl;
             std::cin >> arba;
             while (std::cin.fail() || arba!=(int)arba ||arba<1 || arba>2 || (arba>1&&arba<2))
             {
                 std::cin.clear();
                 std::cin.ignore(1000,'\n');
                 std::cout <<"Ivyko klaida, kad sugeneruotu random namu darbu rezultatus spauskite 1, jeigu ne, spauskite 2:"<<std::endl;
                 std::cin >>arba;
             }
             ar=(int)arba;
             if(ar == 1)
             {
                 kiekrand=rand()%11;
                 for(int q=0; q<kiekrand; q++)
                 {
                   Stud[i].C.push_back(rand()%11);
                 }
                 Stud[i].egzaminas = rand()%11;
             }
             else {
                while(true)
               {

                 std::cout << "Iveskite mokinio namu darbu ivertinima, jeigu tai paskutinis namu darbas iveskite -1: "<<std::endl;
                 std::cin >> namdarb;
                 while (std::cin.fail() || namdarb<-1 || namdarb>10 || namdarb!=(int)namdarb)
                 {
                     std::cin.clear();
                     std::cin.ignore(1000,'\n');
                     std::cout <<"Ivyko klaida, iveskite namu darbu ivertinima intervale nuo 0 iki 10, jeigu tai paskutinis namu darbas iveskite -1:"<<std::endl;
                     std::cin >>namdarb;
                 }
                 nd=(int)namdarb;
                 if(nd==-1)
                    break;
                 else{
                    Stud[i].C.push_back(nd);
                    Stud[i].n++;
                 }
              }

             std::cout << "Iveskite mokinio egzamino rezultata: "<<std::endl;
             std::cin >> egz;
             while (std::cin.fail() || egz<0 || egz>10 || egz!=(int)egz)
             {
                 std::cin.clear();
                 std::cin.ignore(1000,'\n');
                 std::cout <<"Ivyko klaida iveskite skaiciu intervale nuo 0 iki 10:"<<std::endl;
                 std::cin >> egz;
             }
             Stud[i].egzaminas = (int)egz;
             }
         }
     }
     //**********************************//
     //Vidurkio arba medianos uzklausimas//
     //**********************************//
         std::cout << "Spauskite 1 jei norite kad programa isvestu vidurki arba 2 jeigu norite kad programa isvestu mediana: "<<std::endl;
         std::cin >> sk;
         while (std::cin.fail()||sk>2||sk<1)
             {
                 std::cin.clear();
                 std::cin.ignore(1000,'\n');
                 std::cout <<"Ivyko klaida, iveskite 1 jei norite kad programa isvestu vidurki arba 2 jeigu norite kad programa isvestu mediana:"<<std::endl;
                 std::cin >>sk;
             }
         if(sk==1)
         {
             //vidurkio skaiciavimas bei galutinio balo skaiciavimas
             vidarmed = 2;
             for(int i=0; i<kiek; i++)
             {
                 suma=0;
                 for(int ii=0; ii<Stud[i].n; ii++)
                 {
                     suma+=Stud[i].C[ii];
                 }

                  try{
                     Stud[i].vidurkis = suma/Stud[i].n;
                     Stud[i].galutinis = (0.4*Stud[i].vidurkis)+(0.6*Stud[i].egzaminas);
                  }
                  catch(std::exception& e){
                      Stud[i].n = 0;
                      Stud[i].galutinis = 0.6*Stud[i].egzaminas;
                  }



             }
         }
         else if(sk==2)
         {
             vidarmed = 1;
             //medianos skaiciavimas bei galutinio balo skaiciavimas
             int kelintas;
             rikiavimas(Stud, kiek);
             for(int i=0; i<kiek; i++)
             {
                 if(Stud[i].n==0)
                 {
                    Stud[i].galutinis = (0.6*Stud[i].egzaminas);
                 }
                 else{
                    if(Stud[i].n%2==0)
                 {
                     kelintas = Stud[i].n/2;
                     Stud[i].vidurkis = 1.0*(Stud[i].C[kelintas-1]+Stud[i].C[kelintas])/2;
                 }
                 else
                 {
                  kelintas = Stud[i].n/2+1;
                  Stud[i].vidurkis = Stud[i].C[kelintas-1];
                 }
                  Stud[i].galutinis = (0.4*Stud[i].vidurkis)+(0.6*Stud[i].egzaminas);
                 }

             }

         }
         spausdinimas(Stud, kiek, vidarmed);

  return 0;
};
