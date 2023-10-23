#include <iostream>
#include <string>
#include <cctype>
#include <vector>

// Define the size of the key square
const int SQUARE_SIZE = 5;

// Define the key squares
const std::string KEY1 = "ABCDEFGHIKLMNOPQRSTUVWXYZ";
const std::string KEY2 = "PLKJIHGFEDCBAMNOPQRSTUVWXYZ";

// Function to prepare the message by removing spaces and converting to uppercase
std::string prepareMessage(const std::string& message) {
    std::string preparedMessage;
    for (char c : message) {
        if (std::isalpha(c)) {
            preparedMessage += std::toupper(c);
        }
    }
    return preparedMessage;
}

// Function to encrypt a message using the Four-Square Cipher
std::string encrypt(const std::string& message) {
    std::string preparedMessage = prepareMessage(message);
    std::string result;
    
    for (size_t i = 0; i < preparedMessage.length(); i += 2) {
        char c1 = preparedMessage[i];
        char c2 = (i + 1 < preparedMessage.length()) ? preparedMessage[i + 1] : 'X'; // Pad with 'X' if necessary

        int row1, col1, row2, col2;
        
        // Find the positions of the characters in the key squares
        for (int row = 0; row < SQUARE_SIZE; ++row) {
            for (int col = 0; col < SQUARE_SIZE; ++col) {
                if (KEY1[row * SQUARE_SIZE + col] == c1) {
                    row1 = row;
                    col1 = col;
                }
                if (KEY2[row * SQUARE_SIZE + col] == c2) {
                    row2 = row;
                    col2 = col;
                }
            }
        }

        // Encrypt the pair of characters
        result += KEY1[row1 * SQUARE_SIZE + col2];
        result += KEY2[row2 * SQUARE_SIZE + col1];
    }
    
    return result;
}

int main() {
    char choice;
    std::string message;
    
    std::cout << "Four-Square Cipher\n";
    std::cout << "-------------------\n";
    
    std::cout << "Do you want to encrypt (E) or decrypt (D)? ";
    std::cin >> choice;
    
    if (std::toupper(choice) == 'E') {
        std::cin.ignore(); // Clear the newline character from the buffer
        std::cout << "Enter the message to encrypt: ";
        std::getline(std::cin, message);
        std::string encryptedMessage = encrypt(message);
        std::cout << "Encrypted message: " << encryptedMessage << std::endl;
    } else if (std::toupper(choice) == 'D') {
        // Implement decryption logic here if needed
        std::cout << "Decryption is not implemented in this example.\n";
    } else {
        std::cout << "Invalid choice. Please choose E (encrypt) or D (decrypt)." << std::endl;
    }

    return 0;
}
