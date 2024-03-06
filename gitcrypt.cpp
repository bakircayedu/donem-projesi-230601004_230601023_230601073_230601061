#include <iostream>
using namespace std;

int main ( )
{
    char sifre[100];
    int i, anahtar;

    cout << "Sifreyi Girin: ";
    cin.getline (sifre, 100);
    cout << "Anahtari Girin: ";
    cin >> anahtar;

    for (i = 0; sifre[i] != '\0'; ++i)
    {
        if  sifre[i] >= 'a' && sifre[i] <= 'z')
        {
         sifre[i] = sifre[i] - anahtar;

            if  sifre[i] < 'a')
             sifre[i] = sifre[i] + 'z' - 'a' + 1;

         sifre[i] = sifre[i];
        }
        else if  sifre[i] >= 'A' && sifre[i] <= 'Z')
        {
         sifre[i] = sifre[i] - anahtar;

            if  sifre[i] > 'a')
             sifre[i] = sifre[i] + 'Z' - 'A' + 1;

         sifre[i] = sifre[i];
        }
    }

    cout << "Desifre: " << sifre;

return 0;
}
