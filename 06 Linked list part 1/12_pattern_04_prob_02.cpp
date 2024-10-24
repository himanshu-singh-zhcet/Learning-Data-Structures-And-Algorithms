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
int get_length(Node* head){
    int length =0;
    while(head->next != NULL){
        length++;
        head =head->next;
        
    }
    
    return length;
}
Node* get_intersection(Node* head1, Node * head2){
    // step 1  get the lenght of both linkesdlist
    int length1=get_length(head1);
    int length2=get_length(head2);
    cout<<length1;
    // step2 Find differece k and move longer linkedlist ptr by k steps
    if(length1>length2){
        int k= length1-length2;
        for(int i =0;i++;i<k){
            head1=head1->next;
        }
    }
    else{
        int k=length2-length1;
        for(int i=0;i++;i<k){
            head2=head2->next;
        }
    }
    while(head1){
        if(head1==head2){
            return head1;
        } 
        head1= head1->next;
        head2= head2->next; 
    }
    return NULL;
}
int main(){
    linkedlist l1,l2;
    l1.insert_at_tail(1);
    l1.insert_at_tail(2);
    l1.insert_at_tail(3);
    l1.insert_at_tail(4);
    l1.insert_at_tail(5);
    l1.display();
    l2.insert_at_tail(6);
    l2.insert_at_tail(7);
    l2.head->next->next=l1.head->next->next->next;
    // intersecting thr linkedlist l2 with l1;
    l2.display();
    Node* intersection=get_intersection(l1.head,l2.head);
    if(intersection){
        cout<<intersection->value;
    }
    else{
        cout<<"-1";
    }

}


