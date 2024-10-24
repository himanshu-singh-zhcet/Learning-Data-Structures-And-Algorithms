#include<iostream>
#include<queue>
#include<vector>
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

vector<int>   rightviewofbinarytree(Node* rootnode){
   vector<int> ans; 
   if(rootnode == NULL){
    return ans;
   }
   queue<Node*> q;
   q.push(rootnode);
   while(!q.empty()){
    int nodes_at_current_level=q.size();
    while(nodes_at_current_level){
        Node* currnode = q.front();
        q.pop();
        if(nodes_at_current_level==1){
            ans.push_back(currnode->value);
        }
        if(currnode->left){
            q.push(currnode->left);
        }
        if(currnode->right){
            q.push(currnode->right);
        }
        nodes_at_current_level--;
    }
   }
}
int main(){
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    vector<int> res = rightviewofbinarytree(root);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
return 0;
}