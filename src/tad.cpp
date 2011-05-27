//BuscarLista
#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"
#include "tabbcalendario.h"
#include "tavlcalendario.h"
#include "thashcalendario.h"
int
main()
{
	/*
  THASHCalendario a, b(5);
  TListaCalendario tc;

  TCalendario c1(1,1,2011,(const char *)"Fecha1");
  TCalendario c2(2,1,2011,(const char *)"Fecha2");
  TCalendario c3(3,1,2011,(const char *)"Fecha3");
  TCalendario c4(4,1,2011,(const char *)"Fecha4");
  TCalendario c5(5,1,2011,(const char *)"Fecha5");
  TCalendario c6(6,1,2011,(const char *)"Fecha6");
  TCalendario c7(7,1,2011,(const char *)"Fecha7");
  TCalendario c8(8,1,2011,(const char *)"Fecha8");

  int *v = b.BuscarLista(tc);
 
  if (!v) cout<<"La lista estaba vacia"<<endl;
  else cout<<"La lista no estaba vacia"<<endl;
 
  b.Insertar(c1);
  b.Insertar(c2);
  b.Insertar(c3);
  b.Insertar(c4);
  b.Insertar(c5);
  b.Insertar(c6);
  b.Insertar(c8);
  
  tc.Insertar(c1);
  tc.Insertar(c6);
  tc.Insertar(c7);
  tc.Insertar(c8);
 
  v = b.BuscarLista(tc);
  for (int i=0; i<tc.Longitud(); i++)
	cout<<v[i]<<" ";
  cout<<endl;
  delete [] v;
 
    return 0;
    * 
    * */
    
    
TABBCalendario a;
TVectorCalendario vec1, vec2, vec3;

TCalendario c1(1,1,2011,"Fecha1");
TCalendario c2(2,1,2011,"Fecha2");
TCalendario c3(3,1,2011,"Fecha3");
TCalendario c4(4,1,2011,"Fecha4");
TCalendario c5(5,1,2011,"Fecha5");
TCalendario c6(6,1,2011,"Fecha6");

a.Insertar(c5);
a.Insertar(c2);
a.Insertar(c1);
a.Insertar(c3);
a.Insertar(c6);

vec1 = a.Inorden();
vec2 = a.Preorden();
vec3 = a.Postorden();

cout << "Inorden: " << vec1 << endl;
cout << "Preorden: " << vec2 << endl;
cout << "Postorden: " << vec3 << endl;

{
  TAVLCalendario a;
  TCalendario cal1(1,1,2011,(char *)"uno");
  TCalendario cal2(2,1,2011,(char *)"dos");
  TCalendario cal3(3,1,2011,(char *)"tres");
  TCalendario cal4(4,1,2011,(char *)"cuatro");

  a.Insertar(cal1);
  a.Insertar(cal2);
  a.Insertar(cal3);
  if (a.Insertar(cal4)) 
	cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl; 
  
  if (a.Insertar(cal3)) 
	cout<<"Insertado"<<endl;
  else cout<<"No insertado"<<endl;

  cout << "Altura: " << a.Altura() << endl;
  cout << a.Preorden() <<endl;
 }
{
THASHCalendario hash(5);
hash.Insertar(c1);
hash.Insertar(c2);
cout << hash << endl;
}
return 0; 


/* SALIDA
Inorden: [(1) 01/01/2011 "Fecha1", (2) 02/01/2011 "Fecha2", (3) 03/01/2011 "Fecha3", (4) 05/01/2011 "Fecha5", (5) 06/01/2011 "Fecha6"]
Preorden: [(1) 05/01/2011 "Fecha5", (2) 02/01/2011 "Fecha2", (3) 01/01/2011 "Fecha1", (4) 03/01/2011 "Fecha3", (5) 06/01/2011 "Fecha6"]
Postorden: [(1) 01/01/2011 "Fecha1", (2) 03/01/2011 "Fecha3", (3) 02/01/2011 "Fecha2", (4) 06/01/2011 "Fecha6", (5) 05/01/2011 "Fecha5"]
Insertado
No insertado
Altura: 3
[(1) 02/01/2011 "dos", (2) 01/01/2011 "uno", (3) 03/01/2011 "tres", (4) 04/01/2011 "cuatro"]
#(0) <> (1) <01/01/2011 "Fecha1" 02/01/2011 "Fecha2"> (2) <> (3) <> (4) <>#*/ 
}



