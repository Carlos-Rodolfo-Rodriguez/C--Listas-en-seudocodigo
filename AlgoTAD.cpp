#include "AlgoTAD.h"

Algo::Algo() {
tipo = NADA;
#ifdef DEPURACION
mostrar << "Construyendo Algo...\n";
muestra();
#endif
}

Algo::Algo(doble d) {
tipo = REAL;
valor.re = d;
#ifdef DEPURACION
mostrar << "Construyendo Algo REAL...\n";
muestra();
#endif
}

Algo::Algo(largo e) {
tipo = ENTERO;
valor.ent = e;
#ifdef DEPURACION
mostrar << "Construyendo Algo ENTERO...\n";
muestra();
#endif
}

Algo::Algo(entero e) {
tipo = ENTERO;
valor.ent = e;
#ifdef DEPURACION
mostrar << "Construyendo Algo ENTERO...\n";
muestra();
#endif
}

Algo::Algo(caracter c) {
tipo = CARACTER;
valor.car = c;
#ifdef DEPURACION
mostrar << "Construyendo Algo CARACTER...\n";
muestra();
#endif
}

Algo::Algo(logico lo) {
tipo = CARACTER;
valor.log = lo;
#ifdef DEPURACION
mostrar << "Construyendo Algo LOGICO...\n";
muestra();
#endif
}

Algo::Algo(cadena cad) {
tipo = CADENA;
sinSigno i;
variarMas1(i,0,LARGOCAD-2)
    valor.cad[i] = fSi(i <= tamanio(cad),cad[i],'\0');
    finVariar
valor.cad[i] = '\0';
#ifdef DEPURACION
mostrar << "Construyendo Algo CADENA...\n";
muestra();
#endif
}

Algo::Algo(Lista porRef l) {
tipo = LISTA;
valor.subL = & l;
//*valor.subL = *l;
#ifdef DEPURACION
mostrar << "Construyendo Algo LISTA...\n";
muestra();
#endif
}

Algo::Algo(Lista * l) {
tipo = ALISTA;
valor.subL = l;
//*valor.subL = *l;
#ifdef DEPURACION
mostrar << "Construyendo Algo LISTA...\n";
muestra();
#endif
}

Algo::Algo(noCambia Algo porRef otraCosa) {
tipo = otraCosa.tipo;
valor.bits = otraCosa.valor.bits;
#ifdef DEPURACION
mostrar << "Construyendo Algo copiado...\n";
muestra();
#endif
}

Algo::~Algo() {
#ifdef DEPURACION
mostrar << "Destruyendo ";
muestra();
#endif
//si(tipo ES LISTA) borraLista(*valor.subVec);
}

largo Algo::operador ++(entero) {
valor.ent++;
#ifdef DEPURACION
mostrar << "Incrementando Algo++...\n";
muestra();
#endif
regresa(valor.ent);
}

largo Algo::operador ++() {
++valor.ent;
#ifdef DEPURACION
mostrar << "Incrementando ++Algo...\n";
muestra();
#endif
regresa(valor.ent);
}

largo Algo::operador --(entero) {
valor.ent--;
#ifdef DEPURACION
mostrar << "Incrementando Algo++...\n";
muestra();
#endif
regresa(valor.ent);
}

largo Algo::operador --() {
--valor.ent;
#ifdef DEPURACION
mostrar << "Incrementando ++Algo...\n";
muestra();
#endif
regresa(valor.ent);
}

vectorDin(Algo) Algo::operador =(vectorDin(Algo) otro) {
vectorDin(Algo) resul;
paraCada(e,otro)
    agregaEleVDin(resul,e);
    finPara
regresa(resul);
}

procedimiento Algo::borraLista(vectorDin(Algo) porRef l) {
//largo pos = tamanio(l) - 1;
//mientras(pos >= 0)
//    si(l[pos].tipo ES LISTA) borraLista(*l[pos].valor.subVec);
//    borra1EleVDin(l,pos);
//    pos--;
//    finMientras
}

