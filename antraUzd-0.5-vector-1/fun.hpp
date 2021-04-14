#ifndef fun_hpp
#define fun_hpp

#include "lib.hpp"
#include "struct.hpp"
#include "math.hpp"

void tinkamaReiksme(string &y);
int neRaide();
void sortedIsvedimas(vector<studentoSarStruct> studentas);
void sarIsvedimas(vector<studentoSarStruct> studentas);
ifstream failoPasirinkimas();
void skaitymas(vector<studentoSarStruct> &studentas, bool tipas);
void isvedimas(int studentuSkaicius, studentoStruct* studentas);
void nd(studentoStruct* studentas, int i);
void ivedimas(int studentuSkaicius, studentoStruct* studentas);

#endif