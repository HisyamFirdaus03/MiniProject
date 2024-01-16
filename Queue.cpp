#include "src/Queue.hpp"
#include <iostream>
#include <iomanip>
using namespace std;

Queue :: Queue(){

    front = NULL;
    back = NULL;
    currWaitingNumber = 0;
    currRoomNumber = 0;
}

Queue :: ~Queue(){

    Patient *currNode = front, *delNode;
    while(currNode){

        delNode = currNode;
        currNode = currNode->next;
        delete delNode;
    }
}

bool Queue :: isEmpty(){

    return (front == NULL);
}

void Queue :: enqueue(Patient *newPatient){

    if(isEmpty()){

        front = newPatient;
        back = newPatient;
        newPatient->next = NULL;
    }
    else{

        back->next = newPatient;
        back = newPatient;
        newPatient->next = NULL;
    }
}

void Queue :: dequeue(){

    Patient *delNode = front;

    if(front == back){

        front = NULL;
        back = NULL;
        delete delNode;
    }
    else if(!isEmpty()){

        front = front->next;
        delete delNode;
    }
}

void Queue :: generateNewNumber(Patient *newPatient){

    enqueue(newPatient);
    back->assignWaitingNumber(++currWaitingNumber);
    back->assignRoom(++currRoomNumber);

    if(currRoomNumber >= MAX_ROOM_NUMBER)
        currRoomNumber = 0;
}

void Queue :: deleteLastNumber(){

    front->assignWaitingNumber(-1);
    front->assignRoom(-1);
    dequeue();
}

void Queue :: displayFront(){

    if(isEmpty()) throw EmptyQueue();

    cout << endl;
    cout << left << setw(15) << " Waiting Number" << ": " << front->getWaitingNumber() << endl;
    cout << left << setw(15) << " Patient's Name" << ": " << front->getName() << endl;
    cout << left << setw(15) << " Patient's Age" << ": " << front->getAge() << endl;
    cout << left << setw(15) << " Room Number" << ": " << front->getRoomNumber() << endl;
    cout << endl;
}

void Queue :: displayBack(){

    if(isEmpty()) throw EmptyQueue();

    cout << left << setw(15) << " Waiting Number" << ": " << back->getWaitingNumber() << endl;
    cout << left << setw(15) << " Patient's Name" << ": " << back->getName() << endl;
    cout << left << setw(15) << " Patient's Age" << ": " << back->getAge() << endl;
    cout << left << setw(15) << " Room Number" << ": " << back->getRoomNumber() << endl;
    cout << endl;
}

void Queue :: displayAll(){

    Patient *currNode = front;
    int num = 0;

    if(isEmpty()) throw EmptyQueue();

    cout << left;
    cout << setw(5) << "No.";
    cout << setw(20) << "Waiting Number";
    cout << setw(20) << "Patient's Name";
    cout << setw(6) << "Age";
    cout << setw(6) << "Room Number";
    cout << endl;

    while(currNode){
        
        cout << left;
        cout << setw(5) << ++num;
        cout << setw(20) << currNode->getWaitingNumber();
        cout << setw(20) << currNode->getName();
        cout << setw(11) << currNode->getAge();
        cout << setw(6) << currNode->getRoomNumber();
        cout << endl;
        currNode = currNode->next;
    }
    cout << endl;
}
