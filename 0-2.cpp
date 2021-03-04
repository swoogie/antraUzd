 // Ignas Bieksa
#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>
#include <sstream>
#include <string>
#include <random>
#include <ctype.h>
#include <algorithm> 
#include <fstream>
#include <chrono>
#include "RandInt.hpp"

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::vector;
using std::sort;
using std::ifstream;
using std::ofstream;
using std::setw;
using std::fixed;
using std::setprecision;
using std::stringstream;

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
    RandInt rnd{1,10};
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
                    studentas[i].ndRez.push_back(rnd());
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
            studentas[i].egzamRez = rnd();
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

void isvedimas(int studentuSkaicius, studentoStruct* studentas)
{   
    ofstream pr("rez.txt");
    
    pr << "Vardas" << setw(15+7) << "Pavarde" << setw(15+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(int i=0; i<studentuSkaicius; i++)
    {
        pr << studentas[i].vardas << setw(21-studentas[i].vardas.length()+studentas[i].pavarde.length()) << studentas[i].pavarde 
        << setw(23-studentas[i].pavarde.length()+3) << fixed << setprecision(2) << mediana(studentuSkaicius, studentas, i) 
        << setw(20-3+3) << fixed << setprecision(2) << vidurkis(studentuSkaicius, studentas, i) << endl;
    }
}



ifstream failoPasirinkimas()
{
    string failas;
    cout << "Pasirinkite faila: \n 1. 10000 \n 2. 100000 \n 3. 1000000" << endl;
    cin >> failas;
    while(failas!="1" && failas!="2" && failas!="3")
    {   
            cout << "Iveskite tinkama reiksme (1,2 arba 3)" << endl;
            cin.clear();
            cin >> failas;
    }

    if(failas=="1")
    {
        ifstream rd("10000.txt");
        return rd;
    }
    else if(failas=="2")
    {  
        ifstream rd("100000.txt");
        return rd;
    }
    ifstream rd("1000000.txt");
    return rd;
}

/*void skaitymas()
{
    auto start = std::chrono::high_resolution_clock::now();
    string eil;
    ifstream rd = failoPasirinkimas();
    ofstream pr("rez.txt");
    if (rd.is_open())
    {
        while(rd.good()) 
        {
            getline(rd,eil);
        }
        rd.close();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end-start;
    std::cout << "100 000 elementų užpildymas užtruko: "<< diff.count() << " s\n";
}*/

studentoStruct* skaitymas(int &studentuSkaicius)
{
    string eil;
    stringstream buffer;
    ifstream rd = failoPasirinkimas();
    getline(rd, eil);
    eil.clear();
    while (!rd.eof())
    {
        getline(rd, eil);
        buffer << eil << "\n";
        studentuSkaicius++;
    }    
    
    studentoStruct* studentas = new studentoStruct[studentuSkaicius];
    for(int i=0;i<studentuSkaicius;i++)
    {
        stringstream linestream;
        getline(buffer,eil);
        linestream << eil;
        linestream >> studentas[i].vardas >> studentas[i].pavarde;
        while(!linestream.eof())
        {      
            double paz;
            linestream >> paz;
            if(linestream.eof())
                studentas[i].egzamRez = paz;
            else
            {
                studentas[i].ndRez.push_back(paz);
                studentas[i].pazymiuSkaicius++;
            }             
        }
    }

    sort(studentas, studentas + studentuSkaicius);

    return studentas;
}

int main()
{   

    cout << "Ar skaityti is failo? y/n: " << endl;    
    string y;
    tinkamaReiksme(y);
    if(y == "Y" || y == "y")
    {
        int studentuSkaicius=0;
        studentoStruct* studentas = skaitymas(studentuSkaicius);
        isvedimas(studentuSkaicius, studentas);
        delete studentas;
    }
    else
    {
        cout << "Studentu skaicius: " << endl;
        int studentuSkaicius = neRaide();
        studentoStruct* studentas = new studentoStruct[studentuSkaicius];
        ivedimas(studentuSkaicius, studentas);
        isvedimas(studentuSkaicius, studentas);
        delete studentas; 
    }

    
    
    return 0;
}

