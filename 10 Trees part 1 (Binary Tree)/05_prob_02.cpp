#include<iostream>
#include<queue>
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

int  leafnodes(Node* rootnode){
   // base case  
   if(rootnode == NULL){
    return 0;
   }
   if(rootnode->left==NULL and rootnode->right == NULL){
   return 1;
   }
   
   // recursive case
   int left_subtree_leaf_nodes = leafnodes(rootnode->left);
   int right_subtree_leaf_nodes = leafnodes(rootnode->right);
   return left_subtree_leaf_nodes+right_subtree_leaf_nodes;
}
int main(){
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    int i = leafnodes(root);
    cout<<"the no of leaf nodes in the given tree is: "<<i<<endl;
return 0;
}