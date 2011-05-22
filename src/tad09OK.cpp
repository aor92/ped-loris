//EsVacia 
#include "thashcalendario.h"
int
main()
{
  THASHCalendario a, b(5);

  TCalendario c1(1,1,2011,(const char *)"Fecha1");
  TCalendario c2(2,1,2011,(const char *)"Fecha2");
  TCalendario c3(3,1,2011,(const char *)"Fecha3");
  TCalendario c4(4,1,2011,(const char *)"Fecha4");
  TCalendario c5(5,1,2011,(const char *)"Fecha5");

  b.Insertar(c1);
  b.Insertar(c2);
  b.Insertar(c3);
  b.Insertar(c4);
  b.Insertar(c5);

  a = b;
  a.~THASHCalendario();

  if(a.EsVacia())
    cout << "Tabla hash vacia" << endl;
  else
    cout << "Tabla hash No vacia" << endl;

  if(b.EsVacia())
    cout << "Tabla hash vacia" << endl;
  else
    cout << "Tabla hash No vacia" << endl;
 
    return 0; 
}
















