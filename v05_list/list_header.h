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
int egzaminas;
float galutinis;

 bool operator<( const mokinys& a) const {
 return galutinis < a.galutinis;
 }
};

string IntToStr(int);
list<mokinys> skirstykStudentusNetrinant(list<mokinys>&);
list<mokinys> skirstykStudentusTrinant(list<mokinys>&);

#endif
