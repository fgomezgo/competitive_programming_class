#include <iostream>
#include <list>

using namespace std;

void print_list(list <int> L){

    list <int> :: iterator it;

    for(it = L.begin(); it != L.end(); ++it){
        cout << *it << " ";
    } cout<<endl;
}

int main(){

    list <int> L;
    L.push_back(11);
    L.push_back(3);
    L.push_back(201);

    //11 -> 3 -> 201
    list <int> :: iterator it, it2;

    for(it = L.begin(); it != L.end(); ++it){
        cout << *it << " ";
    } cout<<endl;

    L.push_front(5);
    //5 -> 11 -> 3 -> 201

    //5 -> 11 -> 4 -> 3 -> 201
    int i = 0;
    int pos = 2;
    for(it = L.begin(); it != L.end(); ++it){
        if(i == pos){
            it2 = L.insert(it, 4);
        }
        ++i;
    }

    print_list(L);

    it2 = L.insert(it2, 66);

    print_list(L);

    ++it2;
    it2 = L.insert(it2, 88);
    print_list(L);

    int val = 3;
    for(it = L.begin(); it != L.end(); ++it){
        if(*it == val){
            ++it;
            it2 = L.insert(it, 69);
            break;
        }
    }

    print_list(L);

    it2 = L.erase(it2);

    print_list(L);

    it2 = L.insert(it2,43);

    print_list(L);

    --it2;
    it2 = L.insert(it2,51);

    print_list(L);

    L.insert(L.end(), 22);
    print_list(L);

    L.insert(L.begin(), 22);
    print_list(L);
    

    return 0;
}
