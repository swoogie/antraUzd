#include "lib.hpp"
#include "struct.hpp"
#include "fun.hpp"
#include "newFile.hpp"

int main()
{   
    cout << "Pasirinkite veiksma: \n 1. Studentu irasymas ranka\n 2. Studentai is saraso\n 3. Sugeneruoti studentus " << endl;    
    
    int choice;
    while(choice!=1 && choice!=2 && choice!=3)
    {
        cin >> choice;
        if(choice == 1 || choice ==2 || choice==3)
        {
            break;
        }
        else
        {
            cout << "Pasirinkite tinkama reiksme" << endl;
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
        
    if(choice==2)
    {
        vector<studentoSarStruct> studentas;
        skaitymas(studentas,1);
        sarIsvedimas(studentas);
        studentas.clear(); 
    } 
    else if(choice==1)
    {
        cout << "Studentu skaicius: " << endl;
        int studentuSkaicius = neRaide();
        studentoStruct* studentasK = new studentoStruct[studentuSkaicius];
        ivedimas(studentuSkaicius, studentasK);
        isvedimas(studentuSkaicius, studentasK);
        delete studentasK; 
    }
    else if(choice==3)
    {
        gen();
        vector<studentoSarStruct> studentas;
        skaitymas(studentas,0);
        sortedIsvedimas(studentas);
        studentas.clear();
    }

    return 0;
}

