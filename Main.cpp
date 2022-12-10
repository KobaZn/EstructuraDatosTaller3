#include "stdio.h"
#include "iostream"
#include "string.h"
#include "cstring"
using namespace std;




/*
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

struct Node
{
    string mes;
    int altura;
    int peso;
    Node *l, *r;
    Node(string mes) : mes(mes), peso(calcularPeso(mes)), altura(0),l(nullptr), r(nullptr){};

};

Node *left(Node *n)
{
    return n->l;
}
Node *right(Node *n)
{
    return n->r;
}

int altura(Node *n)
{
    if(!n)
    {
        return -1;
    } else
    {
        return n->altura;
    }
}

void actualizarAltura(Node *n)
{
    if(n)
    {
        n->altura = max(altura(n->l), altura(n->r)) +1;


    }
}

void rotar_s (Node **n, bool izq)
{
    cout<<"ROTACIÓN SIMPLE"<<endl;
    Node *n1;
    //Rotación izquierda
    if(izq)
    {
        n1 = left(*n);
        (*n)->l = right(n1);
        n1->r = *n;
    }
    else //Rotacion derecha
    {
        cout<<"b"<<endl;
        cout<<(*n)->mes<<endl;
        n1 = right(*n);

        cout<<"a"<<endl;
        (*n)->r = left(n1);
        cout<<"c"<<endl;
        n1->l = *n;
    }
    cout<<"a"<<endl;
    actualizarAltura(*n);
    actualizarAltura(n1);

    //cambio de raiz
    *n = n1;
}

void rotar_d(Node **n, bool izq)
{
    cout<<"ROTACIÓN DOBLE"<<endl;
    cout<<(*n)->mes<<endl;
    cout<<endl;
    if(izq)   //Rotación hacia la izquierda
    {
        cout<<"Hacia la izquierda"<<endl;
        rotar_s(&(*n)->l,false);
        rotar_s(n,true);
    }
    else  //Rotación pa la derecha
    {
        cout<<"Hacia la derecha"<<endl;
        rotar_s (&(*n)->r, true);
        rotar_s(n, false);
    }

};

int obtenerFactorBalance(Node* root) {
    return altura(root->l) - altura(root->r);
}

void balancear(Node **n)
{

    if(*n)
    {
        cout<<altura(left(*n)) - altura(right(*n))<<endl;
        cout<<endl;
        int factor = obtenerFactorBalance(*n);

        switch (factor) {

            case 2:
                cout<<"BALANCEO"<<endl;
                if(obtenerFactorBalance((*n)->l) == 1)
                {
                    rotar_s(n,true);    //Desequilibro simple hacia la izq
                }
                else
                {
                    rotar_d(n, true);  //Desequilibrio doble hacia la izquierda
                }
                break;

            case (-2):
                cout<<"BALANCEO"<<endl;

                // if (altura ((*n)->r->r) >= altura ((*n)->r->l)) //Desequilibrio simple hacia la izq

                if(obtenerFactorBalance((*n)->r) == -1)
                {
                    rotar_s(n, false);
                }
                else  //desequilibrio doble hacia la izq
                {
                    rotar_d(n, false);
                }
                break;


        }
    }
}

void recorrerPreOrder(Node* root){
    cout<<root->mes<<"(";
    cout<<root->peso<<") ";
    if(root->l){
        recorrerPreOrder(root->l);
    }
    if(root->r){
        recorrerPreOrder(root->r);
    }

};

void insertar (Node **n, string mes)
{
    if((*n) == nullptr)
    {
        *n = new Node(mes);
        return;

    }

    int peso = calcularPeso(mes);
    cout<<"Peso mes "<<(peso);
    cout<<", Peso nodo "<<(*n)->peso<<endl;

    if(peso == (*n)->peso)
    {

        insertar(&(*n)->r,mes + "a");
    }
    else
    {
        if(peso < (*n)->peso)
        {

            insertar(&(*n)->l,mes);
        }
        else{
            insertar(&(*n)->r,mes);
        }
    }

    balancear(n);
    actualizarAltura(*n);


}
int main() {
    cout<<"Insercion Enero"<<endl;
    Node *r = new Node("enero");

    cout<<"Insercion Febrero"<<endl;
    insertar(&r, "febrero");

    cout<<"Insercion Marzo"<<endl;
    insertar(&r, "Marzo");

    cout<<"Insercion abril"<<endl;
    insertar(&r, "abril");

    cout<<"insercion mayo"<<endl;
    insertar(&r, "Mayo");

    cout<<"insercion junio"<<endl;
    insertar(&r, "Junio");

    cout<<"insercion julio"<<endl;
    insertar(&r, "Julio");

    cout<<"insercion agosto"<<endl;
    insertar(&r, "agosto");

    cout<<"insercion septiembre"<<endl;
    insertar(&r, "septiebre");

    cout<<"insercion octubre"<<endl;
    insertar(&r, "octubre");

    cout<<"insercion noviembre"<<endl;
    insertar(&r, "noviembre");

    cout<<"insercion diciembre"<<endl;
    insertar(&r, "diciembre");

    recorrerPreOrder(r);

    return 0;
}
*/



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

