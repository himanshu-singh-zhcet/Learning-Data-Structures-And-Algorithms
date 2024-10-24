#include<iostream>
#include<vector>
using namespace std;
class queue{
    int front;
    int back;
    vector<int> v;
    public:
    queue(){
        front = -1;
        back = -1;
    }
    void enqueue(int value){
        if(front == -1){
            front =0;
            back =0;
            v.push_back(value);
        }
        else{
            v.push_back(value);
            back++;
        }
    }
    void dequeue(){
        if(front == back){
            back = front = -1;
            v.clear();
        }
        else{
            front++;
        }
    }
    int getfront(){
        if(front == -1) {
        return -1;
        }
        else{
        return v[front];
        }
    }
    bool isempty(){
        return front ==-1;  
    }

};
int main(){
    queue qu;
    qu.enqueue(10);
    qu.enqueue(20);
    qu.enqueue(30);
    qu.dequeue();
    qu.enqueue(40);
    while(! qu.isempty()){
        cout<<qu.getfront()<<endl;
        qu.dequeue();
    }
return 0;
}