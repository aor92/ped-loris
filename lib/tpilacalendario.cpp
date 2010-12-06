#include <iostream>
using namespace std;

#include "tpilacalendario.h"

TPilaCalendario::TpilaCalendario()
{
		posicion=0;
		v.Resimensionar(10);
}


TPilaCalendario::TPilaCalendario(const TPilaCalendario& pila)
{
	posicion=pila.posicion;
	for (int i = 0; i < pila.v.Tamano(); i++)
	{
		v[i]=pila.v[i];
	}
	
}

TPilaCalendario&
TPilaCalendario::operator =(const TPilaCalendario& pila)
{
		if(v.Tamano()>0)
		{
			for (int i = 0; i < pila.v.Tamano(); i++)
			{
				delete v[i];
			}
		}
		if (this!=NULL)
		{
			posicion=pila.posicion;
			for (int i = 0; i < pila.v.Tamano(); i++)
			{
				v[i]=pila.v[i];
			}
		}

	return *this;
}

TPilaCalendario::~TPilaCalendario()
{
		posicion=1;
		delete []v;
}


TPilaCalendario::EsVacia()
{
	bool vacia=false;
		if (v.Tamano()==0)
		{
			vacia=true;
		}
	return vacia;
}

bool
TPilaCalendario::operator ==(const TPilaCalendario& pila)
{
	return v==pila.v;
}

bool 
TPilaCalendario::operator!=(const TPilaCalendario& pila)
{
	return !(v==pila.v);
}

int
TPilaCalendario::Longitud() const 
{
	return posicion-1;
}

int 
TPilaCalendario::NoVacios() const 
{
	return posicion;
}

TPilaCalendario::operator -(const TPilaCalendario pila)
{
	TPilaCalendario tmp;
	
	for(int i=1;i<=posicion;i++)
	{ 
		if(!PC.v.ExisteCal(v[i]))
		{
			tmp.Apilar(v[i]);
		}
	}
	
	return tmp;
}

TCalendario
TPilaCalendario::Cima()
{
	return v[posicion];
}


bool
TPilaCalendario::Apilar(const TCalendario& cal)
{
	if(NoVacios()<Longitud())
	{
		posicion++;
		v[posicion]=cal;
		return true;
	}
	else
	{
		posicion++;
		v.Redimensionar(Longitud()+10);
		v[posicion]=cal;
		return true;
	}
	return false;
}

bool 
TPilaCalendario::Desapilar()
{
	bool desapi=false;
	
	if(posicion > 0)
	{
		if (posicion % 10 == 1 && posicion > 10) v.Redimensionar(v.Longitud()-10);
		v[posicion].~TPoro();
		posicion--;
		desapi=true;
	}
	else desapi=false;
	
	return desapi;
}
