#include <iostream>
#include <string>

using namespace std;

string encrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isupper(ch)) {
            result += char(int(ch + shift - 65) % 26 + 65);
        }
        // Encrypt lowercase letters
        else if (islower(ch)) {
            result += char(int(ch + shift - 97) % 26 + 97);
        }
        else {
            result += ch;
        }
    }

    return result;
}

string decrypt(string text, int shift) {
    string result = "";

    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        if (isupper(ch)) {
            result += char(int(ch - shift - 65 + 26) % 26 + 65);
        }
        else if (islower(ch)) {
            result += char(int(ch - shift - 97 + 26) % 26 + 97);
        }
        else {
            result += ch;
        }
    }

    return result;
}

int main() {
    string text;
    int shift;
    int userShift;
    int attempts = 0;
    const int maxAttempts = 3;

    cout << "Enter the text: ";
    getline(cin, text);

    cout << "Enter the shift value (1-25): ";
    cin >> shift;

    string encryptedText = encrypt(text, shift);

    cout << "Encrypted Text: " << encryptedText << endl;

    while (attempts < maxAttempts) {
        
        cout << "Enter the decryption code: ";
        cin >> userShift;

        if (userShift == shift) {
            string decryptedText = decrypt(encryptedText, shift);
            cout << "Decrypted Text: " << decryptedText << endl;
            break;
        } else {
            attempts++;
            if (attempts < maxAttempts) {
                cout << "Incorrect code. Try again (" << (maxAttempts - attempts) << " attempts left)." << endl;
            } else {
                cout << "Incorrect code. Decryption failed." << endl;
            }
        }
    }

    return 0;
}
