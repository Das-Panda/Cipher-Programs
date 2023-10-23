#include <iostream>
#include <string>

using namespace std;

// Function to encrypt a message using Rail-fence Cipher
string encryptRailFence(string plaintext, int rails) {
    string ciphertext;
    string rail[rails];

    // Initialize rail strings
    for (int i = 0; i < rails; i++) {
        rail[i] = "";
    }

    int railIdx = 0;
    bool directionDown = true;

    for (char c : plaintext) {
        rail[railIdx] += c;

        if (railIdx == 0) {
            directionDown = true;
        } else if (railIdx == rails - 1) {
            directionDown = false;
        }

        if (directionDown) {
            railIdx++;
        } else {
            railIdx--;
        }
    }

    // Combine the rail strings to form the ciphertext
    for (int i = 0; i < rails; i++) {
        ciphertext += rail[i];
    }

    return ciphertext;
}

// Function to decrypt a message encrypted using Rail-fence Cipher
string decryptRailFence(string ciphertext, int rails) {
    string plaintext;
    string rail[rails];

    // Initialize rail strings
    for (int i = 0; i < rails; i++) {
        rail[i] = "";
    }

    int railIdx = 0;
    bool directionDown = true;

    for (int i = 0; i < ciphertext.length(); i++) {
        rail[railIdx] += 'X'; // Fill the rail with a placeholder character

        if (railIdx == 0) {
            directionDown = true;
        } else if (railIdx == rails - 1) {
            directionDown = false;
        }

        if (directionDown) {
            railIdx++;
        } else {
            railIdx--;
        }
    }

    // Fill the rail strings with the characters from the ciphertext
    int charIdx = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < rail[i].length(); j++) {
            rail[i][j] = ciphertext[charIdx++];
        }
    }

    railIdx = 0;
    directionDown = true;

    for (int i = 0; i < ciphertext.length(); i++) {
        plaintext += rail[railIdx][0];
        rail[railIdx] = rail[railIdx].substr(1); // Remove the first character

        if (railIdx == 0) {
            directionDown = true;
        } else if (railIdx == rails - 1) {
            directionDown = false;
        }

        if (directionDown) {
            railIdx++;
        } else {
            railIdx--;
        }
    }

    return plaintext;
}

int main() {
    int choice;
    cout << "Rail-fence Cipher" << endl;
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "Enter your choice (1/2): ";
    cin >> choice;
    cin.ignore(); // Clear the newline character from the input buffer

    if (choice == 1) {
        string plaintext;
        int rails;

        cout << "Enter the plaintext: ";
        getline(cin, plaintext);
        cout << "Enter the number of rails: ";
        cin >> rails;

        string ciphertext = encryptRailFence(plaintext, rails);
        cout << "Ciphertext: " << ciphertext << endl;
    } else if (choice == 2) {
        string ciphertext;
        int rails;

        cout << "Enter the ciphertext: ";
        cin.ignore(); // Clear the newline character from the input buffer
        getline(cin, ciphertext);
        cout << "Enter the number of rails: ";
        cin >> rails;

        string plaintext = decryptRailFence(ciphertext, rails);
        cout << "Decrypted plaintext: " << plaintext << endl;
    } else {
        cout << "Invalid choice. Please select 1 or 2." << endl;
    }

    return 0;
}
