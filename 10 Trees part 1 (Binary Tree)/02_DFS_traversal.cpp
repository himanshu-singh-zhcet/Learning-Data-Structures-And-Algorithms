#include<iostream>
using namespace std;
class Node{
    public:
    int value;
    Node* left;
    Node* right;
    Node(int data){
    value = data;
    left = right = NULL;
    }
};
void preorder_traversal(Node* rootnode){
    // base case 
    if(rootnode == NULL){
        return;
    }
    // recursive case 
    cout<<rootnode->value<<" ";
    preorder_traversal(rootnode->left);
    preorder_traversal(rootnode->right);

}

void inorder_traversal(Node* rootnode){
    // base case 
    if(rootnode == NULL){
        return;
    }
    // recursive case
    inorder_traversal(rootnode->left); 
    cout<<rootnode->value<<" ";
    inorder_traversal(rootnode->right);
}

void postorder_traversal(Node* rootnode){
    // base case 
    if(rootnode == NULL){
        return;
    }
    // recursive case
    postorder_traversal(rootnode->left); 
    postorder_traversal(rootnode->right);
    cout<<rootnode->value<<" ";
}
int main(){
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    preorder_traversal(root);
    cout<<endl;
    inorder_traversal(root);
    cout<<endl;
    postorder_traversal(root);
return 0;
}