#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to perform Bifid encryption
string bifidEncrypt(string plaintext, string key) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<vector<int>> grid(5, vector<int>(5));

    // Fill the grid with the key
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k < key.length()) {
                grid[i][j] = key[k++] - 'A';
            } else {
                for (char c : alphabet) {
                    if (key.find(c) == string::npos) {
                        grid[i][j] = c - 'A';
                        key += c;
                        break;
                    }
                }
            }
        }
    }

    string ciphertext = "";
    string rowNumbers = "";
    string colNumbers = "";

    // Convert plaintext to uppercase
    for (char& c : plaintext) {
        if (isalpha(c)) {
            c = toupper(c);
            int row, col;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (grid[i][j] == c - 'A') {
                        row = i;
                        col = j;
                        break;
                    }
                }
            }
            rowNumbers += to_string(row + 1);
            colNumbers += to_string(col + 1);
        }
    }

    // Combine row and column numbers
    rowNumbers += colNumbers;

    // Split the combined numbers into pairs
    for (size_t i = 0; i < rowNumbers.length(); i += 2) {
        int row = rowNumbers[i] - '0';
        int col = colNumbers[i + 1] - '0';
        ciphertext += alphabet[(row - 1) * 5 + col - 1];
    }

    return ciphertext;
}

// Function to perform Bifid decryption
string bifidDecrypt(string ciphertext, string key) {
    string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    vector<vector<int>> grid(5, vector<int>(5));

    // Fill the grid with the key
    int k = 0;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (k < key.length()) {
                grid[i][j] = key[k++] - 'A';
            } else {
                for (char c : alphabet) {
                    if (key.find(c) == string::npos) {
                        grid[i][j] = c - 'A';
                        key += c;
                        break;
                    }
                }
            }
        }
    }

    string rowNumbers = "";
    string colNumbers = "";

    // Convert ciphertext to uppercase
    for (char& c : ciphertext) {
        if (isalpha(c)) {
            c = toupper(c);
            int index = alphabet.find(c);
            int row = index / 5;
            int col = index % 5;
            rowNumbers += to_string(row + 1);
            colNumbers += to_string(col + 1);
        }
    }

    // Combine row and column numbers
    string combinedNumbers = rowNumbers + colNumbers;

    string plaintext = "";

    // Read pairs of numbers and convert them to letters
    for (size_t i = 0; i < combinedNumbers.length(); i += 2) {
        int row = combinedNumbers[i] - '0';
        int col = combinedNumbers[i + 1] - '0';
        plaintext += alphabet[(row - 1) * 5 + col - 1];
    }

    return plaintext;
}

int main() {
    string key;
    cout << "Enter the Bifid key (25 unique uppercase letters): ";
    cin >> key;

    if (key.length() != 25) {
        cout << "Key must contain 25 unique uppercase letters." << endl;
        return 1;
    }

    cout << "Do you want to encrypt (E) or decrypt (D)? ";
    char choice;
    cin >> choice;

    if (choice == 'E' || choice == 'e') {
        cin.ignore(); // Consume the newline character left by cin
        string plaintext;
        cout << "Enter the plaintext: ";
        getline(cin, plaintext);
        string ciphertext = bifidEncrypt(plaintext, key);
        cout << "Ciphertext: " << ciphertext << endl;
    } else if (choice == 'D' || choice == 'd') {
        string ciphertext;
        cout << "Enter the ciphertext: ";
        cin >> ciphertext;
        string plaintext = bifidDecrypt(ciphertext, key);
        cout << "Plaintext: " << plaintext << endl;
    } else {
        cout << "Invalid choice. Please enter 'E' or 'D' for encryption or decryption." << endl;
        return 1;
    }

    return 0;
}
