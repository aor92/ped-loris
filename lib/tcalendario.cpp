#include "tcalendario.h"
#include <string.h>

TCalendario::TCalendario()
{}

TCalendario::TCalendario(int xdia, int xmes, int xanyo, char* xmens)
{
	
	
	
	if( CheckDate(xdia, xmes, xanyo) )
	{
		dia = xdia;
		mes = xmes;
		anyo = xanyo;
			
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
		}
	}
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

bool
TCalendario CheckDate(int dia, int mes, int anyo)
{
	//Comprobar la fecha
	bool correcto = false;
	bool bisiesto = false;
	
	if ( anyo >= 1900 )
	{
			if( anyo%4 == 0)
			{
					//Primer nivel bisiesto
				if( anyo%100 == 0)
				{
						//Puede que no sea.. a no ser... 400
						if ( anyo%400 == 0)
						{
							//Es bisiesto....
							bisiesto = true;
						}
						else bisiesto = false;
						
				}
				else bisiesto = true;
			}
			
			switch (mes)
			{
				case 1: 
				{
					if( dia >= 1 && dia <= 31 ) correcto = true;
				
					break;
				}
				
				case 2: 
				{	
					if( bisiesto )
					{
						if( dia >= 1 && dia <= 29 ) correcto = true;
					}
					else if( dia >= 1 && dia <= 28 ) correcto = true;
									
					break;
				}
				
				case 3:
				{	
					if( dia >= 1 && dia <= 31 ) correcto = true;
					
					break;
				}
				
				case 4:
				{	
					if( dia >= 1 && dia <= 30 ) correcto = true;
					break;
				}
				
				case 5:
				{	
					if( dia >= 1 && dia <= 31 ) correcto = true;
					break;
				}	
				
				case 6:
				{	
					if( dia >= 1 && dia <= 30 ) correcto = true;
					break;
				}	
				
				case 7:
				{	
					if( dia >= 1 && dia <= 31 ) correcto = true;
					break;
				}		
					
				case 8:
				{	
					if( dia >= 1 && dia <= 31 ) correcto = true;
					break;
				}	
				
				case 9:
				{	
					if( dia >= 1 && dia <= 30 ) correcto = true;
					break;
				}	
				
				case 10:
				{	
					if( dia >= 1 && dia <= 31 ) correcto = true;
					break;
				}
				case 11:
				{	
					if( dia >= 1 && dia <= 30 ) correcto = true;
					break;
				}	
				case 12:
				{	
					if( dia >= 1 && dia <= 31 ) correcto = true;
					break;
				}	
			}
			
	}
	
	return correcto;
}


TCalendario operator+(int d)
{
	dia = dia + d;
}

TCalendario operator-(int d)
{
	dia = dia - d;
}
