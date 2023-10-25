#include <iostream>
#include <string>
#include <map>
#include <sstream> // Add this line to include the necessary header

using namespace std;

// Function to create the Straddle Checkerboard Cipher
map<char, string> createCipher() {
    map<char, string> cipher;
    string checkerboard[] = {
        " 12345",
        "67890!@",
        "#$%^&*",
        "()-=_+",
        "[]{}<>",
        ",.;:\"'"
    };

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 8; j++) {
            char letter = checkerboard[i][j];
            cipher[letter] = to_string(i) + to_string(j);
        }
    }

    return cipher;
}

// Function to encrypt a message using the Straddle Checkerboard Cipher
string encrypt(const string& message, const map<char, string>& cipher) {
    string ciphertext;
    for (char c : message) {
        c = toupper(c); // Convert to uppercase
        if (cipher.count(c)) {
            ciphertext += cipher.at(c) + ' ';
        } else {
            ciphertext += c;
        }
    }
    return ciphertext;
}

// Function to decrypt a message using the Straddle Checkerboard Cipher
string decrypt(const string& ciphertext, const map<char, string>& cipher) {
    string plaintext;
    istringstream iss(ciphertext);
    string token;

    while (getline(iss, token, ' ')) {
        if (token.size() == 2) {
            int row = token[0] - '0';
            int col = token[1] - '0';
            char letter = ' ';
            for (const auto& entry : cipher) {
                if (entry.second == token) {
                    letter = entry.first;
                    break;
                }
            }
            plaintext += letter;
        } else {
            plaintext += token;
        }
    }

    return plaintext;
}

int main() {
    map<char, string> cipher = createCipher();
    char choice;

    cout << "Welcome to the Straddle Checkerboard Cipher program!" << endl;
    cout << "Do you want to (E)ncrypt or (D)ecrypt? ";
    cin >> choice;
    cin.ignore();

    if (choice == 'E' || choice == 'e') {
        string plaintext;
        cout << "Enter the message to encrypt: ";
        getline(cin, plaintext);
        string ciphertext = encrypt(plaintext, cipher);
        cout << "Encrypted message: " << ciphertext << endl;
    } else if (choice == 'D' || choice == 'd') {
        string ciphertext;
        cout << "Enter the message to decrypt: ";
        getline(cin, ciphertext);
        string plaintext = decrypt(ciphertext, cipher);
        cout << "Decrypted message: " << plaintext << endl;
    } else {
        cout << "Invalid choice. Please enter 'E' or 'D'." << endl;
    }

    return 0;
}
