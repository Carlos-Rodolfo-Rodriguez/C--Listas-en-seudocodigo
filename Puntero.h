#ifndef PUNTERO_H
#define PUNTERO_H
#include <program1.h>
clase Algo;
clase Lista;
union Punteros {
privado:
publico:
    Lista * puntALista;
    Algo * puntAAlgo;
    vectorDin(Algo) * puntAVAlgo;
};

clase Puntero {
privado:
    Punteros p;
publico:
    Puntero(Lista * l) {p.puntALista = l;};
};
#endif

