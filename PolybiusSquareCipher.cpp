#include <iostream>
#include <string>

// Define the Polybius Square
const char polybiusSquare[5][5] = {
    {'A', 'B', 'C', 'D', 'E'},
    {'F', 'G', 'H', 'I', 'K'},
    {'L', 'M', 'N', 'O', 'P'},
    {'Q', 'R', 'S', 'T', 'U'},
    {'V', 'W', 'X', 'Y', 'Z'}
};

// Function to find the coordinates of a character in the Polybius Square
void findCoordinates(char ch, int& row, int& col) {
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (polybiusSquare[i][j] == ch) {
                row = i;
                col = j;
                return;
            }
        }
    }
}

// Function to encrypt a message using the Polybius Square Cipher
std::string encrypt(const std::string& plaintext) {
    std::string ciphertext = "";
    for (char ch : plaintext) {
        if (ch == ' ') {
            ciphertext += ' ';
        } else {
            int row, col;
            findCoordinates(toupper(ch), row, col);
            ciphertext += std::to_string(row + 1) + std::to_string(col + 1);
        }
    }
    return ciphertext;
}

// Function to decrypt a message using the Polybius Square Cipher
std::string decrypt(const std::string& ciphertext) {
    std::string plaintext = "";
    for (int i = 0; i < ciphertext.length(); i += 2) {
        if (ciphertext[i] == ' ') {
            plaintext += ' ';
        } else {
            int row = ciphertext[i] - '0' - 1;
            int col = ciphertext[i + 1] - '0' - 1;
            plaintext += polybiusSquare[row][col];
        }
    }
    return plaintext;
}

int main() {
    char choice;
    std::string input;

    std::cout << "Polybius Square Cipher\n";
    std::cout << "Choose an option:\n";
    std::cout << "1. Encrypt\n";
    std::cout << "2. Decrypt\n";
    std::cout << "Enter 1 or 2: ";
    std::cin >> choice;
    std::cin.ignore(); // Clear the newline character

    if (choice == '1') {
        std::cout << "Enter the plaintext to encrypt: ";
        std::getline(std::cin, input);
        std::string ciphertext = encrypt(input);
        std::cout << "Ciphertext: " << ciphertext << std::endl;
    } else if (choice == '2') {
        std::cout << "Enter the ciphertext to decrypt: ";
        std::getline(std::cin, input);
        std::string plaintext = decrypt(input);
        std::cout << "Plaintext: " << plaintext << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 1 or 2." << std::endl;
    }

    return 0;
}
