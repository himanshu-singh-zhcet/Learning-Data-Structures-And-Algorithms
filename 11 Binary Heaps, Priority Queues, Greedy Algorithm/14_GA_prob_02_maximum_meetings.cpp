#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

struct meeting{
    int start;
    int end;
    int idx;
};

bool cmp(meeting m1 ,meeting m2){
    return m1.end<m2.end;
}

void print_meeting(vector<meeting> &arr){
    sort(arr.begin(),arr.end(),cmp);
    cout<<arr[0].idx<<" ";
    meeting last =arr[0];
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
    vector<meeting> arr(n);
    int idx =0;
    cout<<"enter the details of meetings: "<<endl;
    while(n--){
        int start;
        int end;
        cin>>start>>end;
        idx++;
        meeting m;
        m.start = start;
        m.end = end;
        m.idx = idx;
        arr.push_back(m);
    }
    
    print_meeting(arr);
    
return 0;
}