/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 18 de septiembre de 2023, 05:39 PM
 */

#include <iostream>
#include <cstdlib>
#include "ArbolBinario.h"
using namespace std;
#include "funcionesArbolesBinarios.h"
/*
 * 
 */
int main(int argc, char** argv) {

    /*Post Fijo con Arboles y Pilas*/
    
    int resultado = 0;
    
    struct ArbolBinario arbol;
    construir(arbol);    
    notacionPostfija(arbol); //Contruye el árbol de expresión
    recorrerEnOrden(arbol); //muestra el árbol
    cout<<endl;
    resultado = evaluarExpresion(arbol);//evalúa la expresión
    destruirArbolBinario(arbol);
    cout<<endl<<"El resultado es: "<<resultado<<endl;
      
    return 0;
}

