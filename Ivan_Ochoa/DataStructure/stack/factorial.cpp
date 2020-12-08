#include <iostream>
#include <vector>
#include <stack>
using namespace std;


int fact(int n){
    if(n == 0){
        return 1;
    }
    return fact(n-1)*n;
}

int main(){

    int n = 5;

    cout<<fact(n)<<endl;


    stack <int> S;

    vector <int> vec(n+1);

    S.push(n);

    while(!S.empty()){
        int top = S.top();
        if(top == 0){
            vec[top] = 1;
            S.pop();
        } else{
            if(vec[top-1] != 0){
                vec[top] = vec[top-1] * top;
                S.pop();
            } else{
                S.push(top-1);
            }
        }
    }

    cout<<vec[n]<<endl;

    return 0;
}