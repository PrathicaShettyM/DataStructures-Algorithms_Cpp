#include<bits/stdc++.h>
using namespace std;

int reverseNum(int n){
    int reverse = 0;
    while(n > 0){
        int lastDigit = n % 10;
        reverse = (reverse * 10) + lastDigit;
        n /= 10;
    }   
    return reverse;
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int rev = reverseNum(n);
    cout << "Reverse of the number: " << rev;

    return 0;
}