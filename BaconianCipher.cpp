#include <iostream>
#include <string>
#include <map>

using namespace std;

// Function to encrypt a message using Baconian Cipher
string baconianEncrypt(string plainText) {
    string cipherText = "";
    map<char, string> baconianMap;
    
    // Define the Baconian Cipher mapping
    baconianMap['A'] = "AAAAA";
    baconianMap['B'] = "AAAAB";
    baconianMap['C'] = "AAABA";
    baconianMap['D'] = "AAABB";
    baconianMap['E'] = "AABAA";
    baconianMap['F'] = "AABAB";
    baconianMap['G'] = "AABBA";
    baconianMap['H'] = "AABBB";
    baconianMap['I'] = "ABAAA";
    baconianMap['J'] = "ABAAB";
    baconianMap['K'] = "ABABA";
    baconianMap['L'] = "ABABB";
    baconianMap['M'] = "ABBAA";
    baconianMap['N'] = "ABBAB";
    baconianMap['O'] = "ABBBA";
    baconianMap['P'] = "ABBBB";
    baconianMap['Q'] = "BAAAA";
    baconianMap['R'] = "BAAAB";
    baconianMap['S'] = "BAABA";
    baconianMap['T'] = "BAABB";
    baconianMap['U'] = "BABAA";
    baconianMap['V'] = "BABAB";
    baconianMap['W'] = "BABBA";
    baconianMap['X'] = "BABBB";
    baconianMap['Y'] = "BBAAA";
    baconianMap['Z'] = "BBAAB";
    
    // Convert plaintext to uppercase
    for (char &c : plainText) {
        c = toupper(c);
    }
    
    // Encrypt the plaintext
    for (char c : plainText) {
        if (isalpha(c)) {
            cipherText += baconianMap[c];
        } else {
            cipherText += c; // Preserve non-alphabetic characters
        }
    }
    
    return cipherText;
}

// Function to decrypt a message using Baconian Cipher
string baconianDecrypt(string cipherText) {
    string plainText = "";
    
    // Define the reverse Baconian Cipher mapping
    map<string, char> reverseMap;
    for (char c = 'A'; c <= 'Z'; ++c) {
        string baconianCode = "";
        for (int i = 0; i < 5; ++i) {
            baconianCode += cipherText[0];
            cipherText.erase(0, 1);
        }
        reverseMap[baconianCode] = c;
    }
    
    // Decrypt the ciphertext
    while (!cipherText.empty()) {
        if (isalpha(cipherText[0])) {
            string baconianCode = cipherText.substr(0, 5);
            cipherText.erase(0, 5);
            plainText += reverseMap[baconianCode];
        } else {
            plainText += cipherText[0]; // Preserve non-alphabetic characters
            cipherText.erase(0, 1);
        }
    }
    
    return plainText;
}

int main() {
    char choice;
    string input;

    cout << "Baconian Cipher\n";
    cout << "----------------\n";
    cout << "Choose an option:\n";
    cout << "1. Encrypt\n";
    cout << "2. Decrypt\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;
    cin.ignore(); // Clear the newline character from the buffer

    if (choice == '1') {
        cout << "Enter the plaintext message: ";
        getline(cin, input);
        string cipherText = baconianEncrypt(input);
        cout << "Encrypted message: " << cipherText << endl;
    } else if (choice == '2') {
        cout << "Enter the ciphertext message: ";
        getline(cin, input);
        string plainText = baconianDecrypt(input);
        cout << "Decrypted message: " << plainText << endl;
    } else {
        cout << "Invalid choice. Please choose 1 or 2." << endl;
    }

    return 0;
}
