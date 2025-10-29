#include<bits/stdc++.h>
using namespace std;

// create our own vector
class Vector {
public:
    int size;
    int capacity;
    int* arr;

    Vector(){ // default constructor
        size = 0;
        capacity = 1;
        arr = new int[1];
    }

    // push_back()
    void add(int ele){
        if(size == capacity){
            // double the capacity and copy paste the elements
            capacity *= 2;
            int* new_arr = new int[capacity];
            
            for(int i = 0; i < size; i++){
                new_arr[i] = arr[i];
            }

            arr = new_arr; // arr will point to new_arr
        }

        arr[size++] = ele;
    }

    void print(){
        for(int i = 0; i < size; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int get(int idx){
        if(size == 0){
            cout << "Vector is empty" << endl;
            return -1;
        } 
        
        if(idx < 0 && idx >= size){
            cout << "Invalid Index" << endl;
            return -1;
        }

        return arr[idx];
    }

    void remove(){
        if(size == 0){
            cout << "Vector is empty" << endl;
            return;
        }

        size--;
    }
};

int main(){
    Vector v1;

    v1.add(10);
    v1.print();
    cout << v1.size << " " << v1.capacity << endl;

    v1.add(20);
    v1.print();
    cout << v1.size << " " << v1.capacity << endl;

    v1.add(30);
    v1.print();
    cout << v1.size << " " << v1.capacity << endl;

    v1.add(40);
    v1.print();
    cout << v1.size << " " << v1.capacity << endl;

    v1.add(50);
    v1.print();
    cout << v1.size << " " << v1.capacity << endl;

    cout << v1.get(2) << endl;
    cout << "Size of the vector is: " << v1.size << endl;

    v1.remove();
    v1.print();
    cout << v1.size << " " << v1.capacity << endl;

    return 0;
}