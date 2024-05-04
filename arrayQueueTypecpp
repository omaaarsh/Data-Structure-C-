#include<iostream>
#include<string>
#include<cassert>
using namespace std;
template<class T>
class arrayQueueType{
    private:
    int rear;
    int front;
    int length;
    T *array;
    int maxSize;
    public:
    arrayQueueType(int size){
        if(size<=0){
            maxSize=100;
            cout<<"negative size,so by default size is "<<maxSize<<endl;
        }
        else{
            maxSize=size;
        }
        rear=maxSize-1;
        front=0;
        length=0;
        array=new T[maxSize];
    }
    bool isEmpty(){
        return length==0;
    }
    bool isFull(){
        return length==maxSize;
    }
    T rearQueue(){
        assert(!isEmpty());
        return array[rear];
    }
    T frontQueue(){
        assert(!isEmpty());
        return array[front];
    }
    void enqueue(T element){
        if(!isFull()){
            rear=(rear+1)%maxSize;
            array[rear]=element;
            length++;
        }
        else{
            cout<<"Cannot enqueue...Queue is full "<<endl; 
        }
    }
    void dequeue(){
        if(!isFull()){
            front=(front+1)%maxSize;
            length--;
        }
        else{
            cout<<"Cannot dequeue...Queue is Empty "<<endl; 
        }
    }
    void print(){
        for (size_t i = front; i !=rear;i=(i+1)%maxSize)
        {
            cout<<array[i]<<" ";
        }
        cout<<array[rear]<<endl;
    }
    int search(T element){
        int index=-1;
        if(isEmpty()){
            cout<<"Queue is Empty..."<<endl;
        }
        else{
            for (size_t i = front; i !=rear;i=(i+1)%maxSize)
            {
                if(array[i]==element)
                {
                    index=i;
                    break;
                }
            }
            if(index==-1){
                if(array[rear]==element)
                {
                    index=rear;
                }
            }
        }
        return index;
    }
};
int main(){
    arrayQueueType<int>queue(5);
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);
    queue.dequeue();
    queue.enqueue(60);
    queue.enqueue(80);
    cout<<queue.search(20)<<endl;
    cout<<queue.frontQueue()<<endl;
    cout<<queue.rearQueue()<<endl;
    queue.print();
}