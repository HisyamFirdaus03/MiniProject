#pragma once
#include "Patient.hpp"  

#define MAX_ROOM_NUMBER 5

class Queue
{
    private:
        Patient *front, *back;
        int currWaitingNumber, currRoomNumber;
    
    public:
        Queue();
        bool isEmpty();
        void enqueue(Patient *newPatient);
        void dequeue();
        void generateNewNumber(Patient *newPatient);
        void deleteLastNumber();
        void displayBack();
        void displayAll();
};