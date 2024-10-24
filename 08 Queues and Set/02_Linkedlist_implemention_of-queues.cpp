#include<iostream>
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next = NULL;
    }
};
class queue{
    Node* head;
    Node* tail;
    int size;
    public:
    queue(){
        head = NULL;
        tail = NULL;
        size = 0;
    }
    void enqueue(int value){
    Node* newNode = new Node(value);
    if(head == NULL){
        // LINKEDLIST IS EMPTY
        head = tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = newNode;
    }
    size++;
    }
    void dequeue(){
        if(head == NULL){
            // LINKEDLIST IS empty
            return;
        }
        else{
            Node* temp = head;
            head = head->next;
            if(head == NULL) tail = NULL;
            free(temp);
            size--;
        }
    }
    int getsize(){
        return size;
    }
    bool isempty(){
        return head ==NULL;
    }
    int front(){
        if(head == NULL){
            return -1;
        }
        
     return head->data;
        
        
    }

};
using namespace std;
int main(){
    queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    while(! qu.isempty()){
        cout<<qu.front()<<endl;
        qu.dequeue();
    }
return 0;
}