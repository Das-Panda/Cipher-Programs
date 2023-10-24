#include <iostream>
#include <cctype>
#include <cstring>

// Function to remove spaces and make the input all uppercase
std::string prepareInput(std::string input) {
    std::string preparedInput = "";
    for (char c : input) {
        if (std::isalpha(c)) {
            preparedInput += std::toupper(c);
        }
    }
    return preparedInput;
}

// Function to generate the Playfair key table
void generateKeyTable(const std::string& key, char keyTable[5][5]) {
    std::string uniqueKey = "";
    for (char c : key) {
        if (uniqueKey.find(c) == std::string::npos && std::isalpha(c)) {
            uniqueKey += c;
        }
    }

    // Fill the table with the unique key
    int k = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (k < uniqueKey.size()) {
                keyTable[i][j] = uniqueKey[k++];
            } else {
                for (char c = 'A'; c <= 'Z'; ++c) {
                    if (uniqueKey.find(c) == std::string::npos) {
                        keyTable[i][j] = c;
                        uniqueKey += c;
                        break;
                    }
                }
            }
        }
    }
}

// Function to find the coordinates of a character in the key table
void findCoordinates(char keyTable[5][5], char c, int& row, int& col) {
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (keyTable[i][j] == c) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Function to encrypt a digraph (two characters) using the Playfair Cipher
std::string encryptDigraph(char keyTable[5][5], char a, char b) {
    int row1, col1, row2, col2;
    findCoordinates(keyTable, a, row1, col1);
    findCoordinates(keyTable, b, row2, col2);

    if (row1 == row2) {
        // Characters are in the same row
        return std::string(1, keyTable[row1][(col1 + 1) % 5]) + std::string(1, keyTable[row2][(col2 + 1) % 5]);
    } else if (col1 == col2) {
        // Characters are in the same column
        return std::string(1, keyTable[(row1 + 1) % 5][col1]) + std::string(1, keyTable[(row2 + 1) % 5][col2]);
    } else {
        // Characters form a rectangle
        return std::string(1, keyTable[row1][col2]) + std::string(1, keyTable[row2][col1]);
    }
}

int main() {
    char keyTable[5][5];
    std::string key, input, output;
    char choice;

    std::cout << "Enter the Playfair key: ";
    std::cin >> key;

    generateKeyTable(key, keyTable);

    std::cout << "Enter 'e' for encryption or 'd' for decryption: ";
    std::cin >> choice;

    std::cin.ignore();  // Clear the newline character from the input buffer

    if (choice == 'e' || choice == 'E') {
        std::cout << "Enter the plaintext to encrypt: ";
        getline(std::cin, input);
        input = prepareInput(input);

        // Ensure the input has an even length
        if (input.length() % 2 != 0) {
            input += 'X';
        }

        for (int i = 0; i < input.length(); i += 2) {
            output += encryptDigraph(keyTable, input[i], input[i + 1]);
        }

        std::cout << "Encrypted text: " << output << std::endl;
    } else if (choice == 'd' || choice == 'D') {
        std::cout << "Enter the ciphertext to decrypt: ";
        getline(std::cin, input);
        input = prepareInput(input);

        for (int i = 0; i < input.length(); i += 2) {
            output += encryptDigraph(keyTable, input[i], input[i + 1]);
        }

        std::cout << "Decrypted text: " << output << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 'e' or 'd'." << std::endl;
    }

    return 0;
}
