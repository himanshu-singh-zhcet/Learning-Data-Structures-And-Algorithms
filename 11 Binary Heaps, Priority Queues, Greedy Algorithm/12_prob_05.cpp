class MedianFinder {
    priority_queue<int> maxpq; // storing lower half of stream 
    priority_queue<int,vector<int>,greater<int>> minpq; // storing greater half of stream 

public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxpq.empty() or num<= maxpq.top()){
            maxpq.push(num);
        }
        else{
            minpq.push(num);
        }

        // reblance the priority queue 
        if(maxpq.size()>minpq.size()+1){
            minpq.push(maxpq.top());
            maxpq.pop();
        }
        else if(minpq.size()>maxpq.size()){
            maxpq.push(minpq.top());
            minpq.pop();
        }
    }
    
    double findMedian() {
        if(minpq.size() == maxpq.size()){
            return (maxpq.top()+minpq.top())/2.0;
        }
        else{  // odd elements in maxpq;
             return maxpq.top();
        }
    }
};