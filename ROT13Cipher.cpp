#include <iostream>
#include <string>
#include <cctype>
#include <limits> // Include the <limits> header

// Function to perform ROT13 encryption
std::string encryptROT13(const std::string& input) {
    std::string result = input;
    for (char& c : result) {
        if (std::isalpha(c)) {
            char base = (std::islower(c)) ? 'a' : 'A';
            c = ((c - base + 13) % 26) + base;
        }
    }
    return result;
}

// Function to perform ROT13 decryption (same as encryption)
std::string decryptROT13(const std::string& input) {
    return encryptROT13(input);
}

int main() {
    char choice;
    std::string input;

    std::cout << "Would you like to (e)ncrypt or (d)ecrypt a message? ";
    std::cin >> choice;

    // Clear newline character from input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    if (std::tolower(choice) == 'e') {
        std::cout << "Enter the message to encrypt: ";
        std::getline(std::cin, input);
        std::string encrypted = encryptROT13(input);
        std::cout << "Encrypted message: " << encrypted << std::endl;
    } else if (std::tolower(choice) == 'd') {
        std::cout << "Enter the message to decrypt: ";
        std::getline(std::cin, input);
        std::string decrypted = decryptROT13(input);
        std::cout << "Decrypted message: " << decrypted << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 'e' for encryption or 'd' for decryption." << std::endl;
    }

    return 0;
}
