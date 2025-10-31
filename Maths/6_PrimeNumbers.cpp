#include<bits/stdc++.h>
using namespace std;

// Prime no. have only 2 factors: '1' and the no. itself

// brute force
// method 1: TC = O(n), SC = O(1)
bool isPrime1(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) count++;
    }
    return (count == 2);
}

// optimal approach
// method 2: TC = O(sqrt(n)), SC = O(1)
bool isPrime2(int n){
    int count = 0;
    for(int i = 1; i*i <= n; i++){
        if(n % i == 0){
            count++;
            if((n/i) != i) count++;
        }
    }
    return (count == 2);
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;
    
    bool check1 = isPrime1(n);
    cout << check1 << endl;

    return 0;
}