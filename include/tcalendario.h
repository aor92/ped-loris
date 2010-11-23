#ifndef _TCALENDARIO_H_
#define _TCALENDARIO_H_


/** \file tcalendario.h
* 	\brief Este fichero contiene la clase tcalendario
*
* 	En el fichero se incluyen los encabezados de las funciones de la clase tcalendario asi como miembros y 
* 	declaraciones
*/

#include<iostream>
using namespace std;
/** \brief Clase tcalendario
*
* 	La clase tcalendario es un clase que contiene un calendario
*/
class TCalendario{
	private:
		/** \brief dia
		* Dia del Calendario*/
		int dia;
		/** \brief mes
		* Mes del Calendario*/
		int mes;
		/** \brief Anyo
		* Anyo del Calendario*/
		int anyo;
		/** \brief mens
		* Mensaje del Calendario*/
		char *mens;
	public: 
		TCalendario ();
		TCalendario (const int dia,const int mes,const int anyo,const char * mens);
		TCalendario (const TCalendario &);
		~TCalendario();
		TCalendario & operator=(const TCalendario &);
		TCalendario operator+(const int);
		TCalendario operator-(const int);
		TCalendario operator++(const int);
		TCalendario &operator++();
		TCalendario operator--(const int);
		TCalendario &operator--();
		bool ModFecha (const int,const int,const int);
		void ModMensaje(const char *);
		bool operator ==(const TCalendario &)const;
		bool operator !=(const TCalendario &)const;
		bool operator>(const TCalendario &)const;
		bool operator<(const TCalendario &)const;
		bool EsVacio() const;
		//! Funcion Dia()
		/*! Devuelve el dia del calendario*/
		int Dia() const{return dia;}
		//! Funcion Mes()
		/*! Devuelve el mes del calendario*/
		int Mes() const{return mes;}
		//! Funcion Anyo()
		/*! Devuelve el Anyo del calendario*/
		int Anyo() const{return anyo;}
		//! Funcion *Mensaje()
		/*! Modifica el mensaje del calendario*/
		char *Mensaje() const{return mens;}
		friend ostream & operator<<(ostream &,const TCalendario &);
};
#endif
