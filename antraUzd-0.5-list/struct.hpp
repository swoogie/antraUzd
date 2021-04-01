#ifndef struct_hpp
#define struct_hpp

#include "lib.hpp"

struct studentoSarStruct
{
    string vardas, pavarde;
    double medRez;
    double avgRez;

    /*bool operator < (const studentoSarStruct &stud) const
    {
        return vardas.compare(stud.vardas) < 0;
    }*/
};

struct studentoStruct
{
    string vardas, pavarde;
    int pazymiuSkaicius=0;
    vector<double> ndRez;
    double egzamRez;

    bool operator < (const studentoStruct &stud) const
    {
        return vardas.compare(stud.vardas) < 0;
    }
};

#endif