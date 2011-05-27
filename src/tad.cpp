#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"
#include "tabbcalendario.h"
#include "tavlcalendario.h"
#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"
#include "tlistacalendario.h"
#include "tabbcalendario.h"
#include "tavlcalendario.h"
#include "thashcalendario.h"
using namespace std;

int
main(void)
{
/************************************************/
/***************** INORDEN, PREORDEN, POSTORDEN */
/************************************************/


TABBCalendario a;
TVectorCalendario vec1, vec2, vec3;
return 0; 

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
}
