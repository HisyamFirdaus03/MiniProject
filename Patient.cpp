#include "src/Patient.hpp"

Patient :: Patient(string _name, int _age) : name(_name), age(_age), waitingNumber(-1), roomNumber(-1) {}

string Patient :: getName() const{

    return name;
}

int Patient :: getAge() const{

    return age;
}

int Patient :: getRoomNumber() const{

    return roomNumber;
}

int Patient :: getWaitingNumber() const{

    return waitingNumber;
}

void Patient :: assignRoom(int _room){

    roomNumber = _room;
}

void Patient :: assignWaitingNumber(int _waitingNumber){

    waitingNumber = _waitingNumber;
}
