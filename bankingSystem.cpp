#include <iostream>
#include <string>
#include <map>
using namespace std;

class Account {
public:
    // Default constructor
    Account() : name(""), title(""), gender(' '), nationality(""), accType(""), pan(""), balance(0.0f) {}

    // Parameterized constructor
    Account(string n, string t, char g, string nat, string aType, string p, float initialBalance)
        : name(n), title(t), gender(g), nationality(nat), accType(aType), pan(p), balance(initialBalance) {}

    // Member variables
    string name;
    string title;
    char gender;
    string nationality;
    string accType;
    string pan;
    float balance;

    // Member functions
    void display() const {
        cout << "Name: " << name << endl;
        cout << "Title: " << title << endl;
        cout << "Gender: " << gender << endl;
        cout << "Nationality: " << nationality << endl;
        cout << "Account Type: " << accType << endl;
        cout << "PAN: " << pan << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main() {
    map<string, Account> accounts;

    float deposit = 0, withdraw = 0;
    int choice = 1;

    cout << "Welcome to the XYZ Bank" << endl;
    cout << "1. Create Account 2. Deposit 3. Withdraw 4. Close the Account 5. Balance Enquiry 6. Exit" << endl;

    while (choice >= 1 && choice <= 6) {
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                cout << "Thank you for Choosing Us" << endl;
                cout << "Account Number: ";
                string accNumber;
                cin >> accNumber;

                cout << "Name: ";
                string name;
                cin >> name;

                cout << "Title: ";
                string title;
                cin >> title;

                cout << "Gender (M/F): ";
                char gender;
                cin >> gender;

                cout << "Nationality: ";
                string nationality;
                cin >> nationality;

                cout << "Account Type (Savings/Corporate): ";
                string accType;
                cin >> accType;

                cout << "PAN: ";
                string pan;
                cin >> pan;

                cout << "Initial Deposit Amount: ";
                float initialBalance;
                cin >> initialBalance;

                Account newAccount(name, title, gender, nationality, accType, pan, initialBalance);
                accounts[accNumber] = newAccount;

                cout << "Account Created Successfully!" << endl;
                break;
            }

            case 2: {
                cout << "Enter Account Number: ";
                string accNumber;
                cin >> accNumber;

                if (accounts.find(accNumber) != accounts.end()) {
                    cout << "Enter Deposit Amount: ";
                    cin >> deposit;
                    accounts[accNumber].balance += deposit;
                    cout << "Amount Deposited" << endl;
                } else {
                    cout << "Account Not Found" << endl;
                }
                break;
            }

            case 3: {
                cout << "Enter Account Number: ";
                string accNumber;
                cin >> accNumber;

                if (accounts.find(accNumber) != accounts.end()) {
                    cout << "Enter Withdraw Amount: ";
                    cin >> withdraw;

                    if (accounts[accNumber].balance < withdraw)
                        cout << "Not Enough Balance" << endl;
                    else {
                        accounts[accNumber].balance -= withdraw;
                        cout << "Amount Withdrew" << endl;
                    }
                } else {
                    cout << "Account Not Found" << endl;
                }
                break;
            }

            case 4: {
                cout << "Enter Account Number to Close: ";
                string accNumber;
                cin >> accNumber;

                if (accounts.find(accNumber) != accounts.end()) {
                    cout << "Are you sure you want to close the account? (Y/N): ";
                    char ch;
                    cin >> ch;
                    ch = tolower(ch);

                    if (ch == 'y') {
                        accounts.erase(accNumber);
                        cout << "Account Closed" << endl;
                    } else {
                        cout << "Closing Denied" << endl;
                    }
                } else {
                    cout << "Account Not Found" << endl;
                }
                break;
            }

            case 5: {
                cout << "Enter Account Number: ";
                string accNumber;
                cin >> accNumber;

                if (accounts.find(accNumber) != accounts.end()) {
                    cout << "Available Balance: $" << accounts[accNumber].balance << endl;
                } else {
                    cout << "Account Not Found" << endl;
                }
                break;
            }

            case 6:
                cout << "Exited" << endl;
                choice = 0;
                break;

            default:
                cout << "Invalid Choice" << endl;
        }
    }

    return 0;
}
