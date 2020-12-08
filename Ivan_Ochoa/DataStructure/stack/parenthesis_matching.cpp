#include <iostream>
#include <stack>
#include <string>
using namespace std;


string valido(string p){

    stack <char> S;

    for (int i = 0; i < p.size(); ++i){
        if(p[i] == '('){
            S.push(p[i]);
        } else{
            if(!S.empty()){
                S.pop();
            } else{
                return "invalido";
            }
        }
    }

    if(!S.empty()){
        return "invalido";
    }

    return "valido";
}


int main(){

    string p = "((()(()))())";
 
    stack <char> S;

    bool flag = true;

    for (int i = 0; i < p.size(); ++i){
        if(p[i] == '('){
            S.push(p[i]);
        } else{
            if(!S.empty()){
                S.pop();
            } else{
                cout<<"invalido"<<endl;
                flag = false;
                break;
            }
        }
    }

    if(flag){
        if(!S.empty()){
            cout<<"invalido"<<endl;
        } else {
            cout<<"valido"<<endl;
        }
    }

    cout<<valido(p)<<endl;

    return 0;
}