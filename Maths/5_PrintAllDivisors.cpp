#include<bits/stdc++.h>
using namespace std;

// brute force
// method 1: TC=O(N), SC=O(1)
void printAllDivisors(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cout << i << " ";
    }
    cout << endl;
}

// optimal approach
// method 2: TC=O(sqrt(n) + nlogn + n), SC=O(n)
void printAllDivisor(int n){
    vector<int> ls;
    // iterate only upto sqrt(n) or (i*i <= n)
    for(int i = 1; i*i <= n; i++){ // O(sqrt(n))
        if(n % i == 0){
            ls.push_back(i);
            if((n/i) != i) ls.push_back(n/i);
        }
    }
    // sort the vector
    sort(ls.begin(), ls.end()); // O(nlogn)
    
    // print all the divisors
    for(auto i : ls) cout << i << " "; // O(n)
    
    cout << endl;
}

int main(){
    int n;
    cout << "Enter the no: ";
    cin >> n;
    
    printAllDivisors(n);
    printAllDivisor(n);

    return 0;
}