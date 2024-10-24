#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

vector<int>   topviewofbinarytree(Node* rootnode){
   vector<int> ans; 
   if(rootnode == NULL){
    return ans;
   }
   queue<pair<Node*,int>>  q;
   map<int,int> m;
   q.push(make_pair(rootnode,0));
   while(!q.empty()){
    int nodes_at_current_level=q.size();
    while(nodes_at_current_level--){
        pair<Node* , int> p = q.front();
        Node* current_node =  p.first;
        int current_coloumn = p.second;
        q.pop();
        if(m.find(current_coloumn)== m.end()){
            m[current_coloumn] = current_node->value;
        }
        if(current_node->left){
            q.push(make_pair(current_node->left,current_coloumn-1));
        }
        if(current_node->right){
            q.push(make_pair(current_node->right,current_coloumn+1));
        }
        
      
        
    }
   }
   for(auto i: m){
    ans.push_back(i.second);
   }
   return ans;
}
int main(){
    Node* root = new Node(2);
    root->left = new Node(4);
    root->right = new Node(10);
    root->left->left = new Node(6);
    root->left->right = new Node(5);
    root->right->right = new Node(11);
    vector<int> res = topviewofbinarytree(root);
    for(int i =0;i<res.size();i++){
        cout<<res[i]<<" ";
    }
return 0;
}