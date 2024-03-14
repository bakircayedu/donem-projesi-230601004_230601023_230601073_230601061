#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char sifre[100];
    int anahtar;

    // Dosyayı yazma modunda aç
    ofstream dosya("sifre.txt");

    // Kullanıcıdan sifre ve anahtar değerlerini al
    cout << "Sifreyi Girin: ";
    cin.getline(sifre, 100);
    cout << "Anahtari Girin: ";
    cin >> anahtar;

    // Dosyaya sifre ve anahtar değerlerini yaz
    dosya << sifre << endl;
    dosya << anahtar << endl;

    // Dosyayı kapat
    dosya.close();

    // Dosyayı okuma modunda aç
    ifstream dosyaOku("sifre.txt");

    // Dosyadan sifre ve anahtar değerlerini oku
    dosyaOku.getline(sifre, 100);
    dosyaOku >> anahtar;

    // Şifreleme işlemi
    for (int i = 0; sifre[i] != '\0'; ++i)
    {
        if (sifre[i] >= 'a' && sifre[i] <= 'z')
        {
            sifre[i] = sifre[i] - anahtar;
            if (sifre[i] < 'a')
                sifre[i] = sifre[i] + 'z' - 'a' + 1;
            sifre[i] = sifre[i];
        }
        else if (sifre[i] >= 'A' && sifre[i] <= 'Z')
        {
            sifre[i] = sifre[i] - anahtar;
            if (sifre[i] < 'A')
                sifre[i] = sifre[i] + 'Z' - 'A' + 1;
            sifre[i] = sifre[i];
        }
    }

    // Şifrelenmiş sifreyi ekrana yazdır
    cout << "Desifre: " << sifre << endl;

    // Dosyayı kapat
    dosyaOku.close();

    return 0;
}
