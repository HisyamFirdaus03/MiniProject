#include "src/Queue.hpp"
#include <iomanip>
using namespace std;

Queue :: Queue(){

    front = NULL;
    back = NULL;
    currWaitingNumber = 0;
    currRoomNumber = 0;
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

        newPatient->next = front;
        front = newPatient;
    }
}

void Queue :: dequeue(){

    if(isEmpty()) return;

    Patient *lastNode = front;
    while(lastNode){

        if(lastNode->next == back) break;
        lastNode = lastNode->next;
    }

    lastNode->next = NULL;
    back = lastNode;
}

void Queue :: generateNewNumber(Patient *newPatient){

    enqueue(newPatient);
    front->assignWaitingNumber(currWaitingNumber++);
    front->assignRoom(currRoomNumber++);

    if(currRoomNumber >= MAX_ROOM_NUMBER)
        currRoomNumber = 0;
}

void Queue :: deleteLastNumber(){

    back->assignWaitingNumber(-1);
    back->assignRoom(-1);
    dequeue();
}

void Queue :: displayBack(){

    cout << left << setw(15) << " Waiting Number" << ": " << back->getWaitingNumber() << endl;
    cout << left << setw(15) << " Patient's Name" << ": " << back->getName() << endl;
    cout << left << setw(15) << " Patient's Age" << ": " << back->getAge() << endl;
    cout << left << setw(15) << " Room Number" << ": " << back->getRoomNumber() << endl;
}

void Queue :: displayAll(){

    Patient *currNode = front;
    int num = 0;

    cout << left;
    cout << setw(5) << "No.";
    cout << setw(10) << " Waiting Number";
    cout << setw(15) << " Patient's Name";
    cout << setw(6) << " Patient's Age";
    cout << setw(6) << " Room Number";
    cout << endl;

    while(currNode){
        
        cout << setw(5) << ++num;
        cout << setw(10) << back->getWaitingNumber();
        cout << setw(15) << back->getName();
        cout << setw(6) << back->getAge();
        cout << setw(6) << back->getRoomNumber();
        cout << endl;
        currNode = currNode->next;
    }
    cout << endl;
}
