#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

class Node{
    public:
    int data;
    vector<Node*> childern;

    Node(char value){
        data = value;
    }
};

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
 
void mirror_tree(Node* root){
    if(root == NULL){
        return;
    }
    if(root->childern.size()<2){
        return;
    }
    reverse(root->childern.begin(),root->childern.end());
    for(Node* child : root->childern){
        mirror_tree(child);
    }
    return;
}
int main(){
    Node* root = new Node(10);
    root->childern.push_back(new Node(2));
    root->childern.push_back(new Node(34));
    root->childern.push_back(new Node(56));
    root->childern.push_back(new Node(100));
    root->childern[1]->childern.push_back(new Node(1));
    root->childern[3]->childern.push_back(new Node(7));
    root->childern[3]->childern.push_back(new Node(8));
    root->childern[3]->childern.push_back(new Node(9));
    level_order_traversal(root);
    cout<<endl;
    mirror_tree(root);
    level_order_traversal(root);


return 0;
}