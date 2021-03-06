#include "libraries.hpp"
#include "strukturos.hpp"
#include "failoFun.hpp"

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

studentoStruct* skaitymas(int &studentuSkaicius)
{
    string eil;
    stringstream buffer;
    ifstream rd = failoPasirinkimas();

    try
    {
        if(rd.fail()) throw "Nepavyko atidaryti failo"; 
    }
    catch(const char * e)
    {
        std::cerr << e << endl;
        exit(EXIT_FAILURE);
    }

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
            try{
                if(paz > 10 || paz < 1)
                {
                    throw std::runtime_error("Faile yra pazymys, kaip is pasakos trauktas!!!\n");
                }
            }
            catch(const std::runtime_error& e)
            {
                cout << e.what() << '\n';
                exit(EXIT_FAILURE);
            } 
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
