#include <bits/stdc++.h>
#include <vector>
#include <limits>

struct mokinys{
std::string vardas, pavarde;
std::vector<int> C={};
int n=0, egzaminas;
float vidurkis, galutinis;
};

void spausdinimas(mokinys Stud[], int kiek)
{

    for(int i=0; i<kiek; i++)
    {
        std::cout .width(15);
        std::cout << Stud[i].vardas;
        std::cout .width(15);
        std::cout << Stud[i].pavarde;
        std::cout .width(20);
        std::cout <<std::fixed<<std::setprecision(2)<< Stud[i].galutinis<<std::endl;
    }
}
void rikiavimas(mokinys Stud[], int kiek)
{
    for(int p=0; p<kiek; p++)
    {
        for(int i=0; i<Stud[p].n-1; i++)
        {
            for(int ii=i+1; ii<Stud[p].n; ii++)
            {
                if(Stud[p].C[i] > Stud[p].C[ii])
                {
                    std::swap(Stud[p].C[i], Stud[p].C[ii]);
                }
            }
        }
    }

}
int main()
{
    double zmogus, namdarb, egz, arba;
 int kiek, sk, nd, suma=0, ar, kiekrand;
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
 mokinys Stud[kiek];

 for(int i=0; i<kiek; i++)
 {
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
         std::cout <<"Ivyko klaida, iveskite naturaluji skaiciu(didesni uz 0):"<<std::endl;
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
 std::cout << "Spauskite 1 jei norite kad programa isvestu vidurki arba 2 jeigu norite kad programa isvestu mediana: "<<std::endl;
 std::cin >> sk;
 while (std::cin.fail()||sk>2||sk<1)
     {
         std::cin.clear();
         std::cin.ignore(1000,'\n');
         std::cout <<"Ivyko klaida iveskite 1 jei norite kad programa isvestu vidurki arba 2 jeigu norite kad programa isvestu mediana:"<<std::endl;
         std::cin >>sk;
     }
 if(sk==1)
 {
     //vidurkio skaiciavimas bei galutinio balo skaiciavimas
     for(int i=0; i<kiek; i++)
     {
         suma=0;
         for(int ii=0; ii<Stud[i].n; ii++)
         {
             suma+=Stud[i].C[ii];
         }
         if(Stud[i].n==0)
         {
             Stud[i].galutinis = (0.6*Stud[i].egzaminas);
         }
         else{
            Stud[i].vidurkis = 1.0*suma/Stud[i].n;
            Stud[i].galutinis = (0.4*Stud[i].vidurkis)+(0.6*Stud[i].egzaminas);
         }



     }
     std::cout .width(15);
     std::cout << "Pavarde";
     std::cout .width(15);
     std::cout << "Vardas";
     std::cout .width(20);
     std::cout << "Galutinis(Vid.)"<<std::endl;
     spausdinimas(Stud, kiek);
 }
 else if(sk==2)
 {
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

     std::cout .width(15);
     std::cout << "Pavarde";
     std::cout .width(15);
     std::cout << "Vardas";
     std::cout .width(20);
     std::cout << "Galutinis(Med.)"<<std::endl;
     spausdinimas(Stud, kiek);
 }


  return 0;
};
