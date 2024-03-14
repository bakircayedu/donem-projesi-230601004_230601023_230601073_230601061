/*
    RSA Algorithm Implementation
    Mehmet Akif Akbulut
    230601004
*/


#include <iostream>
#include <cmath>
#include <random>

using namespace std;

uint64_t* primeGen();
bool isPrime(uint64_t);
uint64_t modInverse(uint64_t a, uint64_t m);
uint64_t power(uint64_t a, uint64_t b);
uint64_t modExp(uint64_t base, uint64_t exp, uint64_t m);
uint64_t gcd(uint64_t,uint64_t);
void encrypt(uint64_t *m, int size, uint64_t p, uint64_t q, uint64_t e);
void decrypt(uint64_t *m, int size, uint64_t p, uint64_t q, uint64_t e);

int main(){
    /*
        This portion is for testing purposes only as the program is still in the developmental stage.
        Will change it up to augument it to a user interface. 
    */

    //Generate two prime numbers and compute phi for the public and private keys
    uint64_t* primes = primeGen();
    uint64_t p = *(primes);
    uint64_t q = *(primes + 1);
    uint64_t e = 3;
    uint64_t phi = (p - 1)*(q - 1);

    //Select e so that it's coprime with phi
    while (gcd(e,phi) != 1)
    {
        e+=2;
    }
    
    //Get message to encrypt from user
    cout<<"Public anahtarinizin p: "<<p<<", q: "<<q<<" ve e: "<<e<<endl;
    cout<<"Sifrelenecek metni girin: ";
    char message[256];
    cin.getline(message,256);

    int messageLength = 0;

    //Get message length
    while (message[messageLength] != '\0')
    {
        messageLength++;
    }

    //Initialize an array of integers for the message
    uint64_t messageInt[messageLength];

    //Convert message characters into integers and place them into the previously initialized array
    for(int i=0;i<messageLength;i++){
        messageInt[i] = ((uint64_t) message[i]);
    }

    //Encrypt the message with p, q and e
    encrypt(&messageInt[0],messageLength,p,q,e);

    //Print out encrypted letters
    cout<<"Encrypted: ";
    for(int i:messageInt)
    {
        cout<<i;
    }
    cout<<"\n-----------------"<<endl;

    //Decrypt the message
    decrypt(&messageInt[0],messageLength,p,q,e);

    //Print out the decrypted message
    cout<<"Decrypted: ";
    for(int i:messageInt)
    {
        cout<<(char)i;
    }

}

//Function to generate prime numbers between given min and max 
uint64_t* primeGen(){

    uint64_t randNum;

    static uint64_t primes[2];
    
    //Initialize random engine and set min max
    uint64_t max = 9999;
    uint64_t min = 1000;
    random_device rd;
    default_random_engine generator(rd());
    uniform_int_distribution<long long unsigned> distribution(min,max);


     
    //Generate two numbers, check for primality, if prime place the integers in the primes array
    for(int i = 0; i<=1; i++){
        do{
            randNum= distribution(generator);
        }while(isPrime(randNum)==0);
        primes[i] = randNum;
    }

    //Return pointer to the primes array
    return primes;

}

//This function brute forces through 3 to sqrt(num) to check for primality
bool isPrime(uint64_t num){
    
    uint64_t max = sqrt(num);

    //Return false if number is even
    if(num%2==0){
        return false;
    }

    //Iterate through 3 to sqrt(num) skipping even numbers and checking for divisors
    for(uint64_t i = 3; i <= max; i+=2){
        if(num%i==0){
            return false;
        }
    }
    return true;

}

//Kind of a lazy approach to compute the modular inverse of a mod m. Found more efficient methods. Couldn't implement them
uint64_t modInverse(uint64_t a, uint64_t m) {

    //TO-DO: Write this function using the extended euclidian algorithm
    
    //Iterate through all b's for a*b%m until it gets a value for b to compute a*b%m = 1 
    uint64_t b = 0;
    while ((a*b)%m != 1)
    {
        b++;
    }
    return b;
    
}

//Wrote a function to compute exponents as pow() acted unexpectedly with bigger numbers
uint64_t power(uint64_t a, uint64_t b){
    uint64_t base = a;
    for(int i = b; i>1; i--){
        a *= base;
    }
    return a;
}

//Memory efficient modular exponentiation algorithm
//https://en.wikipedia.org/wiki/Modular_exponentiation
uint64_t modExp(uint64_t base, uint64_t exp, uint64_t m){
    uint64_t tempExp = 1;
    uint64_t c = base*1%m;
    for(int i = 2; i<=exp; i++){
        c = base*c%m;
    }
    return c;
}

//Quick way to compute the greatest common divisor
uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

//Encryption function
void encrypt(uint64_t *m, int size, uint64_t p, uint64_t q, uint64_t e){

    uint64_t temp;

    uint64_t n = p*q;

    //Iterate through the array
    //Use the modular exponentiation function to compute encrypted value according to the RSA algorithm
    //Encrypt the value at the adress of the original message array
    for(int i = 0; i<size; i++){
        temp = *(m+i);
        temp = modExp(temp,e,n);
        *(m+i) = temp;
    }
    
}

//Decryption function
void decrypt(uint64_t *m, int size, uint64_t p, uint64_t q, uint64_t e){

    uint64_t temp;

    //Compute n, phi and e^-1 mod phi
    uint64_t n = p*q;
    uint64_t phi = (p-1)*(q-1);
    uint64_t d = modInverse(e,phi);
    
    //Iterate through the array
    //Use the modular exponentiation function to compute decrypted value according to the RSA algorithm
    //Decrypt the value at the adress of the original message array
    for(int i = 0; i<size; i++){
        temp = *(m+i);
        temp = modExp(temp,d,n);
        *(m+i) = temp;
    }
}