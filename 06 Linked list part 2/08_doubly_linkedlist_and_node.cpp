#include<iostream>
using namespace std;
class Node{
    public:
    int Value;
    Node* prev;
    Node* next;
    Node(int data){
        Value=data;
        prev=NULL;
        next=NULL;
    }
};
class doubly_linkedlist{
    public: 
    Node* head;
    Node* tail;
    doubly_linkedlist(){
        head=NULL;
        tail=NULL;
    }
};
int main(){
    Node* new_node= new Node(4);
    doubly_linkedlist l1;
    l1.head=new_node;
    l1.tail=new_node;
    cout<<l1.head->Value; 

return 0;
}