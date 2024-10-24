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

void f(Node* root,Node* pre, Node* succ,int key){
    if(root == NULL){
        return;
    }
    if(root->value==key){
        // pre is the rightmost node in left subtree;
        if(root->left!= NULL){
            Node* temp = root->left;
            while(temp->right != NULL){
                temp = temp->right;
            }
            pre = temp;
        }
        // successor is left most node in right subtree 
        if(root->right!= NULL){
            Node* temp = root->right;
            while(temp!= NULL){
                temp = temp->left;
            }
            succ = temp;
        }
        
    }
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

    preorder_traversal(bst1.root);
    cout<<endl;
    Node* temp;
    temp = remove_leaf_node(bst1.root);
    preorder_traversal(temp);
return 0;
}