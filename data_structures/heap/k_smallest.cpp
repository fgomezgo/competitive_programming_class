#include<iostream>
#include<queue>
using namespace std;
int main(){

    //priority_queue <int> pq;

    priority_queue<int, vector<int>, greater<int> > pq;

    vector <int> vec;

    vec.push_back(9);
    vec.push_back(0);
    vec.push_back(3);
    vec.push_back(20);
    vec.push_back(-5);
    vec.push_back(87);
    vec.push_back(2);
    vec.push_back(8);
    vec.push_back(23);
    vec.push_back(-100);
    vec.push_back(-50);

    int k = 5;
    int n = vec.size();

    for(int i = 0; i < n; ++i){
        if(pq.size() < k){
            pq.push(vec[i]); 
        } else{
            pq.push(vec[i]); 
            pq.pop();
        } 
    }
    
    while(!pq.empty()){
        cout<<pq.top()<<" ";
        pq.pop();
    }

    cout<<endl;

    return 0;
}