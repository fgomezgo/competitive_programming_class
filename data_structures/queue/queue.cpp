#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue <int> S;


    S.push(74);
    S.push(23);
    S.push(98);
    S.push(76);

    cout<<S.front()<<endl;
    S.pop();
    cout<<S.front()<<endl;
    S.push(78);
    cout<<S.front()<<endl;

    //Procesar todos los elementos de la cola
    while(!S.empty()){
        cout<<S.front()<<endl;
        S.pop();
    }

    cout<<endl<<endl;
    S.push(74);
    S.push(23);
    S.push(98);
    S.push(76);

    while(!S.empty()){
        cout<<S.front()<<endl;
        S.pop();
    }
    
    return 0;
}