#include <iostream>
#include <string>
#include <cctype>
#include <vector>

// Define the Trifid grid
const char trifidGrid[3][3] = {
    {'A', 'B', 'C'},
    {'D', 'E', 'F'},
    {'G', 'H', 'I'}
};

// Function to find the position of a character in the Trifid grid
std::pair<int, int> findPosition(char c) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (trifidGrid[i][j] == c) {
                return std::make_pair(i, j);
            }
        }
    }
    return std::make_pair(-1, -1); // Character not found
}

// Function to encrypt a message using the Trifid Cipher
std::string encrypt(const std::string& message) {
    std::string encrypted = "";
    for (char c : message) {
        if (std::isalpha(c)) {
            std::pair<int, int> position = findPosition(std::toupper(c));
            if (position.first != -1 && position.second != -1) {
                int row = position.first + 1;
                int col = position.second + 1;
                int layer = (row + col - 2) / 3 + 1;
                encrypted += std::to_string(layer) + std::to_string(row) + std::to_string(col);
            }
        } else {
            encrypted += c; // Keep non-alphabetical characters unchanged
        }
    }
    return encrypted;
}

// Function to decrypt a message using the Trifid Cipher
std::string decrypt(const std::string& message) {
    std::string decrypted = "";
    for (size_t i = 0; i < message.length(); i += 3) {
        int layer = message[i] - '0';
        int row = message[i + 1] - '0';
        int col = message[i + 2] - '0';
        char c = trifidGrid[(layer - 1) * 3 + row - 1][col - 1];
        decrypted += c;
    }
    return decrypted;
}

int main() {
    std::string choice;
    std::cout << "Trifid Cipher - Encrypt or Decrypt? (e/d): ";
    std::cin >> choice;

    if (choice == "e" || choice == "E") {
        std::string plaintext;
        std::cout << "Enter the message to encrypt: ";
        std::cin.ignore(); // Clear the newline character from the buffer
        std::getline(std::cin, plaintext);
        std::string encrypted = encrypt(plaintext);
        std::cout << "Encrypted message: " << encrypted << std::endl;
    } else if (choice == "d" || choice == "D") {
        std::string ciphertext;
        std::cout << "Enter the message to decrypt: ";
        std::cin.ignore(); // Clear the newline character from the buffer
        std::getline(std::cin, ciphertext);
        std::string decrypted = decrypt(ciphertext);
        std::cout << "Decrypted message: " << decrypted << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 'e' for encrypt or 'd' for decrypt." << std::endl;
    }

    return 0;
}
