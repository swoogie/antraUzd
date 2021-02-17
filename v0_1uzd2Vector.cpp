// Ignas Bieksa
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <random>
#include <algorithm> 

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::sort;

struct studentoStruct
{
    string vardas, pavarde;
    int pazymiuSkaicius;
    vector<double> ndRez;
    double egzamRez;
};

void tinkamaReiksme(string &y)
{
    while (true)
    {
        cin >> y;
        if(y == "Y" || y == "y" || y == "N" || y == "n")
            break;
        else
            cout << "Iveskite tinkama reiksme: "<< endl;
    }
}

void nd(studentoStruct* studentas, int kartai, int i)
{
    cout << "Studento pazymys: " << endl;
    int pazymys;
    cin >> pazymys;
    studentas[i].ndRez.push_back(pazymys);

    cout << "Ar norite prideti dar viena pazymi? y/n" << endl;
    string y;
    tinkamaReiksme(y);

    if(y == "Y" || y == "y")
    {
        kartai++;
        nd(studentas, kartai, i);
    }
    else
        studentas[i].pazymiuSkaicius = kartai+1;
}

void ivedimas(int studentuSkaicius, studentoStruct* studentas)
{   
    srand(time(0));
    for(int i = 0; i < studentuSkaicius; i++)
    {
        cout << "Studento vardas: " << endl;
        cin >> studentas[i].vardas;
        cout << "Studento pavarde: " << endl;
        cin >> studentas[i].pavarde;

        cout << "Ar zinote pazymiu skaiciu? y/n" << endl;
        string y;

        tinkamaReiksme(y);
        
        if(y == "Y" || y == "y")
        {
            cout << "Pazymiu skaicius: " << endl;
            cin >> studentas[i].pazymiuSkaicius;

            cout << "Ar norite, kad pazymiai butu sugeneruoti automatiskai? y/n" << endl;
            tinkamaReiksme(y);
            
            if(y == "Y" || y == "y")
            {
                
                for(int j=0;j<studentas[i].pazymiuSkaicius;j++)
                {
                    studentas[i].ndRez.push_back((rand()%(10 - 1 + 1)) + 1);
                    cout << studentas[i].ndRez[j] << " ";
                }
                cout << endl;
            }
            else 
            {
                cout << "Pazymiai: " << endl;
                for(int j=0;j<studentas[i].pazymiuSkaicius;j++)
                {
                    int pazymys;
                    cin >> pazymys;
                    studentas[i].ndRez.push_back(pazymys);
                }
                   
            }
            
        }
        else
        {
            int kartai = 0;
            nd(studentas, kartai, i);
        }

        cout << "Ar norite, kad egzamino balas butu sugeneruotas automatiskai? y/n" << endl;
        tinkamaReiksme(y);

        if(y == "Y" || y == "y")
        {
            studentas[i].egzamRez = (rand()%(10 - 1 + 1)) + 1;
            cout << studentas[i].egzamRez << endl;
        }
        else
        {
            cout << "Studento egzamino balas: " <<endl;
            cin >> studentas[i].egzamRez;
        }
        
    }
}

double vidurkis(int studentuSkaicius, studentoStruct* studentas, int i)
{
    double avrg=0;
    for(int j=0; j<studentas[i].pazymiuSkaicius; j++)
        avrg += studentas[i].ndRez[j];
            
        avrg = ((avrg / studentas[i].pazymiuSkaicius)*0.4)+(0.6*studentas[i].egzamRez);
        return avrg;        
}

double mediana(int studentuSkaicius, studentoStruct* studentas, int i)
{
    sort(studentas[i].ndRez.begin(), studentas[i].ndRez.end());
    
    if((studentas[i].pazymiuSkaicius)%2 == 0)
        return (((studentas[i].ndRez[(studentas[i].pazymiuSkaicius/2)-1]+studentas[i].ndRez[(studentas[i].pazymiuSkaicius/2)])/2)*0.4)+(0.6*studentas[i].egzamRez);
    else
        return (studentas[i].ndRez[studentas[i].pazymiuSkaicius/2]*0.4)+(0.6*studentas[i].egzamRez);  
}

void isvedimas(int studentuSkaicius, studentoStruct* studentas)
{   
    cout << "Ar vietoje vidurkio skaiciuoti mediana? y/n" << endl;
    string y;
    tinkamaReiksme(y);
    if(y == "Y" || y == "y")
    for(int i=0; i<studentuSkaicius; i++)
        cout << studentas[i].vardas << " " << studentas[i].pavarde 
        << " " << std::setprecision(3) << mediana(studentuSkaicius, studentas, i) << endl;
    else
    for(int i=0; i<studentuSkaicius; i++)
        cout << studentas[i].vardas << " " << studentas[i].pavarde 
        << " " << std::setprecision(3) << vidurkis(studentuSkaicius, studentas, i) << endl;
}

int main()
{
    int studentuSkaicius;

    cout << "Studentu skaicius: " << endl;
    cin >> studentuSkaicius;
    
    studentoStruct* studentas = new studentoStruct[studentuSkaicius];

    ivedimas(studentuSkaicius, studentas);
    isvedimas(studentuSkaicius, studentas);

    return 0;
}