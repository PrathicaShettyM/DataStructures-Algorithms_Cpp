#include<bits/stdc++.h>
using namespace std;

// brute force
// method 1: TC = O(min(n1, n2)), SC=O(1)
void gcd1(int n1, int n2){
    int gcd = 1; // gcd of any 2 no.s will be 1
    for(int i = 1; i <= min(n1, n2); i++){
        if(n1 % i == 0 && n2 % i == 0) gcd = i;
    }
    cout << gcd << endl;
}

// optimised approach
// method 2:

int main(){
    int n1, n2;
    cout << "Enter n1: ";
    cin >> n1;
    cout << "Enter n2: ";
    cin >> n2;

    gcd1(n1, n2);

    return 0;
}