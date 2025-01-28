#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct expenses
{

    string name;
    double amount;
    string date;
};

void updateExpenses(expenses &expense, const string &newname, double &newamount, const string &newdate)
{

    expense.name = newname;
    expense.amount = newamount;
    expense.date = newdate;
}

void showExpenses(const expenses &expense)
{
    cout << "name: " << expense.name << endl;
    cout << "amount: " << expense.amount << "$" << endl;
    cout << "date: " << expense.date << endl;
}
void showAllExpenses(const vector<expenses> &expenseslist)
{

    if (expenseslist.empty())
    {
        cout << "no expenses yet" << endl;
        return;
    }
    for (const auto &expenses : expenseslist)
    {
        showExpenses(expenses);
        cout << "------------------------------" << endl;
    }
}
double totalAmountspent(const vector<expenses> &expenseslist)
{
    double total = 0;
    for (const auto &expense : expenseslist)
    {

        total += expense.amount;
    }
    return total;
}
double bugetLine(const vector<expenses> &expenseslist)
{

    double buget;
    cout << "enter your buget: ";
    cin >> buget;
    cout << "your bugetline for the day is: " << buget << "$" << endl;
    return 0;
}
void removeItemByName(vector<expenses> &expenseslist, const string &ItemToRemove)
{
    auto item = remove_if(expenseslist.begin(), expenseslist.end(),
                          [&ItemToRemove](const expenses &expense)
                          {
                              return expense.name == ItemToRemove;
                          });
    if (item != expenseslist.end())
    {
        expenseslist.erase(item, expenseslist.end());
        cout << "expense ' " << ItemToRemove << " '" << "has been removed successfully." << endl;
    }
    else
    {
        cout << "expense ' " << ItemToRemove << " '" << "was not found in the history. " << endl;
    }
}

int main()
{
    vector<expenses> expenseslist;
    while (true)
    {

        int options;
        cout << "main menu" << endl;
        cout << "1.enter your buget line" << endl
             << "2.add expenses" << endl
             << "3.show expense list" << endl
             << "4.show total amount so far" << endl
             << "5.remove expense" << endl
             << "6.Exit" << endl
             << "------------------------------" << endl;

        cout << "enter your option: ";
        cin >> options;
        cout << "-------------------------------" << endl;

        switch (options)
        {
        case 1:
            bugetLine(expenseslist);
            break;
        case 2:
        {
            expenses person1;
            cout << "-----------------------------" << endl;
            cout << "enter name of the item" << endl;
            cin >> person1.name;
            cout << "how much did it cost" << endl;
            cin >> person1.amount;
            cout << "enter the date" << endl;
            cin >> person1.date;
            expenseslist.push_back(person1);

            cout << "expenses updated succesfully" << endl;
            cout << "-------------------------------" << endl;

            break;
        }
        case 3:

            cout << "------------------------------" << endl;
            showAllExpenses(expenseslist);
            break;
        case 4:
            cout << "-------------------------------------" << endl;
            cout << "you have spent: " << totalAmountspent(expenseslist) << "$" << "so far!!" << endl;
            cout << "-------------------------------------" << endl;
            break;

        case 5:
        {
            cout << "enter the name of item you want to remove: ";
            string itemName;
            cin >> itemName;
            removeItemByName(expenseslist, itemName);
            break;
        }
        case 6:
            cout << "exiting program" << endl;
            return 0;
        default:
            cout << "invaild option";
            break;
        }
    }
    return 0;
}