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
bool check_palinddrome(Node* head){
    // 1. Find middle element 
    Node* slow = head;
    Node* fast = head;
    while(fast!=NULL && fast->next!= NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    // now slow is pointing  to the MIDDLE ELMENT
    // 2. BREAK THE LINKEDLIST FROM MIDDLE
    Node* curr=slow->next;
    Node* prev=slow;
    slow->next=NULL;
    
    // 3. reverse the second half list
    while(curr){
    Node* next = curr->next;
    curr->next=prev;
    prev=curr;
    curr=next;
    }

    // 4. compare the two parts of the linkedlist
    Node* head1= head;
    Node* head2= prev;
    while(head2){
    if(head1->value!= head2->value){
        return false;
    }
    head1=head1->next;
    head2=head2->next;
    }
    return true;
}
int main(){
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(3);
    l1.insert_at_tail(2);
    l1.insert_at_tail(1);
    l1.display();
    cout<<check_palinddrome(l1.head);
    return 0;
}
