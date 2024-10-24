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
void insert_at_position(Node* &head,int value,int pos){
    if(pos == 0){
        insert_at_head(head,value);
        return;
    }
    Node* new_node = new Node(value);  // node that is to be inserted
    Node* temp =head;
    int current_pos=0;
    while(current_pos!= pos-1){
        temp =temp->next;
        current_pos++;
    }
    // temp is pointing to node at pos-1
    new_node->next=temp->next;
    temp->next=new_node;
}
void update_at_position(Node* &head,int pos,int value){
    Node* temp =head;
    int curr_pos=0;
    while(curr_pos!= pos){   
        temp =temp->next;
        curr_pos++;
    }
    temp->data =value;
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
    insert_at_position(head,3,3);
    display(head);
    update_at_position(head,3,6);
    display(head);
return 0;
}