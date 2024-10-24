#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> childern;

    Node(char value){
        data = value;
    }
};
void just_greater_node(Node* root, int x, Node* &ans){
    if(root == NULL){
        return;
    }

    if(root->data > x and (ans == NULL or root->data<ans->data)){
        ans = root;
    }
    for(Node* child : root->childern){
        just_greater_node(child,x,ans);
    }
    return;
}
int main(){
    Node* root = new Node(20);
    root->childern.push_back(new Node(8));
    root->childern.push_back(new Node(22));
    root->childern.push_back(new Node(4));
    root->childern[0]->childern.push_back(new Node(12));
    root->childern[0]->childern.push_back(new Node(10));
    root->childern[2]->childern.push_back(new Node(14));
    
    int x = 10;
    Node* ans = NULL;
    just_greater_node(root, x,ans);
    cout<<"Ans: ";
    if(ans == NULL){
        cout<<"NULL";
    }
    else{
        cout<<ans->data;
    }


return 0;
}