#include<iostream>
#include<vector>
#include<stack>
using namespace std;

struct Node{
    int val, L, R, P, h;
};

bool find(int node, int val, vector <Node> AVL){
    if(node == -1){
        return false;
    }

    if(AVL[node].val == val){
        return true;
    }

    if(AVL[node].val < val){
        return find(AVL[node].R, val, AVL);
    }

    return find(AVL[node].L, val, AVL);
}

int diff_h(int node, vector <Node> AVL){

    //Preguntar alturas de hijos
    int hR = (AVL[node].R != -1)? AVL[AVL[node].R].h : 0;
    int hL = (AVL[node].L != -1)? AVL[AVL[node].L].h : 0;
    //Diferencia de alturas
    int diff = hR - hL;

    return diff;
}
//Checar si es necesaria una rotacion
void rot_check(int node, vector <Node> AVL){

    int diff = diff_h(node, AVL);

    if(diff > 1){
        //Rotacion izquierda o rotacion doble a la izquerda
        if(diff_h(AVL[node].R, AVL) == -1){
            rotR(AVL[node].R, AVL);
        }
        rotL(node, AVL);
    }

    if(diff < -1){
        //Rotacion derecha o rotacion doble a la derecha
        if(diff_h(AVL[node].L, AVL) == 1){
            rotL(AVL[node].L, AVL);
        }
        rotR(node, AVL);
    }
}

void insert(int node, int val, vector <Node> AVL, stack <int> S){

    if(AVL[node].val == val){
        return;
    }

    if(AVL[node].val < val){
        //Voy a insertar val como hijo derecho del nodo actual
        if(AVL[node].R == -1){
            //Pedir nueva memoria
            int new_idx = S.top();
            S.pop();
            //Asignar nuevo hijo
            AVL[node].R = new_idx;
            //Actualizar altura del nodo
            if(AVL[node].L == -1){
                AVL[node].h = 2;
            }
            //Actualizar valores del nuevo hijo
            AVL[new_idx].val = val;
            AVL[new_idx].R = -1;
            AVL[new_idx].L = -1;
            AVL[new_idx].P = node;
            AVL[new_idx].h = 1;
        } else{
            insert(AVL[node].R, val, AVL, S);
            //Checar rebalanceo

            //rot_check(node, AVL);
        }
    } else {
        //Voy a insertar val como hijo derecho del nodo actual
        if(AVL[node].L == -1){
            //Pedir nueva memoria
            int new_idx = S.top();
            S.pop();
            //Asignar nuevo hijo
            AVL[node].L = new_idx;
            //Actualizar altura del nodo
            if(AVL[node].R == -1){
                AVL[node].h = 2;
            }
            //Actualizar valores del nuevo hijo
            AVL[new_idx].val = val;
            AVL[new_idx].R = -1;
            AVL[new_idx].L = -1;
            AVL[new_idx].P = node;
            AVL[new_idx].h = 1;
        } else{
            insert(AVL[node].L, val, AVL, S);

            //rot_check(node, AVL);
        }
    }
    return;
}



int main(){

    int N = 100;

    //Memoria
    vector <Node> AVL(N);
    //Memory manager
    stack  <int> S;

    for(int i = 0; i < N; ++i){
        S.push(i);
    }

    int root = -1;

    find(root, val, AVL);
    insert(root, val, AVL, S);




    return 0;
}