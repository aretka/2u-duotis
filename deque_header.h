#ifndef HEADER_H
#define HEADER_H


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
};

string IntToStr(int);
deque<mokinys> skirstykStudentus(deque<mokinys>&);
void GalBalas(deque<mokinys>&);
bool comparePagalVarda(const mokinys&, const mokinys&);
bool comparePagalPavarde(const mokinys&, const mokinys&);
bool comparePagalGalutini(const mokinys&, const mokinys&);

#endif
