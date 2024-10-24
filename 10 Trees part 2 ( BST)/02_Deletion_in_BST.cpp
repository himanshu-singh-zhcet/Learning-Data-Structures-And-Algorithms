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
 Node* largest_node_bst(Node* root){
    Node* curr = root;
    while(curr and curr->right != NULL){
        curr = curr->right;
    }
    return curr;
}

Node* Deletion_in_bst(Node *root, int key){
    // base case;
    if(root == NULL){
        return root;
    }

    if(root->value<key){
        root->right=Deletion_in_bst(root->right,key);
    }
 
    else if(root->value>key){
        root->left = Deletion_in_bst(root->left,key);
    }

    else{ // root is the node to be deleted 
        if(root->left==NULL  && root->right==NULL){  // node has zero child node 
            free(root);
            return NULL;
        }
        else if(root->left==NULL){   // node has one child node 
          Node* temp = root->right;
          free(root);
          return temp;
        }

        else if(root->right==NULL){   // node has one child node 
          Node* temp = root->left;
          free(root);
          return temp;
        }

        else{ // node has two child nodes 
           Node* just_smaller_node = largest_node_bst(root->left);
           root->value=just_smaller_node->value;
           root->left = Deletion_in_bst(root->left,just_smaller_node->value);
        }
    }
        
    return root;
}

 
int main(){

    BST bst1;
    insert(bst1.root,3);
    insert(bst1.root,1);
    insert(bst1.root,4);
    insert(bst1.root,6);
    insert(bst1.root,2);

    inorder_traversal(bst1.root);
    cout<<endl;
    Deletion_in_bst(bst1.root,3);
    inorder_traversal(bst1.root);
return 0;
}