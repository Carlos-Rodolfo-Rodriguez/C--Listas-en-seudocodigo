#ifndef ALGOTAD_H
#define ALGOTAD_H
#include <program1.h>
#include "TipoDeDatos.h"
//#include "Puntero.h"
#ifndef LISTASTAD_H
#include "ListasTAD.h"
#endif
//#define DEPURACION
//#undef DEPURACION
constante entero LARGOCAD = 16;
clase Lista;
clase Algo;
//union Punt;
union Valor {
    caracter vCar[LARGOCAD];
    sinSigno largo largo bits : LARGOCAD*4;
    largo ent;
    doble re;
//    char cad[20];
//    cadena cad[LARGOCAD];
    char cad[LARGOCAD];
    caracter car;
    logico log;
    Lista * subL;
    Algo * subA;
    vectorDin(Algo) * subVec;
    };
clase Algo /*: Puntero*/ {
privado:
    TipoDeDatos tipo;
    Valor valor;
publico:    
    Algo();
    Algo(largo);
    Algo(entero);
    Algo(real);
    Algo(doble);
    Algo(caracter);
    Algo(logico);
    Algo(cadena);
    Algo(Lista *);
    Algo(Lista porRef);
//    Algo(vectorDin(Algo) *);
    Algo(noCambia Algo porRef);
    ~Algo();
    largo operador ++(entero);   // Sufijo
    largo operador ++();         // Prefijo
    largo operador --(entero);   // Sufijo
    largo operador --();         // Prefijo
    vectorDin(Algo) operador =(vectorDin(Algo) );
//    vectorDin(Algo) (std::initializer_list<Algo>);
    vectorDin(Algo) estatico copiaVec(vectorDin(Algo) porRef);
//    Algo & operador [](largo);
//    vectorDin(Algo) operador =(Lista);
    Lista * operador =(Lista *);
    Lista operador =(Lista);
    doble operador =(doble);
    doble operador =(real);
    largo operador =(largo);
    largo operador =(entero);
    logico operador =(logico);
    cadena operador =(cadena);
    caracter operador =(caracter);
//    cadena operador =(caracter*);
//    cadena operador =(caracter []);

    cadena operador =(caracter noCambia *);
    Algo operador =(Algo);
//    plantilla(Tipo) Algo operador=(Tipo);
    logico operador ES(Algo);
    logico amigo operador ES(vectorDin(Algo),vectorDin(Algo));
    procedimiento estatico agregaEle(vectorDin(Algo));
//    procedimiento estatico agregaEle(caracter constante *);
//    procedimiento estatico agregaEle(cadena);
//    procedimiento estatico agregaEle(Lista);
//    procedimiento agregaEle(Algo);
    plantilla(Tipo) procedimiento agregaEle(Tipo);
    procedimiento estatico muestra(vectorDin(Algo),cadena);
    procedimiento borraLista();
    procedimiento borra();
    procedimiento muestra();
    procedimiento muestra(cadena);
    procedimiento estatico borraLista(vectorDin(Algo) porRef);
    procedimiento leeReal(cadena mens = "Valor real: ");
    procedimiento leeEnt(cadena mens = "Valor entero: ");
    procedimiento leeCar(logico conEco = VERDADERO);
    procedimiento leeCad(/*logico conEco = VERDADERO*/);
    procedimiento leeLog(logico conEco = VERDADERO);
    procedimiento estatico leeEnt(largo porRef);
    logico estatico leeMantisa(doble porRef);
    TipoDeDatos cualTipo() {regresa(tipo);}
    Valor vale() {regresa(valor);}
//    Valor poneValor(Algo a) {valor = a.valor; regresa(valor);}
    procedimiento ponePuntero(vectorDin(Algo) * puntero) {valor.subVec = puntero;}
    plantilla(Tipo) procedimiento enLista(Tipo);
//    Lista * operador ()(largo);
//    Lista operador() (largo);    
    Algo & operador[] (largo);    
    Algo operador[] (const largo &) const;    
    procedimiento poneCadena(cadena);
    cadena sacaCadena();    
    };
#endif

