#include <iostream>
using namespace std;

void deposting(int &accbal)
{
    int x;
    cout << "enter the amount to deposit" << endl;
    cin >> x;
    if (x > 0)
    {

        accbal += x;
        cout << "amount has been deposited successfully" << endl
             << "your current balance is " << accbal << " birr" << endl;
    }
    else
    {
        cout << "invalid amount" << endl;
    }
}
void withdrawing(int &accbal)
{

    int x;
    cout << "enter the amount to withdraw" << endl;
    cin >> x;
    if (x <= accbal && x > 0)
    {

        accbal -= x;
        cout << "you have withdrwn " << x << " birr from your account " << "your current balance is " << accbal << endl;
    }

    else
    {
        cout << "insufficinet balance" << endl;
    }
}

int main()
{
    const int user_password = 1234;
    int accbal = 0;
    int input_password;
    cout << "enter your pin: ";
    cin >> input_password;

    if (input_password != user_password)
    {

        cout << "incorrect password" << endl;

        return 0;
    }
    else
    {
        cout << "welcome" << endl;
    }

    while (true)
    {

        int choice;

        cout << "choose from below" << endl;
        cout << "-----------------------" << endl;
        cout << "1. deposit" << endl
             << "2. withdrawl" << endl
             << "3. check your balance" << endl
             << "4. exit" << endl;
        cout << "enter your option" << endl;

        cin >> choice;

        switch (choice)
        {
        case 1:
            cout << "deposit menu" << endl;
            cout << "------------------------" << endl;

            deposting(accbal);

            break;
        case 2:
            cout << "withdrawl menu" << endl;
            cout << "----------------------------" << endl;
            withdrawing(accbal);
            break;
        case 3:
            cout << "balance check menu" << endl;
            cout << "-----------------------------" << endl;
            cout << "your current balance is: " << accbal << endl;
            break;
        case 4:
            cout << "exiting the program" << endl;
            return 0;
        default:
            cout << "please only enter the number corresponding to your choice" << endl;
            break;
        }
    }

    return 0;
}