#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;
int least_interval(vector<char> tasks,int n){
    //  1. count frequency of tasks
    unordered_map<char,int> taskfrequency;
    for(auto t: tasks){
        taskfrequency[t]++;
    }

    //2. insert frequencty into max heap
    priority_queue<int> pq;
    for(auto e: taskfrequency){
        pq.push(e.second);
    }

    // 3. finding time until pq is empty
    int total_time = 0;
    while(!pq.empty()){
        vector<int> temp;
        // loopint one time frame = n+1 units of time 
        for(int i =0;i<=n;i++){
         if(!pq.empty()){
            int freq = pq.top();
            pq.pop();
            if(freq>1){
                temp.push_back(freq-1);  // adding remaining time in temp vector
            }
         }
         total_time++;
            if(pq.empty()  and temp.empty()){
                return total_time;    // all task have been executed
            }
        }
        for(auto t: temp){
            pq.push(t);
        }
    }
    return total_time;
}
int main(){
    vector<char> tasks ={'A','A','A','A','B','B','B'};
    int cooldown =2;
    int leasttime = least_interval(tasks,cooldown);
    cout<<"the least interval time is: "<<leasttime;
return 0;
}