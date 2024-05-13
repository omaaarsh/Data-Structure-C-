#include <iostream>
using namespace std;

template <typename T>
class Stack {
private:
    struct node {
        T item;
        node* next;
    };
    node *top, *current;

public:
    Stack() {
        top = NULL;
        current = NULL;
    }

    void push(T item) {
        node* new_item = new node;
        if (new_item == NULL) {
            cout << "Cannot allocate memory\n";
        }
        else {
            new_item->item = item;
            new_item->next = top;
            top = new_item;
            current = top; // Update current pointer
        }
    }

    bool is_empty() {
        return top == NULL;
    }

    T peek() {
        if (is_empty()) {
            cout << "Stack is empty";
            exit(EXIT_FAILURE);
        }
        return top->item;
    }

    void pop() {
        if (is_empty()) {
            cout << "Stack is empty";
        }
        else {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }

    void print() {
        if (is_empty()) {
            cout << "Stack is empty\n";
        }
        else {
            node* current = top;
            cout << "Stack: ";
            while (current != NULL) {
                cout << current->item << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    ~Stack() {
        while (!is_empty()) {
            pop();
        }
    }
};

int main() {
    Stack<int> s;

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    s.print();

    cout << "Top element: " << s.peek() << endl;

    s.pop();

    s.print();

    cout << "Top element: " << s.peek() << endl;

    return 0;
}
