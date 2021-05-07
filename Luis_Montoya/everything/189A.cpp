#include <iostream>
#include <vector>
using namespace std;

vector <int> f(4001, -2);
int n,a,b,c;

int result(int x){
    if(x < 0){
        return -1;
    }
    if(f[x] != -2){
        return f[x];
    }
    if(x == 0){
        return f[0] = 0;
    }
    f[x] = max(max(result(x-a)+1, result(x-b)+1), result(x-c)+1);
    if(f[x] == 0){
        return f[x] = -1;
    }
    return f[x];
}

int main(){
    cin>>n>>a>>b>>c;
    cout<<result(n)<<endl;


    return 0;
}


