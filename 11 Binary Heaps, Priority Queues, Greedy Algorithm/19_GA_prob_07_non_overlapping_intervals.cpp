bool cmp(vector<int> &i1,vector<int> &i2){
        return i1[1]<i2[1];
    }
class Solution {
   

public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int last_picked = 0;
        int count = 0;
        for(int i =1;i<intervals.size();i++){
           if(intervals[last_picked][1]>intervals[i][0]){
            // overlapp detected remove the current node 
            count++;
           }
           else{
               // no overlap pick the current one
               last_picked = i;
           }
        }
        return count;
    }
}; 