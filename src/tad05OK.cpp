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

  if(p1.EsVacia()) 
	cout << "pila vacia" << endl;
  else 
	cout << "pila no vacia" << endl;
  
  p1.Apilar(c1); 
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  p1.Apilar(c2);
  
  if(p1.EsVacia()) 
	cout << "pila vacia" << endl;
  else 
	cout << "pila no vacia" << endl;

  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();
  p1.Desapilar();

  if(p1.EsVacia()) 
	cout << "pila vacia" << endl;
  else 
	cout << "pila no vacia" << endl;

  return 0;
}
