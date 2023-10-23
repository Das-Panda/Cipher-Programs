#include <iostream>
#include <string>
#include <cctype>

// Function to perform Atbash encryption
std::string atbashEncrypt(const std::string& text) {
    std::string result = "";
    for (char c : text) {
        if (std::isalpha(c)) {
            char encryptedChar;
            if (std::isupper(c)) {
                encryptedChar = 'Z' - (c - 'A');
            } else {
                encryptedChar = 'z' - (c - 'a');
            }
            result += encryptedChar;
        } else {
            result += c; // Keep non-alphabetic characters unchanged
        }
    }
    return result;
}

// Function to perform Atbash decryption
std::string atbashDecrypt(const std::string& text) {
    return atbashEncrypt(text); // Atbash decryption is the same as encryption
}

int main() {
    std::string inputText;
    std::string outputText;
    
    std::cout << "Are you trying to 'encrypt' or 'decrypt'?: ";
    std::string mode;
    std::cin >> mode;
    
    std::cin.ignore(); // Clear the newline character
    
    std::cout << "Enter text: ";
    std::getline(std::cin, inputText);
    
    if (mode == "encrypt") {
        outputText = atbashEncrypt(inputText);
        std::cout << "Encrypted text: " << outputText << std::endl;
    } else if (mode == "decrypt") {
        outputText = atbashDecrypt(inputText);
        std::cout << "Decrypted text: " << outputText << std::endl;
    } else {
        std::cout << "Invalid mode. Please enter 'encrypt' or 'decrypt'." << std::endl;
    }
    
    return 0;
}
