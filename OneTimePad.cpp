#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void setKey(string &key, int length);
void encrypt(string &message, string &key, string &encryptedMessage);
void decrypt(string &encryptedMessage, string &key, string &decryptedMessage);

int main() {
    int length;
    string key;
    string message;
    string encryptedMessage;
    string decryptedMessage;

    cout << "Enter a message to encrypt: ";
    getline(cin, message);
    length = message.length();

    setKey(key, length);
    encrypt(message, key, encryptedMessage);
    decrypt(encryptedMessage, key, decryptedMessage);
    
    cout << "Encrypted message: " << encryptedMessage << endl;
    cout << "Decrypted message: " << decryptedMessage << endl;

    return 0;
}
// Generates random key
void setKey(string &key, int length) {
    key = "";
    for (int i = 0; i < length; i++) {
        key += rand() % 26;
    }
}

//Encrypts message with random key
void encrypt(string &message, string &key, string &encryptedMessage) {
    encryptedMessage = "";
    for (int i = 0; i < message.length(); i++) {
        encryptedMessage += message[i] + key[i % key.length()];
    }
}

//Decrypts encrypted message with key
void decrypt(string &encryptedMessage, string &key, string &decryptedMessage) {
    decryptedMessage = "";
    for (int i = 0; i < encryptedMessage.length(); i++) {
        decryptedMessage += encryptedMessage[i] - key[i % key.length()];
    }
}

