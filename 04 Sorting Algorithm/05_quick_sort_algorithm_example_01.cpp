#include<iostream>
using namespace std;
int partition(int arr[],int first,int last){
    int pivot=arr[last];
    int i =first-1;
    int j=first;
    for(;j<last;j++){
        if(arr[j]<pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    // now i is pointing to the last leemnt less than pivot
    swap(arr[i+1],arr[last]);
    return i+1;


}
void  quick_sort(int arr[], int first,int last){
    // base case
    if(first>=last){
        return;
    }
    // recusive case
    int p=partition(arr,first,last);
    quick_sort(arr,first,p-1);
    quick_sort(arr,p+1,last);

}
int main(){
    int arr[]={ 20,12,35,16,18,30};
    int n=sizeof(arr)/sizeof(arr[0]);
    quick_sort(arr,0,n-1);
    cout<<"the sorted array is"<<endl;
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    
return 0;
}