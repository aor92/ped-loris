// Borrar
#include "thashcalendario.h"
int
main()
{
  THASHCalendario a,b(4);
 
  TCalendario c1(1,1,2011,(const char *)"Fecha1");
  TCalendario c2(2,1,2011,(const char *)"Fecha2");
  TCalendario c3(3,1,2011,(const char *)"Fecha3");
  TCalendario c4(4,1,2011,(const char *)"Fecha4");
  TCalendario c5(5,1,2011,(const char *)"Fecha5");

  b.Insertar(c1);
  b.Insertar(c2);
  b.Insertar(c3);
  b.Insertar(c4);
 
 cout<<b.Buscar(c5)<<endl;
  if ( b.Borrar(c4) )  cout<<"Elemento borrado" <<endl;
  else cout<<"Elemento no borrado" <<endl;
  if ( b.Borrar(c5) ) cout<<"Elemento borrado" <<endl;
  else cout<<"Elemento no borrado" <<endl;

  return 0; 
}
