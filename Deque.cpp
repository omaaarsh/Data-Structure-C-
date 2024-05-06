#include<iostream>
#include<cassert>

using namespace std;

class Deque {
private:
    int *arr;
    int capacity;
    int front;
    int rear;
    int size;

public:
    // Constructor
    Deque(int capacity) {
        this->capacity = capacity;
        arr = new int[capacity];
        front = 0;
        rear = capacity - 1;
        size = 0;
    }

    // Destructor
    ~Deque() {
        delete[] arr;
    }

    // Check if the deque is empty
    bool isEmpty() {
        return size == 0;
    }

    // Check if the deque is full
    bool isFull() {
        return size == capacity;
    }

    // Insert element at the front of the deque
    void pushFront(int value) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        front = (front - 1 + capacity) % capacity;
        arr[front] = value;
        size++;
    }

    // Insert element at the rear of the deque
    void pushRear(int value) {
        if (isFull()) {
            cout << "Deque is full!" << endl;
            return;
        }
        rear = (rear + 1) % capacity;
        arr[rear] = value;
        size++;
    }

    // Remove and return the front element of the deque
    int popFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int frontValue = arr[front];
        front = (front + 1) % capacity;
        size--;
        return frontValue;
    }

    // Remove and return the rear element of the deque
    int popRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        int rearValue = arr[rear];
        rear = (rear - 1 + capacity) % capacity;
        size--;
        return rearValue;
    }

    // Return the front element of the deque
    int getFront() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[front];
    }

    // Return the rear element of the deque
    int getRear() {
        if (isEmpty()) {
            cout << "Deque is empty!" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Return the size of the deque
    int getSize() {
        return size;
    }
};
int main() {
    Deque dq(5);
    dq.pushFront(10);
    dq.pushRear(20);
    dq.pushFront(5);
    dq.pushRear(15);
    cout << "Front element: " << dq.getFront() << endl;
    cout << "Rear element: " << dq.getRear() << endl;
    cout << "Size of deque: " << dq.getSize() << endl;
    cout << "Removing front element: " << dq.popFront() << endl;
    cout << "Removing rear element: " << dq.popRear() << endl;
    cout << "Size of deque after removals: " << dq.getSize() << endl;

    return 0;
}

