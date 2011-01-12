#ifndef __TLISTACALENDARIO_H
#define __TLISTACALENDARIO_H

#include <iostream>
#include "tcalendario.h"
using namespace std;

class TNodoCalendario;
class TListaPos;

class TListaCalendario
{
		friend class TNodoCalendario;
		friend ostream& operator<<(ostream &, TListaCalendario &);

	private:
		TNodoCalendario *primero;
	
	public:
		
		TListaCalendario();
		TListaCalendario( const TListaCalendario &);
		~TListaCalendario();
		TListaCalendario& operator=( const TListaCalendario &);
		bool operator==( const TListaCalendario &) const;
		TListaCalendario operator+ (TListaCalendario &);
		TListaCalendario operator- (TListaCalendario &);
		bool Insertar( const TCalendario &);
		bool Borrar( const TCalendario &);
		bool Borrar ( const TListaPos &);
		bool Borrar( const int, const int, const int);
		bool EsVacia();
		TCalendario Obtener(TListaPos &);
		bool Buscar( const TCalendario &);
		int Longitud();
		TListaPos Primera();
		TListaPos Ultima();
		TListaCalendario SumarSubl (int, int, TListaCalendario&, int, int);
		TListaCalendario ExtraerRango (int , int );
};


class TListaPos
{
		private:
			TNodoCalendario *pos;
			
		public:
			TListaPos();
			TListaPos(TListaPos &);
			~TListaPos();
			TListaPos& operator=(TListaPos &);
			bool operator==(TListaPos &);
			bool operator!=(TListaPos &);
			TListaPos Siguiente();
			bool EsVacia();
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
