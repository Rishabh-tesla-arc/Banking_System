#include "iostream"
#include "string"
using namespace std;

int main()
{
    float deposit=0,withdraw=0;

    cout<<"Welcome to the XYZ Bank"<<endl;
    cout<<"1.Create Account 2.Deposit 3.Withdraw 4.Close the Account 5.Balance Enquiry 6.Exit"<<endl;
    int choice = 1;

    while(choice>=1 && choice<=6) {

        cout<<"Choice: ";
        cin>>choice;

        switch (choice) {
            case 1: {
                cout << "Thank you for Choosing Us" << endl;
                cout << "Name : ";
                string name;
                cin >> name;
                cout << " ";
                string title;
                cin >> title;

                cout << "Gender M/F: ";
                char gender;
                cin >> gender;

                cout << "Nationality: ";
                string nationality;
                cin >> nationality;

                cout << "Savings/Corporate: ";
                string accType;
                cin >> accType;

                cout << "PAN: ";
                string pan;
                cin >> pan;

                cout << "You're Done. Thank you -- VISIT AGAIN...";
                break;
            }

            case 2:
                cout << "Enter Deposit Amount: ";
                cin >> deposit;
                deposit += deposit;
                cout << "Amount Deposited " << endl;
                break;

            case 3:
                cout << "Enter Withdraw Amount: ";
                cin >> withdraw;

                if (deposit < withdraw)
                    cout << "Not Enough Balance " << endl;
                else {
                    deposit -= withdraw;
                    cout << "Amount Withdrew" << endl;
                }
                break;

            case 4:
                cout << "Tussi Jaa rhe hooo..." << endl;
                cout << "Enter Y=Yes   N=No" << endl;
                char ch; cin >> ch;
                ch = tolower(ch);

                if(ch == 'y')
                {
                    cout << "Account Closed " << endl;
                    choice=0;
                    deposit=0;
                }
                else cout << "Closing Denied "<<endl;
                break;

            case 5:
                cout << "Available Balance: " << deposit <<endl;
                break;

            case 6:
                if(choice==6)
                    cout << "Exited ";
                choice=0;
                break;

            default:
                cout << "Invalid Choice ";
        }
    }
}