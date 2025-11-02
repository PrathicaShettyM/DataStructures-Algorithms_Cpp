#include<bits/stdc++.h>
using namespace std;

// this algo is used to find the prime no.s in a range like [1-31] and so on..

// brute force: just check every no. in the range is prime
// TC = O(n*sqrt(n)), SC=O(1)

// optimised soln: sieve of eratosthenes
// TC = O(n*log(log(n))), SC=O(1) (just remember the time complexity, proof is not required)
void sieveOfEratosthenes(int n){
    // take an array of size n+1 to include the nth no.
    int primes[n+1];

    // fill all the places by 1 : assume everything is prime starting from 2
    for(int i = 2; i <= n; i++){
        primes[i] = 1;
    }

    // mark the multiples of the prime as zero coz it never be prime
    for(int i = 2; i*i <= n; i++){
        if(primes[i] == 1){ // if the no. is a prime
            for(int j = i*i; j <= n; j+=i){ // start with the sqaure of tht prime coz its smaller valued multiples would have been covered earlier
                primes[j] = 0; // mark the multiples of tht prime as zero
            }
        }
    }

    // print all the primes
    for(int i = 2; i <= n; i++){
        if(primes[i] == 1) cout << i << " ";
    }

    cout << endl;
}

int main(){
    int n;
    cout << "Enter the range: ";
    cin >> n;
    
    sieveOfEratosthenes(n);

    return 0;
}