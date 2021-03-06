#ifndef STRUKTUROS_HPP
#define STRUKTUROS_HPP

#include "libraries.hpp"

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