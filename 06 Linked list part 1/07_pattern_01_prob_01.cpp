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
void delete_duplicate_node (Node* &head){
    Node* current_node=head;
    while(current_node!= NULL){
    while(current_node->next != NULL and current_node->value == current_node->next->value){
        Node *temp =current_node->next;
        current_node->next=current_node->next->next;
        free(temp);
        }
        current_node=current_node->next;
    }
}
int main(){
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(3);
    l1.insert_at_tail(3);
    l1.display();
    delete_duplicate_node(l1.head);
    l1.display();

return 0;
}