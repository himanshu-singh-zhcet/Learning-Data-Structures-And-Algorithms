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
Node* reverse_k_nodes_of_list(Node* &head, int k){
    Node*  prevptr =NULL;
    Node*  currptr =head;
    int counter =0;  // for counting first k nodes
    while(currptr!= NULL && counter<k){ // reversing first k nodes
        Node* nextptr=currptr->next;
        currptr->next=prevptr;
        prevptr =currptr;
        currptr=nextptr;
        counter++;
    }
    // current pointer will give us (k+1)th node
    if(currptr!=NULL){
        Node* new_head=reverse_k_nodes_of_list(currptr,k);
        head->next= new_head;
    }
    return prevptr; // preptr will give the new head of corrected linkedlist
}
int main(){
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.insert_at_tail(6);
    l1.head=reverse_k_nodes_of_list(l1.head,2);
    l1.display();
    return 0;
}