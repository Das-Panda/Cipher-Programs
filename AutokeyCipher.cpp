#include <iostream>
#include <string>
using namespace std;

string encryptAutokey(const string &message, const string &key) {
    string encryptedMessage = "";
    int messageLen = message.length();
    int keyLen = key.length();

    for (int i = 0; i < messageLen; i++) {
        char messageChar = message[i];
        char keyChar = key[i % keyLen];
        char encryptedChar = ((messageChar + keyChar) % 26) + 'A'; // Assuming uppercase letters
        encryptedMessage += encryptedChar;
    }

    return encryptedMessage;
}

string decryptAutokey(const string &message, const string &key) {
    string decryptedMessage = "";
    int messageLen = message.length();
    int keyLen = key.length();

    for (int i = 0; i < messageLen; i++) {
        char messageChar = message[i];
        char keyChar = key[i % keyLen];
        char decryptedChar = ((messageChar - keyChar + 26) % 26) + 'A'; // Assuming uppercase letters
        decryptedMessage += decryptedChar;
    }

    return decryptedMessage;
}

int main() {
    char choice;
    cout << "Autokey Cipher - Encrypt (E) or Decrypt (D): ";
    cin >> choice;

    if (choice == 'E' || choice == 'e') {
        string message, key;
        cout << "Enter the message to encrypt: ";
        cin.ignore(); // Clear newline character from the buffer
        getline(cin, message);
        cout << "Enter the encryption key: ";
        getline(cin, key);

        string encryptedMessage = encryptAutokey(message, key);
        cout << "Encrypted Message: " << encryptedMessage << endl;
    } else if (choice == 'D' || choice == 'd') {
        string message, key;
        cout << "Enter the message to decrypt: ";
        cin.ignore(); // Clear newline character from the buffer
        getline(cin, message);
        cout << "Enter the decryption key: ";
        getline(cin, key);

        string decryptedMessage = decryptAutokey(message, key);
        cout << "Decrypted Message: " << decryptedMessage << endl;
    } else {
        cout << "Invalid choice. Please choose E or D for Encrypt or Decrypt." << endl;
    }

    return 0;
}
