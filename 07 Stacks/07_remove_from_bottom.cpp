#include<iostream>
#include<stack>
using namespace std;
void remove_from_bottom(stack<int> &st){
    stack<int> temp;
    int y =st.size()-1;
    for(int i = 0;i<y;i++){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.pop();  // this is the point deleted  at the bottom
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
    return;
}
void remove_from_bottom_by_recursive_method(stack<int> &st){
    // base case
    if(st.size()==1){
        st.pop();
        return;
    }
    int curr=st.top();
    st.pop();
    remove_from_bottom_by_recursive_method(st);
    st.push(curr);
}
int main(){
stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    remove_from_bottom_by_recursive_method(st);
    //remove_from_bottom(st);
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;
    }
return 0;
}