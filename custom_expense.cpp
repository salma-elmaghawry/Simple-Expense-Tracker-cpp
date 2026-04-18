#include "expense_class.cpp"

// Generic derived class for any custom category
class CustomExpense : public Expense {
private:
    string category;

public:
    CustomExpense(float amt, string desc, string cat)
        : Expense(amt, desc), category(cat) {}

    void setCategory(string cat) {
        category = cat;
    }

    string getCategory() {
        return category;
    }

    void display() override {
        cout << "[" << category << "] ";
        Expense::display();
        cout << endl;
    }
};
