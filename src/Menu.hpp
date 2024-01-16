#pragma once
#include "Queue.hpp"
#include <string>
using namespace std;

class Menu
{
    private:
        Queue *patientQueue;

    public:
        Menu(Queue *_queue = NULL);
        void displayMainMenu(int &option);
        void displayFirstOption(string &patientName, int &age);
        void displaySecondOption();
        void displayThirdOption();
};