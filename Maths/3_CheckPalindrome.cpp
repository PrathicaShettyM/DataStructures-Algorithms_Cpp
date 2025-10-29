#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(int n){
    int originalNum = n;
    int reverseNum = 0;
    
    while(n > 0){
        int lastDigit = n % 10;
        reverseNum = (reverseNum * 10) + lastDigit;
        n /= 10;
    }

    return (originalNum == reverseNum);
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    bool check = isPalindrome(n);
    cout << check;

    return 0;
}