#include <iostream>
#include <stack>
using namespace std;

int main(){
    stack <int> S;


    S.push(74);
    S.push(23);
    S.push(98);
    S.push(76);

    cout<<S.top()<<endl;
    S.pop();
    cout<<S.top()<<endl;
    S.push(7);
    cout<<S.top()<<endl;
    S.pop();
    cout<<S.top()<<endl;
    S.pop();
    cout<<S.top()<<endl;

    while(!S.empty()){
        cout<<S.top()<<endl;
        S.pop();
    }



    cout<<endl<<endl;
    S.push(74);
    S.push(23);
    S.push(98);
    S.push(76);

    while(!S.empty()){
        cout<<S.top()<<endl;
        S.pop();
    }

    return 0;
}