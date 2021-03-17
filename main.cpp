#include "lib.hpp"
#include "struct.hpp"
#include "fun.hpp"

int main()
{   

    cout << "Ar skaityti is failo? y/n: " << endl;    
    string y;
    tinkamaReiksme(y);
    if(y == "Y" || y == "y")
    {
        auto start = std::chrono::high_resolution_clock::now();
        vector<studentoSarStruct> studentas;
        skaitymas(studentas);
        sarIsvedimas(studentas);
        studentas.clear();
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end-start;
        cout << "\nPrograma uztruko: "<< diff.count() << " s\n";
    } 
    else
    {
        cout << "Studentu skaicius: " << endl;
        int studentuSkaicius = neRaide();
        studentoStruct* studentasK = new studentoStruct[studentuSkaicius];
        ivedimas(studentuSkaicius, studentasK);
        isvedimas(studentuSkaicius, studentasK);
        delete studentasK; 
    } 
    return 0;
}

