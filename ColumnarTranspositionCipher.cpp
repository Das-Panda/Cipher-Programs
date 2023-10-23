#include <iostream>
#include <vector>
#include <algorithm>

// Function to encrypt a message using Columnar Transposition Cipher
std::string encrypt(const std::string& plaintext, const std::string& key) {
    int keyLength = key.length();
    int textLength = plaintext.length();
    
    // Calculate the number of rows required for the grid
    int numRows = textLength / keyLength;
    if (textLength % keyLength != 0) {
        numRows++;
    }
    
    // Create a 2D grid to hold the characters
    std::vector<std::vector<char>> grid(numRows, std::vector<char>(keyLength, ' '));
    
    // Fill the grid with characters from the plaintext
    int index = 0;
    for (int col = 0; col < keyLength; col++) {
        for (int row = 0; row < numRows; row++) {
            if (index < textLength) {
                grid[row][col] = plaintext[index];
                index++;
            }
        }
    }
    
    // Create the ciphertext by reading the grid column-wise based on the key order
    std::string ciphertext;
    for (char c : key) {
        int col = c - '1';
        for (int row = 0; row < numRows; row++) {
            if (grid[row][col] != ' ') {
                ciphertext += grid[row][col];
            }
        }
    }
    
    return ciphertext;
}

// Function to decrypt a message encrypted using Columnar Transposition Cipher
std::string decrypt(const std::string& ciphertext, const std::string& key) {
    int keyLength = key.length();
    int textLength = ciphertext.length();
    
    // Calculate the number of rows required for the grid
    int numRows = textLength / keyLength;
    
    // Create a 2D grid to hold the characters
    std::vector<std::vector<char>> grid(numRows, std::vector<char>(keyLength, ' '));
    
    // Calculate the number of characters in the last row
    int lastRowLength = textLength % keyLength;
    
    // Calculate the number of columns that have one more character than the others
    int numColsWithExtraChar = std::count(key.begin(), key.end(), key[keyLength - 1]);
    
    // Calculate the number of columns with one less character than the others
    int numColsWithLessChar = keyLength - numColsWithExtraChar;
    
    // Fill the grid column-wise based on the key order
    int index = 0;
    for (char c : key) {
        int col = c - '1';
        int numRowsInThisCol = (col < numColsWithLessChar) ? numRows : (numRows - 1);
        for (int row = 0; row < numRowsInThisCol; row++) {
            grid[row][col] = ciphertext[index];
            index++;
        }
    }
    
    // Read the grid row-wise to create the plaintext
    std::string plaintext;
    for (int row = 0; row < numRows; row++) {
        for (int col = 0; col < keyLength; col++) {
            if (grid[row][col] != ' ') {
                plaintext += grid[row][col];
            }
        }
    }
    
    return plaintext;
}

int main() {
    std::cout << "Columnar Transposition Cipher" << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Encrypt" << std::endl;
    std::cout << "2. Decrypt" << std::endl;
    
    int choice;
    std::cin >> choice;
    
    std::cin.ignore(); // Clear the newline character
    
    if (choice == 1) {
        std::cout << "Enter the plaintext: ";
        std::string plaintext;
        std::getline(std::cin, plaintext);
        
        std::cout << "Enter the encryption key (e.g., 3214): ";
        std::string key;
        std::cin >> key;
        
        std::string ciphertext = encrypt(plaintext, key);
        std::cout << "Ciphertext: " << ciphertext << std::endl;
    } else if (choice == 2) {
        std::cout << "Enter the ciphertext: ";
        std::string ciphertext;
        std::cin >> ciphertext;
        
        std::cout << "Enter the decryption key (e.g., 3214): ";
        std::string key;
        std::cin >> key;
        
        std::string plaintext = decrypt(ciphertext, key);
        std::cout << "Plaintext: " << plaintext << std::endl;
    } else {
        std::cout << "Invalid choice." << std::endl;
    }
    
    return 0;
}
