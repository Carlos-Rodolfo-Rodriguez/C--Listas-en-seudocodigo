#include "ListasTAD.h"
//#define DEPURACION

Lista::Lista() {
#ifdef DEPURACION
muestra();
#endif
}

procedimiento Lista::enLista(Lista porRef l) {
Lista subLista1 = l
     ,subLista2;
subLista2.agregaEle(subLista1);
agregaEle(& subLista2);
#ifdef DEPURACION
muestra();
#endif
}

plantilla(Tipo)
procedimiento Lista::enLista(Tipo a) {
Lista * puntero = nuevo Lista(a);
//agregaEleVDin(vEle,a);
agregaEle(puntero);
#ifdef DEPURACION
muestra();
#endif
}
implementa procedimiento Lista::enLista(largo);
implementa procedimiento Lista::enLista(entero);
implementa procedimiento Lista::enLista(doble);
implementa procedimiento Lista::enLista(real);
implementa procedimiento Lista::enLista(caracter);
implementa procedimiento Lista::enLista(logico);
implementa procedimiento Lista::enLista(cadena);
implementa procedimiento Lista::enLista(Lista *);

procedimiento Lista::enLista(caracter noCambia * cad) {
enLista((cadena)cad);
#ifdef DEPURACION
muestra();
#endif
}

Lista::Lista(noCambia Lista porRef otraLi) {
vEle = otraLi.vEle;
#ifdef DEPURACION
muestra();
#endif
}
/*
Lista::Lista(std::initializer_list<Lista> li) {
//ajusTamanio(vEle,0);
//esto->vEle = vE;
}
*/
plantilla(Tipo)
Lista::Lista(Tipo e) {
ajusTamanio(vEle,1);
vEle[0] = e;
}
implementa Lista::Lista(largo);
implementa Lista::Lista(entero);
implementa Lista::Lista(doble);
implementa Lista::Lista(real);
implementa Lista::Lista(caracter);
implementa Lista::Lista(caracter[]);
implementa Lista::Lista(logico);
implementa Lista::Lista(cadena);
implementa Lista::Lista(Lista *);

Lista::~Lista() {
//borraLista();
}

Lista::Lista(Lista porRef l) {
esto->vEle = l.vEle;
}

TipoDeDatos Lista::cualTipo() {
regresa(vEle[0].cualTipo());
}

TipoDeDatos Lista::cualTipo(sinSigno pos) {
regresa(vEle[pos].cualTipo());
}

procedimiento Lista::borraEle(sinSigno pos) {
si(cualTipo(pos) ES LISTA) (vEle[pos].vale().subL)->borraLista();
borra1EleVDin(vEle,pos);
}

Lista Lista::copiaLista(Lista l) {
Lista resul;
//resul.vEle = Algo::copiaVec(l.vEle);
resul.vEle = Algo::copiaVec(l.vEle);
regresa(resul);
}

plantilla(Tipo)
procedimiento Lista::intercalaEle(Tipo e, sinSigno pos) {
intercalaEleVDin(vEle,e,pos);
#ifdef DEPURACION
muestra();
#endif
}
implementa procedimiento Lista::intercalaEle(largo, sinSigno);
implementa procedimiento Lista::intercalaEle(entero, sinSigno);
implementa procedimiento Lista::intercalaEle(doble, sinSigno);
implementa procedimiento Lista::intercalaEle(caracter, sinSigno);
implementa procedimiento Lista::intercalaEle(cadena, sinSigno);
implementa procedimiento Lista::intercalaEle(Lista *, sinSigno);

procedimiento Lista::intercalaEle(Lista l, sinSigno pos) {
Lista * puntero = nuevo Lista();
* puntero = l;
intercalaEle(puntero,pos);
}

plantilla(Tipo)
procedimiento Lista::insertaEle(Tipo e) {
insertaEleVDin(vEle,e);
#ifdef DEPURACION
muestra();
#endif
}
implementa procedimiento Lista::insertaEle(largo);
implementa procedimiento Lista::insertaEle(entero);
implementa procedimiento Lista::insertaEle(doble);
implementa procedimiento Lista::insertaEle(caracter);
implementa procedimiento Lista::insertaEle(cadena);
implementa procedimiento Lista::insertaEle(Lista *);
//implementa procedimiento Lista::insertaEle(Lista porRef);

procedimiento Lista::insertaEle(Lista porRef l) {
//enLista(l.vEle);
Lista * puntero = & l;
* puntero = l;
//insertaEleVDin(vEle,puntero);
insertaEle(puntero);
}

plantilla(Tipo)
procedimiento Lista::agregaEle(Tipo e) {
agregaEleVDin(vEle,e);
#ifdef DEPURACION
muestra();
#endif
}
implementa procedimiento Lista::agregaEle(largo);
implementa procedimiento Lista::agregaEle(entero);
implementa procedimiento Lista::agregaEle(doble);
implementa procedimiento Lista::agregaEle(caracter);
//implementa procedimiento Lista::agregaEle(caracter noCambia *);
implementa procedimiento Lista::agregaEle(logico);
implementa procedimiento Lista::agregaEle(cadena);
implementa procedimiento Lista::agregaEle(Lista *);

