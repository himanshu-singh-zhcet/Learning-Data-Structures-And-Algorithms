#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;    // declaring a pointer of node type
    Node(int value){
        data=value;
        next =NULL;
    }
    };

int main(){
    Node* node1 =new Node(1);
    cout<<node1->data<<endl;
    cout<<node1->next<<endl;
    
return 0;
}