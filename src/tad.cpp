#include <iostream>

using namespace std;

#include "tcalendario.h"
#include "tpilacalendario.h"

int
main(void)
{
  TCalendario c1(1, 1, 2001, (char*) "Fecha Correcta");
  TCalendario c2(1, 1, 2002, (char*) "Fecha Correcta");
  TCalendario c3(1, 1, 2003, (char*) "Fecha Correcta");
  TCalendario c4(1, 1, 2004, (char*) "Fecha Correcta");
  TPilaCalendario p1, p2;
      
  p1.Apilar(c1); 
  p1.Apilar(c2);
  p2.Apilar(c2);
  p2.Apilar(c3);
  p2.Apilar(c4);

	cout<<p1<<"   "<<p1.Longitud()<<endl;
	cout<<p2<<"   "<<p2.Longitud()<<endl;
  cout << (p1 - p2) << endl;

  return 0;
}
