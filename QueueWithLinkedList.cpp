#include<iostream> 
#include<string> 
#include<cassert>
using namespace std;
template<class T> 
class LinkedQueue{
    private:
        struct node{
        T item;
        node *next;
        };
        node*frontptr;
        node*rareptr;
        int length;
    public:
    LinkedQueue(): frontptr(NULL), rareptr(NULL) , length(0){}
    bool isEmpty()
    {
        return frontptr==NULLi
    }
    void enqueue (T element)
    {
        if(isEmpty()){
            frontptr=new node; frontptr->item=element;
            frontptr->next=NULL;
            rareptr=frontptr;
            length++;
        }
        else{
            node*newptr=new node; newptr->item=element;
            newptr->next=NULLi
            rareptr->next=newptr;
            rareptr=newptr;
            length++;
            }
    }
    void dequeue(){
        if(isEmpty())
        {
            cout<<"can not equeue, Queue is empty!!\n";
        }
        else{
            if(frontptr==rareptr)
            {
            frontptr=rareptr=NULL;
            length=0;
            }
            else{
            node*ptrd=frontptr;
            frontptr=frontptr->next;
            ptrd->next=NULL;
            free (ptrd);
            Length--;
            }
        }
    }
    T getfront()
    {
        assert(!isEmpty());
        return frontptr->item;
    }
    T getrare()
    {
        assert(!isEmpty());
        return rareptr->item;
    }
    void clear()
    {
        if(isEmpty()){
            cout<<"empty queue\n";
        }
    else{
        node*current;
        while (frontptr!=NULL)
        {
            current=frontptr; 
            frontptr=frontptr->next;
            free(current);
        }
        rareptr=NULL;
        length=0;
        }
    }
    void print_queue()
    {
        if(isEmpty())
        {
            cout<<"Empty queue!!\n";
        }
        node*current=frontptr;
        while (current!=NULL)
        {
            cout<<current->item<<" ";
            current=current->next;
        }
        cout<ぐ"\n";
        int size()
        {
        return length;
        }
    }
};
int main(){
LinkedQueue<int>queue;
queue. enqueue (10); 
queue. enqueue (20); 
queue. enqueue (30); 
queue. enqueue (40); 
queue. dequeue (); 
queue. enqueue (60); 
queue. enqueue (80);
cout<<queue.getfront ()<<"\n";
cout<<queue.getrare()<<"\n";
queue.print_queue();}