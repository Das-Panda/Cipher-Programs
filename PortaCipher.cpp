#include <iostream>
#include <string>

// Function to encrypt a message using the Porta Cipher
std::string encrypt(const std::string& message, const std::string& keyword) {
    std::string ciphertext;
    for (size_t i = 0; i < message.length(); ++i) {
        char c = message[i];
        char k = keyword[i % keyword.length()];
        // Check if the character is a letter
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            // Perform Porta Cipher encryption
            char encrypted_char = (c - base + (k - 'A')) % 26 + base;
            ciphertext += encrypted_char;
        } else {
            // Non-alphabetic characters are left unchanged
            ciphertext += c;
        }
    }
    return ciphertext;
}

// Function to decrypt a message using the Porta Cipher
std::string decrypt(const std::string& ciphertext, const std::string& keyword) {
    std::string message;
    for (size_t i = 0; i < ciphertext.length(); ++i) {
        char c = ciphertext[i];
        char k = keyword[i % keyword.length()];
        // Check if the character is a letter
        if (isalpha(c)) {
            char base = islower(c) ? 'a' : 'A';
            // Perform Porta Cipher decryption
            char decrypted_char = (c - base - (k - 'A') + 26) % 26 + base;
            message += decrypted_char;
        } else {
            // Non-alphabetic characters are left unchanged
            message += c;
        }
    }
    return message;
}

int main() {
    std::string choice;
    std::cout << "Porta Cipher - Choose an option (encrypt/decrypt): ";
    std::cin >> choice;

    if (choice == "encrypt") {
        std::string message, keyword;
        std::cout << "Enter the message to encrypt: ";
        std::cin.ignore(); // Clear the newline character from the buffer
        std::getline(std::cin, message);
        std::cout << "Enter the keyword: ";
        std::cin >> keyword;
        std::string ciphertext = encrypt(message, keyword);
        std::cout << "Encrypted message: " << ciphertext << std::endl;
    } else if (choice == "decrypt") {
        std::string ciphertext, keyword;
        std::cout << "Enter the ciphertext to decrypt: ";
        std::cin.ignore(); // Clear the newline character from the buffer
        std::getline(std::cin, ciphertext);
        std::cout << "Enter the keyword: ";
        std::cin >> keyword;
        std::string message = decrypt(ciphertext, keyword);
        std::cout << "Decrypted message: " << message << std::endl;
    } else {
        std::cout << "Invalid choice. Please choose 'encrypt' or 'decrypt'." << std::endl;
    }

    return 0;
}
