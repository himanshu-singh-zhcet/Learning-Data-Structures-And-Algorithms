#include<iostream>
#include<stack>
#include<vector>
using namespace std;

vector<int> pge(vector<int> &v1){       // next greater element 
    int n = v1.size();
    reverse(v1.begin(),v1.end());  // reversing the vector
    stack<int> st;     // stores the indexes
    vector<int> output(n,-1);  // output vector
    st.push(0);
    for(int i =1;i<n;i++){
        while(!st.empty() and v1[i]>v1[st.top()]){
        output[st.top()] = n-i-1;  //  because after reverse indexs will be changed
        st.pop();
    }
    st.push(i);
    }
    reverse(output.begin(),output.end());
    reverse(v1.begin(),v1.end());
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
   
    vector<int> result = pge(v);
    for(int i = 0;i<result.size();i++){
        cout<<i-result[i]<<endl;
    }

return 0;
}