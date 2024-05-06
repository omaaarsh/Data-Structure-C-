#include<iostream>
#include<string>
#include<cassert>
using namespace std;
class PriorityQueue {
private:
    int heap[100];
    int size;
    void heapifyUp(int index) {
        while (index > 0) {
            int parent = (index - 1);
            if (heap[index] <= heap[parent])
                break;
            swap(heap[index], heap[parent]);
            index = parent;
        }
    }
public:
    PriorityQueue(){
        size = 0;
    }
    bool is_full(){
        return size == 100;
    }
    void push(int value) {
        if (is_full()) {
            cout << "Queue is full!" << endl;
            return;
        }
        heap[size++] = value;
        heapifyUp(size-1);
    }
    int pop() {
        if (is_empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        size--;
        for (int i = 0; i < size; i++){
            heap[i] = heap[i+1];
        }
        return heap[0];
    }
    int Top() {
        if (is_empty()) {
            cout << "Queue is empty!" << endl;
            return -1;
        }
        return heap[0];
    }

    bool is_empty() {
        return size == 0;
    }

    int getSize() {
        return size;
    }

    void printQueue() {
        for (int i = 0; i < size; i++)
            cout << heap[i] << " ";
        cout << endl;
    }
};
int main() {
    PriorityQueue pq;
    pq.push(10);
    pq.push(20);
    pq.push(30);
    pq.push(5);
    pq.push(40);
    pq.printQueue();
    cout << "\nSize of queue: " << pq.getSize() << endl;
    cout << "Top element of queue: " << pq.Top() << endl;

    cout<<pq.pop();
    cout << "Top element after popping: " << pq.Top() << endl;

    cout << "Is queue empty? " << (pq.is_empty() ? "Yes" : "No") << endl;
   pq.printQueue();
    return 0;
}
