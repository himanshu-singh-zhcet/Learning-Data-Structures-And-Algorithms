#include<iostream>
#include<stack>
using namespace std;
stack<int> copy_stack(stack<int> &input){
    stack<int> temp;
    while(!input.empty()){
        int curr=input.top();
        input.pop();
        temp.push(curr);
    }
    stack<int> result;
    while(!temp.empty()){
        int curr = temp.top();
        temp.pop();
        result.push(curr);
    }
    return result;
}
void copy_stack_by_recursive_method(stack<int> &st,stack<int> &result){
    // base case
    if(st.empty()){
        return;
    }
    int curr = st.top();
    st.pop();
    copy_stack_by_recursive_method(st,result);
    result.push(curr);
}
int main(){
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // stack<int> result= copy_stack(st);

    stack<int> result1;
    copy_stack_by_recursive_method(st,result1);
    while(!result1.empty()){
        int curr=result1.top();
        result1.pop();
        cout<<curr<<endl;
    }
return 0;
}