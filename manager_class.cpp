#include "expense_class.cpp"
#include "food_expense.cpp"
#include "transport_expense.cpp"
class ExpenseManager {
private:
    vector<Expense*> expenses;

public:
    void addExpense() {
        int type;
        float amount;
        string desc;

        cout << "1. Food\n2. Transport\nChoose type: ";
        cin >> type;

        cout << "Enter amount: ";
        cin >> amount;

        cout << "Enter description: ";
        cin.ignore();
        getline(cin, desc);

        if (type == 1) {
            expenses.push_back(new FoodExpense(amount, desc));
        } else if (type == 2) {
            expenses.push_back(new TransportExpense(amount, desc));
        } else {
            cout << "Invalid type!\n";
        }
    }

    void viewExpenses() {
        if (expenses.empty()) {
            cout << "No expenses found.\n";
            return;
        }

        for (int i = 0; i < expenses.size(); i++) {
            cout << i + 1 << ". ";
            expenses[i]->display(); // Polymorphism here
        }
    }

    void totalSpending() {
        float total = 0;
        for (int i = 0; i < expenses.size(); i++) {
            total += expenses[i]->getAmount();
        }
        cout << "Total Spending: " << total << endl;
    }

    void deleteExpense() {
        int index;
        cout << "Enter index to delete: ";
        cin >> index;

        if (index < 1 || index > expenses.size()) {
            cout << "Invalid index!\n";
            return;
        }

        delete expenses[index - 1];
        expenses.erase(expenses.begin() + (index - 1));

        cout << "Deleted successfully.\n";
    }

    // Destructor to free memory
    ~ExpenseManager() {
        for (int i = 0; i < expenses.size(); i++) {
            delete expenses[i];
        }
    }
};