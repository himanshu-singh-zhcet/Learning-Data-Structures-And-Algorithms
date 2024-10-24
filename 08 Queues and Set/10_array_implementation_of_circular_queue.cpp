#include<iostream>
#include<vector>
using namespace std;
class queue{
    int front;
    int back;
    int current_size;
    int total_size;
    vector<int> v;
    public:
    queue(int n){
        v.resize(n);
        back = n-1;
        total_size =n;
        front = 0;
        current_size = 0;
    }
    void enqueue(int value){
        if(isfull()) return;
        back = (back+1)%total_size;
        v[back] = value;
        current_size++;

    }
    void dequeue(){
        if(isempty())  return;
        front = (front+1)%total_size;
        current_size--;
    } 
    int getfront(){
        if(isempty()) {
        return -1;
        }
        else{
        return v[front];
        }
    }
    bool isempty(){
        return current_size ==0;  
    }
    bool isfull(){
        return current_size == total_size;
    }

};
int main(){
    queue qu(3)  ;
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