#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Tem {

    string username, email, password; // Variables for storing user information
    string searchName, searchPass, searchEmail; // Variables for search operations
    fstream file; // File stream object for file operations

    void login();   // Function to handle login
    void signup();  // Function to handle sign-up
    void forgot();  // Function to handle forgot password
};

void Tem::signup() {
    cout << "Enter username: ";
    cin >> username; // Get username
    cout << "Enter your Email: ";
    cin >> email; // Get email
    cout << "Enter your password: ";
    cin >> password; // Get password

    file.open("logindata.txt", ios::out | ios::app); // Open file in append mode
    if (file.is_open()) {
        file << username << "*" << email << "*" << password << endl; // Save data
        file.close(); // Close file
        cout << "Account created successfully!\n";
    } else {
        cout << "Error opening file for writing.\n";
    }
}

void Tem::login() {
    cout << "------Login------" << endl;
    cout << "Enter your username: ";
    cin >> searchName; // Get username
    cout << "Enter your password: ";
    cin >> searchPass; // Get password

    file.open("logindata.txt", ios::in); // Open file in read mode
    if (!file.is_open()) {
        cout << "Error opening file for reading.\n";
        return;
    }

    bool found = false;
    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, password)) {
        if (username == searchName && password == searchPass) {
            cout << "\nAccount login is successful!";
            cout << "\nUsername: " << username;
            cout << "\nEmail: " << email << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Invalid username or password.\n";
    }

    file.close();
}

void Tem::forgot() {
    cout << "\nEnter your username: ";
    cin >> searchName; // Get username
    cout << "Enter your email address: ";
    cin >> searchEmail; // Get email

    file.open("logindata.txt", ios::in); // Open file in read mode
    if (!file.is_open()) {
        cout << "Error opening file for reading.\n";
        return;
    }

    bool found = false;
    while (getline(file, username, '*') &&
           getline(file, email, '*') &&
           getline(file, password)) {
        if (username == searchName && email == searchEmail) {
            cout << "\nAccount found!";
            cout << "\nYour password: " << password << endl;
            found = true;
            break;
        }
    }

    if (!found) {
        cout << "Account not found.\n";
    }

    file.close();
}

int main() {
    Tem obj;
    int choice;

    do {
        cout << "\n1 - Login";
        cout << "\n2 - Sign-up";
        cout << "\n3 - Forgot password";
        cout << "\n4 - Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            obj.login();
            break;
        case 2:
            obj.signup();
            break;
        case 3:
            obj.forgot();
            break;
        case 4:
            cout << "Exiting program.\n";
            return 0;
        default:
            cout << "Invalid selection. Try again.\n";
        }
    } while (choice != 4);

    return 0;
}
