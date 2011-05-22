// Tamanyo
#include "thashcalendario.h"
int
main()
{
  THASHCalendario b(4);
 
  TCalendario c1(1,1,2011,(const char *)"Fecha1");
  TCalendario c2(2,1,2011,(const char *)"Fecha2");
  TCalendario c3(3,1,2011,(const char *)"Fecha3");
  TCalendario c4(4,1,2011,(const char *)"Fecha4");
  TCalendario c5(5,1,2011,(const char *)"Fecha5");


  b.Insertar(c1);
  cout << b.Tamanyo() << endl;

  b.Insertar(c2);
  cout << b.Tamanyo() << endl;

  b.Insertar(c3);
  cout << b.Tamanyo() << endl;

  b.Insertar(c4);
  cout << b.Tamanyo() << endl;
  
  b.Insertar(c5);
  cout << b.Tamanyo() << endl;
 
    return 0; 
}

