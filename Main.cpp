#include "stdio.h"
#include "iostream"
#include "string.h"
#include "cstring"
using namespace std;

struct Nodo{
    string mes;
    int peso;
    Nodo *l;
    Nodo *r;
};

int calcularPeso(string mes);

struct Nodo* nuevoNodo(string mes){
    struct Nodo* nodo = new struct Nodo;
    nodo->mes = mes;
    nodo->peso = calcularPeso(mes);
    nodo->l = NULL;
    nodo->r = NULL;
    return nodo;
}


int obtenerAltura(Nodo* root);
int obtenerFactorBalance(Nodo* root);

void recorrerPreOrder(Nodo* root); // RID

void LL(Nodo* root);
Nodo* RR(Nodo* root); 
void LR(Nodo* root);
void RL(Nodo* root);

void insertarAVL(Nodo* root, string mes);

void recorrerInOrder(Nodo* root); // IRD
void recorrerPostOrder(Nodo* root); // IDR

int main(){

    string meses[12]={"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};
    for(int i=0;12>i;i++){
        int x= calcularPeso(meses[i]);
        //crear nodo con estos datos
        cout<<x<<endl;
    }

    //Arbol de prueba para las funciones de recorrer
    /* tree
            En
            /  \
        Feb     Mar
        /   \
       Abr  May
    */
    struct Nodo* Root = nuevoNodo("Enero");
    Root->r = nuevoNodo("Febrero"); Root->r->r = nuevoNodo("Marzo");
    //Root->l->l = nuevoNodo("Abril"); Root->l->r = nuevoNodo("Mayo");

    Root = RR(Root);

    cout<<"Pre Order (RID): ";recorrerPreOrder(Root);cout<<endl;
    cout<<"In Order (IRD): ";recorrerInOrder(Root);cout<<endl;
    cout<<"Post Order (IDR): ";recorrerPostOrder(Root);cout<<endl;

    Nodo* root = nuevoNodo("");
    cout<<root->peso<<endl;
    insertarAVL(root, "Enero");
    cout<<root->peso<<endl;
    insertarAVL(root, "Febrero");
    //insertarAVL(root, "Marzo");
    cout<<"Pre Order (RID): ";recorrerPreOrder(root);cout<<endl;
    return 0;
};

int calcularPeso(string mes){
    int valor=0;
    char abecedario[27]= {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z','\0'};
    char part[mes.size()+1];
    strcpy(part,mes.c_str()); //copia la string a el  array "part"
    for(int i=0; i<mes.size(); i++){
        //según busqué, la mejor forma de hacer esto es con busqueda binaria, pero para eso la lista debe ser distinta
        for(int j=0; j<26;j++){
            if(tolower(part[i])==abecedario[j]){
                valor+=j+1;
                break;
            }
        }
    }
    return valor;
}

int obtenerAltura(Nodo* root){
    if(root == NULL){
        return 0;
    }
    
    int hl = obtenerAltura(root->l);
    int hr = obtenerAltura(root->r);

    if(hl>=hr){
        return hl+1;
    }
    return hr+1;
};

int obtenerFactorBalance(Nodo* root){
    return obtenerAltura(root->l) - obtenerAltura(root->r);
};

void LL(Nodo* root){
    Nodo* aux = root->l->r;
    root->l->r = root;
    root->l = aux;
};

Nodo* RR(Nodo* root){
    Nodo* newRoot = root->r;

    Nodo* aux = root->r->l;
    root->r->l = root;
    root->r = aux;

    return newRoot;
};

void LR(Nodo* root){
    RR(root->l);
    LL(root);
};

void RL(Nodo* root){
    LL(root->r);
    RR(root);
};

void insertarAVL(Nodo* root, string mes){
    Nodo* nodo = nuevoNodo(mes);
    if(root->mes == "" || root->peso == 0){
        *root = *nodo;
        return;
    }
    if(root->peso > nodo->peso){
        if(root->l){
            insertarAVL(root->l, mes);
        }else{
            root->l = nodo;
        }
    }
    if(root->peso < nodo->peso){
        if(root->r){
            insertarAVL(root->r, mes);
        }else{
            root->r = nodo;
        }
    }

    int FB = obtenerAltura(root->l) - obtenerAltura(root->r);

    if(FB > 1 && obtenerFactorBalance(root->l) == 1){
        LL(root);
    }
    if(FB > 1 && obtenerFactorBalance(root->l) == -1){
        LR(root);
    }
    if(FB < -1 && obtenerFactorBalance(root->r) == -1){
        //root = RR(root);
    }
    if(FB < -1 && obtenerFactorBalance(root->r) == 1){
        RL(root);
    }

};

void recorrerPreOrder(Nodo* root){
    cout<<root->mes<<"(";
    cout<<root->peso<<") ";
    if(root->l){
        recorrerPreOrder(root->l);
    }
    if(root->r){
        recorrerPreOrder(root->r);
    }

};

void recorrerInOrder(Nodo* root){
    if(root->l){
        recorrerInOrder(root->l);
    }
    cout<<root->mes<<"(";
    cout<<root->peso<<") ";
    if(root->r){
        recorrerInOrder(root->r);
    }

};

void recorrerPostOrder(Nodo* root) {
    if (root->l) {
        recorrerPostOrder(root->l);
    }
    if (root->r) {
        recorrerPostOrder(root->r);
    }
    cout<<root->mes<<"(";
    cout<<root->peso<<") ";
};
