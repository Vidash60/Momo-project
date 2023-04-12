#include <iostream>
using namespace std;

bool authenticate(int pin);
void resetPin(int& pin);
void checkBalance(int balance);
void sendMoney(int& balance);

int main() {
    int pin = 0000; 
    int balance = 1000; 
    int wrongTry = 0; 

    while (true) {
        cout << "Welcome to Mobile Money Service" << endl;
        cout << "1. Authenticate" << endl;
        cout << "2. Reset PIN" << endl;
        cout << "3. Check Balance" << endl;
        cout << "4. Send Money" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        int choice;
        cin >> choice;

        switch (choice) {
            case 1: {
                int enteredPin;
                cout << "Enter PIN: ";
                cin >> enteredPin;

                if (authenticate(enteredPin)) {
                    cout << "Authentication successful!" << endl;
                   wrongTry = 0;
                } else {
                  wrongTry++;
                    cout << "Wrong PIN! Attempt " << wrongTry<< " of 3." << endl;
                    if (wrongTry >= 3) {
                        cout << "Too many wrong attempts. Exiting." << endl;
                        return 0;
                    }
                }
                break;
            }
            case 2: {
                resetPin(pin);
                break;
            }
            case 3: {
                checkBalance(balance);
                break;
            }
            case 4: {
                sendMoney(balance);
                break;
            }
            case 5: {
                cout << "Exiting." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }
    }
}

bool authenticate(int pin) {
    int Pin = 0000;
    return pin == Pin;
}

void resetPin(int & pin) {
    cout << "Enter new PIN: ";
    cin >> pin;
    cout << "PIN changed successfully!" << endl;
}

void checkBalance(int balance) {
 int pin;
	cout<<"Enter PIN to check balance"<<endl;
	cin>>pin;
    cout << "Current balance:GHS" << balance<<".00" << endl;
}

void sendMoney(int & balance) {
    cout << "Enter amount to send: GHS";
    int amount;
    cin >> amount;
    if (amount > balance) { 
        cout << "Insufficient balance!" << endl;
    } else {
	int pin;
        balance -= amount;
        cout<<"Enter PIN to complete transaction"<<endl;
        cin>>pin;
        cout << "Money sent successfully!" << endl;
    }
}


