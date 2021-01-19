#include <iostream>
#include <utility>
#include <vector>
#include <stack>
using namespace std;
 
 
 
int main(){
 
    int n,m,a,b,result = 0;
    bool flag = true;
    stack <int> aux;
    
    vector <pair <int,int> > kids_pairs;
 
    //input
    cin >> n;
    cin >> m;
 
    vector <int> kids (n);
 
    for(int i = 0; i < m; i++){
        cin >> a >> b;
        kids_pairs.push_back({a-1,b-1});
        kids[a-1]++;
        kids[b-1]++;
    }
 
    //algoritmo
    while(flag){
        for (int i = 0; i < n ; i++)
        {
            if(kids[i] == 1){
                aux.push(i);
            }
        }
 
        if (aux.empty()){
            flag = false;
            break;
        }
        
        while (!aux.empty())
        {    
            for (int i = 0; i < m; i++)
            {
                if(aux.top() ==  kids_pairs[i].first || aux.top() == kids_pairs[i].second){
                    kids[kids_pairs[i].first]--;
                    kids[kids_pairs[i].second]--;
                    kids_pairs[i] = {0,0};
                }
            }
            aux.pop();
        }
 
        result++;
    }
    
    cout << result << endl;
 
 
    return 0;
}