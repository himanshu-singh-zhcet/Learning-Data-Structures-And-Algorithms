#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    char data;
    vector<Node*> childern;

    Node(char value){
        data = value;
    }
};

int main(){
    Node* root = new Node('A');
    root->childern.push_back(new Node('B'));
    root->childern.push_back(new Node('C'));
    cout<<root->data<<endl;
    for(Node* child: root->childern){
        cout<<child->data<<" ";
    }


return 0;
}