#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct activity{
    int start;
    int end;
    int idx;
};

bool cmp(activity m1 ,activity m2){
    return m1.end<m2.end;
}

void print_activity(vector<activity> &arr){
    sort(arr.begin(),arr.end(),cmp);
    cout<<arr[0].idx<<" ";
    activity last =arr[0];
    for(int i =1;i<arr.size();i++){
        if(arr[i].start>last.end){
            cout<<arr[i].idx<<" ";
            last = arr[i];
        }
    }
    
}
int main(){
    int n;
    cout<<"enter the vvslue of n: "<<endl;
    cin>>n;
    vector<activity> arr(n);
    int idx =0;
    cout<<"enter the details of  activitys: "<<endl;
    while(n--){
        int start;
        int end;
        cin>>start>>end;
        idx++;
        activity m;
        m.start = start;
        m.end = end;
        m.idx = idx;
        arr.push_back(m);
    }
    
    print_activity(arr);
    
return 0;
}