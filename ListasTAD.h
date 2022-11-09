#ifndef LISTASTAD_H
#define LISTASTAD_H
#include <program1.h>
#include "TipoDeDatos.h"
#ifndef ALGOTAD_H
#include "AlgoTAD.h"
#endif
#include "Puntero.h"
//constante entero LARGOCAD = 8;
//clase Algo;
//clase Lista;
clase Lista {
privado:
    vectorDin(Algo) vEle;
publico:
    Lista();
    Lista(noCambia Lista porRef);
    plantilla(Tipo) Lista(Tipo);
    Lista(Lista porRef);
//    Lista(std::initializer_list<Algo>);
//    Lista(std::initializer_list<Lista>);
    ~Lista();
    vectorDin(Algo) pone(vectorDin(Algo) otro) {* esto = otro; regresa(otro);};
    vectorDin(Algo) vAlgo() {regresa(vEle);};
    procedimiento enLista(Lista porRef);
    procedimiento enLista(caracter noCambia *);
    plantilla(Tipo) procedimiento enLista(Tipo);
    procedimiento borraEle();
    vectorDin(Algo) operador =(vectorDin(Algo));
    procedimiento borraLista();
    procedimiento borraEle(sinSigno);
    plantilla(Tipo) procedimiento intercalaEle(Tipo,sinSigno);
    procedimiento intercalaEle(Lista,sinSigno);
    plantilla(Tipo) procedimiento insertaEle(Tipo);
    procedimiento insertaEle(Lista porRef);
    plantilla(Tipo) procedimiento agregaEle(Tipo);
    procedimiento agregaEle(Lista);
    procedimiento agregaEle(noCambia caracter *);
    TipoDeDatos cualTipo(unsigned);
    TipoDeDatos cualTipo();
    procedimiento muestra();
    procedimiento muestra(cadena);
    Lista menosPrimero();
    Lista menosUltimo();
    Lista estatico copiaLista(Lista);
    Algo primero();
    Algo ultimo();
    Lista operador =(Lista);
//    vectorDin(Algo) operador =(Lista);
    logico operador ES(Lista);
    logico operador NOES(Lista);
    logico listaVacia();
//    Lista & operador ()(largo);
    Algo & operador [] (largo);
    Lista operador [] (const largo &) const;
    Algo & operador [] (const largo) const;
//    Algo & operador [](largo);
//    Algo & operador ()(largo);
    };
#endif

