 #include<iostream>
 #include<vector>
 using namespace std;
 int find_minimum_of_sorted_array(vector<int> &v){
    int n= v.size();
    if(n==1) return 0;
    int low =0;
    int high =n-1;
    if(v[low]<v[high]){
        return low; // the given sorted array is not rotated 
    }
    while(low<=high){
        int mid=low+(high-low)/2;
        if(v[mid]>v[mid+1]) return mid+1;
        if(v[mid]<v[mid-1]) return mid;
        if(v[mid]>v[low]){
            low =mid+1;
        }
        else{
            high=mid-1;
        }
    }
    return -1; 
 }
 int main(){
    int n;
    cout<<"enter the size of vector: ";
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++){
        cout<<"enter the "<<i<<"th elemnet of vector: ";
        cin>>a[i];// 2 4 5 7 15 24 45 50
    }
    cout<<find_minimum_of_sorted_array(a)<<endl;
 return 0;
 }