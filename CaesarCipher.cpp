#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    char sifre[100];
    int anahtar;

    
    ofstream dosya("sifre.txt");

   
    cout << "Sifreyi Girin: ";
    cin.getline(sifre, 100);
    cout << "Anahtari Girin: ";
    cin >> anahtar;

    dosya << sifre << endl;
    dosya << anahtar << endl;

    dosya.close();

    ifstream dosyaOku("sifre.txt");

    dosyaOku.getline(sifre, 100);
    dosyaOku >> anahtar;

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

    cout << "Desifre: " << sifre << endl;

    dosyaOku.close();

    return 0;
}
