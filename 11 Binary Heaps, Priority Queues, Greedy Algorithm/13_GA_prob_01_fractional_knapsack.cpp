#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct item{
    int value;
    int weight;
};

bool cmp(item i1, item i2){
    // custom comprater for comparing

    double ratio_i1 = static_cast<double>(i1.value)/i1.weight;
    double ratio_i2 = static_cast<double>(i2.value)/i2.weight;
    return ratio_i1>ratio_i2;
}

double fractional(int w , vector<item> &items){
    double ans = 0;
    sort(items.begin(),items.end(),cmp);
    for(const auto &item: items){
        if(item.weight<=w){
            ans+=item.value;
            w-= item.weight;
        }
        else{  // we can not pick the whole item as space in the knapsack is less
        double fraction = static_cast<double>(w)/item.weight; 
        ans+= fraction*item.value;
        w=0;
        }
    }
     
     return ans;
    
}

int main(){
    int n,w;
    cout<<" enter the vslue of n and w: "<<endl;
    cin>>n>>w;
    vector<item> items;
    cout<<"enter the value and weight of the items: "<<endl;
    for(int i = 0;i<n;i++){
        int v,w;
        cin>>v>>w;
        item it;
        it.value=v;
        it.weight=w;
        items.push_back(it);
    }

    cout<<"the ans is: "<<fractional(w,items);
return 0;
}