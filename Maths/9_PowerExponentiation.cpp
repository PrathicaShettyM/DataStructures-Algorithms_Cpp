#include<bits/stdc++.h>
using namespace std;

// TC: log2(n) : because almost all the time the power gets reduces by 2
float exponent(int num, int power){
    int p = power;
    float ans = 1;

    while(power > 0){
        if(power % 2 == 1){ // odd power
            // multiply the answer by num and reduce the power by 1
            ans *= num;
            power -= 1;
        } else { // even power
            // square the num and reduce the power by 2
            num *= num;
            power /= 2;
        }
    }

    if(p < 0) return (1.0)/ans;

    return ans;
}

int main(){
    int number, power;
    cout << "Enter the number: ";
    cin >> number;
    cout << "Enter the power: ";
    cin >> power;

    float ans = exponent(number, power);
    cout << ans << endl;
    return 0;
}