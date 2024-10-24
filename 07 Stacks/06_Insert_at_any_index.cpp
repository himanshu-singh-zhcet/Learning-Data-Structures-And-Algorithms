#include<iostream>
#include<stack>
using namespace std;
void insert_at_any_index(stack<int> &st,int x,int idx){
    stack<int> temp;
    int y = st.size()-idx;
    for(int i = 0;i<y;i++){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);  
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
    return;
}
void insert_at_any_index_by_recursive_method(stack<int> &st,int x ,int idx){
    // based case
    if(st.size()==idx){
    st.push(x);
    return;
    }
    int curr =st.top();
    st.pop();
    insert_at_any_index(st,x,idx);
    st.push(curr);
}
int main(){
stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // insert_at_any_index(st,10,1);
    insert_at_any_index_by_recursive_method(st,10,1);
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;
    }
return 0;
}