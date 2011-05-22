//BuscarLista
#include "thashcalendario.h"
int
main()
{
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
}



