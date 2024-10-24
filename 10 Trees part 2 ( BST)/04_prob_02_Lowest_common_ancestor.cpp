#include<iostream>
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

void insert(Node* &root,int value){
    Node* newNode = new Node(value);

    if(root ==NULL){
        root = newNode;
        return;
    }

    Node* current = root;
    while(true){
        if(current->value>value){
            if(current->left==NULL){
                current->left=newNode;
                return;
            }
            current=current->left;
        }
        else{
            if(current->right==NULL){
                current->right=newNode;
                return;
            }
            current=current->right;
        }

        
    }
}


Node* lowest_common_ancestor(Node* root , Node* node1 ,Node* node2){

    // base case 
    if(root == NULL){
        return NULL;
    }

    if(root->value> node1->value and root->value>node2->value){
       //  lca will be in the left subtree 
    return lowest_common_ancestor(root->left,node1,node2);
    }

    if(root->value< node1->value and root->value < node2->value){
       //  lca will be in the right subtree 
    return lowest_common_ancestor(root->right,node1,node2);
    }

    // if root values lies between node1 and node2 value or if any of node value is equal to the root value 
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
    BST bst1;
    insert(bst1.root,3);
    insert(bst1.root,1);
    insert(bst1.root,4);
    insert(bst1.root,6);
    insert(bst1.root,2);

    Node* node1 = new Node(2);
    Node* node2 = new Node(1);
    Node* temp = lowest_common_ancestor(bst1.root,node1,node2);
    cout<<temp->value;
    cout<<endl;
    preorder_traversal(temp);
return 0;
}
