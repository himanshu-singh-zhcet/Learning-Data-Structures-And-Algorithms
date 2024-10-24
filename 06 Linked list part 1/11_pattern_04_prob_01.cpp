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
bool check_equal_linkedlist(Node* head1,Node* head2){
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    while(ptr1 != NULL && ptr2 != NULL){
        if(ptr1->value!= ptr2->value){
            return false;
        }
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    // at this point either ptr1 is null or ptr2 is null or both are null
    return (ptr1==NULL && ptr2 == NULL);
}
int main(){
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.display();
    linkedlist l2;
    l2.insert_at_tail(1);
    l2.insert_at_tail(2);
    l2.insert_at_tail(3);
    l2.display();
    cout<<check_equal_linkedlist(l1.head,l2.head);



}