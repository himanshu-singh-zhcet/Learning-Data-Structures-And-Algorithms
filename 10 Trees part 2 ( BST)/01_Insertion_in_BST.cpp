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

bool search_by_recursive_method(Node* root,int key){
    // base case 
    if(root == NULL){
        return false;
    }

    if(root->value==key){
        return true;
    }

    // recursive case
    if(root->value<key){
        return search_by_recursive_method(root->right,key);
    }
    if(root->value>key){
        return search_by_recursive_method(root->left,key);
    }
}

Node* insertion_by_recursive_method(Node* root,int value){
    // base case
    if(root ==NULL){
        Node* newNode =new Node(value);
        return newNode;
    }

    // recursive case

    if(root->value>value){
        root->left = insertion_by_recursive_method(root->left,value);
    }
    else if(root->value<value){
        root->right = insertion_by_recursive_method(root->right,value);
    }
    return root;
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

int main(){
    BST bst1;
    insert(bst1.root,3);
    insert(bst1.root,1);
    insert(bst1.root,4);

    inorder_traversal(bst1.root);
    cout<<endl;
    cout<<search_by_recursive_method(bst1.root,8);
return 0;
}