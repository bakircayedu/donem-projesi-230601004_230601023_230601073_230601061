#include <iostream>
#include <cmath>
#include <random>
#include <algorithm>

using namespace std;

bool isPrime(uint64_t);
uint64_t* primeGen();
uint64_t gcd(uint64_t,uint64_t);



int main(){

    //testing
    uint64_t* a = primeGen();
    uint64_t n = (*(a)-1) * (*(a+1)-1);

    cout<<*a<<endl;
    cout<<*(a+1)<<endl;
    uint64_t e = 3;
    while(gcd(e,n)!=1){
        e+=2;
    }
    cout<<e<<endl;
    //testing
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


