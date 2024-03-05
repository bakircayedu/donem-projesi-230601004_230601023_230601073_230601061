#include <iostream>
#include <cmath>
#include <random>
uint64_t power(uint64_t a, uint64_t b);

using namespace std;

bool isPrime(uint64_t);
uint64_t* primeGen();
uint64_t gcd(uint64_t,uint64_t);
uint64_t* encrypt(uint64_t *m, int size, uint64_t p, uint64_t q, uint64_t e);
uint64_t modInverse(uint64_t a, uint64_t m);
uint64_t* decrypt(uint64_t *m, int size, uint64_t p, uint64_t q, uint64_t e);

int main(){
    
    //TO-DO: Fix integer overflow problem

    uint64_t* primes = primeGen();
    uint64_t p = *(primes);
    uint64_t q = *(primes - 1);
    uint64_t e = 3;
    uint64_t phi = (p - 1)*(q - 1);

    while (gcd(e,phi) != 1)
    {
        e+=2;
    }
    
    char message[50];
    cin>>message;
    int messageLength = 0;

    while (message[messageLength] != '\0')
    {
        messageLength++;
    }

    uint64_t messageInt[messageLength];

    for(int i=0;i<messageLength;i++){
        messageInt[i] = ((uint64_t) message[i]);
    }


    encrypt(&messageInt[0],messageLength,p,q,e);
    
    for(int i:messageInt)
    {
        cout<<i<<endl;
    }
    cout<<"-----------------"<<endl;

    decrypt(&messageInt[0],messageLength,p,q,e);

    for(int i:messageInt)
    {
        cout<<i<<endl;
    }

}

uint64_t* primeGen(){

    uint64_t randNum;

    static uint64_t primes[2];
    
    random_device rd;
    default_random_engine generator(rd());
    uint64_t max = 999;
    uint64_t min = 100;

    uniform_int_distribution<long long unsigned> distribution(min,max);
    for(int i = 0; i<=1; i++){
        do{
            randNum= distribution(generator);
        }while(isPrime(randNum)==0);
        primes[i] = randNum;
    }


    return primes;

}

bool isPrime(uint64_t num){
    
    uint64_t max = sqrt(num);

    if(num%2==0){
        return false;
    }

    for(uint64_t i = 3; i <= max; i+=2){
        if(num%i==0){
            return false;
        }
    }
    return true;

}

uint64_t gcd(uint64_t a, uint64_t b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

uint64_t* encrypt(uint64_t *m, int size, uint64_t p, uint64_t q, uint64_t e){

    uint64_t temp;

    uint64_t n = p*q;

    for(int i = 0; i<size; i++){
        temp = *(m+i);
        temp = power(temp,e);
        temp = temp%n;
        *(m+i) = temp;
    }
    
}

uint64_t* decrypt(uint64_t *m, int size, uint64_t p, uint64_t q, uint64_t e){

    uint64_t temp;

    uint64_t n = p*q;
    uint64_t phi = (p-1)*(q-1);
    uint64_t d = modInverse(e,phi);

    for(int i = 0; i<size; i++){
        temp = *(m+i);
        temp = power(temp,d);
        temp = temp%n;
        *(m+i) = temp;
    }
}

uint64_t modInverse(uint64_t a, uint64_t m) {

    uint64_t b = 0;
    while ((a*b)%m != 1)
    {
        b++;
    }
    return b;
    
}

uint64_t power(uint64_t a, uint64_t b){
    uint64_t base = a;
    for(int i = b; i>1; i--){
        a *= base;
    }
    return a;
}






