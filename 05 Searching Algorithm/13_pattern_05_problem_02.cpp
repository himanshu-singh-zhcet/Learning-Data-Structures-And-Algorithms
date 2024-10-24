#include<iostream>
#include<vector>
using namespace std;
bool canplacestudents(vector<int> &pos,int s,int mid){
    int studentsReqd =1;
    int lastplaced = pos[0];
    for(int i =1;i<pos.size();i++){
        if(pos[i] - lastplaced >= mid){
            studentsReqd++;
            lastplaced = pos[i];
            if(studentsReqd==s){
                return true;
            }
        }
    }
    return false;
}
int race(vector<int> &pos, int s){
    // space complexity - O(1)
    // Time complexity - O(nlog(xn-x1))
    int n = pos.size();
    int low = 1;
    int high = pos[n-1]-pos[0];
    int ans = -1;
    while(low<=high){
        int mid = low+(high-low)/2;
        if(canplacestudents(pos,s,mid)){
        ans = mid;
        low = mid+1;
        }
        else{
            high = mid-1;
        }
    }
    return ans;

}
int main(){
    int n;
    cout<<"the no of elements: ";
    cin>>n;
    vector<int> v(n);
    for(int i =0;i<n;i++){
        cin>>v[i];
    }
    int s;
    cout<<"enter the no of students: ";
    cin>>s;
    cout<<race(v,s);
return 0;
}