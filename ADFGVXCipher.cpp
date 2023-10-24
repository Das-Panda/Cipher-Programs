#include <iostream>
#include <map>
#include <string>
#include <vector>

// ADFGVX cipher key
const char adfgvxTable[6][6] = {
    {'A', 'D', 'F', 'G', 'V', 'X'},
    {'F', 'R', 'C', 'N', 'Y', 'T'},
    {'E', 'J', 'O', 'T', 'U', 'K'},
    {'P', 'H', 'Q', 'Z', 'G', 'M'},
    {'W', 'B', 'S', 'I', 'L', 'V'},
    {'X', 'N', 'O', 'P', 'A', 'Q'}};

std::map<char, std::string> adfgvxMap;

void initializeADFGVXMap() {
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 6; ++j) {
            adfgvxMap[adfgvxTable[i][j]] = std::to_string(i) + std::to_string(j);
        }
    }
}

std::string encrypt(const std::string& plaintext) {
    std::string ciphertext;
    for (char c : plaintext) {
        if (adfgvxMap.find(c) != adfgvxMap.end()) {
            ciphertext += adfgvxMap[c];
        }
    }
    return ciphertext;
}

std::string decrypt(const std::string& ciphertext) {
    std::string plaintext;
    for (size_t i = 0; i < ciphertext.length(); i += 2) {
        char row = ciphertext[i];
        char col = ciphertext[i + 1];
        plaintext += adfgvxTable[row - '0'][col - '0'];
    }
    return plaintext;
}

int main() {
    initializeADFGVXMap();

    std::cout << "ADFGVX Cipher\n";
    std::cout << "1. Encrypt\n";
    std::cout << "2. Decrypt\n";
    std::cout << "Choose an option (1/2): ";

    int choice;
    std::cin >> choice;
    std::cin.ignore();

    if (choice == 1) {
        std::string plaintext;
        std::cout << "Enter the plaintext: ";
        std::getline(std::cin, plaintext);
        std::string ciphertext = encrypt(plaintext);
        std::cout << "Ciphertext: " << ciphertext << std::endl;
    } else if (choice == 2) {
        std::string ciphertext;
        std::cout << "Enter the ciphertext: ";
        std::getline(std::cin, ciphertext);
        std::string plaintext = decrypt(ciphertext);
        std::cout << "Decrypted Text: " << plaintext << std::endl;
    } else {
        std::cout << "Invalid choice.\n";
    }

    return 0;
}
