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
Node* odd_even_linkedlist(Node* &head){
    if(!head){
        return head;
    }
    Node* evenhead= head->next;
    Node* oddptr= head;
    Node* evenptr= evenhead;
    while(evenptr && evenptr->next){
        oddptr->next=oddptr->next->next;
        evenptr->next=evenptr->next->next;
        oddptr=oddptr->next;
        evenptr=evenptr->next;
    }
    oddptr->next=evenhead;
    return head;
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
    l1.head=odd_even_linkedlist(l1.head);
    l1.display();
    return 0;
}