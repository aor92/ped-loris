//PRUEBA DE LISTA Y VECTOR VACIOS
#include <iostream>
#include "tvectorcalendario.h"
#include "tlistacalendario.h"

using namespace std;

int main()
{
TListaCalendario lista;
TVectorCalendario vc;
int *vent;

vent = lista.Funcion1 (vc);
if (vent) cout<<"ERROR: EL VECTOR DE ENTEROS NO ES NULL"<<endl;
else cout<<"CORRECTO: EL VECTOR DE ENTEROS ES NULL"<<endl;
return (0);
}