#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function declarations
void registerUser(map<string, string>& users);
bool loginUser(const map<string, string>& users);

int main() {
    map<string, string> users;  // Store usernames and passwords
    int choice;

    while (true) {
        cout << "1. Register\n2. Login\n3. Exit\nChoose an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser(users);
                break;
            case 2:
                if (loginUser(users)) {
                    cout << "Login successful!\n";
                } else {
                    cout << "Login failed.\n";
                }
                break;
            case 3:
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
}

// Register user function
void registerUser(map<string, string>& users) {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if username already exists
    if (users.find(username) != users.end()) {
        cout << "Username already exists. Please choose a different username.\n";
        return;
    }

    // Store the username and password
    users[username] = password;
    cout << "User registered successfully!\n";
}

// Login user function
bool loginUser(const map<string, string>& users) {
    string username, password;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    // Check if username exists and password matches
    auto it = users.find(username);
    if (it != users.end() && it->second == password) {
        return true;
    }

    return false;
}
