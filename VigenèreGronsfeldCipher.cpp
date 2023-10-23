#include <iostream>
#include <string>
using namespace std;

// Function to encrypt a message using the Vigenère cipher
string vigenereEncrypt(const string &message, const string &key) {
    string encryptedMessage = "";
    int keyLength = key.length();

    for (int i = 0; i < message.length(); i++) {
        char plainChar = message[i];
        char keyChar = key[i % keyLength];
        char encryptedChar;

        if (isalpha(plainChar)) {
            char base = isupper(plainChar) ? 'A' : 'a';
            encryptedChar = ((plainChar - base + keyChar - 'a') % 26) + base;
        } else {
            encryptedChar = plainChar;
        }

        encryptedMessage += encryptedChar;
    }

    return encryptedMessage;
}

// Function to decrypt a message using the Vigenère cipher
string vigenereDecrypt(const string &encryptedMessage, const string &key) {
    string decryptedMessage = "";
    int keyLength = key.length();

    for (int i = 0; i < encryptedMessage.length(); i++) {
        char encryptedChar = encryptedMessage[i];
        char keyChar = key[i % keyLength];
        char decryptedChar;

        if (isalpha(encryptedChar)) {
            char base = isupper(encryptedChar) ? 'A' : 'a';
            decryptedChar = ((encryptedChar - base - keyChar + 'a' + 26) % 26) + base;
        } else {
            decryptedChar = encryptedChar;
        }

        decryptedMessage += decryptedChar;
    }

    return decryptedMessage;
}

// Function to encrypt a message using the Gronsfeld cipher
string gronsfeldEncrypt(const string &message, const string &key) {
    string encryptedMessage = "";
    int keyLength = key.length();

    for (int i = 0; i < message.length(); i++) {
        char plainChar = message[i];
        char keyChar = key[i % keyLength];
        char encryptedChar;

        if (isalpha(plainChar)) {
            char base = isupper(plainChar) ? 'A' : 'a';
            encryptedChar = ((plainChar - base + keyChar - '0') % 26) + base;
        } else {
            encryptedChar = plainChar;
        }

        encryptedMessage += encryptedChar;
    }

    return encryptedMessage;
}

// Function to decrypt a message using the Gronsfeld cipher
string gronsfeldDecrypt(const string &encryptedMessage, const string &key) {
    string decryptedMessage = "";
    int keyLength = key.length();

    for (int i = 0; i < encryptedMessage.length(); i++) {
        char encryptedChar = encryptedMessage[i];
        char keyChar = key[i % keyLength];
        char decryptedChar;

        if (isalpha(encryptedChar)) {
            char base = isupper(encryptedChar) ? 'A' : 'a';
            decryptedChar = ((encryptedChar - base - keyChar + '0' + 26) % 26) + base;
        } else {
            decryptedChar = encryptedChar;
        }

        decryptedMessage += decryptedChar;
    }

    return decryptedMessage;
}

int main() {
    cout << "Choose an option:" << endl;
    cout << "1. Encrypt using Vigenère cipher" << endl;
    cout << "2. Decrypt using Vigenère cipher" << endl;
    cout << "3. Encrypt using Gronsfeld cipher" << endl;
    cout << "4. Decrypt using Gronsfeld cipher" << endl;
    
    int choice;
    cin >> choice;
    cin.ignore();

    if (choice == 1 || choice == 2 || choice == 3 || choice == 4) {
        cout << "Enter the message: ";
        string message;
        getline(cin, message);

        cout << "Enter the key: ";
        string key;
        getline(cin, key);

        string result;

        if (choice == 1) {
            result = vigenereEncrypt(message, key);
            cout << "Encrypted message: " << result << endl;
        } else if (choice == 2) {
            result = vigenereDecrypt(message, key);
            cout << "Decrypted message: " << result << endl;
        } else if (choice == 3) {
            result = gronsfeldEncrypt(message, key);
            cout << "Encrypted message: " << result << endl;
        } else if (choice == 4) {
            result = gronsfeldDecrypt(message, key);
            cout << "Decrypted message: " << result << endl;
        }
    } else {
        cout << "Invalid choice. Please choose a valid option." << endl;
    }

    return 0;
}
