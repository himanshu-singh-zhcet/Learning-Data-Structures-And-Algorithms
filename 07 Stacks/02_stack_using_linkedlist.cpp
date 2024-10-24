#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* next;
    Node(int data){
        value=data;
        next=NULL;
    }
};
class stack{
    Node* head;
    int capacity;
    int currsize;
    public:
    stack(int c){
        capacity=c;
        head=NULL;
        currsize=0;
    }
    bool isempty(){
        return head==NULL;
    }
    bool isfull(){
        return currsize=capacity;
    }
    void push(int data){
        if(currsize==capacity){
           cout<<"overflow"<<endl;
           return;
        }
        Node* new_node=new Node(data);
        new_node->next=head;
        head=new_node;
        currsize++;
        return;
    }
    int pop(){
        if(head==NULL){
            cout<<"underflow<<endl";
            return -1;
        }
        Node* temp = head;
        int result=temp->value;
        head=head->next;
        free(temp);
        return result;
    }
    int size(){
        return currsize;
    }
    int gettop(){
        if(head==NULL){
            cout<<"underflow<<endl";
            return -1;
        }
        return head->value;
    }
};
int main(){
    stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);
    cout<<st.gettop()<<endl;
    st.push(4);
    st.push(5);
    cout<<st.gettop()<<endl;
    st.push(6);
    cout<<st.gettop()<<endl;
    st.pop();
    st.pop();
    cout<<st.gettop()<<endl;
return 0;
}