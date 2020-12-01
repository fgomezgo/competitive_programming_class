#include<iostream>
#include<queue>
using namespace std;
int main(){

    priority_queue <int> pq;

    vector <int> vec;
    

    pq.push(9);
    pq.push(0);
    pq.push(3);
    pq.push(20);
    pq.push(-5);
    pq.push(87);

    while(!pq.empty()){
        cout<<pq.top()<<endl;
        pq.pop();
    }

    // heap sort



    return 0;
}