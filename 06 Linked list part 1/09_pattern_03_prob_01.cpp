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
Node* reverse_list(Node*  &head){
    Node* prev=NULL;
    Node* curr=head;
    // curr->next= prev
    // move all 3 pointers by one step ahead
    while(curr!= NULL){
        Node * nextptr=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextptr;
    }
    // when this loop is end prev pointer pointing to the last node which is my new head
    Node* new_head = prev;
    return new_head;
}Node* reverse_list_by_recursive_method(Node* &head){
    // base case
    if(head==NULL || head->next ==NULL){
        return head;
    }
    // recursive case
    Node* new_head = reverse_list_by_recursive_method(head->next);
    head->next->next=head;
    head->next=NULL; //head is now pointing to the last node in reversed linkedlist
    return new_head;
}

int main(){
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.insert_at_tail(6);
    l1.display();
    //l1.head=reverse_list(l1.head);
    l1.head=reverse_list_by_recursive_method(l1.head);
    l1.display();
return 0;
}