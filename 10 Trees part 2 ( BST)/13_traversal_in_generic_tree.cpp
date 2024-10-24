#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node{
    public:
    char data;
    vector<Node*> childern;

    Node(char value){
        data = value;
    }
};

void preorder_traversal(Node* root){
    if(root == NULL){
        return;
    }
    cout<<root->data<<" ";
    for(Node* child : root->childern){
        preorder_traversal(child);
    }
    return;
}

void inorder_traversal(Node* root ){
    if(root == NULL){
        return;
    }
    int child_nodes = root->childern.size();
    for(int i =0;i<child_nodes-1;i++){
        inorder_traversal(root->childern[i]);
    }
    cout<<root->data<<" ";
    if(child_nodes>0){
        inorder_traversal(root->childern[child_nodes-1]);
    }
    return;
}

void postorder_traversal(Node* root){
    if(root == NULL){
        return; 
    }
    for(Node* child : root->childern){
        postorder_traversal(child);
    }
    cout<<root->data<<" ";
}

void level_order_traversal(Node* root){
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        int current_level_nodes = q.size();
        while(current_level_nodes--){
            // dequeue 
            Node* curr = q.front();
            q.pop();
            cout<<curr->data<<" ";
            // enequeue all child nodes 
            for(Node* child: curr->childern){
                q.push(child);
            }
        }
        cout<<endl;
    }
    

}
int main(){
    Node* root = new Node('A');
    root->childern.push_back(new Node('B'));
    root->childern.push_back(new Node('C'));
    root->childern.push_back(new Node('D'));
    root->childern[0]->childern.push_back(new Node('F'));
    root->childern[0]->childern.push_back(new Node('G'));
    root->childern[2]->childern.push_back(new Node('H'));
    //preorder_traversal(root);
    level_order_traversal(root);
    


return 0;
}