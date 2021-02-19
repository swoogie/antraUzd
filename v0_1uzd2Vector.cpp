// Ignas Bieksa
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <string>
#include <random>
#include <ctype.h>
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

int neRaide()
{
    int n;
    while(true)
    {
        cin >> n;
        if(!cin)
        {
            cout << "Iveskite tinkama reiksme: " << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            return n;
            break;
        }    
    }
}

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

void nd(studentoStruct* studentas, int i)
{
    int kartai = 0;
    int pazymys;
    string str1="0";
    cout << "Studento pazymiai (baige rasyti, paspauskite 'enter' 2 kartus): " << endl;
    
    while (str1.length()!=0)
    {
        cin.clear();
        cin.sync();
        getline(cin, str1);
        if(str1.length()!=0)
        {
            pazymys = stoi(str1);
            studentas[i].ndRez.push_back(pazymys);
            kartai++;
        }
    }    
    studentas[i].pazymiuSkaicius=kartai;
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
                    studentas[i].ndRez.push_back((rand()%(10)) + 1);
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
            nd(studentas, i);
        }

        cout << "Ar norite, kad egzamino balas butu sugeneruotas automatiskai? y/n" << endl;
        tinkamaReiksme(y);

        if(y == "Y" || y == "y")
        {
            studentas[i].egzamRez = (rand()%(10)) + 1;
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
    {
        cout << "Vardas" << std::setw(5+7) << "Pavarde" << std::setw(5+15) << "Vidurkis (med.)" << endl << "------------------------------------------" << endl;
        for(int i=0; i<studentuSkaicius; i++)
        {
            cout << studentas[i].vardas << std::setw(11-studentas[i].vardas.length()+studentas[i].pavarde.length()) << studentas[i].pavarde 
            << std::setw(13-studentas[i].pavarde.length()+3) << std::fixed << std::setprecision(2) << mediana(studentuSkaicius, studentas, i) << endl;
        }
                          
    }
    else
    {
        cout << "Vardas" << std::setw(5+7) << "Pavarde" << std::setw(5+15) << "Vidurkis (vid.)" << endl << "------------------------------------------" << endl;

        for(int i=0; i<studentuSkaicius; i++)
        cout << studentas[i].vardas << std::setw(11-studentas[i].vardas.length()+studentas[i].pavarde.length()) << studentas[i].pavarde 
        << std::setw(13-studentas[i].pavarde.length()+3) << std::fixed << std::setprecision(2) << vidurkis(studentuSkaicius, studentas, i) << endl;
    }
}

int main()
{
    cout << "Studentu skaicius: " << endl;
    int studentuSkaicius = neRaide();
    
    studentoStruct* studentas = new studentoStruct[studentuSkaicius];

    ivedimas(studentuSkaicius, studentas);
    isvedimas(studentuSkaicius, studentas);

    return 0;
}