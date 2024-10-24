#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> nge(vector<int> v1){       // next greater element 
    int n = v1.size();
    stack<int> st;     // stores the indexes
    vector<int> output(n,-1);  // output vector
    st.push(0);
    for(int i =1;i<n;i++){
        while(!st.empty() and v1[i]>v1[st.top()]){
        output[st.top()] = v1[i];
        st.pop();
        }
    st.push(i);
    }
    return output;
}
vector<int> nse(vector<int> v1){   // next smaller elememt
    int n = v1.size();
    stack<int> st;     // stores the indexes
    vector<int> output(n,-1);  // output vector
    st.push(0);
    for(int i =1;i<n;i++){
        while(!st.empty() and v1[i]<v1[st.top()]){
        output[st.top()] = v1[i];
        st.pop();
    }
    st.push(i);
    }
    return output;
}

int main(){
    int n;
    cout<<"enter the size of vector ";
    cin>>n;
    vector<int> v;
    while(n--){
        int x;
        cin>>x;
        v.push_back(x);
    }
    vector<int> result = nge(v);
    for(int i = 0;i<result.size();i++){
        cout<<result[i]<<endl;
    }

return 0;
}