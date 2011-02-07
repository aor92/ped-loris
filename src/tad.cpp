//PRUEBA DE LISTA NORMAL
#include <iostream>
#include "tlistacalendario.h"
#include "tvectorcalendario.h"

using namespace std;

int main()
{

const int kMaxV=8;
TListaCalendario lista;
TVectorCalendario vc(kMaxV);


TCalendario c1(1,1,2007,"DIA DE RESACA");
TCalendario c2(1,1,2007,"FELIZ 2007");
TCalendario c3(6,1,2007,"DIA DE LOS REYES MAGOS");
TCalendario c4(19,3,2007,"DIA DE SAN JOSE");
TCalendario c5(6,4,2007,"VIERNES SANTO 2007");
TCalendario c6(9,4,2007,"LUNES DE PASCUA 2007");
TCalendario c7(1,5,2007,"DIA DEL TRABAJADOR");
TCalendario c8(24,6,2007,"DIA DE SANT JOAN");
TCalendario c9(15,8,2007,"DIA DE NTRA. SRA. ASUNCION");
TCalendario c10(9,10,2007,"DIA DE LA COMUNIDAD VALENCIANA");
TCalendario c11(12,10,2007,"DIA DEL PILAR");
TCalendario c12(1,11,2007,"DIA DE TODOS LOS SANTOS");
TCalendario c13(6,12,2007,"DIA DE LA CONSTITUCION ESPANYOLA");
TCalendario c14(8,12,2007,"LA INMACULADA CONCEPCION");
TCalendario c15(24,12,2007,"NOCHEBUENA");
TCalendario c16(25,12,2007,"NAVIDAD");
TCalendario c17(31,1,2007,"NOCHEVIEJA");

int *vent;

vc[1]=c1;
vc[2]=c2;
vc[3]=c3;
vc[4]=c4;
vc[5]=c4;
vc[6]=c3;
vc[7]=c2;
vc[8]=c1;

lista.Insertar(c2);
lista.Insertar(c3);
lista.Insertar(c4);
lista.Insertar(c6);
lista.Insertar(c8);
lista.Insertar(c10);
lista.Insertar(c12);
lista.Insertar(c14);
lista.Insertar(c16);


vent = lista.Funcion1 (vc);
if (!vent) cout<<"ERROR: EL VECTOR DE ENTEROS ES NULL"<<endl;
else for (int i=0; i<kMaxV; i++) cout<<vent[i]<<endl;
return (0);
}
//parece funcion que devuelve un vector de punteros a entero (imagino, que la posicion), de aquellos que se encuentran
//en una lista a la que se le ha pasado por parametro un vector de calendarios.
