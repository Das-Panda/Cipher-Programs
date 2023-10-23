#include <iostream>
#include <string>
using namespace std;

string encryptBeaufort(const string& message, const string& key) {
    string encryptedMessage = "";
    for (int i = 0; i < message.length(); i++) {
        char messageChar = message[i];
        char keyChar = key[i % key.length()];
        char encryptedChar;

        if (isalpha(messageChar)) {
            int shift = toupper(keyChar) - 'A';
            if (islower(messageChar)) {
                encryptedChar = 'a' + (26 - (messageChar - 'a' + shift)) % 26;
            } else {
                encryptedChar = 'A' + (26 - (messageChar - 'A' + shift)) % 26;
            }
        } else {
            encryptedChar = messageChar;  // Non-alphabetical characters remain unchanged
        }

        encryptedMessage += encryptedChar;
    }
    return encryptedMessage;
}

string decryptBeaufort(const string& message, const string& key) {
    // Decryption is the same as encryption for Beaufort Cipher
    return encryptBeaufort(message, key);
}

int main() {
    char choice;
    string message, key;

    cout << "Beaufort Cipher\n";
    cout << "Enter 'E' for encryption or 'D' for decryption: ";
    cin >> choice;

    cout << "Enter the message: ";
    cin.ignore(); // Clear the newline character from the buffer
    getline(cin, message);

    cout << "Enter the key: ";
    getline(cin, key);

    string result;

    if (toupper(choice) == 'E') {
        result = encryptBeaufort(message, key);
        cout << "Encrypted message: " << result << endl;
    } else if (toupper(choice) == 'D') {
        result = decryptBeaufort(message, key);
        cout << "Decrypted message: " << result << endl;
    } else {
        cout << "Invalid choice. Please enter 'E' for encryption or 'D' for decryption." << endl;
    }

    return 0;
}
