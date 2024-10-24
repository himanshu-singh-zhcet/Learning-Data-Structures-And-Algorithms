#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#include<unordered_map>
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

void serialized_tree(Node* root, string &ans){
    if(root == NULL){
        return;
    }
    ans += to_string(root->data) +":" + to_string(root->childern.size()) + ":";
    for(Node* child : root->childern){
        ans+= to_string(child->data)+",";
    }
    if(root->childern.size()>0){
    ans.pop_back();
    }
    ans+= "\n";
    for(Node* child : root->childern){
        serialized_tree(child,ans);
    }
}

Node* deserialized_helper(int nodevalue, unordered_map<int ,string> mp){
    Node* node = new Node(nodevalue);
    string node_str = mp[nodevalue];
    if(node_str[0]='0'){
        // leaf node
        return node;
    }

    int breakpos = node_str.find(':');
    int child_no = stoi(node_str.substr(0,breakpos));
    string child_node_str = node_str.substr(breakpos+1);

    int start =0;
    for(int i = 0;i<child_no;i++){
       int end = child_node_str.find(',',start);
       if(end == string::npos) end = child_node_str.size();
       int child_node_value = stoi(child_node_str.substr(start,end));
       node->childern.push_back(deserialized_helper(child_node_value,mp));
       start = end+1;
    }
    return node;
}
Node* deserialized(string serialized_str){
    if(serialized_str==""){
        return NULL;
    }
    // creating map
    unordered_map<int,string> mp; //nodevalue-> childnode string
    int start = 0;
    for(int i =0;i<serialized_str.size();i++){
        if(serialized_str[i] == '\n'){
            string nodestr = serialized_str.substr(start,i-start); // "10:2:30,40"
            int breakpos1 = nodestr.find(':');
            int nodevalue = stoi(nodestr.substr(0,breakpos1)); // 10
            mp[nodevalue] = nodestr.substr(breakpos1+1);  // "2:30,40"
            start=i+1;
        }
    }

    int root_node_value = stoi(serialized_str.substr(0,serialized_str.find(':')));
    return deserialized_helper(root_node_value,mp);
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
    string serialized_string ="";
    serialized_tree(root,serialized_string);
    cout<<serialized_string<<endl;

    Node* deserialized_root = deserialized(serialized_string);
    level_order_traversal(deserialized_root);
return 0;
}