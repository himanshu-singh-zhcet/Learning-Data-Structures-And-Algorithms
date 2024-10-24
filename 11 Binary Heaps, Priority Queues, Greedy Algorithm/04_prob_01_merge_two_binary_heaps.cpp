#include<iostream>
#include<vector>
using namespace std;


class{
    public:
    
    void max_heapify(vector<int> &v,int size,int curr){
        while(2*curr<size){
            int leftchild = 2*curr;
            int rightchild = 2*curr+1;
            int maxchild = leftchild;

            if(rightchild<= size and v[rightchild]>v[leftchild]){
                maxchild = rightchild;
            }
            if(v[curr]<v[maxchild]){
                return;
            }
            swap(v[curr],v[maxchild]);
            curr = maxchild;        }
    }

    vector<int> mergeheaps(vector<int> &a,vector<int> &b, int m , int n){
        vector<int> mergedheap;
        for(auto ele: a){
            mergedheap.push_back(ele);
        }
        for(auto ele: b){
            mergedheap.push_back(ele);
        }
        for(int i =m+n/2;i>0;i--){
            max_heapify(mergedheap,m+n,i);
        }
        return mergedheap;
    }
};
int main(){
return 0;
}
