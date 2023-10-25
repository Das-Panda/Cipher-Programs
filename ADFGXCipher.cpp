#include <iostream>
#include <string>
#include <vector>
#include <map>

// Define the ADFGX grid
const char adfgx[5][5] = {
    {'A', 'D', 'F', 'G', 'X'},
    {'N', 'B', 'C', 'E', 'H'},
    {'I', 'K', 'L', 'M', 'P'},
    {'Q', 'R', 'S', 'T', 'U'},
    {'V', 'W', 'Y', 'Z', ' '},
};

// Function to encrypt a message
std::string encrypt(const std::string& message) {
    std::map<char, std::string> adfgxMap;

    // Create a map to store ADFGX mappings
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            adfgxMap[adfgx[i][j]] = std::string(1, 'A' + i) + std::string(1, 'A' + j);
        }
    }

    std::string ciphertext;

    // Convert the message to ADFGX
    for (char c : message) {
        c = std::toupper(c);
        if (adfgxMap.find(c) != adfgxMap.end()) {
            ciphertext += adfgxMap[c];
        }
    }

    return ciphertext;
}

// Function to decrypt ADFGX ciphertext
std::string decrypt(const std::string& ciphertext) {
    // Implement the decryption logic here
    // You will need to reverse the mapping and reconstruct the original message
    // This is a more complex part of the ADFGX cipher and requires additional code.
    // We'll simplify it by leaving it as a placeholder.
    return "Decryption not implemented";
}

int main() {
    std::cout << "Choose an option (1 for encryption, 2 for decryption): ";
    int option;
    std::cin >> option;
    std::cin.ignore();  // Consume newline character

    if (option == 1) {
        std::cout << "Enter the plaintext message: ";
        std::string plaintext;
        std::getline(std::cin, plaintext);

        std::string ciphertext = encrypt(plaintext);
        std::cout << "Encrypted message: " << ciphertext << std::endl;
    } else if (option == 2) {
        std::cout << "Enter the ciphertext: ";
        std::string ciphertext;
        std::getline(std::cin, ciphertext);

        std::string plaintext = decrypt(ciphertext);
        std::cout << "Decrypted message: " << plaintext << std::endl;
    } else {
        std::cout << "Invalid option." << std::endl;
    }

    return 0;
}
