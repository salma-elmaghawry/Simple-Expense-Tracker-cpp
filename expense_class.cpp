#ifndef EXPENSE_CLASS_H
#define EXPENSE_CLASS_H

#include <iostream>
#include <vector>
using namespace std;
//Base Class 
class Expense {
protected:
    float amount;
    string description;

public:
    Expense(float amt, string desc) {
        amount = amt;
        description = desc;
    }

    // Virtual function (Polymorphism)
    virtual void display() {
        cout << "Amount: " << amount
             << " | Description: " << description;
    }

    float getAmount() {
        return amount;
    }

    void setAmount(float amt) {
        amount = amt;
    }

    string getDescription() {
        return description;
    }

    void setDescription(string desc) {
        description = desc;
    }

    virtual ~Expense() {}
};

#endif