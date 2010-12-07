#include <iostream>

using namespace std;

#include "tcalendario.h"
#include "tpilacalendario.h"

int
main(void)
{
  TCalendario c1(14, 12, 1966, (char*) "Fecha Correcta");
  TCalendario c2(1, 1, 1954, (char*) "Fecha Correcta");
  TPilaCalendario p1, p2;
      
  p1.Apilar(c1); 
  p1.Apilar(c2);
  p2.Apilar(c1); 
  p2.Apilar(c2);

  if(p1 == p2) 
	cout << "iguales" << endl;
  else 
	cout << "distintas" << endl;

  if(p1 != p2) 
	cout << "distintas" << endl;
  else 
	cout << "iguales" << endl;

  return 0;
}
