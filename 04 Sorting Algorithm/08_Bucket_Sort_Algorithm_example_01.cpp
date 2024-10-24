#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
void bucket_sort(float arr[], int size){
    // step 1  creating a bucket 
    vector<vector<float>> bucket(size, vector<float>());

    // step 2 inserting elemnet in the bucket
    for(int i=0;i<size;i++){
        int index =arr[i]*size;
        bucket[index].push_back(arr[i]);
    }
    //  step 3 sorting individual buckets
    for(int i =0;i<size;i++){
        if(!bucket[i].empty()){
            sort(bucket[i].begin(),bucket[i].end());
        }
    }
    // step 4 combining element from buckets
    int k =0;
    for(int i =0;i<size;i++){
        for(int j =0;j<bucket[i].size();j++){
            arr[k++]=bucket[i][j];
        }
    }

}
int main(){
    float arr[]={0.13,0.45,0.12,0.89,0.75,0.63,0.85,0.39};
    int size= sizeof(arr)/sizeof(arr[0]);
    bucket_sort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
return 0;
}