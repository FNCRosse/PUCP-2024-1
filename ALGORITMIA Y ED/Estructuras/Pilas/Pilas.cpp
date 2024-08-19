#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct NodoPila {
    int valor;
    struct NodoPila *ptrSig; //estructura auto-referenciada
} TNodoPila;

typedef TNodoPila* Tpila;

void crear(Tpila* ptrpila) {
    *ptrpila = NULL;
}

void push(Tpila* Pila, int valor) {
    TNodoPila* ptrNuevo;
    ptrNuevo = new TNodoPila;
    
    ptrNuevo->valor = valor;
    ptrNuevo->ptrSig = *Pila;
    *Pila = ptrNuevo;
}

bool pila_vacia(Tpila* ptrPila) {
    return *ptrPila == NULL;
}

void top(Tpila* ptrPila) {
    TNodoPila* ptrrec;
    ptrrec = *ptrPila;
    if (pila_vacia(ptrPila))
        cout << "Pila vacia" << endl;
    else
        cout << ptrrec->valor << endl;
}

int pop(Tpila* Pila) {
    TNodoPila* ptrEliminar;
    int valor;
    if (!pila_vacia(Pila)) {
        ptrEliminar = *Pila;
        valor = ptrEliminar->valor;
        *Pila = ptrEliminar->ptrSig;
        free(ptrEliminar);
    }
    return valor;
}

void finalizar(Tpila ptrPila) {
    TNodoPila* ptrEliminar;
    ptrEliminar = ptrPila;
    while (ptrEliminar != NULL) {
        ptrPila = ptrEliminar->ptrSig;
        delete ptrEliminar;
        ptrEliminar = ptrPila;
    }
}

void cambia(Tpila ptrPila, int n) {
    ptrPila->valor = n;
}

void imprimepila(Tpila ptrpila) {
    while (ptrpila != NULL) {
        cout << ptrpila->valor << " ";
        ptrpila = ptrpila->ptrSig;
    }
}

void imprimepila2(Tpila ptrPila) {
    Tpila ptraux;
    if (ptrPila == NULL)
        return;
    ptraux = ptrPila;
    ptrPila = ptrPila->ptrSig;
    imprimepila(ptrPila);
    cout << ptraux->valor << " ";
}

int main() {
    Tpila ptrPila;
    crear(&ptrPila);
    top(&ptrPila);
    push(&ptrPila, 19);
    push(&ptrPila, 18);
    push(&ptrPila, 17);
    push(&ptrPila, 20);
    imprimepila(ptrPila);
    cout << endl;
    cout << "Desapila:" << pop(&ptrPila) << endl;
    cout << "Desapila:" << pop(&ptrPila) << endl;
    cout << "Top:";
    top(&ptrPila);
    imprimepila(ptrPila);
    finalizar(ptrPila);
    return (0);
}

