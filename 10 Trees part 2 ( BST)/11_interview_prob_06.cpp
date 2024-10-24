#include<iostream>
#include<vector>
using namespace std;

class treenode{
    public:
    int value;
    treenode* left;
    treenode* right;
    treenode(int v){
        value = v;
        left = right = NULL;
    }
};

treenode* insert_node(treenode* root, int element,int &successor){

    if(root == NULL){
        return new treenode(element);
    }
    if(element<root->value){
        successor = root->value;
        root->left = insert_node(root->left,element,successor);
    }

    else if(element>root->value){
        root->right = insert_node(root->right,element,successor);
    }

    return root;
}
void replace_with_least_greater_element(vector<int> &v){
    treenode* root = NULL;

    for(int i =v.size()-1;i>=0;i--){
        int successor  = -1;
        root = insert_node(root,v[i],successor);
        v[i] = successor;
    }
}
int main(){
    cout<<"enter input--> "<<endl;
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i = 0;i<n;i++){
        cin>>v[i];
    }
    replace_with_least_greater_element(v);
    for(int i =0;i<n;i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
    


return 0;
}
