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
		friend ostream& operator<<(ostream &, const TListaCalendario &);

	private:
		TNodoCalendario *primero;
	
	public:
		
		TListaCalendario();
		TListaCalendario(const TListaCalendario &);
		~TListaCalendario();
		TListaCalendario& operator=( const TListaCalendario &);
		bool operator==( const TListaCalendario &) const;
		TListaCalendario operator+ (const TListaCalendario &);
		TListaCalendario operator- (const TListaCalendario &);
		bool Insertar( const TCalendario &);
		bool Borrar( const TCalendario &);
		bool Borrar ( const TListaPos &);
		bool Borrar( const int, const int, const int);
		bool EsVacia() const;
		TCalendario Obtener(const TListaPos &) const;
		bool Buscar( const TCalendario &)const;
		int Longitud() const;
		TListaPos Primera() const;
		TListaPos Ultima() const;
		TListaCalendario SumarSubl (const int, const int,const TListaCalendario&,const  int,const  int);
		TListaCalendario ExtraerRango (int , int );
};


class TListaPos
{
		friend class TListaCalendario;
		private:
			TNodoCalendario *pos;
			
		public:
			TListaPos();
			TListaPos(const TListaPos &);
			~TListaPos();
			TListaPos& operator=(const TListaPos &);
			bool operator==(const TListaPos &) const;
			bool operator!=(TListaPos &)const;
			TListaPos Siguiente() const;
			bool EsVacia() const;
};

class TNodoCalendario
{
	friend class TListaCalendario;
	friend class TListaPos;
	private:
	
		TCalendario c;
		TNodoCalendario *siguiente;

	public:
	
		TNodoCalendario();
		TNodoCalendario(const TNodoCalendario &);
		~TNodoCalendario();
		TNodoCalendario& operator=(const TNodoCalendario &);
};

#endif
