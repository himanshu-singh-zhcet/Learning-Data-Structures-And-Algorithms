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
void update_at_position(Node* &head,int k,int value){
    Node* temp =head;
    int curr_pos=0;
    while(curr_pos!= k){
        temp =temp->next;
        curr_pos++;
    }
    temp->data =value;
}
void delete_at_head(Node* &head){
    Node* temp =head;
    head=head->next;
    free(temp);
}
void delete_at_tail(Node* &head){
    Node* second_last =head;
    while(second_last->next->next != NULL){
        second_last=second_last->next;
    }
    // now second last node points to second last node
    Node *temp=second_last->next;//node to be deleted
    second_last->next=NULL;
    free(temp);
}
void delete_at_arbitary_position(Node* &head, int pos){
    if(pos==0){
        delete_at_head(head);
        return;
    }
    int curr_pos=0;
    Node* prev =head;
    while(curr_pos!= pos-1){
        prev=prev->next;
        curr_pos++;
    }
    // prev is pointint to node pos-1
    Node *temp = prev->next; // node to be deleted
    prev->next= prev->next->next;
    free(temp);
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
    delete_at_head(head);
    display(head);
    delete_at_tail(head);
    display(head);
    delete_at_arbitary_position(head,1);
    display(head); 
return 0;
}