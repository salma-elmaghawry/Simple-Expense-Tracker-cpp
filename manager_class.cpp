#include "expense_class.cpp"
#include "food_expense.cpp"
#include "transport_expense.cpp"
#include "custom_expense.cpp"
#include <map>
class ExpenseManager {
private:
    vector<Expense*> expenses;
    map<int, string> categories;  // Map to store category ID and name
    int categoryCount;  // Counter for dynamic categories

public:
    ExpenseManager() {
        categoryCount = 3;  // Start from 3 (1=Food, 2=Transport)
        categories[1] = "Food";
        categories[2] = "Transport";
    }

    void addCategory() {
        string categoryName;
        cout << "Enter new category name: ";
        cin.ignore();
        getline(cin, categoryName);

        categoryCount++;
        categories[categoryCount] = categoryName;

        cout << "Category '" << categoryName << "' added successfully with ID: " << categoryCount << endl;
    }

    void viewCategories() {
        cout << "\n===== Available Categories =====\n";
        for (auto& cat : categories) {
            cout << cat.first << ". " << cat.second << endl;
        }
    }

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
        for (auto e : expenses) {
            total += e->getAmount();
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
        for (auto e : expenses) {
            delete e;
        }
    }
};