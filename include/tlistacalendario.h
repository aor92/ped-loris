#ifndef __TLISTACALENDARIO_H
#define __TLISTACALENDARIO_H

#include <iostream>
#include "tcalendario.h"
using namespace std;

class TListaCalendario
{
		friend class TNodoCalendario;
		friend ostream& operator<<(ostream &, TListaCalendario &);

	private:
		TNodoCalendario *primero;
	
	public:
		
		TListaCalendario();
		TListaCalendario(TListaCalendario &);
		~TListaCalendario();
		TListaCalendario& operator=(TListaCalendario &);
		bool operator==(TListaCalendario &);
		TListaCalendario operator+ (TListaCalendario &);
		TListaCalendario operator- (TListaCalendario &);
		Bool Insertar(TCalendario &);
		bool Borrar(TCalendario &);
		bool Borrar (TListaPos &);
		bool Borrar(int,int,int);
		bool EsVacia();
		TCalendario Obtener(TListaPos &);
		bool Buscar(TCalendario &);
		Int Longitud();
		TListaPos Primera();
		TListaPos Ultima();
		TListaCalendario SumarSubl (int, int, TListaCalendario&, int, int);
		TListaCalendario ExtraerRango (int , int );
};

class TNodoCalendario
{
	private:
	
		TCalendario c;
		TNodoCalendario *siguiente;

	public:
	
		TNodoCalendario();
		TNodoCalendario(TNodoCalendario &);
		~TNodoCalendario();
		TNodoCalendario& operator=(TNodoCalendario &);
};

#endif