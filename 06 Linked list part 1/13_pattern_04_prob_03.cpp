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
void delete_kth_node_from_end(Node* &head, int k){
    Node* ptr1 = head;
    Node* ptr2 = head;
    int count =k;
    while(count--){
        ptr2=ptr2->next;
    }
    if(ptr2==NULL){// k is equal to length of linked list .we have to delete head node 
      Node* temp =head;
      head=head->next;
      free(temp);
      return;

    }
    // now ptr is k steps ahead of ptr1
    while(ptr2->next!=NULL){
        ptr1=ptr1->next;
        ptr2=ptr2->next;
    }
    Node* temp =ptr1->next;
    ptr1->next=ptr1->next->next;
    free(temp);
}
int main(){
    linkedlist l1;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.display();
    delete_kth_node_from_end(l1.head,2);
    l1.display();

    return 0;
}
