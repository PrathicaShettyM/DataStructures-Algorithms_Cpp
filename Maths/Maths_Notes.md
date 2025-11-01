# **Maths Notes**
|sl no|Problem Variants|
|--|---|
|1.|[Extraction of digits](#1-concept-extraction-of-digits)|
|2.|[Count no. of digits in a number](#11-count-the-no-of-digits-in-a-number)|
|3.|[Reverse a no.](#12-reverse-a-number)|
|4.|[Check if the no. is Palindrome](#13-check-if-the-given-number-is-a-palindrome)|
|5.|[Armstrong no.](#14-armstrong-number)|
|6.|[Print all divisors](#concept-2-print-all-the-divisors)|
|7.|[Prime no.s](#21-prime-numbers)|

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

