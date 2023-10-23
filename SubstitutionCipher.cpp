#include <iostream>
#include <string>
#include <cctype>

// Function to perform substitution cipher encryption
std::string encrypt(std::string message, std::string key) {
    std::string encryptedMessage = "";
    for (char c : message) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            encryptedMessage += key[c - base];
        } else {
            encryptedMessage += c;
        }
    }
    return encryptedMessage;
}

// Function to perform substitution cipher decryption
std::string decrypt(std::string encryptedMessage, std::string key) {
    std::string decryptedMessage = "";
    for (char c : encryptedMessage) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            size_t index = key.find(c);
            decryptedMessage += (index != std::string::npos) ? static_cast<char>(base + index) : c;
        } else {
            decryptedMessage += c;
        }
    }
    return decryptedMessage;
}

int main() {
    std::string key = "zyxwvutsrqponmlkjihgfedcba"; // Example key (reverse alphabet)
    
    std::cout << "Simple Substitution Cipher" << std::endl;
    std::cout << "--------------------------" << std::endl;
    
    char choice;
    do {
        std::cout << "Choose an option:" << std::endl;
        std::cout << "1. Encrypt" << std::endl;
        std::cout << "2. Decrypt" << std::endl;
        std::cout << "3. Quit" << std::endl;
        std::cout << "Enter your choice (1/2/3): ";
        std::cin >> choice;
        
        std::cin.ignore(); // Clear newline character
        
        if (choice == '1') {
            std::string message;
            std::cout << "Enter the message to encrypt: ";
            std::getline(std::cin, message);
            std::string encryptedMessage = encrypt(message, key);
            std::cout << "Encrypted message: " << encryptedMessage << std::endl;
        } else if (choice == '2') {
            std::string encryptedMessage;
            std::cout << "Enter the message to decrypt: ";
            std::getline(std::cin, encryptedMessage);
            std::string decryptedMessage = decrypt(encryptedMessage, key);
            std::cout << "Decrypted message: " << decryptedMessage << std::endl;
        } else if (choice != '3') {
            std::cout << "Invalid choice. Please enter 1, 2, or 3." << std::endl;
        }
    } while (choice != '3');
    
    std::cout << "Goodbye!" << std::endl;
    
    return 0;
}
