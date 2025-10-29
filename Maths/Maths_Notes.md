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

