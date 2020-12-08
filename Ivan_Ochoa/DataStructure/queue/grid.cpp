#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

bool valido(int i, int j, int n, int m){
    return (i >= 0 && j >= 0 && i < n && j < m  );
}


int main(){

    int n = 8;
    int m = 8;

    int initial_row = 5;
    int initial_col = 3;

    vector < vector<int> > matrix( n , vector<int> (m, -1));

    queue < pair<int,int> > Q;

    pair<int,int> aux = {initial_row, initial_col};

    Q.push(aux);
    matrix[initial_row][initial_col] = 0;

    int di[4] = {-1,1,0,0};
    int dj[4] = {0,0,-1,1};

    while(!Q.empty()){

        pair<int,int> aux = Q.front();
        Q.pop();
    /*
        //Norte
        if(valido(aux.first-1, aux.second, n, m) && matrix[aux.first-1][aux.second] == -1){
            matrix[aux.first-1][aux.second] = matrix[aux.first][aux.second] + 1;
            Q.push({aux.first-1, aux.second});
        }
        //Sur
        if(valido(aux.first+1, aux.second, n, m) && matrix[aux.first+1][aux.second] == -1){
            matrix[aux.first+1][aux.second] = matrix[aux.first][aux.second] + 1;
            Q.push({aux.first+1, aux.second});
        }
        //Oeste
        if(valido(aux.first, aux.second-1, n, m) && matrix[aux.first][aux.second-1] == -1){
            matrix[aux.first][aux.second-1] = matrix[aux.first][aux.second] + 1;
            Q.push({aux.first, aux.second-1});
        }
        //Este
        if(valido(aux.first, aux.second+1, n, m) && matrix[aux.first][aux.second+1] == -1){
            matrix[aux.first][aux.second+1] = matrix[aux.first][aux.second] + 1;
            Q.push({aux.first, aux.second+1});
        }
    */

        for(int p = 0; p < 4; ++p){
            if(valido(aux.first+di[p], aux.second+dj[p], n, m) && matrix[aux.first+di[p]][aux.second+dj[p]] == -1){
                matrix[aux.first+di[p]][aux.second+dj[p]] = matrix[aux.first][aux.second] + 1;
                Q.push({aux.first+di[p], aux.second+dj[p]});
            }
        }

    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            cout<<matrix[i][j]<<" ";
        } cout<<endl;
    }



    return 0;
}