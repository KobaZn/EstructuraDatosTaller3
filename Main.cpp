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
void recorrerPreOrder(Nodo* root); // RID
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

    Nodo a,b,c,d,e,f,g,h,i,j;
    a.peso = 100;
    b.peso = 50; c.peso = 51;
    d.peso = 25; e.peso = 26; f.peso = 27; g.peso = 28;
    h.peso = 15; i.peso = 10; j.peso = 15;

    a.l = &b; a.r = &c;
    b.l = &d; b.r = &e; c.l = &f; c.r = &g;
    d.l = NULL; d.r = NULL; e.l = NULL; e.r = NULL; f.l = NULL; f.r = NULL; g.l = NULL; g.r = NULL;
    //d.l = &h; d.r = &i; e.l = &j; e.r = NULL; f.l = NULL; f.r = NULL; g.l = NULL; g.r = NULL;
    //h.l = NULL; h.r = NULL; i.l = NULL; i.r = NULL; j.l = NULL; j.r = NULL;

    Nodo *root = &a;

    recorrerPreOrder(root);
    cout<<endl;
    recorrerInOrder(root);
    cout<<endl;
    recorrerPostOrder(root);

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

void recorrerPreOrder(Nodo* root){
    cout<<root->peso<<" ";
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
    cout<<root->peso<<" ";
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
    cout << root->peso << " ";
};
