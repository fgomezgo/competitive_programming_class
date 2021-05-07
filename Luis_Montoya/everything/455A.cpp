#include <iostream>
#include <vector>
using namespace std;
vector <long long> f(100000, -1);if
vector <int> a(100000);

long long  result(int x){
    cout<<x<<endl;
    
    if (f[x] != -1){
        return f[x];
    }
        
    if (x == 0)
        return f[0] = 0;
    if (x == 1)
        return f[1] = a[0];
    
    return f[x] = max(result(x-1), (long long)a[x-1] * x + result(x-2));
    
}

int main(){
    int n,aux;
    cin >> n;
    
    
    int maxi = 0;

    for(int i = 0;  i < n; ++i){
        cin >> aux; 
        maxi = max(maxi, aux);
        a[aux-1]++;
    }

    // Casos base
    /*
    f[0] = 0;
    f[1] = a[0]; 

    for(int i = 2; i <= maxi; ++i){
        f[i] = max(f[i-1], (long long)a[i-1] * (long long)i + f[i-2]);
    }/*
    /*
    for(int i = 0; i <= maxi; ++i){
        cout<<f[i]<<" ";
    } cout<<endl;
    */
    cout<<result(maxi)<<endl;
    

    // for(int i = 0; i < a.size(); ++i){
    //     if (a[i] != 0){
    //         cout << i+1 << '-' <<a[i] << endl;
    //     }
    // }
    
    

    return 0;
}


