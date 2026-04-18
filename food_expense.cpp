
#include "expense_class.cpp"

//Derived Classes 
class FoodExpense : public Expense {
public:
    FoodExpense(float amt, string desc)
        : Expense(amt, desc) {}

    void display() {
        cout << "[Food] ";
        Expense::display();
        cout << endl;
    }
};