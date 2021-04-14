#include "newFile.hpp"

const string vardas[15] = {"Dziuzepe", "Dzeremajus", "Kornelijus", "Apolinaras", 
"Mikelandzelas", "Abrahimas", "Gedgaudas", "Girrvydas", "Edomondas", "Drovydas", 
"Fiulgensas", "Adalberta", "Leopolda", "Prudencija", "Regimalda"};

const string pavarde[15] = {"Jablanskas", "Donelaitis", "Auditera", "Ochmanas", "Zabaliuna", "Abaranas", "Ecka",
 "Ezynas", "Carkus", "Carkauskas", "Ceberekas",
"Ferdinandas", "Fabricijus", "Farsavicius", "Fenclavas"};

void print(vector<studentoStruct> studStruct)
{
    ofstream pr("genFile.txt");
    pr << "Vardas" << setw(15+7) << "Pavarde" << setw(15+7) << 
    "ND1 " << "ND2 " << "ND3 " << "ND4 " << "ND5 " << "ND6 " << 
    "ND7 " << "ND8 " << "ND9 " << "ND10 " << "EGZR" << endl  <<
    "-------------------------------------------------------------------------------------------------" << endl;
    string temp;

    for(int i=0; i<studStruct.size(); i++)
    {
        temp = studStruct[i].vardas + " " + studStruct[i].pavarde;


        for(int j=0;j<studStruct[i].ndRez.size();j++)
        {
            string stemp = std::to_string(studStruct[i].ndRez[j]);
            temp += " " + stemp;
        }
        string stemp = std::to_string(studStruct[i].egzamRez);
        temp += " " + stemp;
        temp += "\n";
        pr << temp;
    }

    pr.close();
} 


void gen()
{
    auto start = std::chrono::high_resolution_clock::now();
    
    RandInt rndPaz {0, 10};
    RandInt rndVard {0, 14};

    int studentuSkaicius;
    
    cout << "Studentu skaicius: " << endl;
    cin >> studentuSkaicius;


    vector<studentoStruct> studStruct;
    
    for(int i=0;i<studentuSkaicius;i++)
    {
        studentoStruct studBuff;
        studBuff.pazymiuSkaicius = 10;
        studBuff.vardas = vardas[rndVard()];
        studBuff.pavarde = pavarde[rndVard()];
        for(int j=0;j<studBuff.pazymiuSkaicius;j++)
            {
                studBuff.ndRez.push_back(rndPaz());
            }
        studBuff.egzamRez=rndPaz();

        studStruct.push_back(studBuff);
    }

    sort(studStruct.begin(), studStruct.end());
    print(studStruct);
    studStruct.clear();

    auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << "\nGeneravimas uztruko: "<< diff.count() << " s\n";
}