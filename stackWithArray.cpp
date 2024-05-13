#include <iostream>
using namespace std;
template <typename T, int MAX_SIZE>
class Stack {
private:
    T stack_array[MAX_SIZE]; // Array to store  elements
    int top; // the top of the stack
public:
    // Constructor
    Stack() {
        top = -1; // Initialize top to -1
    }

    // check if the stack is empty
    bool is_empty() {
        return (top == -1);
    }

    //check if the stack is full
    bool is_full() {
        return (top == MAX_SIZE - 1);
    }

    //  push an element onto the stack
    void push(T value) {
        if (is_full()) {
            cout << "Stack is full. Cannot push element.\n";
        }
        else {
            top++; // Increment top
            stack_array[top] = value; // Insert the element at the top of the stack
        }
    }

    //   pop an element from the stack
    void pop() {
        if (is_empty()) {
            cout << "Stack is empty. Cannot pop element.\n";
        }
        else {
            top--; // Decrement top
        }
    }

    //  print the elements of the stack
    void print() {
        if (is_empty()) {
            cout << "Stack is empty.\n";
        }
        else {
            cout << "Stack elements: ";
            for (int i = top; i >= 0; i--) {
                cout << stack_array[i] << " ";
            }
            cout << endl;
        }
    }
    //  search for an element in the stack
    bool search(T value) {
        for (int i = top; i >= 0; i--) {
            if (stack_array[i] == value) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Stack<int, 5> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    s.print();

    s.pop();

    s.print();

    int value_to_search = 50;
    if (s.search(value_to_search)) {
        cout << value_to_search << " is found in the stack.\n";
    }
    else {
        cout << value_to_search << " is not found in the stack.\n";
    }
    return 0;
}
