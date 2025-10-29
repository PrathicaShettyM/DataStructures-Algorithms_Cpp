#include<bits/stdc++.h>
using namespace std;

// tc: log10(n) - bcoz everytime the no. is getting divided by 10
// here the tc is in log10 bcoz our loop is dependent on 'n' getting divided by 10, similarly its log2 if 'n' is getting divided by 2 and so on ...
void extractDigit(int n){
    while(n > 0){
        int lastDigit = n % 10;
        cout << lastDigit << " ";
        n /= 10;
    }
    cout << "\n";
}

void noOfDigits(int n){
    int ans = (int)(log10(n)+1);
    cout << ans;
}

int main(){
    int n;
    cout << "Enter the number: ";
    cin >> n;
    
    extractDigit(n);
    noOfDigits(n);

    return 0;
}

// problem link: https://www.geeksforgeeks.org/problems/count-digits-1606889545/1