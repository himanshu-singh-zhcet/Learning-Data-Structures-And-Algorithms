#include<iostream>
#include<vector>
using namespace std;

bool candistchoco(vector<int> &arr,int mid,int s){
    int n = arr.size();
    int studentsReqd = 1;
    int currSum = 0;
    for(int i =0;i<n;i++){
        if(arr[i]>mid){  // ek box main hi mid se jyada choclate hai 
            return false;
        }
        if(currSum+arr[i]>mid){
            studentsReqd++;  // ab nye student ko allocate krna shuru karenge
            currSum =arr[i];
            if(studentsReqd>s) return false;
        }
        else{
            currSum+= arr[i];
        }
    }
    return true;
}
int distchoco(vector<int> &arr,int s){
    int n = arr.size();    // no of boxes
    int low = arr[0];
    int hi = 0;
    for(int i =0;i<arr.size();i++){
        hi+= arr[i];
    }
    int ans = -1;
    while(low<=hi){
        int mid = low+(hi-low)/2;
        if(candistchoco(arr,mid,s)){
            ans = mid;
            hi = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main(){
    int n;
    cout<<"the no of boxes: ";
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    int s;
    cout<<"enter the no of students: ";
    cin>>s;
    cout<<distchoco(v,s);
return 0;
}