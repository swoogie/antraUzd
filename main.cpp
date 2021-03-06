 // Ignas Bieksa

#include "RandInt.hpp"
#include "libraries.hpp"
#include "strukturos.hpp"
#include "failoFun.hpp"

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


int main()
{   

    cout << "Ar skaityti is failo? y/n: " << endl;    
    string y;
    tinkamaReiksme(y);
    if(y == "Y" || y == "y")
    {
        int studentuSkaicius=0;
        studentoStruct* studentas = skaitymas(studentuSkaicius);
        
        auto start = std::chrono::high_resolution_clock::now();

        isvedimas(studentuSkaicius, studentas);

        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << "elementu uzpildymas uztruko: "<< diff.count() << " s\n";

        delete studentas;
    }
    else
    {
        cout << "Studentu skaicius: " << endl;
        int studentuSkaicius = neRaide();
        studentoStruct* studentas = new studentoStruct[studentuSkaicius];
        ivedimas(studentuSkaicius, studentas);
        auto start = std::chrono::high_resolution_clock::now();
        isvedimas(studentuSkaicius, studentas);
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << "elementu uzpildymas uztruko: "<< diff.count() << " s\n";
        delete studentas; 
    }
 
    return 0;
}

