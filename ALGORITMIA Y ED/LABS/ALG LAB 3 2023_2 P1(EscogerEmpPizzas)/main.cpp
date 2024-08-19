/* 
 * File:   main.cpp
 * Author: Rosa Cristina La Cruz Musayon
 * Codigo: 20213714
 * Created on 8 de mayo de 2024, 12:14
 */

#include <iostream>
using namespace std;
#define N 10

struct Pedido{
    int hora;
    int CantProdMax;
};
struct Empresa{
    struct Pedido pedidos[10];
};
int CalcularMaxPedidos(struct Pedido *ArrPedido,int inicio,int fin){
    //Caso Base
    if(inicio >=  fin) return ArrPedido[inicio].CantProdMax;
    int med =(inicio+fin)/2;
    
    int maxIzq = CalcularMaxPedidos(ArrPedido,inicio,med);
    int maxDer = CalcularMaxPedidos(ArrPedido,med+1,fin);
    
    if(maxIzq>maxDer){
        return maxIzq;
    } else {
        return maxDer;
    }
}
int CalcularMaxCantProd(struct Empresa *ArrEmpresa,int inicio,int fin){
    //Caso base
    if(inicio == fin){
        int Maximo=CalcularMaxPedidos(ArrEmpresa[inicio].pedidos,0,10-1);
        return Maximo;
    }
    int mitad = (inicio+fin)/2;
    int Prod_Izq = CalcularMaxCantProd(ArrEmpresa,inicio,mitad);
    int Prod_Der = CalcularMaxCantProd(ArrEmpresa,mitad+1,fin);
    
    if(Prod_Izq > Prod_Der) return Prod_Izq;
    else return Prod_Der;
}
int CalcularPicos(struct Pedido *ArrPedido,int numMax,int inicio, int fin){
    // Caso base: solo hay un elemento en el arreglo
    if (inicio > fin) {
        return 0; 
    }
    
    int mitad = (inicio + fin) / 2;
    if (ArrPedido[mitad].CantProdMax == numMax){
        return 1+ CalcularPicos(ArrPedido,numMax,inicio,mitad-1) + CalcularPicos(ArrPedido,numMax,mitad+1, fin);
    } else {
        return CalcularPicos(ArrPedido,numMax,inicio,mitad-1) + CalcularPicos(ArrPedido,numMax,mitad+1, fin);
    }
}
int EscogerEmpresa(struct Empresa *ArrEmpresas, int numMaximo, int inicio, int fin){
    //Caso base
    if(inicio == fin){
        int CantPicos=CalcularPicos(ArrEmpresas[inicio].pedidos,numMaximo,0,10-1);
        return CantPicos;
    }
    int mitad = (inicio+fin)/2;
    int Emp_Izq = EscogerEmpresa(ArrEmpresas,numMaximo,inicio,mitad);
    int Emp_Der = EscogerEmpresa(ArrEmpresas,numMaximo,mitad+1,fin);
    
    if(Emp_Izq > Emp_Der ) return Emp_Izq;
    else return Emp_Der;
}
int main(int argc, char** argv) {
    //Parte A
    int numEmp=3;
     Empresa empresas[numEmp] = {
        {{{2, 15}, {3, 12}, {4, 10}, {5, 17}, {6, 15}, {7, 18}, {8, 18}, {9, 18}, {10, 12}, {11, 16}}}, // Empresa 1
        {{{2, 14}, {3, 17}, {4, 17}, {5, 17}, {6, 17}, {7, 12}, {8, 14}, {9, 14}, {10, 12}, {11, 12}}}, // Empresa 2
        {{{2, 16}, {3, 18}, {4, 20}, {5, 20}, {6, 15}, {7, 18}, {8, 16}, {9, 18}, {10, 18}, {11, 16}}} // Empresa 3
    };
    //Parte B
     int Maximo = CalcularMaxCantProd(empresas, 0, numEmp-1);
     //Parte C
     int EmpresaElegida=EscogerEmpresa(empresas, Maximo, 0, numEmp-1);
     int CantPicos = CalcularPicos(empresas[EmpresaElegida].pedidos,Maximo,0,10-1);
     cout<<"Debe comprar en la empresa "<<EmpresaElegida+1<<" que tiene la menor cantidad de picos con "
             <<CantPicos<<" horas"<<endl;
    return 0;
}
