#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value =data;
        next=NULL;
    }
};
class linkedlist{
    public:
    Node* head;
    linkedlist(){
        head=NULL;
    }
    void insert_at_tail(int value){
        Node *new_node = new Node(value);
        if(head==NULL){
            head=new_node;
            return;
        }
        Node* temp=head;
        while(temp->next!= NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    void display(){
        Node* temp=head;
        while(temp!=NULL){
            cout<<temp->value<<"->";
            temp= temp->next;
        }cout<<"NULL"<<endl;
    }
};
bool detect_cycle(Node* head){
    if(!head){
        return false; 
    }
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
        if(slow ==fast){
            cout<<slow->value<<endl;
            return true;
              }
    }
    return false;
    }
void remove_cycle(Node* &head){ // assuming  that linkedlist has a cycle
    Node* slow = head;
    Node* fast = head;
    do{
        slow=slow->next;
        fast=fast->next->next;
    } 
    while(slow != fast);
    fast = head;
    while(fast->next != slow->next){
        fast = fast->next;
        slow = slow->next;
    }
    slow->next = NULL;
}
int main(){
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.insert_at_tail(6);
    l1.insert_at_tail(7);
    l1.insert_at_tail(8);
    l1.display();
    l1.head->next->next->next->next->next->next->next->next=l1.head->next->next;
    cout<<detect_cycle(l1.head)<<endl;
    remove_cycle(l1.head);
    cout<<"after removig cycle"<<endl;
    cout<<detect_cycle(l1.head)<<endl;
    l1.display();


    return 0;
}