vectorDin(Algo) Algo::copiaVec(vectorDin(Algo) porRef v) {
vectorDin(Algo) resul = v;
//paraCadaValor(x,v)
//    si(x.tipo ES LISTA) entonces
//        vectorDin(Algo) * puntero = nuevo vectorDin(Algo);
//        * puntero = * x.valor.subVec;
////        * puntero = copiaVec(* x.valor.subVec);
//        x.valor.subVec = puntero;
//        finSi
//    agregaEleVDin(resul,x);
//    finPara
regresa(resul);
}

Lista * Algo::operador = (Lista * lis) {
//Algo::borraLista(*esto->valor.subVec);
tipo = ALISTA;
valor.subL = lis;
* valor.subL = * lis;
regresa(valor.subL);
}

/*vectorDin(Algo)*/ 
Lista Algo::operador = (Lista lis) {
si(tipo ES ALISTA) valor.subL->borraLista();
valor.subL = nuevo Lista(lis);
*valor.subL = Lista::copiaLista(lis);
tipo = LISTA;
regresa(lis);
}

doble Algo::operador=(doble unValor) {
tipo = REAL;
valor.re = unValor;
regresa(valor.re);
}

doble Algo::operador=(real unValor) {
tipo = REAL;
valor.re = unValor;
regresa(valor.re);
}

largo Algo::operador=(largo unValor) {
tipo = ENTERO;
valor.ent = unValor;
regresa(valor.ent);
}

largo Algo::operador=(entero unValor) {
tipo = ENTERO;
valor.ent = unValor;
regresa(valor.ent);
}

caracter Algo::operador=(caracter unValor) {
tipo = CARACTER;
valor.car = unValor;
regresa(valor.car);
}

logico Algo::operador=(logico unValor) {
tipo = LOGICO;
valor.log = unValor;
regresa(valor.car);
}

cadena Algo::operador=(caracter noCambia * unValor) {
tipo = CADENA;
cadena resul = unValor+'\0';
sinSigno i;
variarMas1(i,0,LARGOCAD-2)
    si(i < tamanioDe(unValor)) entonces
        valor.cad[i] = unValor[i];
        sino
        valor.cad[i] = '\0';
        finSi
    finVariar
regresa(resul);
}

cadena Algo::operador=(cadena unValor) {
tipo = CADENA;
cadena resul = unValor;
sinSigno i;
variarMas1(i,0,LARGOCAD-2)
    si(i < tamanio(unValor)) entonces
        valor.cad[i] = resul[i];
        sino
        valor.cad[i] = '\0';
        finSi
    finVariar
//resul += valor.cad[i] = '\0';
regresa(resul);
}
//
Algo & Algo::operador [] (largo ind) {
Lista resul = *valor.subL;
//si(tipo ES ALISTA) entonces
//    resul = valor.subL;
//    sino
//    resul = * esto;
//    finSi
assert(ind >= 0);
#ifdef DEPURACION
mostrar << "[" << ind << "]:" << salto;
muestra();
#endif
regresa(resul[ind]);
}

Algo Algo::operador [] (const largo & ind) const {
Algo resul = * esto;
si(resul.tipo ES LISTA O resul.tipo ES ALISTA) entonces
    resul = * (resul.valor.subA); 
    finSi
#ifdef DEPURACION
mostrar << "[" << ind << "]:" << salto;
muestra();
#endif
regresa(resul[ind]);
}

