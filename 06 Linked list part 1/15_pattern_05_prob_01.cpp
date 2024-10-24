#include<iostream>
#include<vector>
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
Node* merge_linkedlist(Node* &head1, Node* &head2){
    Node * dummy_head_node = new Node(-1);
    Node* ptr1 = head1;
    Node* ptr2 = head2;
    Node* ptr3 = dummy_head_node;
    while(ptr1 && ptr2){
        if(ptr1->value < ptr2->value){
            ptr3->next =ptr1;
            ptr1=ptr1->next;
        }
        else{
            ptr3->next=ptr2;
            ptr2=ptr2->next;
        }
        ptr3=ptr3->next;
    }
    if(ptr1){
        ptr3->next=ptr1;
    }
    else{
        ptr3->next=ptr2;
    }
    return dummy_head_node->next;
}
Node* merged_linkedlists(vector<Node*> &heads){
    if(heads.size()==0){
        return NULL;
    }
    while(heads.size()>1){
        Node* merged_head=merge_linkedlist(heads[0],heads[1]);
        heads.push_back(merged_head);
        heads.erase(heads.begin());
        heads.erase(heads.begin());   
    }
    return heads[0];
}
int main(){
    linkedlist l1,l2,l3;
    l1.insert_at_tail(1);
    l1.insert_at_tail(3);
    l1.insert_at_tail(5);
    l1.display();
    l2.insert_at_tail(2);
    l2.insert_at_tail(4);
    l2.insert_at_tail(6);
    l2.display();
    l3.insert_at_tail(7);
    l3.insert_at_tail(8);
    l3.insert_at_tail(9);
    l3.display();
    vector<Node*> heads ={l1.head,l2.head,l3.head};
    linkedlist mereged_list;
    mereged_list.head=merged_linkedlists(heads);
    mereged_list.display();
    
    




}