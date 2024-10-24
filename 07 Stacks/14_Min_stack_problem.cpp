#include<iostream>
#include<stack>;
#define ll long long int
using namespace std;
class minstack{
    public:
    stack<ll> st;
    ll min;
    minstack(){
        min = INT_FAST32_MAX;
    }
    void push(int value){
        if(st.empty()){
            st.push(value);
        }
        else{
            st.push(value-min);
            if(min>value){
                min =value;
            }
        }
    }
    void pop(){
        if(! st.empty()){
            if(st.top()>=0){
                st.pop();
            }
            else{
                min = min - st.top();
                st.pop(); 
            }
        }
    }
    int get_min(){
        return  min;
    }
    int gettop(){
        if(st.size()==1){
            return st.top();
        }
        else if(st.top()<0){
            return min;
        }
        else{
            return min+st.top();
        }
    }
};
int main(){
minstack st;
st.push(10);    
st.push(5);    
st.push(6);   
st.push(12);    
st.push(-1);    
st.push(-5);
cout<<st.get_min();   

return 0;
}