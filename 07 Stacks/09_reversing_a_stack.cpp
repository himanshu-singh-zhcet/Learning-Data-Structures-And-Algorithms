#include<iostream>
#include<stack>
using namespace std;
void reversing_a_stack(stack<int> &st){
    stack<int> temp1;
    stack<int> temp2;

    while(not st.empty()){
        int curr = st.top();
        st.pop();
        temp1.push(curr);
    }
    
    while(!temp1.empty()){
        int curr = temp1.top();
        temp1.pop();
        temp2.push(curr);
    }
    while(! temp2.empty()){
        int curr = temp2.top();
        temp2.pop();
        st.push(curr);
    }
    return;
}
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
void reversing_a_stack_by_recursive_method(stack<int> &st){
    // base case
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    reversing_a_stack_by_recursive_method(st);
    insert_at_bottom(st,curr);
}
int main(){
stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
     reversing_a_stack(st);
    // reversing_a_stack_by_recursive_method(st);
    while(!st.empty()){
        int curr=st.top();
        st.pop();
        cout<<curr<<endl;
    }
return 0;
}