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
void levelorder_traversal(Node* rootnode){
    if(rootnode==NULL){
        return;
    }
    queue<Node*> q;
    q.push(rootnode);
    while(!q.empty()){
        int nodes_at_current_level = q.size();
        while(nodes_at_current_level--){
            Node* currnode = q.front();
            q.pop();
            cout<<currnode->value<<" ";
            if(currnode->left){
                q.push(currnode->left);
            }
            if(currnode->right){
                q.push(currnode->right);
            }
        }
        cout<<endl;
    }

}
int main(){
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    levelorder_traversal(root);
return 0;
}