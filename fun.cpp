//#include "lib.hpp"
//#include "struct.hpp"
//#include "math.hpp"
#include "fun.hpp"

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

void sarIsvedimas(vector<studentoSarStruct> studentas)
{   
    ofstream pr("rez.txt");
    
    pr << "Vardas" << setw(15+7) << "Pavarde" << setw(15+15) << "Vidurkis (med.)" << setw(5+15) << "Vidurkis (vid.)" 
    << endl << "------------------------------------------------------------------------------" << endl;
    for(int i=0; i<studentas.size(); i++)
    {
        pr << studentas[i].vardas << setw(21-studentas[i].vardas.length()+studentas[i].pavarde.length()) << studentas[i].pavarde 
        << setw(23-studentas[i].pavarde.length()+3) << fixed << setprecision(2) << studentas[i].medRez  
        << setw(20-3+3) << fixed << setprecision(2) << studentas[i].avgRez << endl;
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

void skaitymas(vector<studentoSarStruct> &studentas)
{
   
    ifstream rd = failoPasirinkimas();
    try
    {
        if(rd.fail()) throw "Pasitikrinkite failo pavadinima"; 
    }
    catch(const char * e)
    {
        std::cerr << e << endl;
        exit(EXIT_FAILURE);
    } 


    stringstream buffStream;
    
    buffStream << rd.rdbuf();
    rd.close();
    string temp;
    getline(buffStream,temp);
    temp.clear();
    int i=0;
    while(!buffStream.eof())
    {
        string eil;
        getline(buffStream, eil);
        stringstream lineStream(eil);

        double egzamRez;
        vector<double> pazymiai;
        studentoSarStruct buffStud;
        
        lineStream >> buffStud.vardas >> buffStud.pavarde; 
        
        while(!lineStream.eof())
        {      
            double paz;
            lineStream >> paz;
            try
            {
                if(paz > 10 || paz < 1)
                {
                    throw std::runtime_error("Aptiktas klaidingas pazymys\n");
                }
            }
            catch(const std::runtime_error& e)
            {
                std::cout << e.what() << '\n';
                exit(EXIT_FAILURE);
            }

            if(lineStream.eof())
                egzamRez = paz;
            else
                pazymiai.push_back(paz);          
        }
        buffStud.avgRez=(sarVidurkis(pazymiai, egzamRez));
        buffStud.medRez=(sarMediana(pazymiai, egzamRez));
        studentas.push_back(buffStud);
        if(buffStream.eof()) break;
    }
    
    sort(studentas.begin(),studentas.end());
    
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