#pragma once
#include "Patient.hpp"  

#define MAX_ROOM_NUMBER 3

class Queue
{
    private:
        Patient *front, *back;
        int currWaitingNumber, currRoomNumber;
    
    public:
        Queue();
        ~Queue();
        bool isEmpty();
        void enqueue(Patient *newPatient);
        void dequeue();
        void generateNewNumber(Patient *newPatient);
        void deleteLastNumber();
        void displayFront();
        void displayBack();
        void displayAll();
};