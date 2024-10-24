#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
       value=data;
       next = NULL;
    }
};
class circular_linkedlist{
    public:
    Node* head;
    circular_linkedlist(){
        head = NULL;
    }
    void display(){
        Node* temp =head;
        do{
            cout<<temp->value<<"->";
            temp=temp->next;
        }while(temp!=head);
        cout<<endl;
    }
    void insert_at_head(int value){
        Node* new_node = new Node(value);
        if(head==NULL){
           head=new_node;
           new_node->next=head;
           return;
        }
        Node* tail = head;
        while(tail->next!=head){
            tail=tail->next;
        } 
        // now tail pointer is pointing to the last node
        tail->next=new_node;
        new_node->next=head;
        head=new_node;
    }
    void insert_at_tail(int value){
        Node* new_node = new Node(value);
        if(head==NULL){
           head=new_node;
           new_node->next=head;
           return;
        }
        Node* tail = head;
        while(tail->next!=head){
            tail=tail->next;
        } 
        // now tail pointer is pointing to the last node
        tail->next=new_node;
        new_node->next=head;
    }
    void insert_at_kth_position(int value,int pos){// assuming o based counting
        Node* new_node= new Node(value);
        Node* currptr=head;
        int k=pos;
        for(int i=1;i<k;i++){
            currptr=currptr->next;
        }
        // now currptr is pointing towards (k-1)th node
        Node* temp = currptr->next;
        currptr->next=new_node;
        new_node->next=temp;
        return;
    }
    void updation_at_kth_position(int value, int pos){
        Node* new_node= new Node(value);
        Node* currptr=head;
        int k=pos;
        for(int i=1;i<k;i++){
            currptr=currptr->next;
        }
        // now currptr is pointing towards (k-1)th node
        Node* temp = currptr->next;// temp is pointing to kth node
        temp->value= value;
        return;
        
    }
};
int main(){
    circular_linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.display();
    l1.insert_at_kth_position(7,2);
    l1.display();
    l1.updation_at_kth_position(8,2);
    l1.display();

return 0;
}