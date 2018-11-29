#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;


struct Nodo{
    int dato;
    Nodo *izquierda;
    Nodo *derecha;
 
}*aux,*arbol=NULL;
Nodo *crearNodo(int);


void mostrarArbol(Nodo *,int);
void insertarNodo(Nodo *&,int,int);
int main(){
    srand(time(NULL));
    int cara,aguila=0,sol=0,cont=0;
    int veces,p=0;
    int arreglo1[100],arreglo2[100],po1,po2,po3;
    cout << "Cuantas veces desea lanzar la moneda: ";
    cin >> veces;
    cout << endl;
    for(int j=0; j<=veces-1; j++){
        for(int i=0; i<=99; i++){
            cara = 1 + rand()%2;
         cout << cara << " ";
         if(cara==1){
            aguila++;
        //
         }else if(cara==2){
             sol++;
       //
         }
    }
    arreglo1[p]=aguila;
    arreglo2[p]=sol;
    cout << endl;
    p++;
   }

   for(int l=0; l<p; l++){
    cout << arreglo1[l] << ",";
   }
   insertarNodo(arbol,0,0);
        cout << endl;
   for(int l=0; l<p; l++){
    insertarNodo(arbol,arreglo1[l],1);
    insertarNodo(arbol,arreglo2[l],2);
   }

   cout <<"Aguila:" << aguila<< endl;
   cout <<"Sol:" << sol<< endl;;
   cout << endl;
   mostrarArbol(arbol,cont);


    return 0;
}


void mostrarArbol(Nodo *arbol, int cont){
    if(arbol==NULL){
        return;
    }
    else{
        mostrarArbol(arbol->derecha, cont+1);
        for(int i=1; i<cont; i++)
        {
            cout << "-";
        }
        cout << arbol->dato << endl;
        mostrarArbol(arbol->izquierda, cont+1);
    }
}

Nodo *crearNodo(int n){
    Nodo *nuevo_nodo= new Nodo();

    nuevo_nodo->dato=n;
    nuevo_nodo->derecha=NULL;
    nuevo_nodo->izquierda=NULL;

    return nuevo_nodo;

}

void insertarNodo(Nodo *&arbol, int n,int valor){
    if(arbol==NULL){
        Nodo *nuevo_nodo=crearNodo(n);
        arbol=nuevo_nodo;
    }
    else{
        int valorRaiz= arbol->dato;
        if(n!=valorRaiz){
            if(valor==1){
                insertarNodo(arbol->izquierda,n,valor);
            }
            else{
                insertarNodo(arbol->derecha,n,valor);
            }
        }
    }

}
