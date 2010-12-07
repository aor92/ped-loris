#include <iostream>
using namespace std;

#include "tpilacalendario.h"

TPilaCalendario::TPilaCalendario()
{
	TVectorCalendario tmp(10);
	posicion=0;
	v=tmp;
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
				v[i].~TCalendario();
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
		posicion=0;
		v.~TVectorCalendario();;
}

bool
TPilaCalendario::EsVacia()
{
	bool vacia=false;
		if (posicion==0)
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
	return posicion;
}

int 
TPilaCalendario::NoVacios() const 
{
	return posicion;
}

TPilaCalendario
TPilaCalendario::operator-(const TPilaCalendario& pila)
{
	TPilaCalendario aux;
	TCalendario aux2;
	for(int i=1;i<=Longitud();i++)
	{
		cout<<pila.v.ExisteCal(v[i])<<endl;
		if (!pila.v.ExisteCal(v[i]))
		{
			cout<< i <<"    " <<Longitud() <<endl;
			aux2=v[i];
			aux.Apilar(aux2);
		}
		
	}
	
	return aux;
}

TCalendario
TPilaCalendario::Cima()
{
	return v[posicion];
}


bool
TPilaCalendario::Apilar(TCalendario& cal)
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
		if (posicion % 10 == 1 && posicion > 10) 
		{
			v.Redimensionar(v.Tamano()-10);
			//~ v[posicion].~TCalendario();
			posicion--;
			desapi=true;
		}
		else
		{
			//~ v[posicion].~TCalendario();
			posicion--;
			desapi=true;
		}
		
	}
	
	return desapi;
}

ostream& operator<<(ostream &os, const TPilaCalendario &pila)
{
	TPilaCalendario tmp;
	tmp=pila;
	os<<"{";
	
	while(tmp.NoVacios()>0)
	{
		os<<tmp.Cima();
		tmp.Desapilar();
		if(tmp.NoVacios()>0)
		{
			os<<" ";
		}
	}
	os<<"}";
	
	return os;
}
