#include "math.hpp"

double vidurkis(int studentuSkaicius, studentoStruct* studentas, int i)
{
    double avrg=0;
    for(int j=0; j<studentas[i].pazymiuSkaicius; j++)
        avrg += studentas[i].ndRez[j];
            
    avrg = ((avrg / studentas[i].pazymiuSkaicius)*0.4)+(0.6*studentas[i].egzamRez);
    return avrg;     

    studentas[i].ndRez.clear();   
}

double mediana(int studentuSkaicius, studentoStruct* studentas, int i)
{
    sort(studentas[i].ndRez.begin(), studentas[i].ndRez.end());
    
    if((studentas[i].pazymiuSkaicius)%2 == 0)
        return (((studentas[i].ndRez[(studentas[i].pazymiuSkaicius/2)-1]+studentas[i].ndRez[(studentas[i].pazymiuSkaicius/2)])/2)*0.4)+(0.6*studentas[i].egzamRez);
    else
        return (studentas[i].ndRez[studentas[i].pazymiuSkaicius/2]*0.4)+(0.6*studentas[i].egzamRez);  

    studentas[i].ndRez.clear();
}

double sarVidurkis(vector<double> pazymiai, int egzamRez)
{
    double avrg=0;
    for(int i=0; i<pazymiai.size(); i++)
        avrg += pazymiai[i];
            
    avrg = ((avrg/pazymiai.size())*0.4)+(0.6*egzamRez);
    return avrg;    
}

double sarMediana(vector<double> pazymiai, int egzamRez)
{
    sort(pazymiai.begin(), pazymiai.end());
    
    if((pazymiai.size())%2 == 0)
        return (((pazymiai[(pazymiai.size()/2)-1]+pazymiai[(pazymiai.size()/2)])/2)*0.4)+(0.6*egzamRez);
    else
        return (pazymiai[pazymiai.size()/2]*0.4)+(0.6*egzamRez);  
}