Algo Algo::operador =(Algo otro) {
si(tipo ES LISTA O tipo ES ALISTA) entonces
    borraLista(*valor.subVec);
    tipo = NADA;
    finSi
tipo = otro.tipo;
segun(tipo)
    caso ENTERO         : valor.ent = otro.valor.ent;
    otroCaso REAL       : valor.re  = otro.valor.re;
    otroCaso LOGICO     : valor.log = otro.valor.log;
    otroCaso CARACTER   : valor.car = otro.valor.car;
//    otroCaso CADENA     : poneCadena(otro.valor.cad);
    otroCaso CADENA     : valor.bits = otro.valor.bits;
    otroCaso ALISTA      : 
        valor.subL = nuevo (Lista);
        * valor.subVec = copiaVec(* otro.valor.subVec);
        * valor.subL = * otro.valor.subL;
    otroCaso LISTA      : 
        valor.subL = nuevo (Lista);
        * valor.subVec = copiaVec(* otro.valor.subVec);
        * valor.subL = * otro.valor.subL;
    casoAsumido         : ;
    finSegun
regresa(apuntadoPor esto);
}

procedimiento Algo::muestra() {
muestra("");
}

procedimiento Algo::muestra(vectorDin(Algo) v,cadena sangria) {
estatico sinSigno nivel = 1;
largo t = tamanio(v);
nivel++;
rellena(sangria,nivel*4,' ');
si(t > 0) entonces
    mostrar << "Sublista de "<< t << " valores:" << salto;
    entero i = 0;
    paraCada(a,v)
        mostrar << sangria << (++i) << "->";
        a.muestra(" ");
        finPara
    sino
    mostrar << "Sublista sin valores." << salto;
    finSi
nivel--;    
}

procedimiento Algo::muestra(cadena sangria = "") {
mostrar << sangria/* + "Valor: "*/;
segun(tipo)
    caso ENTERO         : mostrar << valor.ent << " (largo)";
    otroCaso REAL       : mostrar << valor.re << " (doble)";
    otroCaso LOGICO     : mostrar << fSi(valor.log,"Verdadero","Falso") << " (lógico)";
    otroCaso CARACTER   : mostrar << "\'" << valor.car << "\' (caracter)";
    otroCaso CADENA     : mostrar << "\"" << valor.cad << "\" (cadena)";
    otroCaso ALISTA:
    caso LISTA :        mostrar << "{";
                        (* valor.subL).muestra(sangria+"   ") ;
                        mostrar << "} (lista)";
    casoAsumido         : mostrar << "(nada)";
    finSegun
mostrar << salto;
}

logico operador ES(vectorDin(Algo) uno,vectorDin(Algo) otro) {
sinSigno i = 0
        ,tam = tamanio(uno);
logico resul = tam ES tamanio(otro);
mientras(resul Y i < tam)
    resul = uno[i] ES otro[i];
    i++;
    finMientras
regresa(resul);
}

logico Algo::operador ES(Algo otro) {
logico resul = tipo ES otro.tipo;
si(resul) entonces
    segun(tipo)
        caso ENTERO         : resul =  valor.ent ES otro.valor.ent;
        otroCaso REAL       : resul =  valor.re  ES otro.valor.re;
        otroCaso LOGICO     : resul =  equiv(valor.log,otro.valor.log);
        otroCaso CARACTER   : resul =  valor.car ES otro.valor.car;
        otroCaso CADENA     : resul =  cadIguales(valor.cad,otro.valor.cad);
        otroCaso ALISTA     :
        caso     LISTA      : resul =  (* valor.subL) ES (* otro.valor.subL);
        casoAsumido         : resul =  FALSO;
        finSegun
    finSi
regresa(resul);
}

