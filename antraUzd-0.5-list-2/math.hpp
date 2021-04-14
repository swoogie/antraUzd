#ifndef math_hpp
#define math_hpp

#include "lib.hpp"
#include "struct.hpp"

double vidurkis(int studentuSkaicius, studentoStruct* studentas, int i);
double mediana(int studentuSkaicius, studentoStruct* studentas, int i);
double sarVidurkis(vector<double> pazymiai, int egzamRez);
double sarMediana(vector<double> pazymiai, int egzamRez);
#endif