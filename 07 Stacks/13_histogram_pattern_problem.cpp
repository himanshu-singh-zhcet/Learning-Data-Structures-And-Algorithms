#include<iostream>
#include<stack>
#include<vector>
using namespace std;
int histogram(vector<int> v1){   // next smaller elememt
    int n = v1.size();
    stack<int> st;     // stores the indexes
    int ans = -10;
    vector<int> output(n,-1);  // output vector
    st.push(0);
    for(int i =1;i<n;i++){
        while(!st.empty() and v1[i]<v1[st.top()]){
        int ele = v1[st.top()];
        st.pop();
        int nsi =i;
        int psi = (st.empty()) ? -1: st.top();
        ans =max(ans,ele*(nsi-psi-1));
    }
    st.push(i);
    }
    return ans;
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
    int  result = histogram(v);
    cout<<"the area of largest element"<<result; 
    

return 0;
}