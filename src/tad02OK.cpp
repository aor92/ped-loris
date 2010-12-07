#include <iostream>

using namespace std;

#include "tcalendario.h"
#include "tpilacalendario.h"

int
main(void)
{
  TCalendario c1(14, 12, 1966, (char*) "Fecha Correcta");
  TCalendario c2(1, 1, 1954, (char*) "Fecha Correcta");
  TPilaCalendario p1;

  cout << p1 << endl;
  p1.Apilar(c1); 
  p1.Apilar(c2);
 
  cout << p1 << endl;

  return 0;
}
