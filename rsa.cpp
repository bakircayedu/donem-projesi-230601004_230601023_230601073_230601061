#include <iostream>
#include <cmath>
#include <ctime>
#include <cstdlib>

using namespace std;

bool isPrime(unsigned long int);
int primeGen();

int main(){


    
}

int primeGen(){
  
  srand((unsigned) time(0));

  unsigned long int randomNumber;

  do{
    randomNumber = rand();
  }while(isPrime(randomNumber) == 0);

  return randomNumber;

}

bool isPrime(unsigned long int num){
    
    unsigned long int max = sqrt(num);

    if(num%2==0){
        return false;
    }

    for(int i = 3; i <= max; i+=2){
        if(num%i==0){
            return false;
        }
    }
    return true;

}

