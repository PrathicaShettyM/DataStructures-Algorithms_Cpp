# *C++ Basics*

Basic C++ program
```cpp
#include<iostream>
using namespace std;

int main(){
    cout << "Hello world" << endl;
    return 0;
}
```

Data types

1. Primitive
int
float
double
long
short
char
boolean
void

2. Derieved
Array
function
pointer
reference

3. User defined
Structure/Classes
Union
Enum
Typedef

- boolean can hold - int, char but not ''

- unsigned - for positive numbers

- for strings use
#include<string>

string favoriteTea = "Lemon Tea"
string description = "Known as "\ best \" tea"


call by value vs call by ref
use of & and *



## Pointers

```cpp
int x = 4;
cout << &x << endl; // prints the address of 'x'

int* p = &x;
cout << p << endl; // prints the content of 'p' -> which was having the address of x
cout << *p << endl; // prints the value present in the address which 'p' is holding -> 4
```




# C++ OOPS
1. Classes


2. Objects


3. Constructors
1. Default Constructor
2. Parameterised Constructor
3. Copy Constructor

4. this keyword

```cpp
#include<bits/stdc++.h>
using namespace std;
class Student {
public:
    string name;
    int age;
    float marks;

    Student(){
        // default constructor
    }

    Student(String name, int age, float marks){
        // parameterised constructor
        this->name = name;
        this->age = age;
        this->marks = marks;
    }
};

int main(){
    Student s1("Student_1", 21, 8.95);
    s1.name = "Prathica Shetty M"; // update the name field of the object s1
    cout << s1.name << " " << s1.age << " " << s1.marks << endl;
    return 0;
}

```

```cpp
Student s1 = s2; //creates a deep copy
Student s3(s1); // also creates deep copy => copy constructor
```


```cpp
#include<bits/stdc++.h>
using namespace std;

class Cricketer {
public: 
    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs, float avg){
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }

    void printInsideClass(int runs){
        // use this keyword when we want to print the values of the object properties
        // if we dont use this the value passed in the parameter will be printed
        cout << this->name << " " << this->runs << " " << this->avg << endl;

        cout << runs << endl;
    }
};

void printOutsideClass(Cricketer c){
    cout << c.name << " " << c.runs << " " << c.avg << endl;
}

int main(){
    Cricketer c1("Virat Kohli", 25000, 55.18);
    Cricketer c2("Rohit Sharma", 19000, 47.98);

    // function outside the class
    printOutsideClass(c1);

    // function inside the class
    c2.printInsideClass(74);
}
```

Passing objects to functions
- By default -> pass by value
- If we use '&' -> pass by reference

## Object pointers


```cpp
#include<bits/stdc++.h>
using namespace std;

class Cricketer {
public: 
    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs, float avg){
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }
};

// pass by reference: the passed object's prop value will be updated
void passByRef(Cricketer& c1){
    c1.avg = 77.2; // will be updated
    cout << c1.avg << endl;
}

// pass by value: the passed object's prop value wont be updated
void passByValue(Cricketer c1){
    c1.avg = 77.2; // wont be updated
    cout << c1.avg << endl;
}

void change(Cricketer* c1){
    (*c1).avg = 77.2; // will be updated
    c1->avg = 68.9; // same meaning as above

    cout << (*c1).avg << endl;
}

int main(){
    Cricketer c1("Virat Kohli", 25000, 55.18);
    Cricketer c2("Rohit Sharma", 19000, 47.98);


    // method 1: for object pointers
    Cricketer* p1 = &c1; // pointer of cricketer type storing address of c1 object
    cout << (*p1).runs << endl; // this is valid - it prints the value of the runs of the c1 object


    (*p1).avg = 77.3; // update the avg of c1 object 
    cout << c1.avg << endl; // 77.3


    change(&c1); // pass the address of c1 object

    // method 2: for object pointers
    cout << p1->runs << endl;
}
```

Note:
- a->b ('a' shd be a pointer) means (*a).b


## Dynamic memory allocation

```cpp
int* ptr = new int(1812);
cout << *ptr << endl; // 1812
```

![alt text](image.png)

```cpp
#include<bits/stdc++.h>
using namespace std;

class Cricketer {
public: 
    string name;
    int runs;
    float avg;

    Cricketer(string name, int runs, float avg){
        this->name = name;
        this->runs = runs;
        this->avg = avg;
    }
};

int main(){
    // static memory allocation
    Cricketer c1("Virat Kohli", 25000, 55.18);
    // dynamic memory allocation
    Cricketer* c2 = new Cricketer("Rohit Sharma", 19000, 47.98);
    
    cout << c1.name << " " << c1.runs << endl; 
    cout << (*c2).name << " " << (*c2).runs << endl;
    cout << c2->name << " " << c2->runs << endl;
}
```


## Access modifier

```cpp
#include<iostream>
using namespace std;

class Student {
public:
    // public members are accessible anywhere in the program
    int rno; 
    string name;
    
    Student(){}

    Student(int rno, string name, float marks){
        // marks is accessible here bcoz private members are accessbile inside tht class.
        // here its acting like a setter method for setting up its value
        this->rno = rno;
        this->name = name;
        this->marks = marks;
    }

    void display(){
        cout << rno << " " << name << " " << marks << endl;
    }

    float getMarks(){
        return marks;
    }

    void setMarks(float m){
        marks = m;
    }

private:
    // private members are inaccessible
    float marks;
    
    void printAvg(){
        cout << marks/5;
    }
};

int main(){
    Student s1(46, "Prathica", 98.2); // this is valid
    Student s2;
    s2.marks = 55; // gives error

    s1.display();
    cout << s1.getMarks() << endl;
    s1.setMarks(99.1);
}
```

## Inheritance

```cpp
#include<iostream>
using namespace std;

// base class or parent class
class Scooty {
public:
    int topSpeed;
    float mileage;

private:
    int bootSpace;
};

// derieved class or child class
class Bike : public Scooty {
public:
    int gears;
    // it inherits topSpeed and mileage coz its public
    // it cant inherit "bootSpace" coz it private
};

int main(){

}
```

- multiple inheritance
```cpp
class A {
public:
    int a1;
    float a2;
};

class B {
public:
    int b1;
    float b2;
};

class C : public A,B {
public:
    int c1;
    string c2;
};

```

![alt text](image-1.png)

