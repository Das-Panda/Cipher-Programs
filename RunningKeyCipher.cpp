#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string encrypt(const string& plaintext, const string& key) {
    string ciphertext = "";
    
    for (size_t i = 0; i < plaintext.length(); ++i) {
        char plainChar = plaintext[i];
        char keyChar = key[i % key.length()];
        
        if (isalpha(plainChar)) {
            char encryptedChar = (toupper(plainChar) + toupper(keyChar) - 2 * 'A') % 26 + 'A';
            ciphertext += encryptedChar;
        } else {
            ciphertext += plainChar;  // Preserve non-alphabetical characters
        }
    }
    
    return ciphertext;
}

string decrypt(const string& ciphertext, const string& key) {
    string plaintext = "";
    
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char cipherChar = ciphertext[i];
        char keyChar = key[i % key.length()];
        
        if (isalpha(cipherChar)) {
            char decryptedChar = ((toupper(cipherChar) - toupper(keyChar) + 26) % 26) + 'A';
            plaintext += decryptedChar;
        } else {
            plaintext += cipherChar;  // Preserve non-alphabetical characters
        }
    }
    
    return plaintext;
}

int main() {
    int choice;
    
    cout << "Running Key Cipher\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "Enter your choice (1/2): ";
    cin >> choice;
    
    cin.ignore();  // Consume newline character
    
    if (choice == 1) {
        string plaintext, key;
        
        cout << "Enter the plaintext: ";
        getline(cin, plaintext);
        cout << "Enter the key: ";
        getline(cin, key);
        
        string ciphertext = encrypt(plaintext, key);
        cout << "Encrypted Text: " << ciphertext << endl;
    } else if (choice == 2) {
        string ciphertext, key;
        
        cout << "Enter the ciphertext: ";
        getline(cin, ciphertext);
        cout << "Enter the key: ";
        getline(cin, key);
        
        string plaintext = decrypt(ciphertext, key);
        cout << "Decrypted Text: " << plaintext << endl;
    } else {
        cout << "Invalid choice. Please enter 1 for encryption or 2 for decryption.\n";
    }
    
    return 0;
}
