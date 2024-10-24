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
Node* rotate_by_k_places(Node* & head, int k){
    int n =0;
    Node* tail = head;
    while(tail->next){
        n++;
        tail=tail->next;
    }
    n++;   // to include the last node
    k=k%n;
    if(k==0){
        return head;
    }
    tail->next=head;
    // traverse n-k nodes
    Node* temp = head;
    for(int i=1; i<n-k;i++){
        temp =temp->next;
    }
    // now twmp is pointing to the n-k node
    Node* newhead = temp->next;
    temp->next=NULL;
    return newhead;
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
    l1.head=rotate_by_k_places(l1.head,3);
    l1.display();
}