#include<bits/stdc++.h>
using namespace std;

bool isArmstrongNumber(int n){
    int num = n;
    int armstrong = 0;

    while(n > 0){
        int lastDigit = n % 10;
        armstrong += (lastDigit*lastDigit*lastDigit);
        n /= 10;
    }

    return (num == armstrong);
}

int main(){
    int n;
    cout << "Enter a number: ";
    cin >> n;

    bool check = isArmstrongNumber(n);
    cout << check;

    return 0;
}