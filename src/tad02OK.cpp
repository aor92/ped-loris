//PRUEBA DE LISTA VACIA Y VECTOR CON ELEMENTOS  
#include <iostream>
#include "tlistacalendario.h"
#include "tvectorcalendario.h"

using namespace std;

int main()
{
const int kMaxV=4;
TListaCalendario lista;
TVectorCalendario vc(kMaxV);
TCalendario c1(1,1,2007,"FELIZ 2007");
TCalendario c2(1,1,2007,"DIA DE RESACA");
TCalendario c3(6,1,2007,"DIA DE LOS REYES MAGOS");
TCalendario c4(19,3,2007,"DIA DE SAN JOSE");

int *vent;

vc[1]=c1;
vc[2]=c2;
vc[3]=c3;
vc[4]=c4;

vent=lista.Funcion1 (vc);

if (!vent) cout<<"ERROR: EL VECTOR DE ENTEROS ES NULL"<<endl;
else for (int i=0; i<kMaxV; i++) cout<<"en el tad"<<vent[i]<<endl;
return (0);
}
