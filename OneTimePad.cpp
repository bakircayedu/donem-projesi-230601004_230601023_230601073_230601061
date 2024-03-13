#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <fstream>

using namespace std;

void setKey(string &key, int length);
void encrypt(string &message, string &key, string &encryptedMessage);
void decrypt(string &encryptedMessage, string &key, string &decryptedMessage);

int main() {
    string message;
    string satir;
    int length;
    string key;
    char mode;
    string encryptedMessage;
    string decryptedMessage;
    
    //Dosya i�lemleri
    ifstream dosyaOku("mesaj.txt"); 
    while (getline(dosyaOku, satir)) {
        message += satir + "\n"; // Her sat�r� stringe ekleyerek mesaj� olu�tur
    }
    dosyaOku.close();
    cout << "Encrypt or Decrypt?(e/d): ";
    cin >> mode;
    if(mode == 'e'){
        length = message.length();
        setKey(key, length);
        encrypt(message, key, encryptedMessage);
        cout << "Your message is encrypted succesfully" << endl;
        cout << "Your key is: " << key << endl;
        ofstream dosyaYaz("mesaj.txt");
        dosyaYaz << encryptedMessage;
        dosyaYaz.close();
    }
    else if (mode == 'd'){
        cout << "Enter your key: ";
        cin >> key;
        // Anahtar�n uzunlu�unu kontrol et ve gerekti�i kadar k�salt
        if (key.length() > message.length()) {
            key = key.substr(0, message.length());
        }
        decrypt(message, key, decryptedMessage);
        cout << "Your message is encrypted succesfully" << endl;
        ofstream dosyaYaz("mesaj.txt");
        dosyaYaz << decryptedMessage;
        dosyaYaz.close();
    }

    return 0;
}

// Generates random key
void setKey(string &key, int length) {
    key = "";
    for (int i = 0; i < length; i++) {
        key += static_cast<char>('A' + rand() % 26); // Rastgele b�y�k harf se�
    }
}

//Encrypts message with random key
void encrypt(string &message, string &key, string &encryptedMessage) {
    encryptedMessage = "";
    for (int i = 0; i < message.length(); i++) {
        encryptedMessage += (message[i] ^ key[i]); // XOR i�lemi
    }
}

//Decrypts encrypted message with key
void decrypt(string &encryptedMessage, string &key, string &decryptedMessage) {
    decryptedMessage = "";
    for (int i = 0; i < encryptedMessage.length(); i++) {
        decryptedMessage += (encryptedMessage[i] ^ key[i]); // XOR i�lemi
    }
}

