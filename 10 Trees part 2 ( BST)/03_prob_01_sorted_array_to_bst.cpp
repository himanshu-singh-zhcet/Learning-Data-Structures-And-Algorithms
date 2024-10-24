#include<iostream>
#include<vector>
using namespace std;
class Node{
    public:
    int value;
    Node *left;
    Node *right;
    Node(int v){
        value =v;
        left = right = NULL;
    }
};

class BST{
    public:
    Node *root;

    BST(){
        root = NULL;
    }
};

Node* sorted_array_to_bst(vector<int> v , int start , int end ){
    // base case 
    if(start>end){
        return NULL;
    }

    int mid = (start+end)/2;
    Node* root = new Node(v[mid]);
    // recursive case 
    root->left = sorted_array_to_bst(v, start,mid-1); // recursively creating left subtree from left half of array 
    root->right = sorted_array_to_bst(v,mid+1,end);   // recursively creating righ subtree from right half of array

    return root;
}
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
int main(){
    int n;
    cout<<"enter the size of vecto: ";
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++){
    cin>>v[i];
    }

    BST bst1;
    bst1.root = sorted_array_to_bst(v,0,n-1);
    preorder_traversal(bst1.root);
    
    
return 0;
}