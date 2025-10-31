# Maths Notes
|sl no|Problem| Link |
|--|---|--|
|1.|Extraction of Digits|[Link](https://www.geeksforgeeks.org/problems/count-digits-1606889545/1)|


### **1. CONCEPT: Extraction of digits**
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

### **1.2 Reverse a Number**

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


### **1.3. Check if the given number is a palindrome**
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

### **1.4 Armstrong Number**

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

1.5 Print all the Divisors
tc=o(n)
```cpp
void printAllDivisors(int n){
    for(int i = 1; i <= n; i++){
        if(n % i == 0) cout << i << " ";
    }
}
```

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

1.6 Prime Numbers

```cpp
bool isPrime1(int n){
    int count = 0;
    for(int i = 1; i <= n; i++){
        if(n % i == 0) count++;
    }
    return (count == 2);
}
```

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