procedimiento Lista::agregaEle(Lista l) {
agregaEle(& l);
#ifdef DEPURACION
muestra();
#endif
}

procedimiento Lista::agregaEle(caracter noCambia * cad) {
cadena resul = cad + '\0';
//sinSigno i;
//variarMas1(i,0,sizeof(cad)-2)
//    resul += cad[i];
//    finVariar
//resul += '\0';
agregaEle(resul);
}


procedimiento Lista::muestra() {
muestra("");
}

procedimiento Lista::muestra(cadena sangria = " ") {
estatico sinSigno nivel = 0;
sinSigno i;
entero ult = tamanio(vEle)-1;
//cadena sangria = " ";
si(ult >= 0) entonces
    nivel++;
    rellena(sangria,nivel*4,' ');
    mostrar << /*sangria <<*/ "Lista de "<< tamanio(vEle) 
            << " valores:" << salto << sangria
            << "{" << salto;
    variarMas1(i,0,ult)
        mostrar << sangria << (i+1) << "->";
        si(vEle[i].cualTipo() ES LISTA O
           vEle[i].cualTipo() ES ALISTA) entonces
            mostrar << /*sangria <<*/ " { ";
            (vEle[i].vale().subL)->muestra(sangria);            
            mostrar << sangria << "    } (Lista)" << salto;
            sino
            vEle[i].muestra(" ");            
            finSi
        finVariar
    mostrar << sangria << "}" << salto;
    nivel--;
    sino
    mostrar << "Lista sin valores." << salto;
    finSi
}

Lista Lista::operador[](const largo & ind) const {
assert(ind >= 0 Y ind < (largo)tamanio(vEle));
Lista resul = esto;
si(resul.cualTipo(ind) ES ALISTA) entonces
    resul = *(resul.vEle[ind].vale().subL);
    finSi
#ifdef DEPURACION
mostrar << "[" << ind << "]:" << salto;
muestra();
#endif
//regresa(esto[ind]);
regresa(resul);
}

Algo & Lista::operador [] (const largo ind) const {
Lista resul;
resul.vEle[ind].vale().subL;
#ifdef DEPURACION
mostrar << "[" << ind << "]:" << salto;
muestra();
#endif
regresa(resul[ind]);
}


Algo & Lista::operador[](largo ind){
assert(ind >= 0 Y ind < (largo)tamanio(vEle));
regresa(vEle[ind]);
}

Lista Lista::operador=(Lista otraLi) {
//* esto = copiaLista(otraLi);
vEle = otraLi.vEle;
regresa(apuntadoPor esto);
}

Lista Lista::menosPrimero()  {
Lista resul = apuntadoPor esto;
resul.borraEle(0);
regresa(resul);
}

Lista Lista::menosUltimo()  {
Lista resul = apuntadoPor esto;
resul.borraEle(tamanio(vEle)-1);
regresa(resul);
}

Algo Lista::primero() {
regresa(vEle[0]);
}

Algo Lista::ultimo() {
regresa(vEle[tamanio(vEle)-1]);
}

logico Lista::operador NOES(Lista otraLi) {
logico resul = NO (*esto ES otraLi);
regresa(resul);
}

logico Lista::listaVacia() {
logico resul = tamanio(vEle) <= 0;    
regresa(resul);
}

procedimiento Lista::borraLista() {
largo ind = tamanio(vEle) - 1;
mientras(ind >= 0)
    si(vEle[ind].cualTipo() ES LISTA) vEle[ind].vale().subL->borraLista();
    borraEle(ind);
#ifdef DEPURACION
mostrar << "Borrando Lista:"<< salto;
muestra();
#endif    
    ind--;
    finMientras
}

logico Lista::operador ES(Lista otraLi) {
logico resul = (listaVacia() Y otraLi.listaVacia());
#ifdef DEPURACION
mostrar << "Comparando;"<< salto;
mostrar << "->"<< fSi(resul,"Sí","No todavia...") << salto;
    primero().muestra("Lista 1:");
    otraLi.primero().muestra("Lista 2:");
    mostrar << "->Tamaños "<< fSi(resul2,"iguales","distintos...") << salto;
        mostrar << "->Primeros "<< fSi(resul3,"iguales","distintos...") << salto;
#endif    
si(NO resul) entonces
    logico resul2 =  ((tamanio(vEle) ES tamanio(otraLi.vEle)));
    si(resul2) entonces
        logico resul3;
        resul3 =  (primero() ES otraLi.primero());
        si(resul3) entonces
            resul = (menosPrimero() ES otraLi.menosPrimero());
            sino
            resul = FALSO;
            finSi
        sino
        resul = FALSO;
        finSi
    finSi
regresa(resul);
}
