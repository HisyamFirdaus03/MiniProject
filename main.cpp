#include "src/Menu.hpp"
#include "src/Patient.hpp"
#include "src/Queue.hpp"
#include <iostream>
#include <string>

using namespace std;

#define MAX_NUMBER_PATIENT 10

int main()
{
    Queue patientQueue;
    Menu menu(&patientQueue);
    Patient *patient[MAX_NUMBER_PATIENT];

    int option, age, patientCount = 0;
    string patientName;

    do{

        menu.displayMainMenu(option);
        
        switch(option){

            case 1:
                menu.displayFirstOption(patientName, age);
                break;

            case 2:

            case 3:

            default:
        }

    }while(option != 4);

    system("pause");
    return 0;
}
