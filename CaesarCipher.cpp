#include <iostream>
#include <string>

using namespace std;

string caesarCipher(string text, int shift) {
    string result = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = static_cast<char>((c - base + shift) % 26 + base);
        }
        result += c;
    }
    return result;
}

string caesarDecipher(string text, int shift) {
    string result = "";
    for (char& c : text) {
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            c = static_cast<char>((c - base - shift + 26) % 26 + base);
        }
        result += c;
    }
    return result;
}

int main() {
    int shift;
    string input, choice;

    cout << "Do you want to create a cipher or decipher a message? (create/decipher): ";
    cin >> choice;
    cin.ignore(); // Clear the newline character from the buffer

    if (choice == "create") {
        cout << "Enter the number of positions to shift the cipher index: ";
        cin >> shift;
        cin.ignore(); // Clear the newline character from the buffer

        cout << "Enter the phrase you want to cipher: ";
        getline(cin, input);

        string encryptedText = caesarCipher(input, shift);
        cout << "Encrypted text: " << encryptedText << endl;
    } else if (choice == "decipher") {
        cout << "Enter the number of positions to shift for deciphering: ";
        cin >> shift;
        cin.ignore(); // Clear the newline character from the buffer

        cout << "Enter the phrase you want to decipher: ";
        getline(cin, input);

        string decryptedText = caesarDecipher(input, shift);
        cout << "Deciphered text: " << decryptedText << endl;
    } else {
        cout << "Invalid choice. Please choose 'create' or 'decipher'." << endl;
    }

    return 0;
}
