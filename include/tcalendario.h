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
	
		/** \brief Constructor por defecto.
		 *
		 * Constructor por defecto que inicializa según el formato especificado los componentes del TCalendario.
		 */
		TCalendario ();
		
		/** \brief Constructor sobrecargado.
		 *
		 * Constructor sobrecargado TCalendario.
		 * \param dia int con el que le pasamos un dia al constructor TCalendario.
		 * \param mes int con el que le pasamos un mes al constructor TCalendario.
		 * \param anyo int con el que le pasamos un anyo al constructor TCalendario.
		 * \param mens Puntero a char en el que le pasamos un mensaje al TCalendario.
		 */
		TCalendario (const int dia,const int mes,const int anyo,const char * mens);
		
		/** \brief Constructor de copia.
		 *
		 * Constructor de copia de TCalendario.
		 * \param cal TCalendario desde el que copiamos al nuevo TCalendario.
		 */
		TCalendario (const TCalendario &);
		
		/** \brief Destructor de TCalendario
		*   Asigna la fecha por defecto al calendario y borra su nombre
		*/
		~TCalendario();
		
		/** \brief Operador de asignacion de la calse Calendario
		*  Asigna los valores de un calendario a otro
		*  \param as calendario del que se toman los valores
		*/
		TCalendario & operator=(const TCalendario &);
		
		/** \brief Operador de suma sobrecargado
		*  Al llamar al operador de suma de la manera TCalendario+int devuelve un TCalendario con los dias sumados
		*  \param ex numero de dias que se quieren sumar a la fecha
		*/
		TCalendario operator+(const int);
		
		/** \brief Operador de resta sobrecargado
		*  Al llamar al operador de resta de la manera TCalendario-int devuelve un TCalendario con los dias restados
		*  \param ex numero de dias que se quieren restar a la fecha
		*/
		TCalendario operator-(const int);
		
		/** \brief Operador TCalendario++ sobrecargado
		*  Aumenta la fecha del calendario en 1 dia y devuelve la fecha original
		*  \param ex parametro que se usa para diferencia los dos operadores de incremento
		*/
		TCalendario operator++(const int);
		
		/** \brief Operador ++TCalendario sobrecargado
		*  Aumenta la fecha del calendario en 1 dia y la devuelve
		*/
		TCalendario &operator++();
		
		/** \brief Operador TCalendario-- sobrecargado
		*  Reduce la fecha del calendario en 1 dia y devuelve la fecha original
		*  \param ex parametro que se usa para diferencia los dos operadores de decremento
		*/
		TCalendario operator--(const int);
		
		/** \brief Operador --TCalendario sobrecargado
		*  Reduce la fecha del calendario en 1 dia y la devuelve
		*/
		TCalendario &operator--();
		
		/** \brief Modificar la fecha de Calendario
		*  Modifica la fecha de calendario
		*  \param dia dia que se va a insertar
		*  \param mes mes que se va a insertar
		*  \param anyo anyo que se va a insertar
		*/
		bool ModFecha (const int,const int,const int);
		
		/** \brief Modificar el mensaje del Calendario
		*  Modifica el mensaje del calendario
		*  \param m nuevo mensaje que se le asigna al calendario
		*/
		void ModMensaje(const char *);
		
		/** \brief Operador comparacion(igualdad) de calendarios
		*  Devuelve true si la primera fecha es igual que la segunda
		*  \param en calendario de la derecha de la comparación
		*/
		bool operator ==(const TCalendario &)const;
		
		/** \brief Operador comparacion(distinto) de calendarios
		*  Devuelve true si la primera fecha es distinta que la segunda
		*  \param en calendario de la derecha de la comparación
		*/
		bool operator !=(const TCalendario &)const;
		
		/** \brief Operador mayor (comparacion) de calendario
		*  Devuelve true si la primera fecha es mayor que la segunda
		*  \param en calendario de la derecha de la comparación
		*/
		bool operator>(const TCalendario &)const;
		
		/** \brief Operador menor (comparacion) de calendario
		*  Devuelve true si la primera fecha es menor que la segunda
		*  \param en calendario de la derecha de la comparación
		*/
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
		
			
		/** \brief Sobrecarga del operador "<<", función amiga.
		 *
		 * Función amiga que se encarga de mostrar por pantalla, en un formato determinado un TCalendario que le pasemos.
		 *
		 * \param os Ostream donde guardaremos la informacion que queremos mostrar.
		 * \param cal TCalendario que queremos mostrar.
		 *
		 * \return La funcion devuelve un ostream&.
		 */
		friend ostream & operator<<(ostream &,const TCalendario &);
};
#endif
