#include <iostream>
#include <string>
#include <map>

// Function to encrypt a message using a Codes and Nomenclators cipher
std::string encryptMessage(const std::string& message, const std::map<char, std::string>& codeMap) {
    std::string encryptedMessage = "";

    for (char c : message) {
        // Check if the character is in the code map
        if (codeMap.find(c) != codeMap.end()) {
            encryptedMessage += codeMap.at(c);
        } else {
            // If the character is not in the code map, leave it unchanged
            encryptedMessage += c;
        }
    }

    return encryptedMessage;
}

// Function to decrypt a message using a Codes and Nomenclators cipher
std::string decryptMessage(const std::string& encryptedMessage, const std::map<char, std::string>& codeMap) {
    std::string decryptedMessage = "";
    std::string buffer = "";

    for (char c : encryptedMessage) {
        buffer += c;

        // Check if the buffer matches any code in the map
        for (const auto& pair : codeMap) {
            if (pair.second == buffer) {
                decryptedMessage += pair.first;
                buffer = "";  // Reset the buffer
                break;
            }
        }
    }

    return decryptedMessage;
}

int main() {
    std::map<char, std::string> codeMap;

    // Define your Codes and Nomenclators mapping here
    codeMap['H'] = "123";
    codeMap['e'] = "456";
    codeMap['l'] = "789";
    codeMap['o'] = "0";
    codeMap[','] = "-";
    codeMap[' '] = " ";

    char choice;
    std::string message;

    std::cout << "Do you want to encrypt (E) or decrypt (D) a message? ";
    std::cin >> choice;

    if (choice == 'E' || choice == 'e') {
        std::cout << "Enter the message to encrypt: ";
        std::cin.ignore();  // Clear the newline character
        std::getline(std::cin, message);

        std::string encryptedMessage = encryptMessage(message, codeMap);
        std::cout << "Encrypted message: " << encryptedMessage << std::endl;
    } else if (choice == 'D' || choice == 'd') {
        std::cout << "Enter the message to decrypt: ";
        std::cin.ignore();  // Clear the newline character
        std::getline(std::cin, message);

        std::string decryptedMessage = decryptMessage(message, codeMap);
        std::cout << "Decrypted message: " << decryptedMessage << std::endl;
    } else {
        std::cout << "Invalid choice. Please enter 'E' for encrypt or 'D' for decrypt." << std::endl;
    }

    return 0;
}
