#include "expense_class.cpp"
class TransportExpense : public Expense {
public:
    TransportExpense(float amt, string desc)
        : Expense(amt, desc) {}

    void display() override {
        cout << "[Transport] ";
        Expense::display();
        cout << endl;
    }
};