void LL(Nodo* *root);
void RR(Nodo* *root); 
void LR(Nodo* *root);
void RL(Nodo* *root);

void insertarAVL(Nodo* *root, string mes, int peso);

void recorrerInOrder(Nodo* root); // IRD
void recorrerPostOrder(Nodo* root); // IDR

int main(){

    //Mostrar pesos de cada mes
    cout<<"Pesos"<<endl;
    string meses[12]={"ENERO","FEBRERO","MARZO","ABRIL","MAYO","JUNIO","JULIO","AGOSTO","SEPTIEMBRE","OCTUBRE","NOVIEMBRE","DICIEMBRE"};
    for(int i=0;12>i;i++){
        int x= calcularPeso(meses[i]);
        //crear nodo con estos datos
        cout<<meses[i]<<": "<<x<<endl;
    }
    cout<<endl<<endl;

    //Crear Raiz del Arbol
    Nodo* root = nuevoNodo("");

    //Insertar
    insertarAVL(&root, "Enero", 0);
    insertarAVL(&root, "Febrero", 0);
    insertarAVL(&root, "Marzo", 0);
    insertarAVL(&root, "Abril", 0);
    insertarAVL(&root, "Mayo", 0);
    insertarAVL(&root, "Junio", 0);
    insertarAVL(&root, "Julio", 0);
    insertarAVL(&root, "Agosto", 0);
    insertarAVL(&root, "Septiembre", 0);
    insertarAVL(&root, "Octubre", 0);
    insertarAVL(&root, "Noviembre", 0);
    insertarAVL(&root, "Diciembre", 0);
    
    //Imprimir recorridos
    cout<<"Pre Order (RID): ";recorrerPreOrder(root);cout<<endl<<endl;
    cout<<"In Order (IRD): ";recorrerInOrder(root);cout<<endl<<endl;
    cout<<"Post Order (IDR): ";recorrerPostOrder(root);cout<<endl<<endl;
    
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

void LL(Nodo* *root){
    Nodo* newRoot = (*root)->l;

    Nodo* aux = (*root)->l->r;
    (*root)->l->r = *root;
    (*root)->l = aux;

    *root = newRoot;//actualiza la raíz
};

void RR(Nodo* *root){
    Nodo* newRoot = (*root)->r;

    Nodo* aux = (*root)->r->l;
    (*root)->r->l = *root;
    (*root)->r = aux;

    *root = newRoot;//actualiza la raíz
};

void LR(Nodo* *root){
    RR( &( (*root)->l ) );
    LL(root);
};

void RL(Nodo* *root){
    LL( &( (*root)->r ) );
    RR(root);
};

//root = raiz del arbol a insertar
//mes = nombre del mes 
//usar peso = 0 para calcularo segun calcularPeso(), sino especificar el peso
void insertarAVL(Nodo* *root, string mes, int peso){
    Nodo* nodo = nuevoNodo(mes);
    //si es el arbol está vacío
    if((*root)->mes == "" || (*root)->peso == 0){
        *(*root) = *nodo;
        return;
    }

    //si el peso no es el por defecto
    if(peso != 0){
        nodo->peso = peso;
    }

    //si el peso es igual a la raiz
    if((*root)->peso == nodo->peso){
        nodo->peso--;
        peso = nodo->peso;
    }

    //si es el peso menor a la raíz
    if((*root)->peso > nodo->peso){
        if((*root)->l){
            insertarAVL(&((*root)->l), mes, peso);
        }else{
            (*root)->l = nodo;
        }
    }
    //si es el peso mayor a la raíz
    if((*root)->peso < nodo->peso){
        if((*root)->r){
            insertarAVL(&((*root)->r), mes, peso);
        }else{
            (*root)->r = nodo;
        }
    }

    //Luego de añadir, balancear
    int FB = obtenerAltura((*root)->l) - obtenerAltura((*root)->r);

    if(FB > 1 && obtenerFactorBalance((*root)->l) == 1){
        LL(root);
    }
    if(FB > 1 && obtenerFactorBalance((*root)->l) == -1){
        LR(root);
    }
    if(FB < -1 && obtenerFactorBalance((*root)->r) == -1){
        RR(root);
    }
    if(FB < -1 && obtenerFactorBalance((*root)->r) == 1){
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
