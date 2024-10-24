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

};
int main(){
    doubly_linkedlist l1;
    l1.insert_at_head(1);
    l1.insert_at_head(2);
    l1.insert_at_head(3);
    l1.insert_at_head(4);
    l1.display();
    doubly_linkedlist l2;
    l2.insert_at_tail(1);
    l2.insert_at_tail(2);
    l2.insert_at_tail(3);
    l2.insert_at_tail(4);
    l2.insert_at_tail(5);
    l2.display();
    l2.insert_at_kth_position(10,3);
    l2.display();



return 0;
}