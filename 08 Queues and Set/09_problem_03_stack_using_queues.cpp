#include<iostream>
#include<queue>
using namespace std;

class stack{
    queue<int> qu;
    public:
    stack(){

    }
    void pop(){
        if(qu.empty()){
            return;
        }
        qu.pop();
    }
    void push(int x){
        queue<int> temp;
        while(!qu.empty()){
            temp.push(qu.front());
            qu.pop();
        }

       // now queue is empty
       qu.push(x);
       while(!temp.empty()){
       qu.push(temp.front());
       temp.pop();
       }
        
    }

    int front(){
        return qu.front();
       
    }
    
};
int main(){
    stack st;
    st.push(4);
    st.push(6);
    st.push(9);
    st.pop();
    cout<<st.front()<<endl;
return 0;
}