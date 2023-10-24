#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

// Function to encrypt a message using a Hill Cipher
string encrypt(string message, vector<vector<int>> key) {
    string encrypted = "";
    int keySize = key.size();

    // Pad the message with 'X' if its length is not a multiple of keySize
    while (message.length() % keySize != 0) {
        message += 'X';
    }

    for (int i = 0; i < message.length(); i += keySize) {
        for (int j = 0; j < keySize; j++) {
            int sum = 0;
            for (int k = 0; k < keySize; k++) {
                sum += (key[j][k] * (message[i + k] - 'A'));
            }
            encrypted += static_cast<char>((sum % 26) + 'A');
        }
    }

    return encrypted;
}

// Function to decrypt a message using a Hill Cipher
string decrypt(string message, vector<vector<int>> key) {
    string decrypted = "";
    int keySize = key.size();
    int det = 0;
    int keyInverse[3][3];

    // Calculate the determinant of the key matrix
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            det += key[i][j] * (key[(i + 1) % keySize][(j + 1) % keySize] * key[(i + 2) % keySize][(j + 2) % keySize] -
                               key[(i + 1) % keySize][(j + 2) % keySize] * key[(i + 2) % keySize][(j + 1) % keySize]);
        }
    }

    // Calculate the modular multiplicative inverse of the determinant
    int detInverse = -1;
    for (int i = 0; i < 26; i++) {
        if ((det * i) % 26 == 1) {
            detInverse = i;
            break;
        }
    }

    // Calculate the key inverse matrix
    for (int i = 0; i < keySize; i++) {
        for (int j = 0; j < keySize; j++) {
            int cofactor = (key[(j + 1) % keySize][(i + 1) % keySize] * key[(j + 2) % keySize][(i + 2) % keySize] -
                            key[(j + 1) % keySize][(i + 2) % keySize] * key[(j + 2) % keySize][(i + 1) % keySize]);

            keyInverse[i][j] = (cofactor * detInverse) % 26;
            if (keyInverse[i][j] < 0) {
                keyInverse[i][j] += 26;
            }
        }
    }

    // Decrypt the message
    for (int i = 0; i < message.length(); i += keySize) {
        for (int j = 0; j < keySize; j++) {
            int sum = 0;
            for (int k = 0; k < keySize; k++) {
                sum += (keyInverse[j][k] * (message[i + k] - 'A'));
            }
            decrypted += static_cast<char>((sum % 26) + 'A');
        }
    }

    return decrypted;
}

int main() {
    string choice;
    cout << "Enter 'E' for encryption or 'D' for decryption: ";
    cin >> choice;

    if (choice == "E" || choice == "e") {
        string message;
        vector<vector<int>> key;

        cout << "Enter the plaintext message (uppercase letters only): ";
        cin.ignore();
        getline(cin, message);

        cout << "Enter the key matrix (3x3):" << endl;
        for (int i = 0; i < 3; i++) {
            vector<int> row;
            for (int j = 0; j < 3; j++) {
                int element;
                cin >> element;
                row.push_back(element);
            }
            key.push_back(row);
        }

        string encryptedMessage = encrypt(message, key);
        cout << "Encrypted message: " << encryptedMessage << endl;
    } else if (choice == "D" || choice == "d") {
        string message;
        vector<vector<int>> key;

        cout << "Enter the ciphertext message (uppercase letters only): ";
        cin.ignore();
        getline(cin, message);

        cout << "Enter the key matrix (3x3):" << endl;
        for (int i = 0; i < 3; i++) {
            vector<int> row;
            for (int j = 0; j < 3; j++) {
                int element;
                cin >> element;
                row.push_back(element);
            }
            key.push_back(row);
        }

        string decryptedMessage = decrypt(message, key);
        cout << "Decrypted message: " << decryptedMessage << endl;
    } else {
        cout << "Invalid choice. Please enter 'E' for encryption or 'D' for decryption." << endl;
    }

    return 0;
}
