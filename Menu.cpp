#include "src/Menu.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Menu :: Menu(Queue *_queue) : patientQueue(_queue) {}

void Menu :: displayMainMenu(int &option){

    cout << "--------------------------------------------" << endl;
    cout << right << setw(10) << " " << "Patient Appointment System" << endl;
    cout << "--------------------------------------------" << endl;
    cout << endl;
    cout << "1. Generate new waiting number" << endl;
    cout << "2. Dequeue the last waiting number" << endl;
    cout << "3. Display waiting number" << endl;
    cout << "4. Exit" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Enter a number corresponding to the selection above: ";
    cin >> option;
    cout << endl;
}

void Menu :: displayFirstOption(string &patientName, int &age){

    cout << "--------------------------------------------" << endl;
    cout << right << setw(10) << " " << "Generate New Waiting Number" << endl;
    cout << "--------------------------------------------" << endl;
    cout << "Enter the patient's name: ";
    cin >> patientName;
    cout << "Enter the patient's age: ";
    cin >> age;
    cout << "--------------------------------------------" << endl;
    cout << "Generated Waiting Number, Please wait until your number shows up on the screen :) " << endl;
}

void Menu :: displaySecondOption(){

    cout << "--------------------------------------------" << endl;
    cout << right << setw(10) << " " << "Current Waiting Number" << endl;
    cout << "--------------------------------------------" << endl;
    patientQueue->displayBack();
    cout << "--------------------------------------------" << endl;
    cout << endl;
}

void Menu :: displayThirdOption(){

    cout << "--------------------------------------------------------------------" << endl;
    cout << right << setw(20) << " " << "Display Waiting Number" << endl;
    cout << "--------------------------------------------------------------------" << endl;
    patientQueue->displayAll();
    cout << "--------------------------------------------------------------------" << endl;
    cout << endl;
}
