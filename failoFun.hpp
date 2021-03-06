#ifndef FAILOFUN_HPP
#define FAILOFUN_HPP

#include "strukturos.hpp"
#include "libraries.hpp"

double vidurkis(int studentuSkaicius, studentoStruct* studentas, int i);
double mediana(int studentuSkaicius, studentoStruct* studentas, int i);
void isvedimas(int studentuSkaicius, studentoStruct* studentas);
ifstream failoPasirinkimas();
studentoStruct* skaitymas(int &studentuSkaicius);

#endif