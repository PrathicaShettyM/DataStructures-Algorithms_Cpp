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

// Euclidian Algorithm: greater%smaller until one of them is zero
// optimised approach
// method 2: TC = O(log$(min(n1, n2))), SC=O(1)
// $ -> bcoz we dont know the extact no. by which it reduces, everytime it fluctuates
void gcd2(int n1, int n2){
    while(n1 > 0 && n2 > 0){
        if(n1 > n2) n1 = n1 % n2;
        else n2 = n2 % n1;
    }

    int gcd = (n1 == 0) ? n2 : n1;
    cout << gcd << endl;
}

int main(){
    int n1, n2;
    cout << "Enter n1: ";
    cin >> n1;
    cout << "Enter n2: ";
    cin >> n2;

    gcd1(n1, n2);
    gcd2(n1, n2);
    return 0;
}