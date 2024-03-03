#include <iostream>
#include <cmath>
#include <random>

using namespace std;

bool isPrime(unsigned long long int);
unsigned long long int* primeGen();



int main(){

    unsigned long long int* a = primeGen();
    cout<<*a<<endl;
    cout<<*(a+1);

    
}

unsigned long long int* primeGen(){

    unsigned long long int randNum;

    static unsigned long long int primes[2];
    
    random_device rd;
    default_random_engine generator(rd());
    unsigned long long int max = 9999999999;
    unsigned long long int min = 1000000000;

    uniform_int_distribution<long long unsigned> distribution(min,max);
    for(int i = 0; i<=1; i++){
        do{
            randNum= distribution(generator);
        }while(isPrime(randNum)==0);
        primes[i] = randNum;
    }


    return primes;

}

bool isPrime(unsigned long long int num){
    
    unsigned long long int max = sqrt(num);

    if(num%2==0){
        return false;
    }

    for(unsigned long long int i = 3; i <= max; i+=2){
        if(num%i==0){
            return false;
        }
    }
    return true;

}

