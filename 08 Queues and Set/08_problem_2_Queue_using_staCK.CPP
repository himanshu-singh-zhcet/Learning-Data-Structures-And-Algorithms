#include<iostream>
#include<stack>
using namespace std;
// push efficient queue using stack
class queue{
    stack<int> st;
    public:
    queue(){

    }
    void push(int x){    // enqueue in queue
    st.push(x);
    }
    void pop(){
    if(st.empty()) {
        return;
        }
    stack<int> temp;
    while(st.size()>1){
        temp.push(st.top());
        st.pop();
    }
    // now the stack size is one we are at bottom element
    st.pop(); 
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    }
    bool empty(){
        return st.empty();
    }
    int front(){
        if(st.empty()) {
        return -1;
        }
    stack<int> temp;
    while(st.size()>1){
        temp.push(st.top());
        st.pop();
    }
    // now the stack size is one we are at bottom element
    int result = st.top(); 
    while(!temp.empty()){
        st.push(temp.top());
        temp.pop();
    }
    return result;
    }
};
int main(){
    queue qu;
    qu.push(10);
    qu.push(20);
    qu.push(30);
    qu.push(40);
    qu.push(50);
    qu.pop();
    while(!qu.empty()){
        cout<<qu.front()<<endl;
        qu.pop();
    }
return 0;
}