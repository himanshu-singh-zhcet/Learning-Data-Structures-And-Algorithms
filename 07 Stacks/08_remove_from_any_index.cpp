#include<iostream>
#include<stack>
using namespace std;
void remove_from_any_index(stack<int> &st,int idx){
    stack<int> temp;
    int y =st.size()-idx-1;
    for(int i = 0;i<y;i++){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();  
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
    return;
}
void remove_from_any_index_by_recursive_method(stack<int> &st,int idx){
    // base case
    if(st.size()==idx+1){
        st.pop();
        return;
    }
    int curr=st.top();
    st.pop();
    remove_from_any_index_by_recursive_method(st,idx);
    st.push(curr);
}
int main(){
stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    // remove_from_any_index(st,2);
    remove_from_any_index_by_recursive_method(st,2);
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;
    }
return 0;
}