#include <iostream>
#include "tabbcalendario.h"
#include "tvectorcalendario.h"
using namespace std;

int
main(void)
{
/***************************************************/
/***************** BUSCARLISTA	********************/
/***************************************************/
  TABBCalendario a,b, suma;
  TVectorCalendario vec;

  TCalendario c1(1,1,2001,"Fecha1");
  TCalendario c2(2,1,2002,"Fecha2");
  TCalendario c3(3,1,2003,"Fecha3");
  TCalendario c4(4,1,2004,"Fecha4");
  TCalendario c5(5,1,2005,"Fecha5");
  TCalendario c6(6,1,2006,"Fecha6");
  TCalendario c7(7,1,2007,"Fecha7");
  TCalendario c8(8,1,2008,"Fecha8");
  TCalendario c9(7,1,2009,"Fecha9");
  TCalendario c10(8,1,2010,"Fecha10");
  
  TListaCalendario lc;

  a.Insertar(c6);
  a.Insertar(c3);
  a.Insertar(c1);
  a.Insertar(c5);
  a.Insertar(c8);
  a.Insertar(c7);
  a.Insertar(c10);

  lc.Insertar(c6);//2006 2003
  lc.Insertar(c5);//2005 2005
  lc.Insertar(c9);//2009 0
  lc.Insertar(c10);//2010 2008
  
  TVectorCalendario va=a.Inorden();
  int *v = a.BuscarLista (lc);
  int n = lc.Longitud();
	cout<<va<<endl;
  cout <<"Vector Enteros: ";
  for (int i=0; i<n; i++)
  {
	cout << v[i];
	if (i < n-1) cout<< ", ";
  }
  cout<<endl;
  

  return 0; 

}

