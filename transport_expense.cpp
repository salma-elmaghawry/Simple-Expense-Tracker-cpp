#include "expense_class.cpp"
class TransportExpense : public Expense {
public:
    TransportExpense(float amt, string desc)
        : Expense(amt, desc) {}

    void display() {
        cout << "[Transport] ";
        Expense::display();
        cout << endl;
    }
};