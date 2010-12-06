#ifndef TPILACALENDARIO_H_
#define TPILACALENDARIO_H_

#include "tvectorcalendario.h"

class TPilaCalendario
{
	friend ostream & operator<<(ostream &, TPilaCalendario &);
	
	public:
		TPilaCalendario();
		~TPilaCalendario();
		TPilaCalendario(const TPilaCalendario&);
		TPilaCalendario& operator=(const TPilaCalendario);
		
		bool Apilar(TCalendario&);
		bool Desapilar();
		bool operator==(const TPilaCalendario&);
		bool operator!=(const TPilaCalendario&);
		bool EsVacia();
		TCalendario Cima();
		int Longitud()const;
		int NoVacios()const;
		TPilaCalendario operator-(const TPilaCalendario&);
	
	private:
		TVectorCalendario v;
		int posicion;
	
};
#endif
