# atm
# INSTALLATION
Install a C++ compiler, such as GCC or Clang.
Download the ATM machine program code.
Open a terminal window and navigate to the directory where you downloaded the code.
Type the following command to compile the code:
g++ -o atm atm.cpp
Type the following command to run the program:
./atm
The program will prompt you to enter your PIN. If the PIN is valid, you will be able to use the ATM machine to check your balance, withdraw money, or transfer money.

# EXPLANATION
The program starts by including the following header files:

C++
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <iomanip>
Use code with caution. Learn more
These header files provide the following functionalities:

iostream: Input/output stream
string: String manipulation
vector: Dynamic array
ctime: Time manipulation
fstream: File stream
iomanip: Formatted output
The next part of the program defines the following functions:

C++
void clear();
string get_current_date_time();
int get_pin();
bool check_pin(int pin, vector<int> pins);
void print_welcome_message();
void print_menu();
void check_balance();
void withdraw();
void transfer();
void log_transaction(string transaction_type);
Use code with caution. Learn more
These functions are used to:

Clear the screen
Get the current date and time
Get the PIN from the user
Check the PIN against a list of valid PINs
Print the welcome message
Print the menu of options
Perform the check balance operation
Perform the withdraw operation
Perform the transfer operation
Log the transaction
The main function of the program is as follows:

C++
int main() {
    // Clear the screen
    clear();

    // Get the current date and time
    string current_date_time = get_current_date_time();

    // Print the welcome message
    print_welcome_message();

    // Get the PIN from the user
    int pin = get_pin();

    // Check the PIN against the list of valid PINs
    vector<int> pins = {1234, 1122, 1133, 1803, 1672, 1110, 1111};
    bool is_valid_pin = check_pin(pin, pins);

    // If the PIN is valid, continue
    if (is_valid_pin) {
        // Print the menu of options
        print_menu();

        // Get the user's choice
        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        // Switch on the user's choice
        switch (choice) {
            case 1:
                check_balance();
                break;
            case 2:
                withdraw();
                break;
            case 3:
                transfer();
                break;
            case 4:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
                break;
        }
    } else {
        cout << "Invalid PIN!" << endl;
    }

    return 0;
}
Use code with caution. Learn more
This function first clears the screen, then gets the current date and time. It then prints the welcome message and gets the PIN from the user. The PIN is then checked against a list of valid PINs. If the PIN is valid, the menu of options is printed and the user is prompted to enter their choice. The program then switches on the user's choice and calls the appropriate function. If the PIN is invalid, the Invalid PIN! message is displayed.
