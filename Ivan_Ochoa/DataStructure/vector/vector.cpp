#include <iostream>  //Inputs outputs cin, cout, leer e imprimir variables en consola
#include <vector>
using namespace std; //namespace de la STL de c++

void print_v(vector <int> b){

    for(int i = 0; i < b.size(); ++i){
        cout<<b[i]<<" ";
    }
    cout<<endl;
}

int main(){

    //int a,b;
    //cin>>a>>b;
    //scanf("%d %d",&a,&b);

    vector <int> b(5); 
    print_v(b);
    b[0] = 1;
    b[1] = 2;
    b[2] = 3;
    b[3] = 4;
    b[4] = 5;

    cout<<b[3]<<endl;
    b[3] = 52;
    cout<<b[3]<<endl;

    b.push_back(34);
    cout<<b[5]<<endl;
    b.resize(10);
    print_v(b);

    b.resize(8);
    print_v(b);

    b.pop_back();
    print_v(b);
    vector <int>::iterator it = b.begin();
    
    it = it + 3;
    b.insert(it,5,11);
    print_v(b);
    it = b.end();
    it -= 3;
    b.erase(it);
    print_v(b);

    for(it = b.begin(); it < b.end(); ++it){
        cout<<*it<<" ";
    } cout<<endl;

    return 0;
}