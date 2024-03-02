#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(unsigned long int);

int main(){


    
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

