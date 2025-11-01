#include<bits/stdc++.h>
using namespace std;

// brute force
// method 1: TC=O(sqrt(n)*2*sqrt(n)) -> but not this exactly, SC=O(n) -> but was given in question, so it can be no extra space
bool isPrime(int n){
    int count = 0;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            count++;
            if((n/i) != i) count++;
        }
    }
    return (count == 2);
}

void printAllPrimes1(int n){
    vector<int> ls;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            if(isPrime(i)) ls.push_back(i);
        }
    }

    // printing all the primes
    for(auto i : ls) cout << i << " ";
    cout << endl;
}

// better approach
// method 2: TC=O(largest prime factor), SC = O(1)
// but incase a prime no. is only given then TC=O(n)
void printAllPrimes2(int n){
    vector<int> ls;
    for(int i = 2; i <= n; i++){
        if(n % i == 0){
            ls.push_back(i);
            // keep dividing 'n' with the prime how much ever times its valid
            while(n % i == 0){
                n = n/i;
            }
        }
    }

    // printing all the primes
    for(auto i : ls) cout << i << " ";
    cout << endl;
}

// optimised approach
// method 2.1: TC = O(sqrt(n)*log(n)), SC=O(1)
// here we are reducing our search space so 'log(n)' comes to the picture
void printAllPrimes3(int n){
    vector<int> ls;
    for(int i = 2; i*i <= n; i++){
        if(n % i == 0){
            ls.push_back(i);
            // keep dividing 'n' with the prime how much ever times its valid
            while(n % i == 0){
                n = n/i;
            }
        }
    }

    // 'n' at this place will the last prime no. factor, so add it the list => hence the time significantly reduces bcoz of this optimisation
    if(n != 1) ls.push_back(n);

    // printing all the primes
    for(auto i : ls) cout << i << " ";
    cout << endl;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    printAllPrimes1(n);
    printAllPrimes2(n);
    printAllPrimes3(n);

    return 0;
}