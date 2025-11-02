# **Maths Notes**
|sl no|Problem Variants|
|--|---|
|1.|[Extraction of digits](#1-concept-extraction-of-digits)|
|2.|[Count no. of digits in a number](#11-count-the-no-of-digits-in-a-number)|
|3.|[Reverse a no.](#12-reverse-a-number)|
|4.|[Check if the no. is Palindrome](#13-check-if-the-given-number-is-a-palindrome)|
|5.|[Armstrong no.](#14-armstrong-number)|
|6.|[Print all divisors](#concept-2-print-all-the-divisors)|
|7.|[Check if the no. is a Prime no.](#21-prime-numbers)|
|8.|[GCD or HCF]()|
|9.|[Power Exponentiation]()|
|10.|[Print all the prime factors of the number]()|
|11.|[Sieve of Eratosthenes]()|


### **CONCEPT 1: Extraction of digits**
- make use of '/' and '%' operators

```cpp
void extractDigit(int n){
    while(n > 0){
        int lastDigit = n % 10;
        cout << lastDigit << " ";
        n /= 10;
    }
}
```

### **1.1. Count the no. of digits in a number**
#### **Method 1**: normal method using extraction of digits logic
```cpp
int count = 0;
int noOfDigits(int n){
    while(n > 0){
        int lastDigit = n % 10;
        count += 1;
        n /= 10;
    }

    return count;
}
```
- **Time complexity** = `O(log10(n))` : bcoz everytime the no. is divided by reducing the no. 10 times in each iteration (TC becomes log2 when the main operation is dividing the no. by 2 every iteration)
- **Space complexity** = `O(1)` 

#### **Method 2**: using the concept of `logarithm`
```cpp
int noOfDigits(int n){
    int count = (int)(log10(n)+1);
    return count;
}
```
- **Time Complexity**: `O(1)`
- **Space Complexity**: `O(1)`

### **1.2 Reverse a Number**
#### **Method 1**: using the extraction of digits logic
```cpp
int reverseNum(int n){
    int reverse = 0;
    while(n > 0){
        int lastDigit = n % 10;
        reverse = (reverse * 10) + lastDigit;
        n /= 10;
    }   
    return reverse;
}
```
- **Time complexity** = `O(log10(n))`
- **Space complexity** = `O(1)` 

### **1.3. Check if the given number is a palindrome**
#### **Method 1**: using the extraction of digits logic
```cpp
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
```
- **Time complexity** = `O(log10(n))` 
- **Space complexity** = `O(1)` 

### **1.4 Armstrong Number**
#### **Method 1**: using the extraction of digits logic
```cpp
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
```
- **Time complexity** = `O(log10(n))` 
- **Space complexity** = `O(1)` 

### **CONCEPT 2: Print all the Divisors**
#### **Method 1**: Brute force
```cpp
void printAllDivisors(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cout << i << " ";
    }
}
```
- **Time complexity** = `O(n)` 
- **Space complexity** = `O(1)` 

#### **Method 2**: Optimal Approach
```cpp
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
```
- **Time complexity** = `O(sqrt(n))` for the question, but total complexity of this function is `O(sqrt(n) + nlog(n) + n)`
- **Space complexity** = `O(1)` 

### **2.1 Prime Numbers**
#### **Method 1**: Using the definition of Prime no.s - it has only 2 divisors - 1 and the no. itself
```cpp
bool isPrime1(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) count++;
    }
    return (count == 2);
}
```
- **Time complexity** = `O(n)` 
- **Space complexity** = `O(1)` 

#### **Method 2**:  Print all the Divisors method
```cpp
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
```
- **Time complexity** = `O(sqrt(n))` 
- **Space complexity** = `O(1)` 

#### **CONCEPT 3: Power Exponentiation**
- Intution for the solving the problem
![alt text](/Maths/images/9_power.png)
```cpp
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
```
- **Time Complexity**: `O(log2(n))` - because almost all the time the power gets reduces by 2
- **Space Complexity**: `O(1)`

#### **CONCEPT 4: Sieve of Eratosthenes**
- This is algorithm is used to find the prime no.s in a range
- Example: find the prime no.s from 1 to 31 - 2 3 5 7 11 13 17 19 23 29 31
```cpp
void sieveOfEratosthenes(int n){
    // take an array of size n+1 to include the nth no.
    int primes[n+1];

    // fill all the places by 1 : assume everything is prime starting from 2
    for(int i = 2; i <= n; i++){
        primes[i] = 1;
    }

    // mark the multiples of the prime as zero coz it never be prime
    for(int i = 2; i*i <= n; i++){
        if(primes[i] == 1){ // if the no. is a prime
            for(int j = i*i; j <= n; j+=i){ // start with the sqaure of tht prime coz its smaller valued multiples would have been covered earlier
                primes[j] = 0; // mark the multiples of tht prime as zero
            }
        }
    }

    // print all the primes
    for(int i = 2; i <= n; i++){
        if(primes[i] == 1) cout << i << " ";
    }

    cout << endl;
}
```
- **Time Complexity** = `O(n*log(log(n)))`
- **Space Complexity** = `O(1) `
- **Note**: just remember the time complexity, proof is not required