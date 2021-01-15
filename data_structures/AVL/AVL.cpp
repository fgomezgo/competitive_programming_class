#include<iostream>
#include<vector>
#include<stack>
#include<utility>
using namespace std;


//Scope Global
struct Node{
    int val, L, R, P, h;

    Node(){}

    Node(int _val, int _L, int _R, int _P, int _h){
        val = _val;
        L   = _L;
        R   = _R;
        P   = _P;
        h   = _h;
    }

};

int root = -1;

int N = 100;

//Memoria
vector <Node> AVL(N);
//Memory manager
stack  <int> S;


int find(int node, int val){

    if(node == -1){
        return -1;
    }

    cout<<AVL[node].val<<endl;

    if(AVL[node].val == val){
        return node;
    }

    if(AVL[node].val < val){
        return find(AVL[node].R, val);
    }

    return find(AVL[node].L, val);
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
/*
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
*/

void insert(int node, int val){

    //Caso para el nodo raiz
    if(node == -1){
        //Pedir nueva memoria
        int new_idx = S.top();
        S.pop();
        //Asignar Raiz
        AVL[new_idx] = Node(val,-1,-1,-1,1);
        root = new_idx;
        return;
    }
 
    //Caso en el que el valor ya existe (se ignora)
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
            AVL[new_idx] = Node(val,-1,-1,node,1);
            
        } else{
            insert(AVL[node].R, val);
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
            AVL[new_idx] = Node(val,-1,-1,node,1);
            
        } else{
            insert(AVL[node].L, val);

            //rot_check(node, AVL);
        }
    }
    return;
}

//Recorrido del arbol en orden
//primero imprimo hijos izquierdos, de ahi me imprimo a mi, y de ahi imprimo a mis hijos derechos
// (   )()(   )
// ( )(5)( () (10) ( (  () (55) ( () (69) () ) ) (99) () ))
void inorder_traversal(int node){

}


//Recorrido del arbol en donde me visito primero a mi, y luego a mis hijos
//Nodo , descendencia izq, descendencia der
// ( 5 () ( 10 () ( 99 (55 () (69) ) () ) ) )
void postorder_traversal(int node){

    //Cuando el arbol esta vacio
    if(node == -1){
        cout<<"( )";
        return;
    }

    cout<<AVL[node].val<<" ";

    cout<<" ( ";
    if(AVL[node].L != -1){
        postorder_traversal(AVL[node].L);
    }
    cout<<" ) ";

    cout<<" ( ";
    if(AVL[node].R != -1){
        postorder_traversal(AVL[node].R);
    }
    cout<<" ) ";
}

//Primer valor es la direccion de memoria (node)
int get_predecessor(int node, int val){
    return 0;
}

void erase(int node, int val){

    //Localidad del nodoe que vamos a borrar
    int val_node = find(node, val);

    if(val_node == -1){
        return;
    }
    //Mi nodo a borrar es una hoja
    if(AVL[val_node].R == -1 && AVL[val_node].L == -1){
        //Liberar espacio del stack
        S.push(val_node);

        //Le decimos al padre que su hijo ya no existe
        //Saber que hijo era
        int parent = AVL[val_node].P;

        //Si borramos la raiz
        if(parent == -1){
            root = -1;
        }

        if(AVL[parent].L == val_node){
            AVL[parent].L = -1;
        } else{
            AVL[parent].R = -1;
        }
    }

    //Cuando solo hay  un hijo


    //Cuando tiene los 2
    //get predecessor


}



int main(){


    for(int i = 0; i < N; ++i){
        S.push(i);
    }


    insert(root, 5);
    postorder_traversal(root); cout<<endl;
    insert(root, 10);
    postorder_traversal(root); cout<<endl;
    insert(root, 99);
    postorder_traversal(root); cout<<endl;
    insert(root, 55);
    postorder_traversal(root); cout<<endl;
    insert(root, 69);
    postorder_traversal(root); cout<<endl;
    insert(root, 3);
    postorder_traversal(root); cout<<endl;
    insert(root, 3);
    postorder_traversal(root); cout<<endl;
    insert(root, 69);
    postorder_traversal(root); cout<<endl;

    cout<<find(root, 69)<<endl;
    cout<<find(root, 50)<<endl;

    erase(root, 69);
    postorder_traversal(root); cout<<endl;
    insert(root, 68);
    postorder_traversal(root); cout<<endl;

    /*

    erase(root, 69);
    postorder_traversal(root); cout<<endl;
    erase(root, 55);
    postorder_traversal(root); cout<<endl;
    erase(root, 99);
    postorder_traversal(root); cout<<endl;
    erase(root, 10);
    postorder_traversal(root); cout<<endl;
    erase(root, 3);
    postorder_traversal(root); cout<<endl;
    erase(root, 5);
    postorder_traversal(root); cout<<endl;
    */

    




    return 0;
}