logico Algo::leeMantisa(doble porRef m) {
caracter teclazo;
cadena t
      ,d = "0123456789";
logico hayDigA = FALSO
      ,hayDigD = FALSO
      ,hayPunto = FALSO;
largo signo = 0;
doble m2 = 0. 
     ,mul = 0.1;
m = 0.;
limpiar
iterar
    leeTecSinEco(teclazo);
    si((hayPunto Y (hayDigA O hayDigD) Y teclazo ES 'e' O teclazo ES 'E')) mostrar << teclazo;
    salirSi(hayPunto Y (hayDigA O hayDigD) Y (teclazo ES 'e' O teclazo ES 'E' O teclazo ES '\n') );
    si(esDigito(teclazo) Y NO hayPunto) entonces
        hayDigA = VERDADERO;
        si(signo ES 0) signo = 1;
        t = teclazo;
        m = m * 10 + posScadEnCad(t,d);
        mostrar << teclazo;
        sinoSi(esDigito(teclazo)) entonces
        hayDigD = VERDADERO;
        t = teclazo;
        m2 = m2 + posScadEnCad(t,d) * mul;
        mul /= 10.; 
        mostrar << teclazo;
        sinoSi(teclazo ES '.' Y NO hayPunto) entonces
        hayPunto = VERDADERO;
        mostrar << teclazo;
        sinoSi(teclazo ES '-' Y signo ES 0) entonces
        mostrar << teclazo;
        signo = (-1);
        sinoSi(teclazo ES '+' Y signo ES 0) entonces
        mostrar << teclazo;
        signo = (+1);
        finSi
    finIterar
m = (m + m2) * signo;
regresa(teclazo ES 'e' O teclazo ES 'E');
}

procedimiento Algo::leeEnt(largo porRef e) {
caracter teclazo;
cadena t
      ,d = "0123456789";
logico hayDig = FALSO;
largo signo = 0;
e = 0;
iterar
    leeTecSinEco(teclazo);
    salirSi(hayDig Y teclazo ES '\n');
    si(esDigito(teclazo)) entonces
        hayDig = VERDADERO;
        si(signo ES 0) signo = 1;
        t = teclazo;
        e = e * 10 + posScadEnCad(t,d)/*-1*/;
        mostrar << teclazo;
        sinoSi(teclazo ES '-' Y signo ES 0) entonces
        mostrar << teclazo;
        signo = (-1);
        sinoSi(teclazo ES '+' Y signo ES 0) entonces
        mostrar << teclazo;
        signo = (+1);
        finSi
    finIterar
e = e * signo;
}

procedimiento Algo::leeEnt(cadena mens) {
mostrar << mens;
leeEnt(valor.ent);
tipo = ENTERO;
}

procedimiento Algo::leeReal(cadena mens) {
doble mantisa;
largo exponente = 0;
mostrar << mens;
si(leeMantisa(mantisa)) leeEnt(exponente);
valor.re = mantisa * XalaY(10,exponente);
tipo = REAL;
//mostrar << salto << nro << salto;
}

procedimiento Algo::leeCad() {
paraCada(c,valor.vCar)
    c = '\0';
    finPara
sinSigno pos = 0;
repetir
leeTecConEco(valor.vCar[pos]);
hasta(valor.vCar[pos] ES '\n' O ++pos ES LARGOCAD-1) 
tipo = CADENA;
}

procedimiento Algo::leeCar(logico conEco) {
valor.car = leeTec(conEco);
tipo = CARACTER;
}

plantilla(Tipo)
procedimiento Algo::agregaEle(Tipo e) {
valor.subL->Lista::agregaEle(e);
}
implementa procedimiento Algo::agregaEle(largo);
implementa procedimiento Algo::agregaEle(entero);
implementa procedimiento Algo::agregaEle(doble);
implementa procedimiento Algo::agregaEle(caracter);
implementa procedimiento Algo::agregaEle(caracter noCambia *);
implementa procedimiento Algo::agregaEle(logico);
implementa procedimiento Algo::agregaEle(cadena);
implementa procedimiento Algo::agregaEle(Lista *);

plantilla(Tipo)
procedimiento Algo::enLista(Tipo a) {
valor.subL->enLista(a);
tipo = LISTA;
#ifdef DEPURACION
muestra();
#endif
}
implementa procedimiento Algo::enLista(largo);
implementa procedimiento Algo::enLista(entero);
implementa procedimiento Algo::enLista(doble);
implementa procedimiento Algo::enLista(real);
implementa procedimiento Algo::enLista(caracter noCambia *);
implementa procedimiento Algo::enLista(logico);
implementa procedimiento Algo::enLista(cadena);
implementa procedimiento Algo::enLista(Lista *);

procedimiento Algo::borraLista() {
valor.subL->borraLista();
}
