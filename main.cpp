#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <iomanip>

using namespace std;

// Function to clear the screen
void clear() {
    system("cls");
}

// Function to get the current date and time
string get_current_date_time() {
    time_t now = time(nullptr);
    struct tm tm;
    char buf[80];
    tm = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", &tm);
    return buf;
}

// Function to get the PIN from the user
int get_pin() {
    int pin;
    cout << "Enter your PIN: ";
    cin >> pin;
    return pin;
}

// Function to check the PIN against the list of valid PINs
bool check_pin(int pin, vector<int> pins) {
    for (int i = 0; i < pins.size(); i++) {
        if (pin == pins[i]) {
            return true;
        }
    }
    return false;
}

// Function to print the welcome message
void print_welcome_message() {
    cout << "Welcome to Cyber ATM center" << endl;
    cout << "Author: Yazeed Ahmed" << endl;
    cout << "Version: 1.0" << endl;
}

// Function to print the menu of options
void print_menu() {
    cout << "What would you like to perform?" << endl;
    cout << "1. Check Balance" << endl;
    cout << "2. Withdraw" << endl;
    cout << "3. Transfer" << endl;
    cout << "4. Exit" << endl;
}

// Function to perform the check balance operation
void check_balance() {
    cout << "Your balance is: 10000" << endl;
}

// Function to perform the withdraw operation
void withdraw() {
    int amount;
    cout << "Enter the amount to withdraw: ";
    cin >> amount;
    cout << "Transaction processing..." << endl;
    cout << "Withdrawing " << amount << endl;
    cout << "Done! Please take your cash." << endl;
}

// Function to perform the transfer operation
void transfer() {
    string account_number;
    int amount;
    cout << "Enter the account number: ";
    cin >> account_number;
    cout << "Enter the amount to transfer: ";
    cin >> amount;
    cout << "You transferred " << amount << " to " << account_number << endl;
    cout << "Transfer is successful." << endl;
}

// Function to log the transaction
void log_transaction(string transaction_type) {
    // Get the current date and time
    string current_date_time = get_current_date_time();

    // Open the log file in append mode
    ofstream log_file("reference.log", ios::app);

    // Write the transaction details to the log file
    log_file << current_date_time << ": " << transaction_type << endl;

    // Close the log file
    log_file.close();
}

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

        
