#include "src/Menu.hpp"
#include "src/Patient.hpp"
#include "src/Queue.hpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
    Queue patientQueue;
    Menu menu(&patientQueue);
    Patient *patient;

    int option, age, patientCount = 0;
    string patientName;

    do{

        menu.displayMainMenu(option);
        system("cls");
        
        try{

            switch(option){

                case 1:
                    menu.displayFirstOption(patientName, age);
                    patient = new Patient(patientName, age);
                    patientQueue.generateNewNumber(patient);
                    patientQueue.displayBack();
                    patient = NULL;
                    system("pause");
                    system("cls");
                    break;

                case 2:
                    menu.displaySecondOption();
                    patientQueue.deleteLastNumber();
                    break;

                case 3:
                    menu.displayThirdOption();
                    system("pause");
                    system("cls");
                    break;

                default:
                    break;
                }   
            }
        catch(Queue::EmptyQueue){

                cout << "Error: The Queue is Empty!" << endl;
                cout << endl;
            }
    
    }while(option != 4);

    system("pause");
    return 0;
}
