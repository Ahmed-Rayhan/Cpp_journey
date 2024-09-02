#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX_ATTEMPTS = 3;

struct User {
    string username;
    string password;
    int failed_attempts;
    bool locked;
};

bool isUsernameTaken(const string &username) {
    ifstream file("users.txt");
    User user;

    while (file >> user.username >> user.password >> user.failed_attempts >> user.locked) {
        if (user.username == username) {
            return true;
        }
    }
    return false;
}

void registerUser() {
    string username, password;

    cout << "Enter a username: ";
    cin >> username;

    if (isUsernameTaken(username)) {
        cout << "Username already taken, please try a different one." << endl;
        return;
    }

    cout << "Enter a password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << " 0 0" << endl; // failed_attempts = 0, locked = false
    file.close();

    cout << "Registration successful!" << endl;
}

bool loginUser() {
    string username, password;
    User user;
    bool found = false;

    cout << "Enter your username: ";
    cin >> username;
    cout << "Enter your password: ";
    cin >> password;

    fstream file("users.txt");
    fstream temp("temp.txt", ios::out);

    while (file >> user.username >> user.password >> user.failed_attempts >> user.locked) {
        if (user.username == username) {
            found = true;
            if (user.locked) {
                cout << "Account is locked due to too many failed login attempts." << endl;
                temp << user.username << " " << user.password << " " << user.failed_attempts << " " << user.locked << endl;
                continue;
            }

            if (user.password == password) {
                cout << "Login successful!" << endl;
                user.failed_attempts = 0;  // Reset failed attempts on successful login
            } else {
                cout << "Invalid password!" << endl;
                user.failed_attempts++;

                if (user.failed_attempts >= MAX_ATTEMPTS) {
                    cout << "Account locked due to too many failed login attempts." << endl;
                    user.locked = true;
                }
            }
        }
        temp << user.username << " " << user.password << " " << user.failed_attempts << " " << user.locked << endl;
    }

    file.close();
    temp.close();

    remove("users.txt");
    rename("temp.txt", "users.txt");

    if (!found) {
        cout << "Username not found!" << endl;
    }

    return found && user.password == password && !user.locked;
}

int main() {
    int choice;

    while (true) {
        cout << "\n1. Register\n2. Login\n3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting..." << endl;
                return 0;
            default:
                cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}
