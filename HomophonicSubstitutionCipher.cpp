#include <iostream>
#include <map>
#include <string>

using namespace std;

// Function to encrypt a message using homophonic substitution cipher
string encrypt(const string &message, const map<char, string> &cipher) {
    string encryptedMessage;
    for (char c : message) {
        if (cipher.find(c) != cipher.end()) {
            encryptedMessage += cipher.at(c) + ' ';
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

// Function to decrypt a message using homophonic substitution cipher
string decrypt(const string &encryptedMessage, const map<string, char> &cipher) {
    string decryptedMessage;
    string currentToken;
    for (char c : encryptedMessage) {
        if (c == ' ' && !currentToken.empty()) {
            if (cipher.find(currentToken) != cipher.end()) {
                decryptedMessage += cipher.at(currentToken);
            } else {
                decryptedMessage += currentToken;
            }
            currentToken.clear();
        } else {
            currentToken += c;
        }
    }
    if (!currentToken.empty()) {
        if (cipher.find(currentToken) != cipher.end()) {
            decryptedMessage += cipher.at(currentToken);
        } else {
            decryptedMessage += currentToken;
        }
    }
    return decryptedMessage;
}

int main() {
    // Define the homophonic substitution cipher
    map<char, string> encryptionCipher;
    map<string, char> decryptionCipher;

    // Define mappings for the complete alphabet
    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string cipherValues[] = {
        "11", "22", "33", "44", "55", "66", "77", "88", "99", "00",
        "AA", "BB", "CC", "DD", "EE", "FF", "GG", "HH", "II", "JJ",
        "KK", "LL", "MM", "NN", "OO", "PP", "QQ", "RR", "SS", "TT",
        "UU", "VV", "WW", "XX", "YY", "ZZ"
    };

    for (size_t i = 0; i < alphabet.length(); i++) {
        encryptionCipher[alphabet[i]] = cipherValues[i];
        decryptionCipher[cipherValues[i]] = alphabet[i];
    }

    char choice;
    cout << "Do you want to encrypt (E) or decrypt (D) a message? ";
    cin >> choice;

    cin.ignore(); // Clear the newline character from the input buffer

    if (choice == 'E' || choice == 'e') {
        string message;
        cout << "Enter the message you want to encrypt: ";
        getline(cin, message);

        string encryptedMessage = encrypt(message, encryptionCipher);
        cout << "Encrypted Message: " << encryptedMessage << endl;
    } else if (choice == 'D' || choice == 'd') {
        string encryptedMessage;
        cout << "Enter the encrypted message you want to decrypt: ";
        getline(cin, encryptedMessage);

        string decryptedMessage = decrypt(encryptedMessage, decryptionCipher);
        cout << "Decrypted Message: " << decryptedMessage << endl;
    } else {
        cout << "Invalid choice. Please choose 'E' for encrypt or 'D' for decrypt." << endl;
    }

    return 0;
}
