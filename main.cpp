#include <iostream>
#include <vector>
#include "manager_class.cpp"
using namespace std;


int main() {
    ExpenseManager manager;
    int choice;

    do {
        cout << "\n===== Expense Tracker =====\n";
        cout << "1. Add Expense\n";
        cout << "2. View Expenses\n";
        cout << "3. Total Spending\n";
        cout << "4. Delete Expense\n";
        cout << "5. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1: manager.addExpense(); break;
            case 2: manager.viewExpenses(); break;
            case 3: manager.totalSpending(); break;
            case 4: manager.deleteExpense(); break;
            case 5: cout << "Goodbye!\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 5);

    return 0;
}