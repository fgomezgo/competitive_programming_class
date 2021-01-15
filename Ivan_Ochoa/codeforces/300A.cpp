#include<iostream>
#include<vector>
using namespace std;

void printResult(int first, vector <int> second, vector <int> tirth){
    int aux;
    cout << 1 << ' ' << first << endl;

    cout << second.size() << ' ';
    for(aux = 0; aux < second.size(); aux++)
        cout << second[aux] << " ";

    cout << endl;


    cout << tirth.size() << ' ';
    for(aux = 0; aux < tirth.size(); aux++)
        cout << tirth[aux] << " ";

    cout << endl; 

}


int main (){
    int nSize,aux;
    vector <int>n; 
    vector <int> second, tirth;
    int first = 0;

    cin >> nSize;

    for(int i = 0; i<nSize; i++){
        cin  >> aux;
        n.push_back(aux);
    }

    for(int i = 0; i < n.size(); i++){
        if(n[i] <= 0 ){
            if (n[i] < 0 && first == 0)
                first = n[i];
            else
                tirth.push_back(n[i]);
            continue;
        }
        second.push_back(n[i]);
    }

printResult(first,second,tirth);

    if(second.empty()){
        for(int i = tirth.size() - 1; i >= 0; i--){
            if (tirth[i] < 0){
                second.push_back(tirth[i]);
                if(tirth.back() == 0){
                    tirth.pop_back();
                    tirth.pop_back();
                    

            }
            if(second.size() == 2)
                break;

        }
    }


    printResult(first,second,tirth);
    return 0;
}