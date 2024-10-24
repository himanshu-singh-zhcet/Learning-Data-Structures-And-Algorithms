#include<iostream>
#include<stack>
using namespace std;
void insert_at_bottom(stack<int> &st,int x){
    /*
    time complexivity o(n)
    space complexivity o(n)
    */
    stack<int> temp;
    while(!st.empty()){
        int curr = st.top();
        st.pop();
        temp.push(curr);
    }
    st.push(x);  // this is the point where x got inserted at the bottom
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        st.push(curr);
    }
    return;
}
void insert_at_bottom_by_recursive_method(stack<int> &st, int x){
    // base case
    if(st.empty()){
        st.push(x);
        return;
    }
    int curr=st.top();
    st.pop();
    insert_at_bottom_by_recursive_method(st,x);
    st.push(curr);
}
int main(){
stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // insert_at_bottom(st,10);
    insert_at_bottom_by_recursive_method(st,10);
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;
    }
return 0;
}