#include <iostream>
#include "tcalendario.h"
#include "tvectorcalendario.h"



using namespace std;


TVectorCalendario::TVectorCalendario()
{
	tamano = 0;

	c = NULL;
}

TVectorCalendario::TVectorCalendario( const int dim )
{
	if ( dim < 0)
	{
		tamano = 0;

		c = NULL;
	}
	else 
	{
		tamano = dim;

		c = new TCalendario[dim];
	}
}

TVectorCalendario::TVectorCalendario( const TVectorCalendario & v )
{
	if (tamano!=0)
	{
		delete [] c;
	}
	
	if( v.tamano == 0 )
	{
		tamano = 0;
		c = NULL;
	}
	else
	{
		tamano = v.tamano;
		c = new TCalendario[ tamano ];

		for( int i = 0; i < tamano; i++)
		{
			c[i] = v.c[i];
		}
	}
}

TVectorCalendario::~TVectorCalendario()
{
	delete [] c;
	c = NULL;
	tamano = 0;
}

TVectorCalendario&
TVectorCalendario::operator =( const TVectorCalendario &v)
{
	if (c!=NULL)
	{
		delete [] c;
		c=NULL;
	}
	
	if( this != &v)
	{

		if( v.tamano != 0 )
		{
			tamano = v.tamano;

			c = new TCalendario[tamano];

			for( int i = 0; i < tamano; i++)
			{
				c[i] = v.c[i];
			}
		}
		else
		{
			tamano = 0;
			c = NULL;
		}
	}
	return *this;
}


bool
TVectorCalendario::operator ==( const TVectorCalendario &v)
{
	bool igual = true;

	if ( tamano == v.tamano )
	{
		for( int i = 0; i < tamano; i++)
		{
			if( c[i] != v.c[i] )
				igual = false;
		}
	}
	else
		igual = false;

	return igual;
}
bool
TVectorCalendario::operator !=( const TVectorCalendario &v)
{
	bool distinto = false;

	if ( tamano == v.tamano )
	{
		for( int i = 0; i < tamano; i++)
		{
			if( c[i] != v.c[i] )
				distinto = true;
		}
	}
	else
		distinto = true;

	return distinto;
}

TCalendario&
TVectorCalendario::operator [](int pos)
{

	TCalendario *dato = NULL;

	if ( pos >= 1 && pos <= tamano)
	{
		dato = &c[pos-1];
	}
	else
	{
		dato = &error;
	}

	return *dato;
}

TCalendario
TVectorCalendario::operator[] ( int pos ) const
{
	if ( pos >= 1 && pos <= tamano)
	{
		return c[pos-1];
	}
	else
	{
		return error;
	}
}

int
TVectorCalendario::Tamano() const
{
	return tamano;
}

int
TVectorCalendario::Ocupadas() const
{
	int cont = 0;

	for( int i = 0; i < tamano; i++)
	{
		if ( !c[i].EsVacio() )
			cont ++;
	}

	return cont;
}

bool
TVectorCalendario::ExisteCal(TCalendario &calen) const
{
	bool existe = false;
	
	for( int i = 0; i < tamano && !existe; i++)
	{
		if ( c[i] == calen )
			existe = true;
	}

	return existe;
}

void 
TVectorCalendario::MostrarMensajes(int d, int m, int a )
{
	TCalendario aux(d,m,a,"");
	
	cout << "[";
	if( d==m==1 && a==1900)//en este caso mostramos
	{}
	else
	{
		//sacamos vacio
		if (aux.Dia()==aux.Mes()==1 && aux.Anyo()==1900)//en este caso la fecha de parametros es incorrecta
		{}
		else for (int i = 0; i <tamano  ; i++)
		{
				if (c[i]==aux)
				{	
					
					if(i == tamano-1) cout<<c[i];
					else cout<<c[i]<<", ";
				}
				else if (c[i]>aux)
				{
					if(i == tamano-1) cout<<c[i];
					else cout<<c[i]<<", ";
				}
		}
	}
	
	cout << "]";

}

bool
TVectorCalendario::Redimensionar(int tam)
{
	bool redi = false;
	int i = 0;

	if ( tam > 0 )
	{
		if(tam != tamano)
		{
			TVectorCalendario aux(tam);
			redi = true;

			if ( tam > tamano)
			{

				for ( ; i < tamano; i++)
				{
					aux.c[i] = this->c[i];
				}

			}
			else
			{
				//Vector nuevo de tamaño menor al antiguo.
				for( ; i < tam; i++)
				{
					aux.c[i] = c[i];
				}


			}

			 *this = aux;
		}
	}
	return redi;
}

ostream&
operator<<( ostream& os, const TVectorCalendario &v )
{
	int i = 0;

	os << "[";
	if ( v.Tamano() > 0 )
	{
		os << "("<< i+1 << ") "<< v.c[i];
		i++;

		for( ; i < v.Tamano(); i++)
		{
			os << ", (" << i+1 <<") " << v.c[i];
		}
	}

	os << "]";

	return os;
}


