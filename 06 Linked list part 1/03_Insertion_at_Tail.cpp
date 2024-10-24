#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int value){
        data = value;
        next =NULL;
    }
};
void insert_at_head(Node* &head,int value){
    Node* new_node=new Node(value);   // creating a new node
    new_node->next =head;  // adding the new node at the starting of current linkedlist
    head =new_node;  // shifting head pointer to starting  
}  
void insertation_at_tail(Node* &head,int value){
    Node* new_node= new Node(value);   // creating a new node
    Node* temp =head;
    while(temp->next != NULL){
        temp =temp->next;
    }
    // temp has reached to the last node
    temp->next =new_node;
}  
void display(Node* head){
    Node* temp = head;
    while(temp!= NULL){
        cout<<temp->data<<" ";
        temp =temp->next;
    }
    cout<<"NULL"<<endl;
}
int main(){
    Node* head=NULL;
    insert_at_head(head,2);
    display(head);
    insert_at_head(head,1);
    display(head); 
    insertation_at_tail(head, 3);
    display(head);
    insertation_at_tail(head, 4);
    display(head);
    insertation_at_tail(head, 5);
    display(head);  
return 0;
}