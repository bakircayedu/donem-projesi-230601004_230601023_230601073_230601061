#include <iostream>
#include <cmath>
#include <random>

using namespace std;

bool isPrime(uint64_t);
uint64_t* primeGen();
uint64_t gcd(uint64_t,uint64_t);
uint64_t* encrypt(char*, uint64_t, uint64_t, uint64_t);
uint64_t modInverse(uint64_t a, uint64_t m);


int main(){

    uint64_t* primes = primeGen();
    uint64_t e = 3;
    uint64_t phi = (*(primes) - 1)*(*(primes+1) - 1);

    while (gcd(e,phi) != 1)
    {
        e+=2;
    }
    
    char message[50];
    cin>>message;
    char* messagePtr = message;


    encrypt(messagePtr,11,3,3);
    /*
    while (*(messagePtr) != '\0')
    {
        cout<<(int)*(messagePtr)<<endl;
        messagePtr++;
    }
    */
   cout<<(modInverse(3,20));

}

uint64_t* primeGen(){

    uint64_t randNum;

    static uint64_t primes[2];
    
    random_device rd;
    default_random_engine generator(rd());
    uint64_t max = 99999;
    uint64_t min = 10000;

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

uint64_t* encrypt(char *m, uint64_t p, uint64_t q, uint64_t e){

    int temp;

    uint64_t n = p*q;

    while(*(m) != '\0'){
        temp = (int)*(m);
        temp = pow(temp,e);
        temp %= n;
        *(m) = temp;
        ++m;
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






