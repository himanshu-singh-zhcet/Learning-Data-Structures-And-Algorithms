#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
       value=data;
       next = NULL;
    }
};
class circular_linkedlist{
    public:
    Node* head;
    circular_linkedlist(){
        head = NULL;
    }
};
int main(){
    circular_linkedlist l1;
    Node* new_node =new Node(2);
    // l1.head=new_node;
    cout<<l1.head;
return 0;
}