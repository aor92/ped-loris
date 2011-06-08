#include "thashcalendario.h"
int
main()
{
  THASHCalendario a,b(4);
 
  TCalendario c1(1,1,2007,(char *)"Fecha1");
  TCalendario c2(2,1,2007,(char *)"Fecha2");
  TCalendario c3(3,1,2007,(char *)"Fecha3");
  TCalendario c4(4,1,2007,(char *)"Fecha4");
  TCalendario c5(5,1,2007,(char *)"Fecha5");

  b.Insertar(c1);
  b.Insertar(c2);
  b.Insertar(c3);
  b.Insertar(c4);
 
  a = b;
  a.~THASHCalendario();

  a.Insertar(c1);
  a.Insertar(c2);
  a.Insertar(c3);
  a.Insertar(c4);
  cout<<a<<endl;


    return 0; 
}
