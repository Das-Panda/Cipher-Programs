#include <iostream>
#include <string>
#include <map>

// Define Morse code mappings
std::map<char, std::string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."}, {'D', "-.."}, {'E', "."},
    {'F', "..-."}, {'G', "--."}, {'H', "...."}, {'I', ".."}, {'J', ".---"},
    {'K', "-.-"}, {'L', ".-.."}, {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."}, {'S', "..."}, {'T', "-"},
    {'U', "..-"}, {'V', "...-"}, {'W', ".--"}, {'X', "-..-"}, {'Y', "-.--"},
    {'Z', "--.."}, {'0', "-----"}, {'1', ".----"}, {'2', "..---"}, {'3', "...--"},
    {'4', "....-"}, {'5', "....."}, {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."}
};

// Function to encrypt a message using Fractionated Morse Cipher
std::string encrypt(const std::string& plaintext) {
    std::string ciphertext;
    for (char c : plaintext) {
        if (isalpha(c)) {
            char upperC = toupper(c);
            ciphertext += morseCode[upperC] + " ";
        } else if (c == ' ') {
            ciphertext += " ";
        }
    }
    return ciphertext;
}

// Function to decrypt a message using Fractionated Morse Cipher
std::string decrypt(const std::string& ciphertext) {
    std::string plaintext;
    std::string currentMorse;
    for (char c : ciphertext) {
        if (c == ' ') {
            if (!currentMorse.empty()) {
                for (const auto& pair : morseCode) {
                    if (pair.second == currentMorse) {
                        plaintext += pair.first;
                        break;
                    }
                }
                currentMorse.clear();
            } else {
                plaintext += ' ';
            }
        } else {
            currentMorse += c;
        }
    }
    return plaintext;
}

int main() {
    char choice;
    std::string input;

    std::cout << "Fractionated Morse Cipher" << std::endl;
    std::cout << "Choose an option:" << std::endl;
    std::cout << "1. Encrypt" << std::endl;
    std::cout << "2. Decrypt" << std::endl;
    std::cin >> choice;

    if (choice == '1') {
        std::cin.ignore();  // Clear the newline character
        std::cout << "Enter the plaintext to encrypt: ";
        std::getline(std::cin, input);
        std::string ciphertext = encrypt(input);
        std::cout << "Encrypted message: " << ciphertext << std::endl;
    } else if (choice == '2') {
        std::cin.ignore();  // Clear the newline character
        std::cout << "Enter the ciphertext to decrypt: ";
        std::getline(std::cin, input);
        std::string plaintext = decrypt(input);
        std::cout << "Decrypted message: " << plaintext << std::endl;
    } else {
        std::cout << "Invalid choice. Please select 1 or 2." << std::endl;
    }

    return 0;
}
