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

int  maxdepth(Node* rootnode){
   // base case  
   if(rootnode == NULL){
    return 0;
   }
   
   
   // recursive case
   int left_subtree_depth = maxdepth(rootnode->left);
   int right_subtree_depth = maxdepth(rootnode->right);
   return max(left_subtree_depth,right_subtree_depth)+1;
}
int main(){
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    int i = maxdepth(root);
    cout<<"the maximum depth is: "<<i<<endl;
return 0;
}