#include <iostream>
using namespace std;
int arr[100];

int fib(int n){
    cout<<"estado: "<<n<<endl;
    //Si el estado ya esta calculado, devuelvemelo
    if(arr[n] != 0){
        return arr[n];
    }
    if(n <= 1){
        return arr[n] = 1;
    }
    return arr[n] = fib(n-1) + fib(n-2);
}


int main(){
    int n;
    cin>>n;

    //cout<<fib(n)<<endl;

    //Iterativo
    arr[0] = 1;
    arr[1] = 1;
    //Orden: menor a mayor :D
    for(int i = 2; i <= n; ++i){
        arr[i] = arr[i-1]+arr[i-2];
    }
    cout<<arr[n]<<endl;




    return 0;
}