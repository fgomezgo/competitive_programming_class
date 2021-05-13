#include <iostream>
#include <vector>
using namespace std;

vector <int> f(4001, -1);
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
//back-propagation
void result2(){
    f[0] = 0;
    
    for(int i = 1; i <= n; ++i){
        int val1 = -1, val2 = -1, val3 = -1;
        if (i - a >= 0 ){
            val1 = f[i - a];
        }
        if (i - b >= 0){
            val2 = f[i - b];
        }
        if (i - c >= 0 ){
            val3 = f[i - c];
        }

        f[i] = max(max(val1,val2),val3);
        if(f[i] != -1){
            f[i]++;
        }
    }
}

void result3(){

    f[0] = 0;
    for(int i = 0; i <= n; ++i){
        if(f[i] != -1){
            if(i+a <= n){
                f[i+a] = max(f[i+a], f[i]+1);
            }
            if(i+b <= n){
                f[i+b] = max(f[i+b], f[i]+1);
            }
            if(i+c <= n){
                f[i+c] = max(f[i+c], f[i]+1);
            }
        }
    }
}

int main(){
    cin>>n>>a>>b>>c;

    //cout<<result(n)<<endl;
    result3();
    for(int i = 0; i <= n; ++i){
        cout<<f[i]<<" ";
    } cout<<endl;
    //cout<<f[n];


    return 0;
}


