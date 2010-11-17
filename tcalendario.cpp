#include "tacalendario.h"
#include <string.h>

TCalendario::TCalendario()
{}

TCalendario::TCalendario(int xdia, int xmes, int xanyo, char* xmens)
{
	
	if( xdia >= 1 && xdia <= 31 && xmes >= 1 && xmes <= 12 && anyo >= 1990 )
	{
		dia = xdia;
		mes = xmes;
		anyo = xanyo;
	}
	else 
	{
		dia = 1;
		mes = 1;
		anyo = 1990;
	}
	
	int lon = 0,i = 0;
	
	if( xmens == NULL )
	{
		mens = NULL;
	}
	else
	{
		lon = strlen(xmens);
		
		for( ; i < lon; i++ )
		{
			mens[i] = xmens[i];
		}
		mens[i] = '/0';
	{
}

TCalendario::TCalendario( const TCalendario &c )
{
	dia = c.dia;
	mes = c.mes;
	anyo = c.anyo;
	
	int lon = 0,i = 0;
	
	if( c.mens == NULL )
	{
		mens = NULL;
	}
	else
	{
		lon = strlen(c.mens);
		
		for( ; i < lon; i++ )
		{
			mens[i] = c.mens[i];
		}
		mens[i] = '/0';
	{
}

TCalendario::~TCalendario()
{
	mes = dia = 1;
	anyo = 1990;
	delete mens;
	mens = NULL;
}

TCalendario &
TCalendario::operator=( const TCalendario & c)
{
	dia = c.dia;
	mes = c.mes;
	anyo = c.anyo;
	
	if( c.cemens == NULL )
	{
		mens = NULL;
	}
	else
	{
		mens = new char[ strlen(c.mens) + 1 ];
	}
	if( mens != NULL ) // Comprobar que se haya creado el espacio en memoria;
	{
		strcpy(mens,c.mens);
	}

	return *this;
}

TCalendario operator+(int d)
{
	dia = dia + d;
}

TCalendario operator-(int d)
{
	dia = dia - d;
}
