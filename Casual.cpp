#include <iostream>
#include "Casual.h"
#include <string>

using namespace std;

Casual::Casual() {
    for (int i = 0; i < 7; i++) {
        this->hoursWorked[i] = 0;
    }    this->dayCount = 0;
}

Casual::Casual(int payRate) {
    this->dayCount = 0;
    for (int i = 0; i < 7; i++) {
        this->hoursWorked[i] = 0;
    }
}

void Casual::set_payRate(int payRate) {
    this->payRate = payRate;
}

void Casual::endWorkDay() {
    this->dayCount++;
    this->hoursWorked[this->dayCount] = 0;
    this->energyLevel = 100;
}

int Casual::get_payRate() {
    return this->payRate;
}

int Casual::get_dayCount() {
    return this->dayCount;
}

void Casual::set_dayCount(int dayCount) {
    this->dayCount = dayCount;
}

void Casual::work(int mins) {
    this->energyLevel -= mins * 0.5;

    if (this->energyLevel < 0) {
        this->energyLevel = 0;
        cout << "too much" << endl;
    } else {
        this->hoursWorked[this->dayCount] += mins;
    }

}

float Casual::pay() {
    float total = 0;
    for (int i = 0; i < 7; i++) {

        if (i < 5) {
        total += this->hoursWorked[i];
        } else if (i >= 5) {
            total += this->hoursWorked[i] * 2;
        }
    }

    this->dayCount = 0;

    for (int i = 0; i < 7; i++) {
        this->hoursWorked[i] = 0;
    }

    return (this->payRate * total);
}