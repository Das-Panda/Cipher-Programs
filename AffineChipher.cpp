#include <iostream>
#include <string>
#include <cstdlib>

// Function to encrypt a character using the Affine Cipher
char encryptChar(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = islower(ch) ? 'a' : 'A';
        return ((a * (ch - base) + b) % 26) + base;
    }
    return ch;
}

// Function to decrypt a character using the Affine Cipher
char decryptChar(char ch, int a, int b) {
    if (isalpha(ch)) {
        char base = islower(ch) ? 'a' : 'A';
        int inv_a = 0;
        for (int i = 0; i < 26; i++) {
            if ((a * i) % 26 == 1) {
                inv_a = i;
                break;
            }
        }
        return (((inv_a * (ch - base - b)) % 26) + 26) % 26 + base;
    }
    return ch;
}

int main() {
    int choice;
    std::cout << "Affine Cipher\n";
    std::cout << "1. Encrypt\n";
    std::cout << "2. Decrypt\n";
    std::cout << "Enter your choice (1/2): ";
    std::cin >> choice;

    if (choice != 1 && choice != 2) {
        std::cout << "Invalid choice. Exiting...\n";
        return 1;
    }

    int a, b;
    std::cout << "Enter the value of 'a' (a must be coprime with 26): ";
    std::cin >> a;

    if (a % 2 == 0 || a % 13 == 0 || a < 1 || a > 25) {
        std::cout << "Invalid 'a' value. Exiting...\n";
        return 1;
    }

    std::cout << "Enter the value of 'b': ";
    std::cin >> b;

    std::cin.ignore(); // Clear the newline character from the input buffer.

    std::string message;
    std::cout << "Enter the message: ";
    std::getline(std::cin, message);

    std::string result = message;

    if (choice == 1) {
        for (char &ch : result) {
            ch = encryptChar(ch, a, b);
        }
        std::cout << "Encrypted message: " << result << std::endl;
    } else {
        for (char &ch : result) {
            ch = decryptChar(ch, a, b);
        }
        std::cout << "Decrypted message: " << result << std::endl;
    }

    return 0;
}
