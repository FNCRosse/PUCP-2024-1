/* 
 * File:   main.cpp
 * Author: ANA RONCAL
 * Created on 24 de abril de 2024, 03:15 PM
 */

#include <iostream>
using namespace std;
#include "Cliente.h"
#include "Cola.h"
#include "funcionesCola.h"
#define MAX_DATOS 6

int main(int argc, char** argv) {

    struct Cola cola;
    construir(cola);

    /*Encolamos elementos pero con prioridad en la Cola*/
    /*  int prioridad;
        char dni[9];
     */
    struct Cliente cliente[MAX_DATOS] = {
        {1, {'0','9','8','6','2','2','2','0'}},
        {2, {'1','2','7','1','1','2','2','1'}},
        {2, {'3','3','7','6','2','5','2','2'}},
        {2, {'4','4','6','1','5','7','2','3'}},
        {2, {'5','5','5','7','4','9','2','4'}},
        {2, {'5','6','7','9','3','1','2','5'}},
    };
    
    for(int i = 0; i < MAX_DATOS; i++){
        encolarConPrioridad(cola, cliente[i]);
    }
    
    imprimir(cola);
    
    return 0;
}

