#pragma once
#include <string>
using namespace std;

class Patient
{
    private:
        string name;
        int age, waitingNumber, roomNumber;

    public:
        Patient *next;
        Patient(string _name, int _age);
        string getName() const;
        int getAge() const;
        int getRoomNumber() const;
        int getWaitingNumber() const;
        void assignRoom(int _room);
        void assignWaitingNumber(int _waitingNumber);
};