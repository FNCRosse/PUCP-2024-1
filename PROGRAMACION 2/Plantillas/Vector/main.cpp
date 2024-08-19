/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 20 de junio de 2024, 12:04
 */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
using namespace std;
#include "Persona.h"

void f(vector<int>v) {
    for (int x : v)
        cout << setw(5) << x;
    cout << endl << endl;
}

int main(int argc, char** argv) {
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    vector<int> vInt;
    cout << "PUSH BACK:" << endl;
    vInt.push_back(56); //Agrega
    vInt.push_back(39);
    vInt.push_back(327);
    vInt.push_back(21);
    cout << "Numero de elementos: " << vInt.size() << endl;
    cout << "Capacidad del arreglo: " << vInt.capacity() << endl << endl;

    vInt.shrink_to_fit(); // hace que coincida el tamaño con la capacidad
    cout << "Numero de elementos: " << vInt.size() << endl;
    cout << "Capacidad del arreglo: " << vInt.capacity() << endl << endl;
    /*como ya le habia seteado la capaciadad, al poner otro int, la capacidad se dublico de lo que 
     tenia ahora de 4 paso  8*/

    vInt.push_back(21);
    cout << "Numero de elementos: " << vInt.size() << endl;
    cout << "Capacidad del arreglo: " << vInt.capacity() << endl << endl;

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "FORMAS DE IMPRIMIR:" << endl;
    //Como si fuera un arreglo
    for (int i = 0; i < vInt.size(); i++)
        cout << setw(5) << vInt[i];
    cout << endl << endl;
    //Otra forma
    for (int x : vInt)
        cout << setw(5) << x;
    cout << endl << endl;
    //con funcion
    f({23, 14, 62, 77, 21, 12, 9, 102, 47, 81, 52});

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "INICALIZACION DE VECTORES:" << endl;
    vector<int>vInt2{23, 14, 62, 77, 21, 9, 102, 67, 81};
    //De esta forma el tamano como la capacidad son iguales
    for (int x : vInt2)
        cout << setw(5) << x;
    cout << endl;
    cout << "Numero de elementos: " << vInt2.size() << endl;
    cout << "Capacidad del arreglo: " << vInt2.capacity() << endl << endl;

    vector<int> vInt3(10); // estamos inicializa con la capacidad con todo en 0
    for (int x : vInt3)
        cout << setw(5) << x;
    cout << endl;
    cout << "Numero de elementos: " << vInt3.size() << endl;
    cout << "Capacidad del arreglo: " << vInt3.capacity() << endl << endl;

    vector<int> vInt4(10, 55); // estamos inicializa con la capacidad con todo en 55
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl;
    cout << "Numero de elementos: " << vInt4.size() << endl;
    cout << "Capacidad del arreglo: " << vInt4.capacity() << endl << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "ASIGNACION DE VECTORES:" << endl;
    vInt4.assign(5, 101);
    //Le asigno el tamaño 5 con el numero 101, pero su capacidad sigue siendo la seteada 10
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl;
    cout << "Numero de elementos: " << vInt4.size() << endl;
    cout << "Capacidad del arreglo: " << vInt4.capacity() << endl << endl;

    vInt4.assign({23, 14, 62, 77, 21, 12, 9, 102, 47, 81, 52});
    //Asigno toda este arreglo y aunq se se pase de la capacidad, esta se setea al tamaño del arreglo
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl;
    cout << "Numero de elementos: " << vInt4.size() << endl;
    cout << "Capacidad del arreglo: " << vInt4.capacity() << endl << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "POP BACK:" << endl;
    //Elimina el ultimo elemento del arreglo
    vInt4.pop_back();
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "FRONT AND BACK:" << endl;
    //Solo visualiza el elemento inicial y final del arreglo
    int dIni, dFin;
    dIni = vInt4.front();
    dFin = vInt4.back();
    cout << "Dato inicial: " << dIni << endl;
    cout << "Dato Fin: " << dFin << endl;
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl << endl;
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "ITERADORES:" << endl;
    //Usos : Recorrer de forma segura un STL
    for (vector<int>::iterator it = vInt4.begin(); it != vInt4.end(); it++)
        cout << setw(5) << *it;
    cout << endl;
    //Usos:Traer un elemento de una posicion especifica
    vector<int>::iterator it2 = vInt4.begin();
    vector<int>::iterator it3 = vInt4.begin();
    it2 += 3; //Recorre 3 veces
    it3 += 6; //Recorre 6 veces
    cout << setw(5) << *it2 << endl;
    cout << setw(5) << *it3 << endl << endl;
    vInt4.erase(it2); //Borra especificamente ese elemento que trae it2
    //elimina el elemento, pero se queda con la misma capacidad
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl;
    cout << setw(5) << *it2 << endl;
    cout << setw(5) << *it3 << endl << endl; //y it2 siempre toma una posicion no un numero, es decir it2 siguen en pos3
    vInt4.erase(it2, it3);
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl;
    cout << setw(5) << *it2 << endl;
    cout << setw(5) << *it3 << endl;

    cout << "Clear:"; //elimina todos los elementos, pero se queda con la misma capacidad
    vInt4.clear();
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl;
    cout << "Numero de elementos: " << vInt4.size() << endl;
    cout << "Capacidad del arreglo: " << vInt4.capacity() << endl << endl;

    vInt4.assign({23, 14, 62, 77, 21, 12, 9, 102, 47, 81, 52});
    it2 = vInt4.begin();
    it2 += 3;
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl;
    cout << setw(5) << *it2 << endl;
    vInt4.insert(it2, 555); //En esa posicion inserto el numero, el otro elemento se desplaza
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl;
    cout << setw(5) << *it2 << endl << endl; //el it2 sigue donde estaba el elemento en la ant pos 3

    cout << "Ordenar el vector (sort):" << endl;
    vInt4.assign({23, 14, 62, 77, 21, 12, 9, 102, 47, 81, 52});
    sort(vInt4.begin(), vInt4.end()); //ordena el vector
    for (int x : vInt4)
        cout << setw(5) << x;
    cout << endl<<endl;
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    cout << "VECTORES CON CLASES" << endl;
    vector<class Persona> vPersona;
    class Persona per;
    ifstream arch("personal.csv");
    while (true) {
        arch>>per;
        if (arch.eof()) break;
        vPersona.push_back(per);
    }
    for (Persona x : vPersona)
        cout << x;
    cout << endl;
    sort(vPersona.begin(),vPersona.end());
    for (Persona x : vPersona)
        cout << x;
    cout << endl;
    return 0;
}

