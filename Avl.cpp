#include <iostream>
using namespace std;

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

struct Nodo{
    string mes;
    int peso;
    Nodo *l;
    Nodo *r;
    Nodo *p;


};
