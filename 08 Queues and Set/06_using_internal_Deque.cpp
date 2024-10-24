#include<iostream>
#include<deque>
using namespace std;
int main(){
    deque<int> dq;
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);;
    dq.push_front(0);
    dq.push_front(40);
    while(!dq.empty()){
        cout<<dq.front()<<endl;
        dq.pop_front();
    }
return 0;
}
