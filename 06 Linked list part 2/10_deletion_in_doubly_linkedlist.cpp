#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* prev;
    Node* next;
    Node(int data){
        value=data;
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
    void insert_at_head(int value){
        Node* new_node=new Node(value);
        if(head==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        new_node->next= head;
        head->prev=new_node;
        head=new_node;
        return;
    }
    void insert_at_tail(int value){
         Node* new_node=new Node(value);
        if(tail==NULL){
            head=new_node;
            tail=new_node;
            return;
        }
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }
    void insert_at_kth_position(int value , int k){// assuming k is less than or equal to the length of linkedlist
        Node* new_Node =new Node(value);
        Node* temp =head;
        int  count =1;
        while(count<(k-1)){
            temp=temp->next;
            count++;
        }
        new_Node->next=temp->next;
        temp->next=new_Node;
        new_Node->next->prev=new_Node;
        new_Node->prev=temp;


    }
    void display(){
        Node* temp = head;
        while(temp!= NULL){
            cout<<temp->value<<"  ";
            temp=temp->next;
        }cout<<endl;
        return;
    }
    void delete_at_head(){
        if(head==NULL){
            return;
        }
        Node* temp = head;
        head=head->next;
        if(head==NULL){// IN THIS CASE DOUBLY LINKEDLIST HAVE ONLY ONE NODE
            tail==NULL;
        }
        else{
            head->prev=NULL;
        }
        free(temp);
        return;
    }
    void delete_at_tail(){
    if(tail==NULL){
        return;
    }
    Node* temp = tail;
    tail=tail->prev;
    if(tail==NULL){
        head=NULL;
    }
    else{
        tail->next=NULL;
    }
    free(temp);
    }
    void delete_at_kth_position(int pos){
        // assumong k is equal to or less then the length of the doubly linkedlist
        Node* temp=head;
        int counter=1;
        while(counter<pos){
            temp=temp->next;
            counter++;
        }
        // Now temp is pointing to node at kth position
        temp->prev->next=temp->next;
        temp->next->prev=temp->prev;
        free(temp);
        return;
    }

};
int main(){
    doubly_linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.insert_at_tail(6);
    l1.display();
    l1.delete_at_head();
    l1.display();
    l1.delete_at_tail();
    l1.display();
    l1.delete_at_kth_position(3);
    l1.display();

}